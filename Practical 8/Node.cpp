#ifndef NODE_CPP
#define NODE_CPP

#include "Node.h"

template <class T>
Node<T>::Node(T data)
{
  this->data=data;
  this->next=NULL;
}

template <class T>
T Node<T>::getData() const
{
    return data;
}

template <class T>
bool Node<T>::operator==(T other) const
{
    if(data == other)
    {
        return true;
    }

    else
    {
        return false;
    }

   // return data==other.data;
}

/*
template <class T>
std::ostream& operator<<(std::ostream& os,const Node<T>* node)
{
    //implementation is present,do i leave this or // it out?(ask tutor)
}*/



#endif /*NODE_CPP*/