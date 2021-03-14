//We are given an array and a number k, we need to find maximums of all subarrays of size k.
#include<iostream>
#include<deque>
using namespace std;
void getMax(int* arr, int n, int k)
{
    deque<int> dq;
    for(int i = 0; i < k; i++)
    {
        while(!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    for(int i = k; i < n; i++)
    {
        cout<<arr[dq.front()]<<" ";
        while(!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }
        while(!dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout<<arr[dq.front()]<<" ";
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    int k;
    cin>>k;
    getMax(arr, n, k);
    return 0;
}