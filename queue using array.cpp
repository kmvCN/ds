#include<iostream>

using namespace std;

class abc
{
    int* arr;
    int n;
    int r=0,s=0;
public:
    abc(int n)
    {
        this->n=n;
        arr=new int[n];
    }

    int is_Full()
    {
        if(r-1==n)
            return 1;
        else
            return 0;
    }

    void enqueue(int x)
    {
        if(is_Full())
        {
            cout<<"\nQueue is Full\n";
            return;
        }
        else
        {
            arr[r]=x;
            r++;
        }
    }
    void dequeue()
    {
        if(r==s)
        {
            cout<<"\nQueue is Empty"<<endl;
            return;
        }
        for(int i=s;i<r-1;i++)
        {
            arr[i]=arr[i+1];
        }
        r--;
        cout<<"\nDeleted\n";
    }
    void front()
    {
        cout<<arr[s]<<endl;
    }
    void display()
    {
        cout<<"\n Elements : ";
        for(int i=s;i<r;i++)
        {
            cout<<arr[i]<<"  ";
        }
    }
};

int main()
{
    int size;
    cout<<"\nEnter the size of Array : ";
    cin>>size;

    abc obj(size);
    int ch;
    do{
    cout<<"\n1. Enqueue\n2. Dequeue\n3. Front\n.4Display\n";
    cin>>ch;
    switch(ch)
    {
        int n;
    case 1:
        {
            cout<<"\nEnter Element : ";
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
            obj.front();
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
