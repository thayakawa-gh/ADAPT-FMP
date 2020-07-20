#ifndef CUF_TRIVIALIZER_H
#define CUF_TRIVIALIZER_H

#include <type_traits>
#include <ADAPT/CUF/Exception.h>

namespace adapt
{

inline namespace cuf
{

//非トリビアルなクラスをラップしてトリビアルに見せかけるためのもの。
//トリビアルなクラスは当然、デフォルトでないコンストラクタ、デストラクタ、代入演算子を持つことが出来ないので、
//このクラスにもそれらの機能はないし、仕組みを理解せずそれらを使ってはいけない。
template <class T>
class Trivializer
{
public:

	//コンストラクタの代わり。このインスタンスが作成されたらまずNotConstructかConstructを呼ぶこと。
	void NotConstruct()
	{
		//コンストラクタを"呼ばない"コンストラクタ。
		//Trivializer自体は初期化されるが、中身は未初期化状態となる。
		mInit = false;
	}
	template <class ...Args>
	void Construct(Args&& ...args)
	{
		//コンストラクタを呼ぶ初期化。初期化済みとなる。
		new (&mStorage) T(std::forward<Args>(args)...);
		mInit = true;
	}

	template <class ...Args>
	void Assign(const T& t)
	{
		if (!mInit)
		{
			//未初期化の場合はコピーコンストラクタを呼ぶべきかもしれないが、
			//コピー代入可能なのにコピーコンストラクタがない、みたいな奇天烈なクラスを作る阿呆がいるかも知れないので、
			//この場合は例外を投げる。
			//コピーコンストラクタを呼びたければResetを使うこと。
			throw NotInitialized("");
		}
		//初期化済みならコピー代入演算子を呼ぶ。
		*reinterpret_cast<T*>(&mStorage) = t;
	}
	void Assign(T&& t)
	{
		if (!mInit)
		{
			//コピーと同様の理由により、ムーブコンストラクタは呼ばず例外を投げる。
			throw NotInitialized("");
		}
		//初期化済みならコピー代入演算子を呼ぶ。
		*reinterpret_cast<T*>(&mStorage) = std::move(t);
	}

	bool IsInitialized() const { return mInit; }

	T* operator->() { if (!mInit) throw NotInitialized(""); return reinterpret_cast<T*>(&mStorage); }
	const T* operator->() const { if (!mInit) throw NotInitialized(""); return reinterpret_cast<const T*>(&mStorage); }
	T& operator*() { if (!mInit) throw NotInitialized(""); return *reinterpret_cast<T*>(&mStorage); }
	const T& operator*() const { if (!mInit) throw NotInitialized(""); return *reinterpret_cast<const T*>(&mStorage); }

	//Construct関数は未初期化状態を前提としているので、ユーザーは二度以上呼び出してはいけない。
	//代わりにResetを使う。
	template <class ...Args>
	void Reset(Args&& ...args)
	{
		Destroy();
		Construct(std::forward<Args>(args)...);
	}

	void Destroy()
	{
		if (!mInit) return;
		reinterpret_cast<T*>(&mStorage)->~T();
		mInit = false;
	}

private:
	bool mInit;
	std::aligned_storage_t<sizeof(T), alignof(T)> mStorage;
};

}

}

#endif