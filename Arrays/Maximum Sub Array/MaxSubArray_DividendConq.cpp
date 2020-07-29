//https://www.geeksforgeeks.org/maximum-subarray-sum-using-divide-and-conquer-algorithm/

//Divide and Conquer Algorithm
//Time: O(NlogN)
#include<iostream>
#include<climits>
using namespace std;

int maxcrosssubarray(int *arr,int low, int mid, int high)
{
    int sum = 0;
    int left_sum = INT_MIN;
    for(int i= mid;i>=low;i--)
    {
        sum = sum + arr[i];
        if(sum>left_sum)
            left_sum = sum;
    }
    sum = 0;
    int right_sum = INT_MIN;
    for(int i=mid+1;i<=high;i++)
    {
        sum = sum + arr[i];
        if(sum>right_sum)
            right_sum = sum;
    }
    return max(left_sum+right_sum,max(right_sum,left_sum));
}

int maxsubarray(int *arr, int low, int high)
{
    if(high<low)
        return 0;
    if(low == high)
        return arr[low];
    int mid = (low+high)/2;

    int left = maxsubarray(arr,low,mid);
    int right = maxsubarray(arr,mid+1,high);
    int cross = maxcrosssubarray(arr,low,mid,high);
    return max(max(left,right),cross);
}

int main()
{
    int n = 8;
    int arr[] = {-2, -3, -4, 1, 2, -1, -5, -3};
    cout<<maxsubarray(arr, 0, n-1);
    return 0;
}
