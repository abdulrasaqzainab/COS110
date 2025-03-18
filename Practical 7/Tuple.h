#ifndef TUPLE_H
#define TUPLE_H

#include<iostream>
template <class T,class E>


class Tuple
{
    private:
        T firstValue;
        E secondValue;

    public:
        Tuple(T,E);
        ~Tuple();
        T getFirst();
        E getSecond();
        bool operator==(Tuple<T,E> t);    

};

#endif

