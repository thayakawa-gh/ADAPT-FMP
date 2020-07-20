#ifndef CUF_STATIC_ANY_H
#define CUF_STATIC_ANY_H

#include <type_traits>
//#include <ADAPT/CUF/Template.h>

namespace adapt
{

inline namespace cuf
{

template <size_t Capacity, size_t Align = 8ui64>
class StaticAny
{
	template <class Type>
	static void ImplicitFunctions(int pr, void* self, void* other)
	{
		Type* ptr = static_cast<Type*>(self);
		//destructor
		if (pr == 0) ptr->~Type();
		//copy
		else if (pr == 1) new (ptr) Type(*static_cast<const Type*>(other));
		//move
		else if (pr == 2) new (ptr) Type(std::move(*static_cast<Type*>(other)));
	}

public:

	StaticAny() : mImplicitFunctions(nullptr) {}
	template <class Type, std::enable_if_t<(Capacity >= sizeof(Type)), std::nullptr_t> = nullptr>
	StaticAny(Type&& arg)
	{
		using Type_ = std::remove_cv_t<std::remove_reference_t<Type>>;
		new (&mStorage) Type_(std::forward<Type>(arg));
		mImplicitFunctions = ImplicitFunctions<Type_>;
	}
	StaticAny(const StaticAny& other)
	{
		other.mImplicitFunctions(1, &mStorage, (void*)&other.mStorage);
		mImplicitFunctions = other.mImplicitFunctions;
	}
	StaticAny(StaticAny&& other) noexcept
	{
		other.mImplicitFunctions(2, &mStorage, &other.mStorage);
		mImplicitFunctions = other.mImplicitFunctions;
		other.Destroy();
	}
	template <class Type, std::enable_if_t<(Capacity >= sizeof(Type)), std::nullptr_t> = nullptr>
	StaticAny& operator=(Type&& arg)
	{
		Destroy();
		using Type_ = std::remove_cv_t<std::remove_reference_t<Type>>;
		new (&mStorage) Type_(std::forward<Type>(arg));
		mImplicitFunctions = ImplicitFunctions<Type_>;
		return *this;
	}
	StaticAny& operator=(const StaticAny& other)
	{
		Destroy();
		other.mImplicitFunctions(1, &mStorage, (void*)&other.mStorage);
		mImplicitFunctions = other.mImplicitFunctions;
		return *this;
	}
	StaticAny& operator=(StaticAny&& other)
	{
		Destroy();
		other.mImplicitFunctions(2, &mStorage, &other.mStorage);
		mImplicitFunctions = other.mImplicitFunctions;
		other.Destroy();
		return *this;
	}
	~StaticAny()
	{
		Destroy();
	}

	void Destroy()
	{
		if (!mImplicitFunctions) return;
		mImplicitFunctions(0, &mStorage, nullptr);
		mImplicitFunctions = nullptr;
	}

	template <class Type, class ...Args>
	std::enable_if_t<(Capacity >= sizeof(Type))> Emplace(Args&& ...args)
	{
		static_assert(sizeof(Type) <= Capacity, "Size of Type assigned to StaticAny must be equal or smaller than the capacity.");
		Destroy();
		new (&mStorage) Type(std::forward<Args>(args)...);
		mImplicitFunctions = ImplicitFunctions<Type>;
	}
	template <class Type>
	Type& Get() { return *reinterpret_cast<Type*>(&mStorage); }
	template <class Type>
	const Type& Get() const { return *reinterpret_cast<const Type*>(&mStorage); }

	void(*mImplicitFunctions)(int, void*, void*);
	std::aligned_storage_t<Capacity, Align> mStorage;
};

template <class Base, size_t Size, size_t Align = 8>
class StaticBase
{
public:

	template <class T, class ...Args>
	std::enable_if_t<std::is_base_of<Base, T>::value>
		Emplace(Args&& ...args)
	{
		mStorage.Emplace<T>(std::forward<Args>(args)...);
	}
	template <class T>
	std::enable_if_t<std::is_base_of<Base, RemoveCVRef<T>>::value>
		operator=(T&& t)
	{
		mStorage = std::forward<T>(t);
	}

private:
	StaticAny<Size, Align> mStorage;
};

}

}

#endif