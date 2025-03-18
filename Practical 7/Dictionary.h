#ifndef DICTIONARY_H
#define DICTIONARY_H

#include "Tuple.h"
#include "Tuple.cpp"

template <class T,class E>

class Dictionary
{
    private:
        T* keys;
        E* values;
        int currSize;

    public:
        Dictionary();
        ~Dictionary();
        void set(T,E);
        E at(T);
        void removeAt(T);
        void remove(E);
        bool exists(T);
        Tuple<int,T*> keysWithValue(E);
        void swap(T firstKey,T secondKey);
        void clear();
        T* getKeys();
        int size();
};

#endif

