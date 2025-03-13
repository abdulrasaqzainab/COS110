#include "Queue.h"
#ifndef QUEUE_CPP
#define QUEUE_CPP

template<class T>
Queue<T>::Queue()
{
    head=NULL;
    tail=NULL;
}

template<class T>
Queue<T>::~Queue()
{
    while(!isEmpty())
    {
        dequeue();
    }   
}

template<class T>
Queue<T>::Queue(const Queue<T>& other)
{
    head=NULL;
    tail=NULL;

    Node<T>* curr=other.head;
    while(curr!=NULL)
    {
        enqueue(curr->data);
        curr=curr->next;
    }
}

template<class T>
Queue<T>* Queue<T>::clone()const
{
    Queue<T>* tyrone=new Queue<T>(*this);
    return tyrone;
}

template<class T>
void Queue<T>::enqueue(T data)
{
    Node<T>* newnode=new Node<T>(data);
    if(isEmpty())
    {
        head=newnode;
        tail=newnode;
    }
    else
    {
        tail->next=newnode;
        tail=newnode;
    }
}

template<class T>
T Queue<T>::dequeue()
{
    if(isEmpty())
    {
        return T();
    }


    Node<T>* removed=head;
    head=head->next;
    T data=removed->data;
    delete removed;

    if(head != NULL)
    {
        tail=NULL;
    }
    return data;
}


template<class T>
const T Queue<T>::peek()const
{
    if(isEmpty())
    {
        return T();
    }
    return head->data;
}

template<class T>
bool Queue<T>::isEmpty()const
{
    return head==NULL;   
}


#endif

