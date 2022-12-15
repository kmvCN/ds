#include<iostream>
using namespace std;

class searching
{
    int *arr,n;
public:
    int s;
    void get()
    {
        cout<<"Enter the length of Array"<<endl;
        cin>>n;
        arr=new int[n];
        cout<<"\n Enter the Elements"<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
    }
    void sort()
    {
        int temp=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
    }
    int search()
    {
        cout<<"\nEnter the element to be searched : ";
        cin>>s;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==s)
                return i;
        }
            return -1;
    }
};

int main()
{
    char y;
    searching obj;
    obj.get();
    obj.sort();
    do{
    int s=obj.search();
    if(s==-1)
        cout<<"\nElement Not Found";
    else
        cout<<"\nElement found at index : "<<s;
    cout<<"\nEnter Y to continue : ";
    cin>>y;
    }while(y=='y'|| y=='Y');

    return 0;
}
