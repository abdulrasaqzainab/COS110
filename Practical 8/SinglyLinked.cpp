#ifndef SINGLY_SinglyList_CPP
#define SINGLY_SinglyList_CPP

#include "SinglyLinked.h"
#include "List.h"
#include "Node.h"

//not done
//sort

//incomplete
//[]

template<class T>
SinglyList<T>::SinglyList()
{
//empty
//ask tutor
this->head=NULL;

}

template<class T>
SinglyList<T>::SinglyList(T* arr,int size)
{

    this->head=NULL;
    int tracker=0;

    //if my first element is zero,my list is empty
    if(arr == NULL || size<=0)
    {
        return;
    }

  //  Node<T>* nodePtr=head;


    for(int x=0;x<size;x++)
    {
        insert(arr[x],x);
    }
}

template<class T>
SinglyList<T>::~SinglyList()
{
    Node<T>* nodePtr=this->head;

    while(nodePtr!=NULL)
    {
        Node<T>* nextPtr=nodePtr->next;
        delete nodePtr;
        nodePtr=nextPtr;
    }
}

template<class T>
Node<T>* SinglyList<T>::insert(T data,int pos)
{
    int sizelist=this->size();




  //  Node<T>* newNode= new Node<T>(data);
   
    if(pos<0 || pos==0)
    {
        //prepend
        Node<T>* newNode= new Node<T>(data);
        newNode->next=this->head;
        this->head=newNode;
        return newNode;
    }

    

    else if(pos>sizelist)
    {
        //append
        Node<T>* trackNode=new Node<T>(data);
        Node<T>* nodePtr;
        trackNode->next=NULL;

        if(this->head==NULL){
            this->head=trackNode;
        }
        else{
            nodePtr=this->head;

            while(nodePtr->next)
            {
                nodePtr=nodePtr->next;
            }

            nodePtr->next=trackNode;

           
        }
        
        return trackNode;
    }


    else
    {
        Node<T>* newNode= new Node<T>(data);
        Node<T>* nodePtr=this->head;

        int idx=0;

        int need2b=pos-1;
        while(idx<need2b)
        {
            if(nodePtr->next)
            {
                nodePtr=nodePtr->next;
                idx++;
            }
            else
            {
                break;
            }
        }

        newNode->next=nodePtr->next;
        nodePtr->next=newNode;

       // this->nextt=newNode;
        return newNode;
        
    }
    
}

template<class T>
int SinglyList<T>::remove(T data)
{
    bool inlist=false;
    int sizelist=this->size();
    Node<T>* trackprev=NULL;
    Node<T>* trackcurr=this->head;
    int idx=0;

    //not in list
    while(trackcurr!=NULL)
    {

        if(trackcurr->getData()==data)
        {
            inlist=true;

            if(trackprev==NULL)
            {
                this->head=trackcurr->next;
                delete trackcurr;
            }
            else
            {
                trackprev->next=trackcurr->next;
                delete trackcurr;
            }
            break;
        }

        trackprev=trackcurr;
        trackcurr=trackcurr->next;
        idx++;
    }

    if(inlist==true)
    {
        return idx;
    }
    else
    {
        return -1;
    }
    //     tracker=tracker->next;
    //     if(tracker->data==data)
    //     {
    //         inlist=true;
    //     }
        
    // }
    // delete tracker;
    // if(inlist==false)
    // {
    //     return -1;
    // }
    

    // //remove first
    
    // while(tracker2!=NULL)
    // {
    //     if(tracker2->data==data && idx==0)
    //     {
    //         this->head=tracker2->next;
    //     }
    //     else if(tracker->data==data && idx!=0)
    //     {
    //         Node<T>* oldie=this->head;

    //         for(int x=0;x<idx;x++)
    //         {
    //             oldie=oldie->next;
    //         }
    //         oldie->next=tracker2->next;
    //     }
    //     delete tracker2;
    //     return idx;

    // }


    // //
    
}

template<class T>
Node<T>* SinglyList<T>::operator[](int index)const
{

   
    
    //head is prot,why cant i get it?

    //Node<T>* nodePtr2=head->next;



    if(this->head==NULL || index>=this->size()  || index<-1*this->size())
    {
        //out of bounds

       return NULL;
    }

    Node<T>* nodePtr=this->head;
    int sizelist=this->size();
    int idx=index;

    if(idx<0)
    {
        idx+=sizelist;
    }

    if(idx<0 || idx>=sizelist)
    {
        return NULL;
    }

    for(int x=0;x<idx;x++)
    {
        nodePtr=nodePtr->next;
    }

    return nodePtr;

    
    
}

template<class T>
Node<T>* SinglyList<T>::operator()(T* dataPtr)const
{
    Node<T>* nodePtr=this->head;
    if(dataPtr == NULL)
    {
        return NULL;

    }

    
    while(nodePtr!=NULL)
    {
        if(*(dataPtr) == nodePtr->getData())
        {
            return nodePtr;
        }

        nodePtr=nodePtr->next;

    }

    return nodePtr;
    //or should i return null?
}

template<class T>
int SinglyList<T>::getIndexFromFront(T data)const
{
    int idx=0;

    Node<T>* nodePtr=this->head;
    
    while(nodePtr!=NULL)
    {
        if(nodePtr->getData() == data)
        {
            return idx;
        }
        idx++;
        nodePtr=nodePtr->next;
    } 

    return -1;   

}

template<class T>
int SinglyList<T>::getIndexFromRear(T data)const
{
    Node<T>* nodePtr=this->head;

    int idxback=0;
    int idx=-1;

    while(nodePtr != NULL)
    {
        if(nodePtr->getData() == data)
        {
            idx=idxback;
        }

        nodePtr=nodePtr->next;
        idxback++;
    }

    if(idx==-1)
    {
        return -1;
    }

    return idxback-1-idx;

}

template<class T>
List<T>* SinglyList<T>::sort(bool order)const
{
    Node<T>* nodePtr=this->head;
    SinglyList<T>* newList=new SinglyList<T>();

    if(this->head==NULL)
    {
        List<T>* empty=new SinglyList();
        return empty;
    }


    //Node<T>* curr=this->head;


    while(nodePtr != NULL)
    {
        newList->insert(nodePtr->getData(),newList->size());

        nodePtr=nodePtr->next;
    }

    int idx=0;

  
    int sizelist=this->size();

    for(int x=0;x<sizelist-1;x++)
    {
        nodePtr=newList->head;
        Node<T>* prev=NULL;

        for(int y=0;y<sizelist-x-1;y++)
        {
            Node<T>* nextPtr=nodePtr->next;

            if((order && nodePtr->getData() > nextPtr->getData()) || (!order && nodePtr->getData() < nextPtr->getData())) 
            {
                if(prev==NULL)
                {
                    newList->head=nextPtr;
                }
                else
                {
                    prev->next=nextPtr;
                }

                nodePtr->next=nextPtr->next;
                nextPtr->next=nodePtr;

                if(prev==NULL)
                {
                    nodePtr=nextPtr;
                    newList->head=nextPtr;
                }
                else
                {
                    nodePtr=prev->next;
                }
            }

            prev=nodePtr;
            nodePtr=nodePtr->next;
        }
    }
    
    // if(order==true)
    // {
    //     //ascending

        
    // }
    // else if(order==false)
    // {
    //     //descending
        
    // }

    return newList;
}

template<class T>
Node<T>* SinglyList<T>::findSmallest()const
{
    Node<T>* smallest=NULL;

    int smallestdata=10000000;

    Node<T>* nodePtr=this->head;

    while(nodePtr!=NULL)
    {
        if(nodePtr->getData() < smallestdata)
        {
            smallest=nodePtr;
            smallestdata=nodePtr->getData();
        }

        nodePtr=nodePtr->next;
    }

    return smallest;
}

template<class T>
Node<T>* SinglyList<T>::findBiggest()const
{
    Node<T>* biggest=NULL;

    int biggestdata=-10000000;

    Node<T>* nodePtr=this->head;

    while(nodePtr!=NULL)
    {
        if(nodePtr->getData() > biggestdata)
        {
            biggest=nodePtr;
            biggestdata=nodePtr->getData();
        }

        nodePtr=nodePtr->next;
    }

    return biggest;
}

template<class T>
List<T>* SinglyList<T>::clone()const
{

 //make a deep copy

  if(this->head==NULL)
    {
        List<T>* empty=new SinglyList();
        return empty;
    }

    SinglyList<T>* newlist= new SinglyList<T>();

    Node<T>* copier=this->head;

    while(copier!=NULL)
    {
        newlist->insert(copier->getData(),newlist->size());
        copier=copier->next;
    }

    return newlist;
}



template <class T>
std::ostream &operator<<(std::ostream &os, const SinglyList<T> *sl)
{
    if (sl->head == NULL)
    {
        os << "NULL";
        return os;
    }
    Node<T> *curr = sl->head;
    while (curr != NULL)
    {
        os << curr;
        curr = curr->next;
    }
    return os;
}

#endif /*SinglyList_CPP*/
