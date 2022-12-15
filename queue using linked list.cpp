#include<iostream>

using namespace std;

class node
{
public:
    node *next;
    int data;
    node()
    {
        next=NULL;
        data=0;
    }
    node(int data)
    {
        this->data=data;
        next=NULL;
    }
};

class Queue
{
    node* point;
public:
    Queue()
    {
        point=NULL;
    }
    void enqueue(int data)
    {
        node* newnode=new node(data);
        if(point==NULL)
        {
            point=newnode;
            point->next=newnode;
            return;
        }
        newnode->next=point->next;
        point->next=newnode;
        point=newnode;
    }
    void dequeue()
    {
        if(point==NULL)
        {
            cout<<"\nlist is empty\n";
            return;
        }
        if(point->next==point)
        {
            delete point;
            point=NULL;
            return;
        }
        node* temp=point->next;
        point->next=temp->next;
        delete temp;
        cout<<"\n Deleted \n";
    }
    void Front()
    {
        cout<<"\n Front : "<<point->next->data<<endl;
    }
    void display()
    {
        if(point==NULL)
        {
            cout<<"List is Empty"<<endl;
            return;
        }
        cout<<"Queue : ";
        node* temp=point->next;
        while(temp!=point)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        if(temp==point)
        {
            cout<<temp->data<<" ";
        }
        cout<<endl<<endl;
    }
};

int main()
{
    Queue obj;

    int ch;
    int n;
    do{
        cout<<"\n1. Enqueue\n2. Dequeue\n3. Front\n4. Display\n";
        cin>>ch;
        switch(ch)
        {
        case 1:
            {
                cout<<"Enter Element : ";
                cin>>n;
                obj.enqueue(n);
                break;
            }
        case 2:
            {
                obj.dequeue();
                break;
            }
        case 3:
            {
                obj.Front();
                break;
            }
        case  4:
            {
                obj.display();
                break;
            }
        }
    }while(true);

    return 0;
}
