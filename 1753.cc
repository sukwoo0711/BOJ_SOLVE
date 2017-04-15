#include <iostream>
#include <queue>
#include <vector>
#define INF 99999999
using namespace std;
int v, e;
int start_vert;
typedef pair<int, int> P;
vector <pair<int, int>> adj[20001];
vector <int> dist(20001,INF);
struct cmp {
	bool operator()(P p1, P p2)
	{
		return p1.second > p2.second;
	}
};
void dijk(int start)
{
	priority_queue<P, vector<P>, cmp> pq;
	dist[start] = 0;
	pq.push(make_pair(start, dist[start]));
	while (!pq.empty())
	{
		int now = pq.top().first;
		int d = pq.top().second;
		pq.pop();
		if (d > dist[now])
			continue;
		for (int i = 0; i < adj[now].size(); i++)
		{
			int v = adj[now][i].first;
			int w = adj[now][i].second;
			
			if (dist[v] > dist[now] + w)
			{
				dist[v] = dist[now] + w;
				pq.push(make_pair(v, dist[v]));
			}
		}
	}
}
int main()
{
	scanf("%d %d", &v, &e);
	scanf("%d", &start_vert);
	for (int i = 0; i < e; i++)
	{
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		adj[from].push_back(make_pair(to, cost));
	}
	dijk(start_vert);
	for (int i = 1; i <= v; i++)
		dist[i] == INF ? printf("INF\n") : printf("%d\n", dist[i]);
}
