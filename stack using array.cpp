#include<iostream>

using namespace std;

class stack
{
    int tos,capacity;
    int *arr;
public:
    stack(int capacity)
    {
        this->capacity=capacity;
        arr=new int[this->capacity];
        tos=-1;
    }
    void push(int x)
    {
        if(tos==capacity-1)
        {
            cout<<"Stack is Full"<<endl;
            return;
        }
        tos++;
        arr[tos]=x;
    }
    void pop()
    {
        if(tos<0)
        {
            cout<<"Stack is Empty"<<endl;
            return;
        }
        tos--;
    }
    int gettos()
    {
        return arr[tos];
    }
    int get_size()
    {
        return tos+1;
    }
    int disp()
    {
        for(int i=0;i<tos;i++)
        {
            cout<<arr[i]<<"->";
        }
        cout<<arr[tos]<<endl;
    }
};

int main()
{
    int capacity;
	cout<<"Enter Capacity\n";
	cin>>capacity;
	int ch;
	stack s(capacity); int x;
	do
	{
		cout<<"Enter choice \n1.Push \n2.Pop \n3.GetTop \n4.Display \n5.GetSize \n6.Exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:cout<<"Enter Element\n";
					cin>>x;
					s.push(x);
					break;
			case 2:cout<<"Element Deleted\n";
					s.pop();
					break;
			case 3:cout<<"The element at front is:"<<s.gettos()<<endl;
					break;
            case 4:cout<<"Display :"<<s.disp()<<endl;
                    break;
			case 5:cout<<"Current size is:"<<s.get_size()<<endl;
					break;
			case 6:exit(0);
			default:break;
		}
		cout<<"----------------------------------------------------------------------------------------------------------------\n";
		}
	while(true);

    return 0;
}
