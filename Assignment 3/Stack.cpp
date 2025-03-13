#include "Stack.h"
#ifndef STACK_CPP
#define STACK_CPP

template<class T>
Stack<T>::Stack()
{
    top=NULL;
}

template<class T>
Stack<T>::~Stack()
{
    while(!isEmpty())
    {
        pop();
    }
}

template<class T>
Stack<T>::Stack(const Stack<T>& other)
{
    top=NULL;

    Node<T>* temp = other.top;
    Node<T>* last=NULL;
    while(temp)
    {
        Node<T>* newnode=new Node<T>(temp->data);
    

    if (last)
    {
        last->next=newnode;
    }
    else
    {
        top=newnode;
    }
    last=newnode;
    temp=temp->next;
    }
}

template<class T>
void Stack<T>::push(T data)
{
  Node<T>* newnode= new Node<T>(data);
  newnode->next=top;
  top=newnode;   
}

template<class T>
T Stack<T>::pop()
{
    if(isEmpty())
    {
        return T();
    }

    Node<T>* popout=top;
    top=top->next;
    T data=popout->data;
    delete popout;
    return data;
}

template<class T>
const T Stack<T>::peek()const
{
    if(isEmpty())
    {
        return T();
    }
    return top->data;
}

template<class T>
bool Stack<T>::isEmpty()const
{
    return top==NULL;
}



#endif