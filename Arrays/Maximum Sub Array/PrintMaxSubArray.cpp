//https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
//Kadane's Algorithm
//Time: O(N)


#include<iostream>
#include<climits>
using namespace std;

int kadane(int *arr,int n)
{
    int maximum=arr[0],sum = 0,s=0,start,stop;
    for(int i=1;i<n;i++)
    {
        sum = max(arr[i], sum+arr[i]);
        if(sum > maximum)
        {
            maximum = sum;
            start = s;
            stop = i;
        }
        if(sum<0)
        {
            sum = 0;
            s = i+1;
        }
    }
    cout<<start<<" "<<stop<<endl;
    return maximum;
}

int main()
{
    int n = 2;
    int arr[] = {-1,2};
    cout<<kadane(arr,n);
    return 0;
}
