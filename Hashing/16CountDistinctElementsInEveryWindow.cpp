//Given an array, one needs to Count Distinct Elements In Every Window of Size K.
#include<iostream>
#include<unordered_map>
using namespace std;
void countDistinct(int *arr, int n, int k)
{
    unordered_map<int, int> m;
    int res = 0;
    for(int i = 0; i < k; i++)
    {
        m[arr[i]] += 1;
    }
    cout<<m.size()<<" ";
    for(int i = k; i < n; i++)
    {
        //m[arr[i - k]]--;
        if(m[arr[i - k]] == 1)
            m.erase(arr[i - k]);    
        else
            m[arr[i - k]]--;
        m[arr[i]]++;
        cout<<m.size()<<" ";
    }
    cout<<endl;
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
    countDistinct(arr, n, k);
    return 0;
}