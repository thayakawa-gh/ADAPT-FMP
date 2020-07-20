#ifndef CUF_ANYTYPE_H
#define CUF_ANYTYPE_H

#include <typeinfo>
#include <memory>
#include <ADAPT/CUF/Template.h>

namespace adapt
{

inline namespace cuf
{

//Boost.Anyの代替品。任意の値を格納できる。
//ADAPTはBoostに依存することが出来ない上に、msvc2015をサポートするためstd::anyも使えない。
//なのでそれっぽいものを作っておく。
class Any
{

	class PlaceHolder
	{
	public:
		virtual ~PlaceHolder() {}
		virtual PlaceHolder* Clone() const = 0;
	};

	template <class Type>
	class Holder : public PlaceHolder
	{
	public:
		template <class ...Args>
		Holder(Args&& ...args)
			: mValue(std::forward<Args>(args)...)
		{}
	private:
		template <class Dummy = void, bool B = std::is_copy_constructible<Type>::value>
		struct Clone_impl;
		template <class Dummy, bool B>
		struct Clone_impl
		{
			static PlaceHolder* f(const Holder<Type>& h) { return new Holder<Type>(h.mValue); }
		};
		template <class Dummy>
		struct Clone_impl<Dummy, false>
		{
			static PlaceHolder* f(const Holder<Type>& h) { throw InvalidType("Assigned class is not copyable."); }
		};
	public:
		virtual PlaceHolder* Clone() const override
		{
			return Clone_impl<>::f(*this);
		}

		Type mValue;
	};

public:

	Any() : mContent(nullptr) {}

	template <class Type, std::enable_if_t<!std::is_same<RemoveCVRefT<Type>, Any>::value, std::nullptr_t> = nullptr>
	Any(Type&& t)
		: mContent(new Holder<RemoveCVRefT<Type>>(std::forward<Type>(t)))
	{}

	Any(const Any& any)
		: mContent(any.mContent->Clone())
	{}
	Any(Any&& any) noexcept
		: mContent(std::move(any.mContent))
	{}

	Any& operator=(const Any& any)
	{
		mContent.reset(any.mContent->Clone());
		return *this;
	}
	Any& operator=(Any&& any) noexcept
	{
		mContent = std::move(any.mContent);
		return *this;
	}

	template <class Type>
	Any& operator=(Type&& v)
	{
		mContent = std::make_unique<Holder<RemoveCVRefT<Type>>>(std::forward<Type>(v));
		return *this;
	}

	template <class Type, class ...Args>
	void Emplace(Args&& ...args)
	{
		mContent = std::make_unique<Holder<Type>>(std::forward<Args>(args)...);
	}

	template <class Type>
	Type& Get()
	{
		return static_cast<Holder<Type>&>(*mContent).mValue;
	}
	template <class Type>
	const Type& Get() const
	{
		return static_cast<const Holder<Type>&>(*mContent).mValue;
	}

	bool IsEmpty() const { return !mContent; }

private:
	std::unique_ptr<PlaceHolder> mContent;
};

//shared_ptr+anyみたいなもの。機能的にはshared_ptr<void>と大差ない気がする。
//任意の型の値を格納することができ、なおかつreference countを持ち共有することができる。
//通常のコピーはshared_ptrと同じようにshallow copyするだけで、
//完全に複製するにはClone関数を呼ぶ必要がある。
//std::shared_ptrはポインタx2の大きさを持つため、ArbValueに格納することができない。
//ので、weak_ptrに相当する機能を排しポインタx1の大きさにしたAnyを用意することにした。
//循環参照対策をしていないので注意。
class ShareableAny
{
	class PlaceHolder
	{
	public:
		PlaceHolder() : mCount(1) {}
		virtual ~PlaceHolder() {}
		virtual PlaceHolder* Clone() const = 0;

		int Increase() { return ++mCount; }
		int Decrease() { return --mCount; }
		int GetCount() const { return mCount; }
	private:
		int mCount;
	};

	template <class Type>
	class Holder : public PlaceHolder
	{
	public:
		template <class ...Args>
		Holder(Args&& ...args)
			: mValue(std::forward<Args>(args)...)
		{}
	private:
		template <class Dummy = void, bool B = std::is_copy_constructible<Type>::value>
		struct Clone_impl;
		template <class Dummy, bool B>
		struct Clone_impl
		{
			static PlaceHolder* f(const Holder<Type>& h) { return new Holder<Type>(h.mValue); }
		};
		template <class Dummy>
		struct Clone_impl<Dummy, false>
		{
			static PlaceHolder* f(const Holder<Type>& h) { throw InvalidType("Assigned class is not copyable."); }
		};
	public:
		virtual PlaceHolder* Clone() const override
		{
			return Clone_impl<>::f(*this);
		}

		Type mValue;
	};

public:

	ShareableAny() : mContent(nullptr) {}

	template <class Type, class ...Args>
	ShareableAny(Args&& ...args)
		: mContent(new Holder<Type>(std::forward<Args>(args)...))
	{}

	//ShareableAnyのコピーはShallowCopyである。
	ShareableAny(const ShareableAny& any)
		: mContent(any.mContent)
	{
		mContent->Increase();
	}
	ShareableAny(ShareableAny&& any) noexcept
		: mContent(any.mContent)
	{
		any.mContent = nullptr;
	}

	ShareableAny& operator=(const ShareableAny& any)
	{
		Delete();
		mContent = any.mContent;
		mContent->Increase();
	}
	ShareableAny& operator=(ShareableAny&& any) noexcept
	{
		Delete();
		mContent = any.mContent;
		any.mContent = nullptr;
	}

	~ShareableAny()
	{
		Delete();
	}

	template <class Type, class ...Args>
	void Emplace(Args&& ...args)
	{
		Delete();
		mContent = new Holder<Type>(std::forward<Args>(args)...);
	}

	template <class Type>
	Type& Get()
	{
		return static_cast<Holder<Type>&>(*mContent).mValue;
	}
	template <class Type>
	const Type& Get() const
	{
		return static_cast<const Holder<Type>&>(*mContent).mValue;
	}

	//ShareableAny Clone() const { return ShareableAny(mContent->Clone()); }

	void Delete()
	{
		if (mContent)
		{
			mContent->Decrease();
			if (mContent->GetCount() == 0) delete mContent;
			mContent = nullptr;
		}
	}
	int GetCount() const { return mContent->GetCount(); }

	bool IsEmpty() const { return !mContent; }

private:
	PlaceHolder* mContent;
};

}

}

#endif