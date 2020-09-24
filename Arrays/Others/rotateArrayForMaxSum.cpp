//https://www.geeksforgeeks.org/find-maximum-value-of-sum-iarri-with-only-rotations-on-given-array-allowed///Given an array, only rotation operation is allowed on array. We can rotate the array as many times as we want. Return the maximum //possbile of summation of i*arr[i].







#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n = 4;
	int arr[] = {1, 20, 2, 10};
			
	int arrSum = 0;
	int currVal = 0;
	for(int i=0;i<n;i++)
	{
		arrSum = arrSum + arr[i];
		currVal = currVal + (i*arr[i]);
	}
	int maxValue = currVal;
	for(int j=1;j<n;j++)
	{
		currVal = currVal + arrSum-(n*arr[n-j]);
		if(currVal>maxValue)
			maxValue = currVal;
	}
	cout<<maxValue<<endl;
}