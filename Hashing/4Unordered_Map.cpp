//Unordered map in c++ STL

#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    unordered_map<string, int> m;
    m["GFG"] = 20;
    m["ide"] = 30;
    m.insert({"courses", 153});
    if(m.find("ide") == m.end())
    {
        cout<<"Not Found"<<endl;
    }
    else
    {
        cout<<m.find("ide")->second<<endl;
    }
    cout<<m.at("GG")<<endl;
    for(auto i:m)
    {
        cout<<i.first<<" "<<i.second<<endl;
    }
    return 0;
}