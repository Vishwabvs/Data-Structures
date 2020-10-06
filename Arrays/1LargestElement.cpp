//Given an arr[], find the index of largest element in the array
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	int max = arr[0];
	int index = 0;
	for(int i=1;i<n;i++)
		if(arr[i]>max)
		{
			max = arr[i];
			index = i;
		}
	cout<<"Index of largest element is : "<<index<<endl;
	return 0;
}
