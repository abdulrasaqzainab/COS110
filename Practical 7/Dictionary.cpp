#ifndef DICTIONARY_CPP
#define DICTIONARY_CPP

// #include "Tuple.h"
// #include "Tuple.cpp"
#include "Dictionary.h"
#include <cstddef>
//#include <iostream>
// #include <sstream>
// #include <string>


template <class T,class E>
Dictionary<T,E>::Dictionary()
{
    currSize=0;
    values=NULL;
    keys=NULL;
}

template <class T,class E>
Dictionary<T,E>::~Dictionary()
{
     if(values != NULL)
    {
        delete [] values;
    }

    values = NULL;

    if(keys != NULL)
    {
        delete [] keys;
    }
    
    keys = NULL;
}

template <class T,class E>
void Dictionary<T,E>::set(T key,E value)
{
    for(int x=0;x<currSize;x++)
    {
        if(keys[x]==key)
        {
            values[x]=value;
            return;
        }
    }

    T* newK=new T[currSize+1];
    E* newV=new E[currSize+1];

    for(int x=0;x<currSize;x++)
    {
        newK[x]=keys[x];
        newV[x]=values[x];
    }

    newK[currSize]=key;
    newV[currSize]=value;

    delete[] keys;
    delete[] values;

    keys=newK;
    values=newV;

    currSize++;
}

template <class T,class E>
E Dictionary<T,E>::at(T key)
{
    for(int x=0;x<currSize;x++)
    {
        if(keys[x]==key)
        {
            return values[x];
        }
    }

    return E();
}

template <class T,class E>
void Dictionary<T,E>::removeAt(T key)
{
    int remove=-1;

    for(int x=0;x<currSize;x++)
    {
        if(keys[x]==key)
        {
            remove=x;
            break;
        }
    }

int hold=currSize-1;
    if(remove!=-1)
    {
        for(int x=remove;x<hold;x++)
        {
           
                keys[x]=keys[x+1];
                values[x]=values[x+1];
            
        }
    }


    currSize=currSize-1;

    T* newK=new T[currSize];
    E* newV=new E[currSize];

    for(int x=0;x<currSize;x++)
    {
        newK[x]=keys[x];
        newV[x]=values[x];
    }

    delete[] keys;
    delete[] values;
    keys=newK;
    values=newV;


}

template <class T,class E>
bool Dictionary<T,E>::exists(T key)
{
    for(int x=0;x<currSize;x++)
    {
        if(keys[x]==key)
        {
            return true;
        }
    }

    return false;
}

template <class T,class E>
Tuple<int,T*> Dictionary<T,E>::keysWithValue(E value)
{
    int count=0;

    //E* matchvalues=new E[currSize];
    for(int x=0;x<currSize;x++)
    {
        if(values[x]==value)
        {
            //match[count++]=keys[x];
            //matchkeys[x]=keys[x];
            count++;
        }
    }
    T* matchkeys=new T[count];

    int count2=0;

    for(int x=0;x<currSize;x++)
    {
        if(values[x]==value)
        {
            matchkeys[count2]=keys[x];
            count2++;
        }
    }

    Tuple<int,T*>result(count,matchkeys);
   // delete[] matchkeys;

    return result;
}

template <class T,class E>
void Dictionary<T,E>::swap(T firstKey, T secondKey)
{
    // T temp.values=firstKey.values; //am i making a shallow copy?->swap pointers?
    // firstKey.values=secondKey.values;
    // secondKey.values=firstKey.values;

    // T temp();

    // for(int x=0;x<currSize;x++)
    // {
    //     temp.values[x]=firstKey.values[x];
    // }

    // for(int x=0;x<currSize;x++)
    // {
    //     firstKey.values[x]=secondKey.values[x];
    // }
    // for(int x=0;x<currSize;x++)
    // {
    //     secondKey.values[x]=temp.values[x];
    // }

   /* int idx1=-1;

    int idx2=-1;

    for(int x=0;x<currSize;x++)
    {
        if(keys[x]==firstKey)
        {
            idx1=x;
        }
        else
        {
            if(keys[x]==secondKey)
            {
                idx2=x;
            }
        }

        if(idx1!=-1)
        {
            if(idx2!=-1)
            {
                break;
            }
        }
    }

    if(idx1!=-1 )
    {
        if(idx2!=-1)
        {
            E temp=values[idx1];
            values[idx1]=values[idx2];
            values[idx2]=temp;
        }
    }*/

    E firstVal=at(firstKey);
    E secondVal=at(secondKey);
    set(firstKey,secondVal);
    set(secondKey,firstVal);

}

template <class T,class E>
void Dictionary<T,E>::clear()
{
    if(keys != NULL)
    {
        // for(int x=0;x<currSize;x++)
        // {
        //     delete keys[x];
        // }

        delete[] keys;
            
            keys=NULL;
    }

    if(values != NULL)
    {
        //  for(int x=0;x<currSize;x++)
        // {
        //     delete values[x];
        // }

            delete[] values;
            
            values=NULL;
    }

    currSize=0;
}

template <class T,class E>
T* Dictionary<T,E>::getKeys()
{
    //return keys;
    if(currSize==0)
    {
        return NULL;
    }

    

    return keys;
}

template <class T,class E>
int Dictionary<T,E>::size()
{
    return currSize;
}

template <class T,class E>
void Dictionary<T,E>::remove(E value)
{
    int size=0;
    for(int x=0;x<currSize;x++)
    {
        if(value!=values[x])
        {
            values[size]=values[x];
            keys[size]=keys[x];
            size++;
        }
    }

    currSize=size;

    if(currSize==0)
    {
        delete[] keys;
        delete[] values;

        keys=NULL;
        values=NULL;
    }
    else
    {
        T* newK=new T[currSize];

        E* newV=new E[currSize];

        for(int x=0;x<currSize;x++)
        {
            newK[x]=keys[x];
            newV[x]=values[x];
        }

        delete[] keys;
        delete[] values;

        keys=newK;
        values=newV;
    }

}

#endif

