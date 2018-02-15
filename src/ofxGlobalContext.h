#pragma once

#include "ofMain.h"

#define OFX_GLOBAL_CONTEXT_BEGIN_NAMESPACE namespace ofx { namespace GlobalContext {
#define OFX_GLOBAL_CONTEXT_END_NAMESPACE } }

#define OFX_GLOBAL_CONTEXT_SHORTCUT(Class) (ofxGlobalContext::Manager::defaultManager().getContext<Class>())

#define $Context OFX_GLOBAL_CONTEXT_SHORTCUT

OFX_GLOBAL_CONTEXT_BEGIN_NAMESPACE

#pragma mark - Context

struct Context
{
	typedef ofPtr<Context> Ref;
	virtual void update() {}
};

#pragma mark - Manager

class Manager
{
public:
	
	static Manager& defaultManager()
	{
		static Manager o;
		return o;
	}
	
public:

	template <typename T>
	T* createContext()
	{
		return newContext<T>(new T);
	}

	/*

	http://nedbatchelder.com/code/cog/
	$ cog.py -r ofxGlobalContext.h

	[[[cog
	import cog
	
	tmpl = '''template <typename T, %(A)s>
	T* createContext(%(B)s)
	{
		return newContext<T>(new T(%(C)s));
	}
	'''
	
	cog.outl('')
	for i in xrange(1, 18):
		a = ', '.join(['typename A%i' % x for x in range(i)])
		b = ', '.join(['const A%i& a%i' % (x, x) for x in range(i)])
		c = ', '.join(['a%i' % x for x in range(i)])
		cog.outl(tmpl % {'A':a, 'B':b, 'C':c})
	
	]]]*/

	template <typename T, typename A0>
	T* createContext(const A0& a0)
	{
		return newContext<T>(new T(a0));
	}

	template <typename T, typename A0, typename A1>
	T* createContext(const A0& a0, const A1& a1)
	{
		return newContext<T>(new T(a0, a1));
	}

	template <typename T, typename A0, typename A1, typename A2>
	T* createContext(const A0& a0, const A1& a1, const A2& a2)
	{
		return newContext<T>(new T(a0, a1, a2));
	}

	template <typename T, typename A0, typename A1, typename A2, typename A3>
	T* createContext(const A0& a0, const A1& a1, const A2& a2, const A3& a3)
	{
		return newContext<T>(new T(a0, a1, a2, a3));
	}

	template <typename T, typename A0, typename A1, typename A2, typename A3, typename A4>
	T* createContext(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4)
	{
		return newContext<T>(new T(a0, a1, a2, a3, a4));
	}

	template <typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
	T* createContext(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5)
	{
		return newContext<T>(new T(a0, a1, a2, a3, a4, a5));
	}

	template <typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6>
	T* createContext(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6)
	{
		return newContext<T>(new T(a0, a1, a2, a3, a4, a5, a6));
	}

	template <typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7>
	T* createContext(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7)
	{
		return newContext<T>(new T(a0, a1, a2, a3, a4, a5, a6, a7));
	}

	template <typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8>
	T* createContext(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8)
	{
		return newContext<T>(new T(a0, a1, a2, a3, a4, a5, a6, a7, a8));
	}

	template <typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9>
	T* createContext(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9)
	{
		return newContext<T>(new T(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9));
	}

	template <typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10>
	T* createContext(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9, const A10& a10)
	{
		return newContext<T>(new T(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10));
	}

	template <typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11>
	T* createContext(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9, const A10& a10, const A11& a11)
	{
		return newContext<T>(new T(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11));
	}

	template <typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12>
	T* createContext(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9, const A10& a10, const A11& a11, const A12& a12)
	{
		return newContext<T>(new T(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12));
	}

	template <typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13>
	T* createContext(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9, const A10& a10, const A11& a11, const A12& a12, const A13& a13)
	{
		return newContext<T>(new T(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13));
	}

	template <typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14>
	T* createContext(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9, const A10& a10, const A11& a11, const A12& a12, const A13& a13, const A14& a14)
	{
		return newContext<T>(new T(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14));
	}

	template <typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15>
	T* createContext(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9, const A10& a10, const A11& a11, const A12& a12, const A13& a13, const A14& a14, const A15& a15)
	{
		return newContext<T>(new T(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15));
	}

	template <typename T, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16>
	T* createContext(const A0& a0, const A1& a1, const A2& a2, const A3& a3, const A4& a4, const A5& a5, const A6& a6, const A7& a7, const A8& a8, const A9& a9, const A10& a10, const A11& a11, const A12& a12, const A13& a13, const A14& a14, const A15& a15, const A16& a16)
	{
		return newContext<T>(new T(a0, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16));
	}

	//[[[end]]]
	
	template <typename T>
	T* getContext()
	{
		TYPE_ID class_id = RTTI<T>::value();
		if (contexts.find(class_id) == contexts.end())
		{
			ofLogError("Manager") << "invalid context classname";
			throw;
			return NULL;
		}
		return (T*) contexts[class_id].get();
	}
	
public:
	
	void clear() { contexts.clear(); }
	void update()
	{
		map<TYPE_ID, Context::Ref>::iterator it = contexts.begin();
		while (it != contexts.end())
		{
			it->second->update();
			it++;
		}
	}
	
protected:
	
	typedef void* TYPE_ID;
	
	template<typename T>
	struct RTTI
	{
		static TYPE_ID value()
		{
			static size_t m = 0;
			return (TYPE_ID)&m;
		}
	};

	map<TYPE_ID, Context::Ref> contexts;
	
private:
	
	Manager() {}
	~Manager() {}
	Manager(const Manager&) {}
      Manager& operator=(const Manager&) { return *this; }

	template <typename T>
	T* newContext(T* p)
	{
		Context::Ref o = Context::Ref(p);
		TYPE_ID class_id = RTTI<T>::value();
		contexts[class_id] = o;
		return p;
	}

};

OFX_GLOBAL_CONTEXT_END_NAMESPACE

namespace ofxGlobalContext = ofx::GlobalContext;
