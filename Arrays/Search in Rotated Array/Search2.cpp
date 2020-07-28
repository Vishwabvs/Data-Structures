//https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/
//Time: O(log N)

#include<iostream>
using namespace std;

int binary_search(int *arr,int low,int high,int key)
{
    if(low>high) return -1;
    int mid = (low+high)/2;

    if(key == arr[mid]) return mid;

    if(arr[mid]>key && arr[low]<=key)
        return binary_search(arr,low,mid-1,key);
    else
        return binary_search(arr,mid+1,high,key);
}
int findpivot(int *arr,int low,int high)
{
    if(low>high) return -1;

    if(low == high) return low;

    int mid = (low+high)/2;

    if(mid<high && arr[mid]>arr[mid+1])
        return mid;
    if(mid>low && arr[mid]<arr[mid-1])
        return mid-1;
    if(arr[low]>=arr[mid])
        return findpivot(arr,low,mid-1);
    else
        return findpivot(arr,mid+1,high);
}

int pivotedsearch(int *arr,int n,int key)
{
    int pivot = findpivot(arr,0,n-1);

    if(pivot == -1)
        return binary_search(arr,0,n-1,key);
    if(arr[pivot] == key) return pivot;

    if(arr[0]<=key)
        return binary_search(arr,0,pivot-1,key);
    else
        return binary_search(arr,pivot+1,n-1,key);

}

int main()
{
    int n=9,key=10,flag=0;
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    cout<<pivotedsearch(arr,n,key)<<endl;

}
