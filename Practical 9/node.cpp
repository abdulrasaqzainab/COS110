#include "node.h"
#include <iostream>
#include <sstream>

node::node(int val)
{

    //unlink after contruction
    this->data=val;
    this->prev=NULL;
    this->next=NULL;
}

node::~node()
{
    this->prev=NULL;
    this->next=NULL;
    
   // delete this;
}

void node::destroyList()
{

    while (next != NULL) {
        next->prev = NULL;
        node* temp = next;
        next = next->next;
        delete temp;
    }

    while (prev != NULL) {
        prev->next = NULL; 
        node* temp = prev;
        prev = prev->prev;
        delete temp;
    }

    delete this;

    /*if (this->prev !=NULL)
    {
        this->prev->next=this->next;
    }
    
    if(this->next != NULL)
    {
        this->next->prev=this->prev;
    }

    this->prev=NULL;
    this->next=NULL;
    delete this;

    if(this->prev != NULL)
    {
        this->prev->destroyList();
    }

    if(this->next != NULL)
    {
        this->next->destroyList();
    }*/

    /*if(prev!=NULL)
    {
        prev->destroyList();
    }
    delete this;

    if(next!=NULL)
    {
        next->destroyList();
    }
    delete this;*/


    /*if(this->head() == NULL)
    {
        return;
    }




    //node* curr=this->head();
     node* current = this->head();
        
        while (current != NULL) {
            node* temp = current->next;
            
            delete current;
            current = temp;
        }
        //delete current;
    if(this->tail() == NULL)
    {
        return;
    }
       node* current2 = this->tail();
        
        while (current2 != NULL) {
            node* temp = current2->prev;
            
            delete current2;
            current2 = temp;
        }*/





    //delete whole list
    /*node* curr=this;

    while(curr->next != NULL)
    {
        node* temp=curr;
        curr=curr->next;
        temp->next=NULL;
        temp->prev=NULL;

        delete temp;
    }

    node* curr2=this;
    while(curr2->prev != NULL)
    {
        node* temp=curr;
        curr2=curr2->prev;
        temp->next=NULL;
        temp->prev=NULL;

        delete temp;
    }

    curr->next=NULL;
    curr->prev=NULL;
    delete curr;

    curr2->next=NULL;
    curr2->prev=NULL;
    delete curr2;*/
    
}

bool node::contains(int val)
{
    //traverse and return
   node* curr=this->head();

    while(curr != NULL)
    {
        if(curr->data == val)
        {
            return true;
        }

        curr=curr->next;
    }

    node* curr2=this->tail();
    while(curr2 !=NULL)
    {
       if(curr2->data == val)
        {
            return true;
        }

        curr2=curr2->prev; 
    }
    return false;

/* node* curr=this;

    while(curr != NULL)
    {
        if(curr != NULL)
        {
            return true;
        }

        curr=curr->next;
    }
    return false;*/
}

void node::insert(int val)
{

    if(this->contains(val))
    {
        return;
    }

    node* newnode=new node(val);
    node* curr=this->head();

    if(val < this->head()->data)
    {
        // this->next=newnode;
        // newnode->prev=this;

        curr->prev=newnode;
        newnode->next=curr;
        newnode->prev=NULL;
       // break;
    }
    else
    {
        
       while(curr != NULL)
        {
            if(curr->data > val)
            {   
                if(curr->prev !=NULL)
                {
                newnode->next=curr;
                newnode->prev=curr->prev;
                curr->prev->next=newnode;
                curr->prev=newnode;
                //break;
                }
                return;
            }
            
                if(curr->next==NULL)
                {
                    newnode->next=NULL;
                    newnode->prev=curr;
                    curr->next=newnode;
                    break;
                }

                curr=curr->next;
            
        }

        // if(curr->next != NULL)
        // {
        //     newnode->next=curr->next;
        //     newnode->next->prev=newnode;
        // }

        // newnode->prev=curr;
        // curr->next=newnode;
    }
}

    /*if(contains(val)==false)
    {
        node* newnode=new node(val);
        node* curr=this;

        while(curr->next!=NULL &&
        (curr->next)->data<val )
        {
            curr=curr->next;
        }
        if(curr->prev==NULL)
        {
            newnode->next=curr;
            //newnode->prev=curr->prev;
            curr->prev=newnode;
            newnode->prev=NULL;

            // if(curr->prev != NULL)
            // {
            //     curr->prev->next=newnode;
            // }
            // curr->prev=newnode;
        }
        else
        {
            // newnode->prev=curr;
            // curr->next=newnode;
            newnode->next=curr;
            newnode->prev=curr->prev;
            curr->prev->next=newnode;
            curr->prev=newnode;
        }
    }*/
//}

/*void node::insert(node* n)
{
    if(n==NULL)
    {
        return;
    }

    node* curr=this->head();
    node* other=n->head();

    while(curr!=NULL && other!=NULL)
    {
        if(curr->data == other->data)
        {
            node* temp=other;
            other=other->next;
            delete temp;
        }
        else if(curr->data < other->data)
        {
            curr=curr->next;
        }
        else
        {
            node* temp=other;
            other=other->next;
            temp->prev=curr->prev;
            temp->next=curr;


            if(curr->prev != NULL)
            {
                curr->prev->next=temp;
            }
            else
            {
                curr=temp;
            }
            curr->prev=temp;
        }
    }

    while(curr!=NULL)
    {
        node* temp=other;
        other=other->next;
        temp->prev=this->tail();
        temp->next=NULL;
        this->tail()->next=temp;
    }

   // n->destroyList();
    
}*/


void node::insert(node* n)
{
    if(n==NULL || this->data==n->data)
    {
        return;
    }

    node* thead=this->head();
    node* ttail=this->tail();

    node* nhead=n->head();
    node* ntail=n->tail();

    node* curr=thead;
    node* curr2=nhead;



    while(curr2)
    {
        if(!curr)
        {
            ttail->next=curr2;
            curr2->prev=ttail;
            ttail=ntail;
            break;
        }

        if(curr2->data < curr->data)
        {
            node* temp=curr2->next;
            curr2->prev=curr->prev;
            curr2->next=curr;


            if(curr->prev)
            {
                curr->prev->next=curr2;
            }
            else
            {
                thead=curr2;
            }

            curr->prev=curr2;
            curr2=temp;
        }
        else if(curr2->data > curr->data)
        {
            
                curr=curr->next;
            
        }
        else
        {
            curr2=curr2->next;
        }
    }



    /*while(curr!=NULL && curr2!=NULL)
    {
        if(curr->data < curr2->data)
        {
            if(curr->next != NULL)
            {
                curr=curr->next;
            }
            else
            {
                curr->next=curr2;
                curr2->prev=curr;
                break;
            }
        }
        else if(curr->data > curr2->data)
        {
            node* temp = curr2;
            curr2 = curr2->next;
            // temp->prev = curr->prev;
            // temp->next = curr;

            if (curr->prev != NULL) {
                curr->prev->next = temp;
                temp->prev=curr->prev;
            } else {
                
                this->prev = temp;
                temp->prev=NULL;
            }
            temp->next=curr;
            curr->prev = temp;
        }
        else
        {
            curr2=curr2->next;
        }
    }
    
        
        
        while (curr2 != NULL) {
            curr = this->tail(); 
            curr->next = curr2;
            curr2->prev = curr;
            curr = curr->next;
            curr2 = curr2->next;
        }*/
    
}

void node::print()
{
    node* curr=this->head();
    
    while(curr != NULL)
    {
        if(curr == this)
        {
            std::cout<<"["<<curr->data<<"]";
        }
        else
        {
            std::cout<<curr->data;
        }

        if(curr->next != NULL)
        {
            std::cout<<"->";
        }
        curr = curr->next;
    }

    std::cout<<"\n";
}

int node::length()
{
    int count=0;

    node* curr=this->head();

    while(curr != NULL)
    {
        count=count+1;
        curr=curr->next;
    }

    return count;
}

node* node::remove(int val)
{
    /*node* curr=this;

    bool found=false;

    while(curr!=NULL && found==false)
    {
        if(curr->data == val)
        {
            found=true;
        }
        curr=curr->next;
    }
    
    if(found==true)
    {
        if(curr != NULL)
        {
            if(curr->prev!=NULL)
            {
                curr->prev->next=curr->next;
            }

            if(curr->next!=NULL)
            {
                curr->next->prev=curr->prev;
            }

            curr->next=NULL;
            curr->prev=NULL;
        }
    }
    return curr;*/

    node* curr=this->head();

    while(curr!=NULL)
    {
        if(curr->data == val)
        {
            if(curr->prev!=NULL)
            {
                curr->prev->next=curr->next;
            }
            if(curr->next!=NULL)
            {
                curr->next->prev=curr->prev;
            }

            node* goner=curr;

            curr=curr->next;
            //goner->prev=NULL;
           // goner->next=NULL;

            return goner;
        }

        curr=curr->next;
    }

    return NULL;

}

node* node::head()
{
    node* curr=this;

    while(curr->prev != NULL)
    {
        curr=curr->prev;
    }

    return curr;
}

node* node::tail()
{
    node* curr=this;

    while(curr->next != NULL)
    {
        curr=curr->next;
    }

    return curr;
}
