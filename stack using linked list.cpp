#include<iostream>

using namespace std;

class node
{
public:
    node* next;
    int data;
    node()
    {
        next=NULL;
        data=NULL;
    }
    node(int data)
    {
        next=NULL;
        this->data=data;
    }
};

class stack
{
    int n=0;
    node* head;
public:

    stack()
    {
        head=NULL;
    }

    void push()
    {
        int data;
        cout<<"Enter Element"<<endl;
        cin>>data;
        node* newnode=new node(data);
        if(head==NULL)
        {
            head=newnode;
            return;
        }
        node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }

    void pop()
    {
        if(head==NULL)
        {
            cout<<"List is Empty"<<endl;
            return;
        }
        node* temp=head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        node* temp2=temp->next;
        delete temp2;
        temp->next=NULL;
    }

    void length()
    {
        node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
            n++;
        }
        cout<<"\nLength : "<<n+1;
        n=0;
    }

    void display()
    {
        if(head==NULL)
        {
            cout<<"\nList is Empty\n";
            return;
        }
        cout<<"List : ";
        node* temp=head;
        while(temp->next!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<temp->data;
    }
};

int main()
{
    stack obj;
    int ch;
    do
    {
        cout<<"\n1. Push"<<"\n2. Pop"<<"\n3. get Size"<<"\n4. Display"<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1:
            {
                obj.push();
                break;
            }
        case 2:
            {
                obj.pop();
                cout<<"\nElement Deleted\n";
                break;
            }
        case 3:
            {
                obj.length();
                break;
            }
        case 4:
            {
                obj.display();
                break;
            }
        }
    }while(true);

    return 0;
}
