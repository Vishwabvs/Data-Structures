#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	list<int> *adj;
public:
	list<int> topo;
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

	void topoSort_visit(int src, bool *visited)
	{
		visited[src] = true;

		list<int>::iterator i;
		cout<<"hello "<<src<<endl;
		for(i = adj[src].begin();i!=adj[src].end();i++)
		{
			if(visited[*i]==false)
			{
				cout<<"hi "<<src<<endl;
				topoSort_visit(*i, visited);	
			}
		}
		topo.push_front(src);
	}


	void topoSort()
	{
		bool *visited = new bool[V];
		for(int i=0;i<V;i++)
			visited[i] = false;

		for(int i=0;i<V;i++)
		{
			if(visited[i]==false)
			{
				//cout<<"oreyy"<<endl;
				topoSort_visit(i, visited);
			}
		}
	}
};

int main()
{
	Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 

    g.topoSort();

    for(int x: g.topo)
    	cout<<x<<" ";
    cout<<endl;
    return 0;
}