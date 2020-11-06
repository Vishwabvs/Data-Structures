//https://www.geeksforgeeks.org/find-a-mother-vertex-in-a-graph/

#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	vector<int>* adj;
public:
	Graph(){}
	Graph(int v)
	{
		V = v;
		adj = new vector<int>[v];
	}
	void addEdge(int src, int dest)
	{
		adj[src].push_back(dest);
	}
	void dfs_util(int src, bool* visited)
	{	
		visited[src] = true;
		vector<int>::iterator i;
		for(i = adj[src].begin(); i != adj[src].end(); i++)
		{
			if(visited[*i] == false)
				dfs_util(*i, visited);
		}
	}

	int find_mother()
	{
		for(int i=0;i<V;i++)
		{
			int flag = 0;
			bool* visited = new bool[V];

			dfs_util(i, visited);

			for(int j = 0;j<V;j++)
				if(visited[j] == false)
					flag = 1;
			if(flag == 0)
				return i;
		}
		return -1;
	}
};
int main()
{
	Graph g(5); 
    g.addEdge(0, 3); 
    g.addEdge(3, 4); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(1, 0); 
    //g.addEdge(5, 6); 
    //g.addEdge(5, 2); 
    //g.addEdge(6, 0);

    cout<<g.find_mother()<<endl;
    return 0;
}