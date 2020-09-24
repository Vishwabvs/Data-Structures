//https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
//Time: O(log N)
#include<iostream>
using namespace std;

int search(int *arr,int low,int high,int key)
{
    if(low>high)
        return -1;
    int mid = (low+high)/2;
    if(arr[mid] == key) return mid;
    if(arr[low]<=arr[mid])
    {
        if(arr[low]<=key && arr[mid]>=key)
            return search(arr,low,mid-1,key);
        else
            return search(arr,mid+1,high,key);
    }
    else
    {
        if(arr[mid]<=key && key<=arr[high])
            return search(arr,mid+1,high,key);
        else
            return search(arr,low,mid-1,key);
    }
}

int main()
{
	int n=9,key=10,flag=0;
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    cout<<search(arr,0,n-1,key)<<endl;
	return 0;
}
