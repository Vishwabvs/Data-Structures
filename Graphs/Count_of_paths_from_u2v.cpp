//https://www.geeksforgeeks.org/count-possible-paths-two-vertices/



#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	list<int> *adj;
public:
	Graph(){}
	Graph(int v)
	{
		V = v;
		adj = new list<int>[v];
	}
	void addEdge(int src, int dest)
	{
		adj[src].push_back(dest);
	}
	void path_u_to_v(int u, int v, int& path)
	{
		if(u == v)
		{
			path++;
			return;
		}
		int sum = 0;
		list<int>::iterator i;
		for(i = adj[u].begin();i!=adj[u].end();i++)
		{
			path_u_to_v(*i, v, path);
		}
	}
};

int main()
{
	Graph g(5); 
    g.addEdge(1, 2); 
    g.addEdge(1, 5); 
    g.addEdge(1, 3); 
    g.addEdge(2, 5); 
    g.addEdge(2, 4); 
    g.addEdge(3, 5);
    g.addEdge(4, 3); 
    int path = 0;
    g.path_u_to_v(1, 5, path);
    cout<<path<<endl;
    return 0;
}