//Implementation of Chaining in Hashing
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct MyHash
{
	int m;
	list<int> *table;
	MyHash(int b)
	{
		m = b;
		table = new list<int>[b];
	}
	void insert(int x)
	{
		int key = x % m;
		table[key].push_back(x);
	}
	bool search(int x)
	{
		int key = x % m;
		for(auto i:table[key])
		{
			if(i == x)
				return true;
		}
		return false;
	}
	void remove(int x)
	{
		int key = x % m;
		table[key].remove(x);
	}
};
int main()
{
    MyHash mh(7);
	mh.insert(10);
    mh.insert(20);
    mh.insert(15);
    mh.insert(7);
    cout << mh.search(10) << endl;
    mh.remove(15);
    cout << mh.search(15);
	return 0;
}