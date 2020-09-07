#ifndef CUF_STRING_H
#define CUF_STRING_H

#include <cstdlib>
#include <cstring>
#include <string>

namespace adapt
{

inline namespace cuf
{

namespace detail
{

inline char Upper(char c)
{
	if ('a' <= c && c <= 'z') c = c - ('a' - 'A');
	return c;
}

inline char Lower(char c)
{
	if ('A' <= c && c <= 'Z') c = c + ('a' - 'A');
	return c;
}

template <class _SizeType>
class CStrAllocator
{
	//Capacity情報のみを追加確保するAllocator。配列の先頭にsizeof(SizeType)バイト分のCapacity格納領域が作られる。
	//使用するメモリがSizeType分小さくなるが、空文字で終端を判定するためやや動作が遅くなる。
	//Capacity==0のとき、ポインタはnullptrである。
public:

	using SizeType = _SizeType;
	static const int msOffset = sizeof(SizeType);//確保したメモリの先頭に、Capacityを格納する領域を追加する。

	static char* New(SizeType size)
	{
		if (size == 0) return nullptr;

		//+1は終端文字の分。
		char* ptr = new char[size + msOffset + 1];
		SizeType* s = reinterpret_cast<SizeType*>(ptr);
		*s = size;
		ptr += msOffset;
		ptr[0] = '\0';
		return ptr;
	}
	static void Delete(char* ptr)
	{
		delete (ptr - msOffset);
	}

	static SizeType GetSize(const char* ptr)
	{
		return ptr ? strlen(ptr) : 0;
	}
	static SizeType GetCapacity(const char* ptr)
	{
		if (!ptr) return 0;
		const SizeType* size = reinterpret_cast<const SizeType*>(ptr - msOffset);
		return *size;
	}

	//ptrの長さをsizeに拡張し（Capacityがすでにsize以上であった場合、何も起きない）、
	//新規に確保した（確保されなかった場合は元々の）ポインタを返す。
	//ptrの中身はきちんとコピーされ、ptrはdeleteされる。
	static char* Reserve(char* ptr, SizeType size)
	{
		if (!ptr) return New(size);
		SizeType cap = GetCapacity(ptr);
		if (cap >= size) return ptr;
		return Reserve_impl(ptr, size);
	}
	//Capacityがsize以上になるまで2^n倍する（Capacityがすでにsize以上であった場合、何も起きない）。
	//戻り値は新規確保（確保されなかった場合は元々の）ポインタと、新たに確保された領域のCapacity。
	static std::pair<char*, SizeType> Expand(char* ptr, SizeType size)
	{
		if (!ptr) return std::make_pair(New(size), size);
		SizeType cap = GetCapacity(ptr);
		if (cap >= size) return std::make_pair(ptr, cap);
		//単に2倍するのではなく+1しておかないと、
		//cap==0である場合に困る。
		SizeType newsize = cap * 2 + 1;
		while (newsize < size)
		{
			//newsizeがsize以上の大きさになるまで繰り返し2倍+1する。
			//logとかでnを求めるのとループするのとではどちらが速いのか。
			newsize = newsize * 2;
		}
		return std::make_pair(Reserve_impl(ptr, newsize), newsize);
	}

	//すでにdstには必要な領域が確保されていることを前提とする。
	static void Append(char* dst, SizeType pos, const char* src, SizeType)
	{
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4996)
#endif
		strcpy(dst + pos, src);
#ifdef _MSC_VER
#pragma warning(pop)
#endif
	}
	static void Append(char* dst, SizeType pos, char c)
	{
		dst[pos] = c;
		dst[pos + 1] = '\0';
	}

private:

	//cap分の長さの配列を確保し、
	//len分をptrから戻り値へコピーする。
	//ptrがnullptrであってはならない。
	static char* Reserve_impl(char* ptr, SizeType cap)
	{
		char* p = new char[cap + msOffset + 1];
		SizeType* s = reinterpret_cast<SizeType*>(p);
		*s = cap;
		p += msOffset;
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4996)
#endif
		strcpy(p, ptr);
#ifdef _MSC_VER
#pragma warning(pop)
#endif
		delete[](ptr - msOffset);
		return p;
	}
};

template <class SizeType>
class CSStrAllocator
{
	//CapacityとLengthの双方を保有するAllocator
	//SizeType分のメモリを余計に食うが、strlenなどを使わなくて済む。
	//......というものをそのうち作りたい。
};

}

template <class Allocator>
class BasicString
{
public:

	using SizeType = typename Allocator::SizeType;
	//std::stringはバイト長が8バイトではない（環境によって異なる？）ので、
	//8バイトに圧縮可能な簡易可変長文字列型を作る。
	//基本的にはAllocatorがその挙動を決めるが、
	//1.CStrAllocatorを使うとmPtrの直前sizeof(SizeType)バイトに容量を格納する領域が追加される。
	//2.CSStrAllocatorを使うと、容量に加えて文字列長も追加される。
	//メンバ変数として容量、サイズを持つAllocatorも設計可能だが、std::stringで足りるか。16バイト文字列なんて使いどころないよなぁ。

	BasicString()
		: mPtr(nullptr)
	{}
	BasicString(size_t len)
	{
		mPtr = Allocator::New(size);
	}
	BasicString(const char* str)
		: mPtr(nullptr)
	{
		SizeType size = strlen(str);
		mPtr = Allocator::New(size);
		if (size != 0) Allocator::Append(mPtr, 0, str, size);
	}
	BasicString(char c)
		: mPtr(nullptr)
	{
		SizeType size = 1;
		mPtr = Allocator::New(size);
		Allocator::Append(mPtr, 0, c);
	}
	BasicString(const std::string& str)
		: mPtr(nullptr)
	{
		SizeType size = str.size();
		mPtr = Allocator::New(size);
		if (size != 0) Allocator::Append(mPtr, 0, str.c_str(), size);
	}
	BasicString(const BasicString& str)
		: mPtr(nullptr)
	{
		SizeType size = str.GetSize();
		mPtr = Allocator::New(size);
		if (size != 0) Allocator::Append(mPtr, 0, str.GetCStr(), size);
	}
	BasicString(BasicString&& str) noexcept
		: mPtr(str.mPtr)
	{
		str.mPtr = nullptr;
	}
	~BasicString()
	{
		Allocator::Delete(mPtr);
	}

	BasicString& operator=(const char* str)
	{
		SizeType size = strlen(str);
		if (GetCapacity() < size) Expand(size);
		if (size != 0) Allocator::Append(mPtr, 0, str, size);
		return *this;
	}
	BasicString& operator=(char c)
	{
		if (GetCapacity() < 1) Expand(1);
		Allocator::Append(mPtr, 0, c);
		return *this;
	}
	BasicString& operator=(const std::string& str)
	{
		SizeType size = str.size();
		if (GetCapacity() < size) Expand(size);
		if (size != 0) Allocator::Append(mPtr, 0, str.c_str(), size);
		return *this;
	}
	BasicString& operator=(const BasicString& str)
	{
		SizeType size = str.GetSize();
		if (GetCapacity() < size) Expand(size);
		if (size != 0) Allocator::Append(mPtr, 0, str.GetCStr(), size);
		return *this;
	}
	BasicString& operator=(BasicString&& str) noexcept
	{
		Allocator::Delete(mPtr);
		mPtr = str.mPtr;
		str.mPtr = nullptr;
		return *this;
	}

	SizeType GetCapacity() const
	{
		return Allocator::GetCapacity(mPtr);
	}
	SizeType GetSize() const
	{
		return Allocator::GetSize(mPtr);
	}
	SizeType capacity() const { return GetCapacity(); }
	SizeType size() const { return GetSize(); }
	bool IsEmpty() const { return GetSize() == 0; }

	BasicString& operator+=(const char* str)
	{
		SizeType size = strlen(str);
		if (size == 0) return *this;
		SizeType ownsize = GetSize();
		Expand(size + ownsize);
		Allocator::Append(mPtr, ownsize, str, size);
		return *this;
	}
	BasicString& operator+=(char str)
	{
		SizeType ownsize = GetSize();
		Expand(size + 1);
		Allocator::Append(mPtr, ownsize, str);
		return *this;
	}
	BasicString& operator+=(const std::string& str)
	{
		SizeType size = str.size();
		if (size == 0) return *this;
		SizeType ownsize = GetSize();
		Expand(size + ownsize);
		Allocator::Append(mPtr, ownsize, str.c_str(), size);
		return *this;
	}
	BasicString& operator+=(const BasicString& str)
	{
		SizeType size = str.GetSize();
		if (size == 0) return *this;
		SizeType ownsize = GetSize();
		Expand(size + ownsize);
		Allocator::Append(mPtr, ownsize, str.GetCStr(), size);
		return *this;
	}
	BasicString operator+(char str) const
	{
		BasicString res(*this);
		res += str;
		return std::move(res);
	}
	BasicString operator+(const char* str) const
	{
		BasicString res(*this);
		res += str;
		return std::move(res);
	}
	BasicString operator+(const std::string& str) const
	{
		BasicString res(*this);
		res += str;
		return std::move(res);
	}
	BasicString operator+(const BasicString& str) const
	{
		BasicString res(*this);
		res += str;
		return std::move(res);
	}

	friend bool operator==(const BasicString& str1, const BasicString& str2)
	{
		int res = strcmp(str1.mPtr, str2.mPtr);
		return res == 0;
	}
	friend bool operator==(const char* str1, const BasicString& str2)
	{
		int res = strcmp(str1, str2.mPtr);
		return res == 0;
	}
	friend bool operator==(const BasicString& str1, const char* str2)
	{
		int res = strcmp(str1.mPtr, str2);
		return res == 0;
	}
	friend bool operator!=(const BasicString& str1, const BasicString& str2)
	{
		return !(str1 == str2);
	}
	friend bool operator!=(const char* str1, const BasicString& str2)
	{
		return !(str1 == str2);
	}
	friend bool operator!=(const BasicString& str1, const char* str2)
	{
		return !(str1 == str2);
	}

	char& operator[](SizeType index) { return mPtr[index]; }
	const char& operator[](SizeType index) const { return mPtr[index]; }

	std::string ToStdString() const { return std::string(mPtr); }
	const char* GetCStr() const { return mPtr; }
	const char* c_str() const { return GetCStr(); }

	BasicString SubStr(SizeType start, SizeType len) const
	{
		BasicString res(len);
		SubStr(res, start, len);
		return std::move(res);
	}
	void SubStr(BasicString& res, SizeType start, SizeType len) const
	{
		//結果を引数で受け取る方。res(len);
		res.Expand(len);
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4996)
#endif
		strncpy(res.mPtr, mPtr + start, len);
#ifdef _MSC_VER
#pragma warning(pop)
#endif
		res.mPtr[len] = '\0';
	}

	//小文字を大文字に変換する。
	BasicString Upper()
	{
		BasicString res;
		Upper(res);
		return std::move(res);
	}
	void Upper(BasicString& res)
	{
		SizeType size = GetSize();
		res.Expand(size);
		for (SizeType pos = 0; pos < size; ++pos)
		{
			res.mPtr[pos] = detail::Upper(mPtr[pos]);
		}
	}
	//大文字を小文字に変換する。
	BasicString Lower()
	{
		BasicString res;
		Lower(res);
		return std::move(res);
	}
	void Lower(BasicString& res)
	{
		SizeType size = GetSize();
		res.Expand(size);
		for (SizeType pos = 0; pos < size; ++pos)
		{
			res.mPtr[pos] = detail::Lower(mPtr[pos]);
		}
	}

private:

	//Capacityがきっちりsizeの長さになるよう調整する。
	void Reserve(SizeType size)
	{
		Allocator::Reserve(mPtr, size);
	}
	//Capacityが自身のサイズ+size以上になるまで2^n倍する。
	void Expand(SizeType size)
	{
		auto res = Allocator::Expand(mPtr, size);
		mPtr = res.first;
	}

	char* mPtr;//文字列の先頭のポインタ。この後ろ8バイトにはサイズ情報が入っているので、new、deleteに注意すること。
};

template <class Allocator>
BasicString<Allocator> operator+(const char* charstr, const BasicString<Allocator>& str)
{
	return BasicString<Allocator>(charstr) + str;
}
template <class Allocator>
BasicString<Allocator> operator+(const std::string& stdstr, const BasicString<Allocator>& str)
{
	return BasicString<Allocator>(stdstr) + str;
}

using String = BasicString<detail::CStrAllocator<std::size_t>>;

}

}

#endif
