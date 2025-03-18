#ifndef ARRAYWRAP_CPP
#define ARRAYWRAP_CPP
#include "ArrayWrap.h"
#include "ListException.h"
#include "ConstructorException.h"
#include "IndexException.h"
#include "SizeException.h"
#include <iostream>
#include <string>
template<class T>
ArrayWrap<T>::ArrayWrap(int size)
{
    if(size <= 0)
    {
        throw ConstructorException();
    }

    this->m_size=0;
    this->maxSize=size;
    this->m_array=new T[size];
}

template<class T>
ArrayWrap<T>::~ArrayWrap()
{
    if(this->m_array != NULL)
    {
    delete[] this->m_array;
    }

}

template<class T>
T& ArrayWrap<T>::operator[](int index)
{
    if(index < 0 )
    {
        throw IndexException(index,this->m_size);
    }
    else if (index >= this->m_size)
    {
     throw IndexException(index,this->m_size);  //can i combine?
     }

    return this->m_array[index];
}

template<class T>
void ArrayWrap<T>::swap(int index1,int index2)
{
    
    // if(index1 >= this->m_size || index2 >= this->m_size || index1<0 || index2<0)
    // {
    //     if(index2 >=m_size || index2<0)
    //     {
    //         throw IndexException(index2,this->m_size);
    //     }

    //     throw IndexException(index1,this->m_size);//should i put m_size?
    // }

    if(index1 >= this->m_size || index1<0)
    {
        throw IndexException(index1,this->m_size);
    }
    if(index2 >= this->m_size || index2<0)
    {
        throw IndexException(index2,this->m_size);
    }


    if((index1>=this->m_size || index1<0 ) && (index2>=this->m_size || index2<0 ))
    {
        throw IndexException(index1,this->m_size);
    }

    if(index1==index2)
    {
        return;
    }

    //simple swap alg
    T temp=this->m_array[index1];
    this->m_array[index1]=this->m_array[index2];
    this->m_array[index2]=temp;


}

template<class T>
void ArrayWrap<T>::push_back(T item)
{
    //add item at the back of the array
    if(this->m_size == this->maxSize )
    {
        throw SizeException(this->maxSize); //does this mean item  or m_size-maxsize

    }
   
    this->m_array[this->m_size]=item;
     this->m_size++;
}

template<class T>
T ArrayWrap<T>::pop_back()
{  
 if(this->m_size <= 0)
    {
        throw SizeException(this->m_size);
    }

    
            this->m_size--;
            return this->m_array[this->m_size];
}


template<class T>
void ArrayWrap<T>::remove(int index)//fixed remove
{
    if(index < 0 )
    {
        throw IndexException(index,this->m_size);
    }
     if(index >= this->m_size)
    {
        throw IndexException(index , this->m_size);
    }


    /* T *newarr=new T[m_size-1]; 

     for(int x=0;x<index;x++)
     {
           newarr[x]=m_array[x];
         
     }
     //m_size--;

     for(int x=index;x<m_size-1;x++)
     {
        newarr[x]=m_array[x+1];
         
     }

    delete[] m_array;
    m_array=newarr;
    m_size--;*/


     

 for(int x=index;x<this->m_size-1;x++)
     {
        this->m_array[x] = this->m_array[x + 1];
     }

   this->m_size--;
         
     
}

template<class T>
void ArrayWrap<T>::clear()
{
    this->m_size=0;
}

template<class T>
void ArrayWrap<T>::print()
{
    if(this->m_size == 0 )
    {
        std::cout<<"\n";
    }
    else
    {
    for(int x=0;x<this->m_size-1;x++)
    {
        std::cout<<this->m_array[x]<<",";
    }
    std::cout<<this->m_array[this->m_size-1]<<"\n";
    }
}

#endif