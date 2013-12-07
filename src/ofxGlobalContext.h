#pragma once

#include "ofMain.h"

#define OFX_GLOBAL_CONTEXT_BEGIN_NAMESPACE namespace ofx { namespace GlobalContext {
#define OFX_GLOBAL_CONTEXT_END_NAMESPACE } }

#define OFX_GLOBAL_CONTEXT_SHORTCUT(Class) (ofxGlobalContext::Manager::defaultManager().getContext<Class>())

#define $Context OFX_GLOBAL_CONTEXT_SHORTCUT

OFX_GLOBAL_CONTEXT_BEGIN_NAMESPACE

#pragma mark - Context

class Context
{
public:
    
    typedef ofPtr<Context> Ref;

    virtual void setup() {}
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
        Context::Ref o = Context::Ref(new T);
        unsigned int class_id = Type2Int<T>::value();
        contexts[class_id] = o;
        
        o->setup();
        return (T*)o.get();
    }
    
    template <typename T>
    T* getContext()
    {
        unsigned int class_id = Type2Int<T>::value();
        if (contexts.find(class_id) == contexts.end())
        {
			ofLogError("Manager") << "invalid context classname";
            throw;
            return NULL;
        }
        return (T*) contexts[class_id].get();
    }
	
public:
	
	void update()
	{
		map<unsigned int, Context::Ref>::iterator it = contexts.begin();
		while (it != contexts.end())
		{
			it->second->update();
			it++;
		}
	}
	
protected:
	
	template<typename T>
    struct Type2Int
    {
        static unsigned int value()
        {
            static size_t m = 0;
            return (unsigned int)&m;
        }
    };

	map<unsigned int, Context::Ref> contexts;
	
private:
	
	Manager() {}
    ~Manager() {}
    Manager(const Manager&) {}
    Manager& operator=(const Manager&) {}
};

OFX_GLOBAL_CONTEXT_END_NAMESPACE

namespace ofxGlobalContext = ofx::GlobalContext;
