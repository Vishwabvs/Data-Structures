#include<bits/stdc++.h>
using namespace std;
class Graph
{
	int V;
	vector<int> *adj;
	stack<int> s;
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
	void fill_stack(int src, bool* visited)
	{
		visited[src] = true;
		vector<int>::iterator i;
		for(i = adj[src].begin(); i != adj[src].end(); i++)
		{
			if(visited[*i] == false)
				fill_stack(*i, visited);
		}
		s.push(src);
	}

	void dfs()
	{
		bool *visited = new bool[V];
		for(int i=0;i<V;i++)
			visited[i] = false;
		for(int i=0;i<V;i++)
		{
			if(visited[i] == false)
				fill_stack(i, visited);
		}
	}

	void dfs_util(int src, vector<int> *adj, bool* visited)
	{
		visited[src] = true;
		cout<<src<<" ";

		vector<int>::iterator i;
		for(i = adj[src].begin(); i != adj[src].end(); i++)
		{
			if(visited[*i] == false)
				dfs_util(*i,adj, visited);
		}
	}
	void countSCC()
	{
		bool* visited = new bool[V];
		for(int i=0;i<V;i++)
			visited[i] = false;

		dfs();

		vector<int>::iterator j;
		vector<int> *adj_rev = new vector<int>[V];
		for(int i=0;i<V;i++)
		{
			for(j = adj[i].begin(); j != adj[i].end(); j++)
			{
				adj_rev[*j].push_back(i);
			}
		}

		int count = 0;
		while(!s.empty())
		{
			int x = s.top();
			s.pop();
			while(visited[x] == false)
			{
				dfs_util(x, adj_rev,visited);
				cout<<endl;
				count++;
			}
		}
		cout<<"Number of connected components are: "<<count<<endl;
	}
};
int main()
{
	Graph g(5);
	g.addEdge(0, 2);
	g.addEdge(0, 3);
	g.addEdge(1, 0);
	g.addEdge(2, 1);
	g.addEdge(3, 4);

	g.countSCC();
	return 0;
}