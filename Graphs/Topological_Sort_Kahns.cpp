//https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/

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

	void computeIndegree(int *indegree)
	{
		list<int>::iterator j;
		for(int i = 0; i < V; i++)
		{
			for(j = adj[i].begin();j!=adj[i].end();j++)
			{
				indegree[*j]++;
			}
		}
	}

	vector<int> topoSort()
	{
		int indegree[V] = {0};
		computeIndegree(indegree);
		
		//for(int i=0;i<V;i++)
		//	cout<<indegree[i]<<" ";
		//cout<<endl;
		queue<int> q;
		int count = 0;
		vector<int> result;
		for(int i=0;i<V;i++)
		{
			if(indegree[i] == 0)
				q.push(i);
		}
		list<int>::iterator j;
		while(!q.empty())
		{
			int temp = q.front();
			result.push_back(temp);
			q.pop();
			for(j = adj[temp].begin();j!=adj[temp].end();j++)
			{
				if(--indegree[*j] == 0)
				{
					q.push(*j);
				}

			}
			count++;
		}
		return result;
	}


};

int main()
{
	Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(0, 3); 
    g.addEdge(2, 0); 
    g.addEdge(2, 1); 
    g.addEdge(1, 3); 

    vector<int> result = g.topoSort();
    for(int x: result)
    	cout<<x<<" ";
    cout<<endl;
    return 0;
}