//https://www.geeksforgeeks.org/transitive-closure-of-a-graph-using-dfs/

#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	vector<int>* adj;
	bool** trans;
public:
	Graph(){}
	Graph(int v)
	{
		V = v;
		adj = new vector<int>[v];
		trans = new bool* [v];
		for(int i = 0; i<V;i++)
		{
			trans[i] = new bool[V];
			for(int j = 0;j<V;j++)
			{
				trans[i][j] = false;
			}
		}
	} 
	void addEdge(int src, int dest)
	{
		adj[src].push_back(dest);
	}
	void dfs_util(int src, int dest)
	{	
		trans[src][dest] = true;
		vector<int>::iterator i;
		for(i = adj[dest].begin(); i != adj[dest].end(); i++)
		{
			if(trans[src][*i] == false)
				dfs_util(src, *i);
		}
	}

	void trans_closure()
	{
		for(int i=0;i<V;i++)
		{
			dfs_util(i,i);
		}

		for(int i=0;i<V;i++)
		{
			for(int j=0;j<V;j++)
			{
				cout<<trans[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	
};
int main()
{
	Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 

    g.trans_closure();
    return 0;
}