#include<iostream>
using namespace std;

struct node
{
    node *next;
    int data;
    node()
    {
        next=NULL;
        data=0;
    }
    node(int data)
    {
        next=NULL;
        this->data=data;
    }
};

class cList
{
public:
    node* point;
    cList()
    {
        point=NULL;
    }
    void insert_beginning(int data)
    {
        node* newnode=new node(data);
        if(point==NULL)
        {
            point=newnode;
            point->next=newnode;
            return;
        }
        node* temp=point;
        newnode->next=temp->next;
        temp->next=newnode;
    }

    void insert_end(int data)
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

    void insert_index(int data,int index)
    {
        index=index-1;
        node* newnode=new node(data);
        if(point==NULL)
        {
            cout<<"\nList is Empty\n";
            point=newnode;
            point->next=newnode;
            return;
        }
        node* temp=point;
        while(index!=0)
        {
            if(index!=0 && temp->next==NULL)
            {
                cout<<"\nindex is not present\n";
                return;
            }
            temp=temp->next;
            index--;
        }
        if(index==0&&temp->next==point)
        {
            newnode->next=point->next;
            point->next=newnode;
            point=newnode;
            return;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }

    void delete_beginning()
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
    }

    void delete_end()
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
        node* temp=point;
        while(temp->next!=point)
        {
            temp=temp->next;
        }
        node* temp2=temp->next;
        temp->next=temp->next->next;
        point=temp;
        delete temp2;
    }

    void delete_index(int index)
    {
        index=index-1;
        if(point==NULL)
        {
            cout<<"\nlist is empty\n";
            return;
        }
        if(point->next==point)
        {
            if(index==0)
            {
                cout<<"\ngiven index is not present\n";
                return;
            }
        }
        node* temp=point;
        index=index-1;
        while(index!=NULL)
        {
            if(index!=NULL&&temp->next==point)
            {
                cout<<"\ngiven index is not present\n";
                return;
            }
            temp=temp->next;
            index--;
        }
        if(index==0&& temp->next==point)
        {
            delete_end();
            return;
        }
        temp->next=temp->next->next;

    }

    void search(int key)
    {
        int i=0;
        node* temp=point->next;
        while(temp!=point)
        {
            i++;
            if(temp->data==key)
            {
                cout<<"\n Found at index : "<<i<<endl;
                return;
            }
            temp=temp->next;
        }
        cout<<"\nNOT Found\n";
    }

    node* concat(cList obj1,cList obj2)
    {
        node* temp1=obj1.point;
        node* temp2=obj2.point;
        node* temp=temp1->next;
        temp1->next=temp2->next;
        temp2->next=temp;
        point=obj2.point;
    }

    void show()
    {
        if(point==NULL)
        {
            cout<<"List is Empty"<<endl;
            return;
        }
        cout<<"Circular linked list : ";
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
    cList obj;
    obj.show();
    cout<<"\n insert at beginning\n";

    obj.insert_beginning(5);
    obj.insert_beginning(4);
    obj.insert_beginning(3);
    obj.insert_beginning(2);
    obj.insert_beginning(1);
    obj.insert_beginning(0);
    obj.show();

    cout<<"\ninsert at end\n";
    obj.insert_end(7);
    obj.insert_end(8);
    obj.show();

    cout<<"\n insert at index\n";
    obj.insert_index(6,6);
    obj.show();

    cout<<"\nDelete from beginning\n";
    obj.delete_beginning();
    obj.show();

    cout<<"\nDelete from end\n";
    obj.delete_end();
    obj.show();

    cout<<"\ndelete from index\n";
    obj.delete_index(5);
    obj.show();

    cout<<"\nsearching 2 and 10\n";
    obj.search(2);
    obj.search(10);

    cList obj2;
    obj2.insert_beginning(12);
    obj2.insert_beginning(11);

    cList obj3;
    cout<<"\nconcat two Circular linked list\n";
    obj3.concat(obj,obj2);
    obj3.show();


    return 0;
}
