#include<iostream>

using namespace std;

class sorting
{
    int *arr,n,nswap=0;
public:
    void get()
    {
        cout<<"\nEnter the length of array : ";
        cin>>n;
        arr=new int[n];
        cout<<"\nEnter the Elements"<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
    }
    void swap(int i,int j)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    void bubble()      // time complexity = O(n²) worst case and average case
    {
        for(int i=0;i<n;i++)  //best case = O(n)
        {
            for(int j=0;j<n-i-1;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    swap(j,j+1);
                    nswap++;
                    show();
                }
            }
            cout<<"\nTotal no of Swappings = "<<nswap<<endl;;
            nswap=0;
        }
    }
    void selection()
    {
        for(int i=0;i<n-1;i++)   // time complexity = O(n²)
        {
            int min=i;
            for(int j=i+1;j<n;j++)
            {
                if(arr[min]>arr[j])
                {
                    min=j;
                }
            }
            if(min!=i)
            {
                swap(i,min);
                show();
            }
        }
    }
    void insertion()    // time complexity = O(n²) average case
    {
        for(int i=1;i<n;i++)  //best case = O(n)
        {
            int val=arr[i];
            int hole=i;
            while(hole>0 && arr[hole-1]>val)
            {
                arr[hole]=arr[hole-1];
                hole--;
            }
            arr[hole]=val;
        }
    }
    void show()
    {
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    int ch;
    char y;
    do
        {
            cout<<"\nEnter 1 for Bubble Sorting"
            <<"\nEnter 2 for Selection Sorting"
            <<"\nEnter 3 for Insertion Sorting"<<endl;
            cin>>ch;
    switch(ch)
    {
    case 1:
        {
            sorting obj;
            obj.get();
            obj.bubble();
            cout<<"\nFinal Result : ";
            obj.show();
            break;
        }
    case 2:
        {
            sorting obj;
            obj.get();
            obj.selection();
            cout<<"\n Final Result : ";
            obj.show();
            break;
        }
    case 3:
        {
            sorting obj;
            obj.get();
            obj.insertion();
            cout<<"\n Final Result : ";
            obj.show();
            break;
        }
    }
    cout<<"\nEnter y to continue : ";
    cin>>y;
        }while(y=='y'||y=='Y');
    return 0;
}
