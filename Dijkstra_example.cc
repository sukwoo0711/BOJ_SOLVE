///(nodes,edges,start)
/*
6 8 1
1 2 1
1 3 7
2 3 5
2 5 9
3 4 2
4 5 2
4 6 3
5 6 4

*/
#include <cstdio>
#include <iostream>
#include <queue>
#define MAX 5000	//unfixed limit
#define INF 999999999 //unlimited max value (for update)

using namespace std;
struct node{
	int node_to;	//to
	int node_weight; //weight || cost
	
					 //default constructor
	node(int elements1, int elements2) : node_to(elements1), node_weight(elements2) {};
};

//overload the cmp class
struct cmp {
	bool operator()(node n1, node n2)
	{
		return n1.node_weight < n2.node_weight;
	}
};

int num_of_nodes, num_of_edges, start;
vector<node> adj[MAX];
int dist[MAX];
void dijkstra(int startVertexNum)
{
	//priority que will pop the data as CMP declaed
	priority_queue<node, vector<node>, cmp> pq;
	for (int i = 1; i <= num_of_nodes; i++)
	{
		pq.push(node(i, INF));	//insert the data
	}
	dist[startVertexNum] = 0;	//start point's distance always be 0
	pq.push(node(startVertexNum, dist[startVertexNum]));
	while (!pq.empty())
	{
		int nextvisit = pq.top().node_to;
		int Cost_to_next = pq.top().node_weight;
		pq.pop();

		//if dist[next] is small than cost,
		//a better route is available
		if (dist[nextvisit] < Cost_to_next)
			continue;
		
		//check the other nodes at nextvisit node;
		for (int i = 0; i < adj[nextvisit].size(); i++)
		{
			node another_node = adj[nextvisit][i];
			if (dist[another_node.node_to] > dist[nextvisit] + another_node.node_weight)
			{
				dist[another_node.node_to] = dist[nextvisit] + another_node.node_weight;
				pq.push(node(another_node.node_to, dist[another_node.node_to]));
			}
		}
	}
}
int main()
{
	scanf("%d %d %d", &num_of_nodes, &num_of_edges, &start);
	//receive all edges data;
	for (int i = 0; i < num_of_edges; i++)
	{
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		//link each nodes (cause It would be a bi-direction graph
		adj[from].push_back(node(to, cost));
		adj[to].push_back(node(from, cost));
	}
	for (int i = 1; i <= num_of_nodes; i++)
		dist[i] = INF;
	dijkstra(start);
	//check the data 
	for (int i = 1; i <= num_of_nodes; i++)
		printf("distance%d from %d => %d\n", i, start, dist[i]);
	return 0;
}
