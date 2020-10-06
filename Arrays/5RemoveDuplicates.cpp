//Given a sorted array, remove all duplicates and return new size
#include<iostream>
using namespace std;
int removeDuplicates(int *arr, int n)
{
	int count = 1;
	int next = 1;
	for(int i=1;i<n;i++)
	{
		if(arr[i]!=arr[i-1])
		{
			arr[next] = arr[i];
			//count++;
			next++;
		}
	}
	return next;
}
int main()
{
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	n = removeDuplicates(arr, n);
	cout<<"New Size: "<<n<<endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}
