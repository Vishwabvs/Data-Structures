#include<iostream>
#define SIZE 20
using namespace std;
class Array
{
	int arr[SIZE];
	int n;
	public:
	Array()
	{
		for(int i=0;i<20;i++)
			arr[i] = 0;
		n = 0;
	}
	void input()
	{
		cout<<"Enter array size: ";
		cin>>n;
		cout<<"Enter array Elements: ";
		for(int i = 0;i<n;i++)
		{
			cin>>arr[i];
		}
		cout<<endl;
	}
	void display()
	{
		cout<<"Array Elements are: ";
		for(int i=0;i<n;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
	void insert(int index, int data)
	{
		if(n == SIZE)
		{
			cout<<"Array is full..Cant be inserted"<<endl;
		}
		else
		{
			for(int i=n-1;i>=index;i--)
			{
				arr[i+1] = arr[i];
			}
			arr[index] = data;
			n++;
			cout<<"Inserted Sucessfully";
		}
	}
	void remove(int data)
	{
		if(n == 0)
		{
			cout<<"Array is empty..Cant Delete!"<<endl;
			return;
		}
		int index, flag = 0;
		for(int i=0;i<n;i++)
		{
			if(arr[i] == data)
			{
				index = i;
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			cout<<"Data not found!"<<endl;
			return;
		}
		for(int i=index;i<n;i++)
		{
			arr[i] = arr[i+1];
		}
		arr[n] = 0;
		n--;
	}
	void reverse()
	{
		int temp = n-1, i = 0;
		while(i<temp)
		{
			int t = arr[i];
			arr[i] = arr[temp];
			arr[temp] = t;
			i++;
			temp--;
		}
	}
};

int main()
{
	Array arr;
	arr.input();
	arr.display();
	arr.insert(2, 23);
	arr.display();
	arr.remove(5);
	arr.display();
	arr.reverse();
	arr.display();
	return 0;
}