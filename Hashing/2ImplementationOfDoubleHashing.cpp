//Implementation of Double Hashing
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class MyHash
{
    int *table;
    int size;
    int n;
    public:
    MyHash(int a)
    {
        n = 0; 
        size = a;
        table = new int[a];
        for(int i = 0; i < a; i++)
            table[i] = -1;
    }
    int h1(int key)
    {
        return key % 7;
    }
    int h2(int key)
    {
        return 6 - (key % 6);
    }
    void insert(int x)
    {
        if(n == size)
        {
            cout<<"Hash Table is full"<<endl;
            return;
        }
        int probe = h1(x);
        int offset = h2(x);
        while(table[probe] != -1 && table[probe] != -2 && table[probe] != x)
        {
            probe = (probe + offset) % size;
        }
        if(table[probe] == x)
        {
            cout<<"Element already present"<<endl;
            return;
        }
        table[probe] = x;
        n++;
    }
    bool search(int x)
    {
        int probe = h1(x);
        int offset = h2(x);
        while(table[probe] != -1)
        {
            if(table[probe] == x)
                return true;
            probe = (probe + offset) % size;
        }
        return false;
    }
    void erase(int x)
    {
        int probe = h1(x);
        int offset = h2(x);
        while(table[probe] != -1)
        {
            if(table[probe] == x)
            {
                table[probe] = -2;
            }
            probe = (probe + offset) % size;
        }
    }
    void display()
    {
        for(int i = 0; i < size; i++)
        {
            cout<<table[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    MyHash mh(7);
    mh.insert(49);
    mh.insert(63);
    mh.insert(56);
    mh.insert(52);
    mh.insert(54);
    mh.insert(48);
    //mh.display();
    if(mh.search(56))
        cout<<"Yes 56 is present"<<endl;
    else
        cout<<"No 56 is not present"<<endl;
    //mh.erase(56);
    mh.display();
    if(mh.search(56))
        cout<<"Yes 56 is present"<<endl;
    else
        cout<<"No 56 is not present"<<endl;
    return 0;
}