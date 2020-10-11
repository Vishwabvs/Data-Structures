//Given the values of N and M, print M numbers in N-bonacci Sequence
#include<iostream>
using namespace std;
void printNbonacci(int n, int m)
{
	int arr[m];
	for(int i=0;i<n-1;i++)
		arr[i] = 0;
	arr[n] = arr[n-1] = 1;
	int sum=1;
	for(int i=n+1;i<m;i++)
	{
		arr[i] = arr[i-1]-arr[i-n-1]+arr[i-1];
	}
	for(int i=0;i<m;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
int main()
{
	int n, m;
	cin>>n>>m;
	printNbonacci(n, m);
	return 0;
}
