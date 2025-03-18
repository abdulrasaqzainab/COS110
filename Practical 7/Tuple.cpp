#ifndef TUPLE_CPP
#define TUPLE_CPP

#include "Tuple.h"
#include <iostream>


template <class T,class E>
Tuple<T,E>::Tuple(T first,E second)
{
    firstValue=first;
    secondValue=second;
}

template <class T,class E>
Tuple<T,E>::~Tuple()
{
    //nothing to destroy
}

template <class T,class E>
T Tuple<T,E>::getFirst()
{
    return firstValue;
}

template <class T,class E>
E Tuple<T,E>::getSecond()
{
    return secondValue;
}

template <class T,class E>
bool Tuple<T,E>::operator==(Tuple<T,E> rhs)
{
    // if(rhs.firstValue == this->firstValue)
    // {
    //     if(rhs.secondValue == this->secondValue)
    //     {
    //         return true;
    //     }
    // }

    return (rhs.firstValue == this->firstValue) && (rhs.secondValue == this->secondValue);
}

#endif