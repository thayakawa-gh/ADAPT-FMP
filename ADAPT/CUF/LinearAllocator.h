#ifndef CUF_LINEAR_ALLOCATOR_H
#define CUF_LINEAR_ALLOCATOR_H

#include <functional>
#include <vector>
#include <assert.h>

namespace adapt
{

inline namespace cuf
{

class LinearAllocator
{
public:

	LinearAllocator()
		: mStorage(nullptr), mStorageEnd(nullptr), mCapacity(0)
	{}
	LinearAllocator(size_t cap)
		: mStorage(nullptr), mStorageEnd(nullptr), mCapacity(cap)
	{
		if (cap > 0) Allocate(cap);
	}
	LinearAllocator(const LinearAllocator&) = delete;
	LinearAllocator(LinearAllocator&& buf) noexcept
		: mStorage(buf.mStorage), mStorageEnd(buf.mStorageEnd),
		mCapacity(buf.mCapacity), mTypeInfos(std::move(buf.mTypeInfos))
	{
		buf.mStorage = nullptr;
		buf.mStorageEnd = nullptr;
		buf.mCapacity = 0;
	}

	LinearAllocator& operator=(const LinearAllocator&) = delete;
	LinearAllocator& operator=(LinearAllocator&& buf) noexcept
	{
		Destroy();
		mStorage = buf.mStorage;
		mStorageEnd = buf.mStorageEnd;
		mCapacity = buf.mCapacity;
		mTypeInfos = std::move(buf.mTypeInfos);
		buf.mStorage = nullptr;
		buf.mStorageEnd = nullptr;
		buf.mCapacity = 0;
		return *this;
	}
	~LinearAllocator()
	{
		Destroy();
	}

private:
	template <class Type>
	static void MoveConstruct(char* from, char* to)
	{
		new (reinterpret_cast<Type*>(to)) Type(std::move(*reinterpret_cast<Type*>(from)));
		reinterpret_cast<Type*>(from)->~Type();
	}
	template <class Type>
	static void Destruct(char* ptr)
	{
		reinterpret_cast<Type*>(ptr)->~Type();
	}
public:

	void Allocate(size_t cap)
	{
		//mStorageがnullptrであるときに呼ぶこと。
		assert(cap > 0 && mStorage == nullptr);
		mCapacity = cap;
		mStorage = static_cast<char*>(malloc(mCapacity));
		mStorageEnd = mStorage;
	}
	void Reallocate(size_t cap)
	{
		//mStorageがnullptrでないときに呼ぶこと。
		assert(cap > GetCapacity() && mStorage);
		//size_t size = GetSize();
		char* oldstrorage = mStorage;
		char* from = oldstrorage;
		char* to = static_cast<char*>(malloc(cap));
		mStorage = to;
		mCapacity = cap;
		for (auto& t : mTypeInfos)
		{
			t.mMoveConstructor(from, to);
			from += t.mSize;
			to += t.mSize;
		}
		mStorageEnd = to;
		free(oldstrorage);
	}
	void Destroy()
	{
		if (mStorage == nullptr) return;
		char* ptr = mStorage;
		for (auto& t : mTypeInfos)
		{
			t.mDestructor(ptr);
			ptr += t.mSize;
		}
		free(mStorage);
		mStorage = nullptr;
		mStorageEnd = nullptr;
	}
	size_t GetSize() const { return mStorageEnd - mStorage; }
	size_t GetCapacity() const { return mCapacity; }

	template <class T>
	T& Get(size_t index = 0) { return *reinterpret_cast<T*>(mStorage + index); }
	template <class T>
	const T& Get(size_t index = 0) const { return *reinterpret_cast<const T*>(mStorage + index); }

	size_t PtrToIndex(const void* ptr) const { return (size_t)((const char*)ptr - mStorage); }

	//Push系関数は構築された場所のポインタを返す。
	template <class Type, class ...Args>
	size_t EmplaceBack(Args&& ...args)
	{
		size_t size = GetSize();
		if (mCapacity < size + sizeof(Type))
		{
			if (mCapacity == 0)
			{
				Allocate(sizeof(Type));
			}
			else
			{
				size_t x = (size + sizeof(Type) - mCapacity) / mCapacity + 2;
				Reallocate(mCapacity * x);
			}
		}
		Type* ptr = reinterpret_cast<Type*>(mStorageEnd);
		new (ptr) Type(std::forward<Args>(args)...);
		mStorageEnd += sizeof(Type);

		TypeInfo i;
		i.mSize = sizeof(Type);
		i.mMoveConstructor = MoveConstruct<Type>;
		i.mDestructor = Destruct<Type>;
		mTypeInfos.emplace_back(std::move(i));

		return reinterpret_cast<char*>(ptr) - mStorage;
	}
	template <class Type>
	size_t PushBack(Type&& t)
	{
		return EmplaceBack<std::remove_cv_t<std::remove_reference_t<Type>>>(std::forward<Type>(t));
	}
	void PopBack()
	{
		auto& i = mTypeInfos.back();
		mStorageEnd -= i.mSize;
		i.mDestructor(mStorageEnd);
		mTypeInfos.pop_back();
	}

private:

	struct TypeInfo
	{
		size_t mSize;
		void(*mMoveConstructor)(char*, char*);
		void(*mDestructor)(char*);
	};
	char* mStorage;
	char* mStorageEnd;
	size_t mCapacity;
	std::vector<TypeInfo> mTypeInfos;
};

}

}

#endif