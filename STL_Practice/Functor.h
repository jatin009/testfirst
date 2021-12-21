/**
* Copyright Aristocrat Technologies Australia Pty Ltd 1994-2017.  All rights reserved.
*
 * \file Functor.h
 *
 */

 // NOTE: The following headers define classes and types in the Mercury namespace and are mostly defined under the Mercury
 // project however THERE IS NOTHING ABOUT THEM THAT IS SPECIFIC TO MERCURY or even to slot games.  All the classes and
 // types defined by these headers should be moved to Common and removed from the Mercury namespace.
 // FunctionBase, FunctionHandler, Event, MessageQueue, ActionCallback, ConditionalEvent, Functor, Action, Message, and
 // MessageT.  These headers are dependent on Types.h defined in GDKBase.  The GDK specific things in Types.h should be
 // moved to another header (GDKBase/GDK.h) and Types.h should also be moved to Common.

#ifndef Functor_h
#define Functor_h

#include "FunctionHandler.h"

namespace Mercury
{
    namespace hidden
    {
        template<typename T>
        struct Type2Type
        {
            typedef T Original_T;
        };
    }

    template<typename ReturnType,
             typename P1 = NullType,
             typename P2 = NullType,
             typename P3 = NullType,
             typename P4 = NullType,
             typename P5 = NullType,
             typename P6 = NullType,
             typename P7 = NullType>
    struct Functor
    {
        template<typename T, typename U>
        static MemberFunctionHandler<T, U, ReturnType, P1, P2, P3> create(T t, U u)
        {
            return MemberFunctionHandler<T, U, ReturnType, P1, P2, P3>(t, u);
        }

        template<typename T>
        static FunctionHandler<T, ReturnType, P1, P2, P3> create(T t)
        {
            return FunctionHandler<T, ReturnType, P1, P2, P3>(t);
        }
    };

    template<typename ReturnType>
    struct Functor<ReturnType, NullType, NullType, NullType, NullType, NullType, NullType, NullType>
    {
        template<typename T, typename U>
        static MemberFunctionHandler<T, U, ReturnType> create(T t, U u)
        {
            return MemberFunctionHandler<T, U, ReturnType >(t, u);
        }

        template<typename T>
        static FunctionHandler<T, ReturnType> create(T t)
        {
            return FunctionHandler<T, ReturnType>(t);
        }
    };

    template<typename ReturnType, typename P1>
    struct Functor<ReturnType, P1, NullType, NullType, NullType, NullType, NullType, NullType>
    {
        template<typename T, typename U>
        static MemberFunctionHandler<T, U, ReturnType, P1> create(T t, U u)
        {
            return MemberFunctionHandler<T, U, ReturnType, P1>(t, u);
        }

        template<typename T>
        static FunctionHandler<T, ReturnType, P1> create(T t)
        {
            return FunctionHandler<T, ReturnType, P1>(t);
        }
    };

    template<typename ReturnType, typename P1, typename P2>
    struct Functor<ReturnType, P1, P2, NullType, NullType, NullType, NullType, NullType>
    {
        template<typename T, typename U>
        static MemberFunctionHandler<T, U, ReturnType, P1, P2> create(T t, U u)
        {
            return MemberFunctionHandler<T, U, ReturnType, P1, P2>(t, u);
        }

        template<typename T>
        static FunctionHandler<T, ReturnType, P1, P2> create(T t)
        {
            return FunctionHandler<T, ReturnType, P1, P2>(t);
        }
    };

    template<typename ReturnType, typename P1, typename P2, typename P3>
    struct Functor<ReturnType, P1, P2, P3, NullType, NullType, NullType, NullType>
    {
        template<typename T, typename U>
        static MemberFunctionHandler<T, U, ReturnType, P1, P2, P3> create(T t, U u)
        {
            return MemberFunctionHandler< T, U, ReturnType, P1, P2, P3>(t, u);
        }

        template<typename T>
        static FunctionHandler<T, ReturnType, P1, P2, P3> create(T t)
        {
            return FunctionHandler<T, ReturnType, P1, P2, P3>(t);
        }
    };

    template<typename ReturnType, typename P1, typename P2, typename P3, typename P4>
    struct Functor<ReturnType, P1, P2, P3, P4, NullType, NullType, NullType>
    {
        template<typename T, typename U>
        static MemberFunctionHandler<T, U, ReturnType, P1, P2, P3, P4> create(T t, U u)
        {
            return MemberFunctionHandler<T, U, ReturnType, P1, P2, P3, P4>(t, u);
        }

        template<typename T>
        static FunctionHandler<T, ReturnType, P1, P2, P3, P4> create(T t)
        {
            return FunctionHandler<T, ReturnType, P1, P2, P3, P4>(t);
        }
    };

    template<typename ReturnType, typename P1, typename P2, typename P3, typename P4, typename P5>
    struct Functor<ReturnType, P1, P2, P3, P4, P5, NullType, NullType>
    {
        template<typename T, typename U>
        static MemberFunctionHandler<T, U, ReturnType, P1, P2, P3, P4, P5> create(T t, U u)
        {
            return MemberFunctionHandler<T, U, ReturnType, P1, P2, P3, P4, P5>(t, u);
        }

        template<typename T>
        static FunctionHandler<T, ReturnType, P1, P2, P3, P4, P5 > create(T t)
        {
            return FunctionHandler<T, ReturnType, P1, P2, P3, P4, P5>(t);
        }
    };

    template<typename ReturnType, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
    struct Functor<ReturnType, P1, P2, P3, P4, P5, P6, NullType>
    {
        template<typename T, typename U>
        static MemberFunctionHandler<T, U, ReturnType, P1, P2, P3, P4, P5, P6> create(T t, U u)
        {
            return MemberFunctionHandler<T, U, ReturnType, P1, P2, P3, P4, P5, P6>(t, u);
        }

        template<typename T>
        static FunctionHandler<T, ReturnType, P1, P2, P3, P4, P5, P6> create(T t)
        {
            return FunctionHandler<T, ReturnType, P1, P2, P3, P4, P5, P6>(t);
        }
    };
}

#endif // Functor_h
