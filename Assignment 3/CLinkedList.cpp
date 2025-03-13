#ifndef CLINKEDLIST_CPP
#define CLINKEDLIST_CPP
#include "CLinkedList.h"


template<class T>
CLinkedList<T>::CLinkedList()
{
    this->head=NULL;
}

template<class T>
CLinkedList<T>::~CLinkedList()
{
    //delete all nodes
    /*if(this->head == NULL)
    {
        return;
    }

    Node<T>* curr=this->head;
    Node<T>* next;

    do
    {
        next=curr->next;
        delete curr;
        curr=next;
    } while (curr != this->head);
    
    this->head=NULL;*/

    if(this->head==NULL)
    {
        return;
    }
    
    if(this->head!=NULL)
    {
        Node<T>* nodePtr=this->head->next;

        while(nodePtr!=this->head)
        {
            Node<T>* prev=nodePtr;
            nodePtr=nodePtr->next;
            delete prev;
        }
        delete this->head;
        this->head=NULL;
    }

}
template<class T>
void CLinkedList<T>::prepend(T data)
{
    Node<T>* newnode=new Node<T>(data);
    Node<T>* temp=head;

    if(this->head == NULL)
    {
        //list empty
        this->head=newnode;
        newnode->next=newnode;
    }

    else
    {
        //list not empty
        

            while(temp->next != head)
            {
            
            temp=temp->next;
           
            }
            temp->next=newnode;
            newnode->next=head;
            this->head=newnode;

    }

}

template<class T>
void CLinkedList<T>::append(T data)
{
    Node<T>* newnode=new Node<T>(data);
    Node<T>* temp=head;
    if(this->head == NULL)
    {
        //list empty
        this->head=newnode;
        newnode->next=newnode;
    }

    else
    {
        //list not empty
            while(temp->next != head)
            {
            //newnode->next=this->head->next;
            //this->head->next=newnode;
            temp=temp->next;
            //this->head=newnode;
            }
            temp->next=newnode;
            newnode->next=head;


    }
}

template<class T>
void CLinkedList<T>::insert(T data,int index)
{

    if(index<0 || index>length())
    {
        return;
    }

    Node<T>* newnode=new Node<T>(data);
    if(index==0)
    {
        this->prepend(data);
    }
    else if(index==length())
    {
        this->append(data);
    }
    else
    {
        //inserting at specific index
        Node<T>* curr=this->head;

        for(int x=0;x<index-1;x++)
        {
            curr=curr->next;
        }

        newnode->next=curr->next;
        curr->next=newnode;
    }

}

template <class T>
void CLinkedList<T>::remove(int index) {
    if (!(index < 0 || index >= this->length() || this->head == NULL)) {
        if (this->length() == 1) {
            delete this->head;
            this->head = NULL;
        } else if (index == 0 && this->length() > 1) {
            Node<T>* curr = this->head;
            while (curr->next != this->head) {
                curr = curr->next;
            }
            curr->next = this->head->next;
            delete this->head;
            this->head = curr->next;
        } else {
            int count = 0;
            Node<T>* curr = this->head;
            while (curr->next != this->head) {
                if (count == index - 1) {
                    Node<T>* temp = curr->next;
                    curr->next = curr->next->next;
                    delete temp;
                    return;
                }
                curr = curr->next;
                count++;
            }
        }
    }
}

/*template<class T>
void CLinkedList<T>::remove(int index)
{
    if(index<0 || index>this->length() || index==this->length())
    {
        return;
    }

    if(index==0)
    {
        Node<T>* goner=this->head;
        
        if(head->next==this->head)
        {
            this->head=NULL;
        }
        else
        {
            Node<T>* curr=this->head;

            while(curr->next != this->head)
            {
                curr=curr->next;
            }
            this->head=this->head->next;
            curr->next=this->head;
        }

        delete goner;
    }
    else
    {
        Node<T>* curr=this->head;

        for(int x=0;x<index-1;x++)
        {
            curr=curr->next;
        }

        Node<T>* goner=curr->next;
        curr->next=goner->next;

        int outie=length()-1;
        if(index==outie)
        {
            this->head=curr;
        }

        delete goner;
    }



}*/

template <class T>
void CLinkedList<T>::removeElements(T data) {
    if(this->length() == 0 || this->head == NULL) return;

    const int maxSize = this->length();
    int indexes[maxSize];

    int indexesTotal = 0, index = 0;
    while(index < this->length()) {
        if(this->get(index) == data) {
            indexes[indexesTotal] = index;
            indexesTotal++;
        }
        index++;
    }

    int count = 0, iterator = 0;
    while(iterator < indexesTotal) {
        this->remove(indexes[iterator] - count);
        count++;
        iterator++;
    }
}

/*template<class T>
void CLinkedList<T>::removeElements(T data)
{
    if(this->head==NULL || this->length()==0)
    {
        return;
    }

    Node<T>* curr=this->head;
    Node<T>* prev=NULL;

    do
    {

     if(curr->data == data)
     {
        if(prev != NULL)
        {
            prev->next=curr->next;

            delete curr;
            curr=prev->next;
        }
        else if(curr==this->head)
        {
            this->head=curr->next;
        
        delete curr;
        curr=this->head;
        }
     }
     else
     {
        Node<T>* outie=this->head;
        this->head=this->head->next;

        if(outie==this->head)
        {
            this->head=NULL;
        }
        delete outie;
        curr=this->head;
     }
     
     
    
    
        prev=curr;
        if(curr!=NULL)
        curr=curr->next;   
    
    }while(curr != this->head);
    

}*/
template <class T>
void CLinkedList<T>::print() const {
    if (this->head == NULL) {
        std::cout << "Empty\n";
        return;
    }

    Node<T>* current = this->head;
    while (current->next != this->head) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << current->data << std::endl;
}

/*
template<class T>
void CLinkedList<T>::print()const
{
    Node<T>* temp=this->head;

    if(this->head != NULL)
    {
        do
        {
            std::cout<<temp->data;
            std::cout<<"->";

            
            temp=temp->next;
            if(temp == NULL)
            {
                break;
            }
            
        } while (temp!= this->head );
        std::cout<<"\n";
        
    }
}*/

template <class T>
void CLinkedList<T>::reverse() {
    if (this->head != NULL) {
        Node<T>* prev = NULL;
        Node<T>* curr = this->head;
        Node<T>* next = NULL;
        while (curr->next != this->head) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        curr->next = prev;
        this->head->next = curr;
        this->head = curr;
    }
}

/*template<class T>
void CLinkedList<T>::reverse()
{
    if(this->head!=NULL)
    {
        Node<T>* prev=NULL;
        Node<T>* curr=this->head;
        Node<T>* next=NULL;

        

        do
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        } while (curr!=this->head);
        this->head=prev;
    }
}*/

/*template <class T>
void CLinkedList<T>::clear() {
    if (this->head != NULL) {
        Node<T>* iterator = this->head;
        while (iterator->next != this->head) {
            Node<T>* temp = current;
            iterator = iterator->next;
            delete temp;
        }
        delete iterator;
        this->head = NULL;
    }
}*/

template<class T>
void CLinkedList<T>::clear()
{
    if(!this->head)
    {
        return;
    }

    Node<T>* curr=this->head;
    Node<T>* next;

    do
    {
        next=curr->next;
        delete curr;
        curr=next;
    } while (curr != this->head);
    
    this->head=NULL;
}

template<class T>
int CLinkedList<T>::length()const
{
     int lengthy=0;
    if (this->head == NULL ) {
       
        return 0;
    }

    if(this->head->next == this->head)
    {
        return 1;
    }

    
        lengthy=1;
    

    Node<T>* current = this->head;
    while (current->next != this->head) {
        
        current = current->next;
        lengthy++;
    
    

    // if(current->next == this->head)
    // {
    //     lengthy++;
    // }
    }
     return lengthy;
    

}

template <class T>
T CLinkedList<T>::get(int index) const {
    if (index >= this->length() || index < 0) {
        return T();
    } else {
        int count = 0;
        Node<T>* current = this->head;
        while (current->next != this->head) {
            if (count == index) {
                return current->data;
            }
            
            current = current->next;
            count++;
        }
        T result = current->data;
        return result;
    }
}
/*template<class T>
T CLinkedList<T>::get(int index)const
{
    if(!head || index>this->length() || index==this->length() || index<0)
    {
        return T();
    }

    Node<T>* curr=this->head;

    int idx=0;

    while (curr)
    {
        if(idx==index)
        {
            return curr->data;
        }
        curr=curr->next;

        if(curr==this->head)
        {
            break;
        }
        
        idx++;
    } 

    return T();
    
}*/

template<class T>
T CLinkedList<T>::operator[](int index)const
{
    return this->get(index);
}

template<class T>
void CLinkedList<T>::filter(std::string op,T query)
{
    /*if(this->head == NULL)
    {
        return;
    }

    Node<T>* curr=this->head;
    Node<T>* prev=NULL;

    do
    {
        bool keep=false;

        if(op==">" && curr->data >query)
        {
            keep=true;
        }
        else if(op=="<" && curr->data <query)
        {
            keep=true;
        }
        else if(op=="==" && curr->data ==query)
        {
            keep=true;
        }
        else if(op=="!=" && curr->data !=query)
        {
            keep=true;
        }
        else if(op==">=" && curr->data >=query)
        {
            keep=true;
        }
        else if(op=="<=" && curr->data <=query)
        {
            keep=true;
        }


        if(keep==true)
        {
            prev=curr;
            curr=curr->next;
        }
        else
        {
            if(prev !=NULL)
            {
                prev->next=curr->next;

                if(curr==this->head)
                {
                    this->head=curr->next;
                }

                Node<T>* temp=curr;
                curr=curr->next;
                delete temp;
            }
            else
            {
                Node<T>* goner=this->head;
                this->head=this->head->next;
                
                if(goner==this->head)
                {
                    this->head=NULL;
                }

                delete goner;
                curr=this->head;

            }
        }

    } while (curr!=this->head);*/
    
}

template <class T>
void CLinkedList<T>::swap(int index1, int index2) {
    if (index1 >= this->length() || index2 >= this->length() || index1 < 0 || index2 < 0 || this->head == NULL) {
        return;
    } else {
        Node<T>* current = this->head;
        Node<T>* first = NULL;
        Node<T>* second = NULL;

        int count = 0;
        while (current->next != this->head) {
            if (count == index1) first = current;
            if (count == index2) second = current;
            current = current->next;
            count++;
        }

        if (count == index1) first = current;
        if (count == index2) second = current;

        T temp = first->data;
        first->data = second->data;
        second->data = temp;
    }
}


/*template<class T>
void CLinkedList<T>::swap(int index1,int index2)
{
    if(index1 < 0 || index2<0 || index1>=this->length() || index2>=this->length() || this->head==NULL)
    {
        return;
    }

    Node<T>* node1=this->head;
    Node<T>* node2=this->head;

    for(int x=0;x<index1;x++)
    {
        node1=node1->next;
    }

    for(int x=0;x<index2;x++)
    {
        node2=node2->next;
    }

    std::swap(node1->data,node2->data);

}*/

template <class T> 
void CLinkedList<T>::slice(int start, int end) {
    if (!(start >= this->length() || end >= this->length() || start > end || start < 0 || end < 0)) {
         Node<T>* current = this->head;
        int count = 0;
        for(int i = start; i <= end; i++) {
            this->append((*this)[i]);
            count++;
        }

        int len = this->length() - count, j = 0;
        while (j < len) {
            this->remove(0);
            j++;
        }
    } 
}

/*template<class T>
void CLinkedList<T>::slice(int start, int end)
{
    if(start<0 || end<start || start>=length() || head==NULL)
    {
        return;
    }

    int length_i=length();

    if(end>=length_i)
    {
        end=length_i-1;
    }

    Node<T>* curr=head;
    Node<T>* prev=NULL;

    int idx=0;

    while(idx<start)
    {
        //fond node with ending idx
        prev=curr;
        curr=curr->next;
        idx++;
    }

    Node<T>* nhead=curr;
    Node<T>* ntail=curr;

    while(idx<end)
    {
        prev=curr;
        curr=curr->next;
        idx++;
    }

    if(prev)
    {
        prev->next=curr->next;
    }

    ntail->next=nhead;
    head=nhead;
}*/

/*template<class T>
void CLinkedList<T>::RRotate(int k)
{
    if(k==0 || k<0 || this->head==NULL)
    {
        return;
    }

    int size=this->length();

    // if(k==0)
    // {
    //     return;
    // }
    int move=k%size;
   

    Node<T>* curr=this->head;

    for(int x=0;x<move;x++)
    {
        curr=curr->next;
    }

   // Node<T>* newhead=curr->next;

    //curr->next=this->head;
    this->head=curr;
}*/

/*template<class T>
void CLinkedList<T>::LRotate(int k)
{
    if(k==0 || k<0 || this->head==NULL)
    {
        return;
    }

    int size=this->length();
    int move=k%size;

    

    Node<T>* curr=this->head;

    for(int x=0;x<size-move;x++)
    {
        curr=curr->next;
    }

   // Node<T>* newhead=curr->next;

    //curr->next=this->head;
    this->head=curr;
}*/

template <class T>
void CLinkedList<T>::RRotate(int k) {
    if (!(this->head == NULL || k < 0)) {
        int i = 0;
        while (i < k) {
            int index = this->length() - (i + 1);
            T data = this->get(index);
            this->prepend(data);
            i++;
        }

        i = 0;
        while (i < k) {
            int index = this->length() - 1;
            this->remove(index);
            i++;
        }
    }
}

template <class T>
void CLinkedList<T>::LRotate(int k) {
    if (!(this->head == NULL || k < 0)) {
        int i = 0;
        while (i < k) {
            T data = this->get(i);
            this->append(data);
            i++;
        }

        i = 0;
        while (i < k) {
            this->remove(0);
            i++;
        }
    }
}

template<class T>
CLinkedList<T>& CLinkedList<T>::operator=(const CLinkedList& other)
{
    if(this == &other)
    {
        return *this;
    }

    clear();

    if(other.head == NULL)
    {
        return*this;
    }

    Node<T>* curr=other.head;

    do
    {
        append(curr->data);
        curr=curr->next;
    } while (curr != other.head);
    
    return *this;
}
//get here//
template <class T>
bool CLinkedList<T>::operator==(const CLinkedList<T> &other) const {
    if (this->length() != other.length() || (this->head == NULL && other.head != NULL)) {
        return false;
    }

    bool result = false;
    
    if(this->length() == other.length()) {
        int thisCount = 0;
        int otherCount = 0;

        int p = 0;
        while (p < this->length()) {
            int thisValue = this->get(p);
            int otherValue = other.get(p);

            int i = 0;
            while (i < this->length()) {
                if ((*this)[i] == otherValue) {
                    thisCount++;
                }
                i++;
            }

            int j = 0;
            while (j < other.length()) {
                if (other[j] == thisValue) {
                    otherCount++;
                }
                j++;
            }
            p++;
        }

        if(thisCount == otherCount) {
            if (this->length() == thisCount) {
                result = true;
                return result;
            }
            result = false;
            return result;
        } else {
            result = false;
            return result;
        }
    }
    
    return result;
}

template <class T>
void CLinkedList<T>::operator+=(const CLinkedList &other)
{
    if (this == &other || other.head == NULL)
    {
        return;
    }

    int index = 0;
    while (index < other.length())
    {
        this->append(other[index]);
        index++;
    }
}
/*template<class T>
bool CLinkedList<T>::operator==(const CLinkedList& other)const
{
    if(this == &other)
    {
        return true;
    }

    if(this->length() != other.length())
    {
        return (this->length() != other.length());
    }

    if(!this->head || !other.head)
    {
        return !this->head && !other.head;
    }



    Node<T>* curr=this->head;
    Node<T>* other_curr=other.head;

    do
    {
        if(curr->data != other_curr->data)
        {
            return false;
        }


        curr=curr->next;
        other_curr=other_curr->next;
    } while (curr != head && other_curr!=other.head);
    
    return true;
}

template<class T>
void CLinkedList<T>::operator+=(const CLinkedList& other)
{
    /*if(this == &other || other.head==NULL)
    {
        return;
    }

    if(head==NULL)
    {
        head=other.head;
    }
    else
    {
        Node<T>* last=head; //what if heads empty
        //dont use head
        //k=just call append

        while(last->next != head)
        {
            last=last->next;
        }
        last->next=other.head;
    }

    Node<T>* temp = other.head;

    while(temp->next != other.head)
    {
        temp=temp->next;
    }
    temp->next=head;*/
   // other.head=NULL;

template <class T>
CLinkedList<T> *CLinkedList<T>::operator-(const CLinkedList<T> &other) const {
    CLinkedList<T>* result = new CLinkedList<T>();
    
    int i = 0;
    while (i < this->length()) {
        result->append((*this)[i]);
        i++;
    }

    int j = 0;
    while (j < other.length()) {
        result->removeElements(other[j]);
        j++;
    }

    return result;
}




/*
template<class T>
CLinkedList<T>* CLinkedList<T>::operator-(const CLinkedList<T> &other) const
{
    CLinkedList<T>* out=new CLinkedList<T>();

    if(this->head == NULL)
    {
        return out;
    }
    if(other.head == NULL)
    {
        //return *this; //cant return  this

        out->operator=(*this);
        return out;
    }

    Node<T>* curr=this->head;

    do
    {
        Node<T>* curr2=other.head;
        bool done=false;
        do
        {
            if(curr->data == curr2->data)
            {
                done=true;
                break;
            }
            curr2=curr2->next;
        }while(curr2!=other.head);

        if(!done)
        {
            out->append(curr->data);
        }
        curr=curr->next;
    } while (curr!=this->head);

    return out;
    
}*/

template <class T>
void CLinkedList<T>::removeDuplicates() {
    if(this->length() == 0 || this->head == NULL) return;

    const int maxSize = this->length();
    T tempList[maxSize];
    int len = 0;

    int outer = 0;
    while (outer < maxSize) {
        T data = this->get(outer);
        bool containsData = false;

        int inner = 0;
        while (inner < len) {
            if(tempList[inner] == data) {
                containsData = true;
                break;
            }
            inner++;
        }

        if(containsData == false) {
            tempList[len] = data;
            len++;
        }

        outer++;
    }

    this->clear();

    int count = 0;
    while (count < len) {
        this->append(tempList[count]);
        count++;
    }
}



/*template<class T>
void CLinkedList<T>::removeDuplicates()
{
    if(head == NULL)
    {
        return;
    }

    Node<T>* curr=head;
    Node<T>* temp;

    do
    {

        temp=curr->next;
        Node<T>* prev=curr;

        while(temp != head)
        {
            if(curr->data == temp->data)
            {
                prev->next=temp->next;
                Node<T>* temp2=temp;
                temp=temp->next;
                delete temp2;
            }
            else
            {
                prev=temp;
                temp=temp->next;
            }
           

        }
         curr=curr->next;
    }while(curr != head);


}*/

template<class T>
void CLinkedList<T>::consume(CLinkedList& other)
{
    if(this==& other || other.head==NULL)
    {
        return;
    }

    if(head ==NULL)
    {
        head=other.head;
    }
    else
    {
        Node<T>* endnode=head;
        while(endnode->next != head)
        {
            endnode=endnode->next;
        }
        endnode->next = other.head;
    }

    Node<T>* temp=other.head;

    do
    {
        
        if(temp->next == other.head)
        {
            temp->next=head;
            break;
        }
        temp=temp->next;

    } while (temp != other.head);
    other.head=NULL;
}



#endif