#ifndef LIST_CPP
#define LIST_CPP

#include "List.h"

//abstract class
template<class T>
List<T>& List<T>::operator=(const List& other)
{
    //copy list
    if(this != &other)
    {
        this->clear();
    }

    for(int x=0;x<other.length();x++)
    {
        T data=other.get(x);
        this->append(data);
    }
    return *this;
}


#endif