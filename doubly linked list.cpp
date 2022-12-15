#include<iostream>

using namespace std;

class node
{
public:
    node* next;
    node* prev;
    int data;
    node()
    {
        data=0;
        next=NULL;
        prev=NULL;
    }
    node(int x)
    {
        data=x;
        prev=NULL;
        next=NULL;
    }
};

class dlist
{
    node* head;
    node* tail;
public:
    dlist()
    {
        head=NULL;
        tail=NULL;
    }

    void insert_after(int data)
    {
        node* newnode=new node(data);
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
            return;
        }
        node* temp=tail;
        temp->next=newnode;
        newnode->prev=temp;
        tail=newnode;
    }

    void insert_before(int data)
    {
        node* newnode=new node(data);
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
            return;
        }
        node* temp=head;
        newnode->next=temp;
        temp->prev=newnode;
        head=newnode;
    }

    void insert_index(int data, int pos)
    {
        node* newnode=new node(data);
        if(head==NULL)
        {
            cout<<"List is Empty"<<endl;
            return;
        }
        node* temp=head;
        int i=1;
        while(temp->next!=NULL && i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        if(i!=pos-1)
        {
            cout<<"\nPosition is not available"<<endl;
            return;
        }
        if(temp==tail)
        {
            temp->next=newnode;
            newnode->prev=temp;
            tail=newnode;
            return;
        }
        node* temp2=temp->next;
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=temp2;
        temp2->prev=newnode;

    }

    void remove_before()
    {
        if(head==NULL)
        {
            cout<<"List is Empty"<<endl;
            return;
        }
        node* temp=head;
        if(temp->next==NULL)
        {
            head=NULL;
            tail=NULL;
            delete temp;
            return;
        }
        head=head->next;
        delete temp;
    }

    void remove_after()
    {
        if(head==NULL)
        {
            cout<<"List is Empty"<<endl;
            return;
        }
        node* temp=tail;
        if(head==tail)
        {
            head=NULL;
            tail=NULL;
            delete temp;
            return;
        }
        tail=temp->prev;
        tail->next=NULL;
        delete temp;
    }

    void remove_index(int pos)
    {
        if(head==NULL)
        {
            cout<<"List is Empty"<<endl;
            return;
        }
        node* temp=head;
        int i=1;
        while(temp->next!=NULL && i<pos)
        {
            temp=temp->next;
            i++;
        }
        if(i!=pos)
        {
            cout<<"Position is not available"<<endl;
            return;
        }
        if(temp==tail)
        {
            tail=temp->prev;
            tail->next=NULL;
            delete temp;
        }
        node* temp2=temp->prev;
        node* temp3=temp->next;
        temp2->next=temp3;
        temp3->prev=temp2;
        delete temp;
        }

        void search(int key)
        {
            if(head==NULL)
            {
                cout<<"\nList is Empty"<<endl;
                return;
            }
            node* temp1=head;
            node* temp2=tail;
            while(temp1!=temp2)
            {
                if(temp1->data==key)
                {
                    cout<<"Found at "<<temp1<<endl;
                    return;
                }
                if(temp2->data==key)
                {
                    cout<<"Found at "<<temp2<<endl;
                    return;
                }
                temp1=temp1->next;
                temp2=temp2->prev;
            }
            if(temp1->data==key)
                {
                    cout<<"Found at "<<temp1<<endl;
                    return;
                }
                cout<<"NOT Found"<<endl;
        }

        node* concat(dlist obj)
        {
            node* p=this->tail;
            node* q=obj.head;

            if(p==NULL)
            {
                cout<<"List 1 is Empty"<<endl;
                return 0;
            }
            if(q=NULL)
            {
                cout<<"list 2 is Empty"<<endl;
                return 0;
            }
            this->tail->next=obj.head;
            obj.head=this->tail->next;
            tail=obj.tail;
            head=this->head;
            return head;
        }

    void print()
    {
        node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"  ";
            temp=temp->next;
        }
    }

};

int main()
{
    dlist obj;
    cout<<"\nInserting after"<<endl;
    obj.insert_after(5);
    obj.insert_after(10);
    obj.insert_after(15);
    obj.insert_after(20);
    obj.print();
    cout<<"\nInserting before "<<endl;
    obj.insert_before(0);
    obj.print();
    cout<<"\ninserting at position 2"<<endl;
    obj.insert_index(50,2);
    obj.print();
    cout<<"\n Removing from beginning"<<endl;
    obj.remove_before();
    obj.print();
    cout<<"\n Removing from end"<<endl;
    obj.remove_after();
    obj.print();
    cout<<"\n removing from index 2"<<endl;
    obj.remove_index(2);
    obj.print();
    cout<<"\nSearching 15 "<<endl;
    obj.search(15);
    obj.print();
    dlist obj2;
    obj2.insert_after(35);
    obj2.insert_after(30);
    obj2.insert_after(35);
    obj2.insert_after(30);
    cout<<"\n concat "<<endl;
    obj.concat(obj2);
    obj.print();

    return 0;
}
