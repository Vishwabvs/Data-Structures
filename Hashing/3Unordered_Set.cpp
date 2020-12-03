//Using unordered set in C++

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    unordered_set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(5);
    s.insert(15);
    for(auto it = s.begin(); it != s.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    cout<<s.size()<<endl;
    cout<<endl;
    cout<<"Usage of find():"<<endl;
    if(s.find(15) == s.end()) //returns s.end() if not present
        cout<<"Not Found"<<endl;
    else
        cout<<"Found "<<*s.find(15)<<endl;  //s.find returns iterator to the element if present

    cout<<endl;
    cout<<"Usage of count():"<<endl;
    if(s.count(15))
        cout<<"Found"<<endl;
    else
        cout<<"Not Found"<<endl;

    cout<<endl;
    cout<<"Usage of erase()"<<endl;
    s.erase(15);
    for(auto it = s.begin(); it != s.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    cout<<s.size()<<endl;

    /*auto it = s.find(15);
    s.erase(it);
    for(auto it = s.begin(); it != s.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    cout<<s.size()<<endl;*/
    s.erase(s.begin(), s.end()); //erases all the elements from s.begin() to s.end()

    s.clear();
    cout<<s.size()<<endl;
    return 0;
}