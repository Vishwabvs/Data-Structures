//Given an array of size n, find the elements which occur more than n/k times

#include<iostream>
#include<unordered_map>
using namespace std;
void findEle(int* arr, int n, int k)
{
    unordered_map<int, int> m;
    for(int i = 0; i < n; i++)
        m[arr[i]] += 1;
    for(auto i: m)
    {
        if(i.second > (n / k))
            cout<<i.first<<" ";
    }
    cout<<endl;
}
void findEle2(int* arr, int n, int k)
{
    unordered_map<int,int> m;
    for(int i=0;i<n;i++){
        if(m.find(arr[i])!=m.end())
            m[arr[i]]++;
        else if(m.size()<k-1)
            m[arr[i]]=1;
        else
        {
            for(auto x:m){
                x.second--;
                if(x.second==0)
                    m.erase(x.first);}
        }
    }
    for(auto x:m){
        int count=0;
        for(int i=0;i<n;i++){
            if(x.first==arr[i])
                count++;
        
       }
        if(count>n/k)
            cout<<x.first<<" ";
    }
    cout<<endl; 
}
int main()
{
    int n, sum;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    cin>>sum;
    findEle2(arr, n, sum);
    return 0;
}