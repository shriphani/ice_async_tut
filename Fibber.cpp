// **********************************************************************
//
// Copyright (c) 2003-2011 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************
//
// Ice version 3.4.2
//
// <auto-generated>
//
// Generated from file `Fibber.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#include <Fibber.h>
#include <Ice/LocalException.h>
#include <Ice/ObjectFactory.h>
#include <Ice/BasicStream.h>
#include <IceUtil/Iterator.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 304
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 2
#       error Ice patch level mismatch!
#   endif
#endif

static const ::std::string __AsyncDemo__Fibber__fib_name = "fib";

::Ice::Object* IceInternal::upCast(::AsyncDemo::Fibber* p) { return p; }
::IceProxy::Ice::Object* IceInternal::upCast(::IceProxy::AsyncDemo::Fibber* p) { return p; }

void
AsyncDemo::__read(::IceInternal::BasicStream* __is, ::AsyncDemo::FibberPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::AsyncDemo::Fibber;
        v->__copyFrom(proxy);
    }
}

::Ice::Int
IceProxy::AsyncDemo::Fibber::fib(::Ice::Int n, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__AsyncDemo__Fibber__fib_name);
            __delBase = __getDelegate(false);
            ::IceDelegate::AsyncDemo::Fibber* __del = dynamic_cast< ::IceDelegate::AsyncDemo::Fibber*>(__delBase.get());
            return __del->fib(n, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, true, __cnt);
        }
    }
}

::Ice::AsyncResultPtr
IceProxy::AsyncDemo::Fibber::begin_fib(::Ice::Int n, const ::Ice::Context* __ctx, const ::IceInternal::CallbackBasePtr& __del, const ::Ice::LocalObjectPtr& __cookie)
{
    __checkAsyncTwowayOnly(__AsyncDemo__Fibber__fib_name);
    ::IceInternal::OutgoingAsyncPtr __result = new ::IceInternal::OutgoingAsync(this, __AsyncDemo__Fibber__fib_name, __del, __cookie);
    try
    {
        __result->__prepare(__AsyncDemo__Fibber__fib_name, ::Ice::Normal, __ctx);
        ::IceInternal::BasicStream* __os = __result->__getOs();
        __os->write(n);
        __os->endWriteEncaps();
        __result->__send(true);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __result->__exceptionAsync(__ex);
    }
    return __result;
}

::Ice::Int
IceProxy::AsyncDemo::Fibber::end_fib(const ::Ice::AsyncResultPtr& __result)
{
    ::Ice::AsyncResult::__check(__result, this, __AsyncDemo__Fibber__fib_name);
    ::Ice::Int __ret;
    if(!__result->__wait())
    {
        try
        {
            __result->__throwUserException();
        }
        catch(const ::Ice::UserException& __ex)
        {
            throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
        }
    }
    ::IceInternal::BasicStream* __is = __result->__getIs();
    __is->startReadEncaps();
    __is->read(__ret);
    __is->endReadEncaps();
    return __ret;
}

const ::std::string&
IceProxy::AsyncDemo::Fibber::ice_staticId()
{
    return ::AsyncDemo::Fibber::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::AsyncDemo::Fibber::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::AsyncDemo::Fibber);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::AsyncDemo::Fibber::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::AsyncDemo::Fibber);
}

::IceProxy::Ice::Object*
IceProxy::AsyncDemo::Fibber::__newInstance() const
{
    return new Fibber;
}

::Ice::Int
IceDelegateM::AsyncDemo::Fibber::fib(::Ice::Int n, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__handler.get(), __AsyncDemo__Fibber__fib_name, ::Ice::Normal, __context);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(n);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    ::Ice::Int __ret;
    try
    {
        if(!__ok)
        {
            try
            {
                __og.throwUserException();
            }
            catch(const ::Ice::UserException& __ex)
            {
                ::Ice::UnknownUserException __uue(__FILE__, __LINE__, __ex.ice_name());
                throw __uue;
            }
        }
        ::IceInternal::BasicStream* __is = __og.is();
        __is->startReadEncaps();
        __is->read(__ret);
        __is->endReadEncaps();
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Int
IceDelegateD::AsyncDemo::Fibber::fib(::Ice::Int n, const ::Ice::Context* __context)
{
    class _DirectI : public ::IceInternal::Direct
    {
    public:

        _DirectI(::Ice::Int& __result, ::Ice::Int n, const ::Ice::Current& __current) : 
            ::IceInternal::Direct(__current),
            _result(__result),
            _m_n(n)
        {
        }
        
        virtual ::Ice::DispatchStatus
        run(::Ice::Object* object)
        {
            ::AsyncDemo::Fibber* servant = dynamic_cast< ::AsyncDemo::Fibber*>(object);
            if(!servant)
            {
                throw ::Ice::OperationNotExistException(__FILE__, __LINE__, _current.id, _current.facet, _current.operation);
            }
            _result = servant->fib(_m_n, _current);
            return ::Ice::DispatchOK;
        }
        
    private:
        
        ::Ice::Int& _result;
        ::Ice::Int _m_n;
    };
    
    ::Ice::Current __current;
    __initCurrent(__current, __AsyncDemo__Fibber__fib_name, ::Ice::Normal, __context);
    ::Ice::Int __result;
    try
    {
        _DirectI __direct(__result, n, __current);
        try
        {
            __direct.servant()->__collocDispatch(__direct);
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
    }
    catch(const ::Ice::SystemException&)
    {
        throw;
    }
    catch(const ::IceInternal::LocalExceptionWrapper&)
    {
        throw;
    }
    catch(const ::std::exception& __ex)
    {
        ::IceInternal::LocalExceptionWrapper::throwWrapper(__ex);
    }
    catch(...)
    {
        throw ::IceInternal::LocalExceptionWrapper(::Ice::UnknownException(__FILE__, __LINE__, "unknown c++ exception"), false);
    }
    return __result;
}

::Ice::ObjectPtr
AsyncDemo::Fibber::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __AsyncDemo__Fibber_ids[2] =
{
    "::AsyncDemo::Fibber",
    "::Ice::Object"
};

bool
AsyncDemo::Fibber::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__AsyncDemo__Fibber_ids, __AsyncDemo__Fibber_ids + 2, _s);
}

::std::vector< ::std::string>
AsyncDemo::Fibber::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__AsyncDemo__Fibber_ids[0], &__AsyncDemo__Fibber_ids[2]);
}

const ::std::string&
AsyncDemo::Fibber::ice_id(const ::Ice::Current&) const
{
    return __AsyncDemo__Fibber_ids[0];
}

const ::std::string&
AsyncDemo::Fibber::ice_staticId()
{
    return __AsyncDemo__Fibber_ids[0];
}

::Ice::DispatchStatus
AsyncDemo::Fibber::___fib(::IceInternal::Incoming& __inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    __is->startReadEncaps();
    ::Ice::Int n;
    __is->read(n);
    __is->endReadEncaps();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Int __ret = fib(n, __current);
    __os->write(__ret);
    return ::Ice::DispatchOK;
}

static ::std::string __AsyncDemo__Fibber_all[] =
{
    "fib",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping"
};

::Ice::DispatchStatus
AsyncDemo::Fibber::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__AsyncDemo__Fibber_all, __AsyncDemo__Fibber_all + 5, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - __AsyncDemo__Fibber_all)
    {
        case 0:
        {
            return ___fib(in, current);
        }
        case 1:
        {
            return ___ice_id(in, current);
        }
        case 2:
        {
            return ___ice_ids(in, current);
        }
        case 3:
        {
            return ___ice_isA(in, current);
        }
        case 4:
        {
            return ___ice_ping(in, current);
        }
    }

    assert(false);
    throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
}

void
AsyncDemo::Fibber::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
AsyncDemo::Fibber::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

// COMPILERFIX: Stream API is not supported with VC++ 6
#if !defined(_MSC_VER) || (_MSC_VER >= 1300)
void
AsyncDemo::Fibber::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type AsyncDemo::Fibber was not generated with stream support";
    throw ex;
}

void
AsyncDemo::Fibber::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type AsyncDemo::Fibber was not generated with stream support";
    throw ex;
}
#endif

void 
AsyncDemo::__patch__FibberPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::AsyncDemo::FibberPtr* p = static_cast< ::AsyncDemo::FibberPtr*>(__addr);
    assert(p);
    *p = ::AsyncDemo::FibberPtr::dynamicCast(v);
    if(v && !*p)
    {
        IceInternal::Ex::throwUOE(::AsyncDemo::Fibber::ice_staticId(), v->ice_id());
    }
}
