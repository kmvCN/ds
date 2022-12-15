#include<iostream>

using namespace std;

class node
{
public:
    node* next;
    int data;
    node()
    {
        data=0;
        next=NULL;
    }
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

class llist
{
    node* head;
public:
    llist()
    {
        head=NULL;
    }
    void insert_after(int data)
    {
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

    void insert_before(int data)
    {
        node* newnode=new node(data);
            newnode->data=data;
            newnode->next=head;
            head=newnode;
    }

    void insert_index(int data,int pos)
    {
        node* newnode=new node(data);
        if(head==NULL)
        {
            cout<<"\nDesired position is not Present"<<endl;;
            return;
        }
        node* temp=head;
        int k=1;
        while(k!=pos-1)
        {
            temp=temp->next;
            k++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }

    void remove_start()
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
            delete temp;
            return;
        }
            head=head->next;
            delete temp;
    }

    void remove_end()
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
        temp->next=NULL;
        delete temp2;
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
        while(temp->next!=NULL && i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        if(temp->next==NULL)
        {
            cout<<"Element is not Present at position"<<endl;
            return;
        }
        node* prev;
        prev=temp->next;
        temp->next=prev->next;
        delete prev;
    }

    void search(int key)
    {
        node* temp=head;
        if(head==NULL)
        {
            cout<<"List is Empty"<<endl;
            return;
        }
        int i=1;
        while(temp->next!=NULL)
        {
            if(temp->data==key)
            {
                cout<<"Element found at : "<<temp->next<<endl;
                return;
            }
            temp=temp->next;
            i++;
        }
        cout<<"Element NOT Found"<<endl;
    }

    node* concat(llist a)
    {
        node* p=this->head;
        node* q=a.head;
        if(q==NULL)
        {
            return 0;
        }
        if(p==NULL)
        {
            cout<<"List is Empty"<<endl;
            return 0;
        }
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=q;
        return head;
    }

    void print()
    {
        node* temp=head;
        if(head==NULL)
        {
            cout<<"List is Empty"<<endl;
            return;
        }
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        int k=0;
        temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
            k++;
        }
        cout<<"\n Total no of Box = "<<k;
    }
};

int main()
{
    llist obj;
    obj.insert_after(1);
    obj.insert_after(2);
    obj.insert_after(3);
    obj.insert_before(4);

    cout<<"Elements of the list are : ";
    obj.print();
    cout<<endl;
    obj.insert_before(5);
    obj.print();
    cout<<"\nElement at index 2"<<endl;
    obj.insert_index(50,2);
    obj.print();
    cout<<"\n removing from beginning"<<endl;
    obj.remove_start();
    obj.print();
    cout<<"\n remove from end "<<endl;
    obj.remove_end();
    obj.print();
    cout<<"\n removing from index 3"<<endl;
    obj.remove_index(3);
    obj.print();
    cout<<"\n searching 4 and 10 in the list"<<endl;
    obj.search(4);
    obj.search(10);
    cout<<"\n Concat two List"<<endl;
    llist obj1;
    obj1.insert_after(40);
    obj1.insert_after(30);
    obj1.insert_after(20);
    obj1.insert_before(10);
    obj.concat(obj1);
    obj.print();

    return 0;
}
