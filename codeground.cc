#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>
/*
2
3 3 1
3 1 1
2 3 2
1 2 5
1
5 6 3
1 3 1
1 2 2
2 3 3
2 4 5
4 5 6
3 5 4
1 2 4
*/
using namespace std;
#define INF 999999999
struct p {
	int to;
	int cost;
	p(int a, int b) : to(a), cost(b) {};
};
struct cmp {
	bool operator()(p p1, p p2)
	{
		return p1.cost < p2.cost;
	}
};
int sum = 0;
vector <p> adj[100001];
vector <int> loc;
vector <int> answer(100001, INF);
int tc, n, m, k;
void dijkstra(int n)
{
	vector <int> dist(5000,INF);
	priority_queue<p, vector<p>, cmp> pq;
	dist[n] = 0;
	pq.push(p(n, 0));
	while (!pq.empty())
	{
		int nxt = pq.top().to;
		int nxtl = pq.top().cost;
		pq.pop();
		if (dist[nxt] < nxtl)
			continue;
		for (int i = 0; i < adj[nxt].size(); i++)
		{
			int v = adj[nxt][i].to;
			int w = adj[nxt][i].cost;
			if (dist[v] > dist[nxt] + w) {
				dist[v] = dist[nxt] + w;
				pq.push(p(v, dist[v]));
				if (answer[v] > dist[v]) {
					answer[v] = dist[v];
					sum += v;
				}
			}
		}
	}
}
int main()
{
	scanf("%d", &tc);
	while (tc--)
	{
		int sum2 = 0;
		int u, v, w;
		scanf("%d %d %d", &n, &m, &k);
		loc.resize(k);
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &u, &v, &w);
			adj[u].push_back(p(v, w));
			adj[v].push_back(p(u, w));
		}
		for (int i = 0; i < k; i++) {
			scanf("%d", &loc[i]);
			sum += loc[i];
		}
		sort(loc.begin(), loc.end());
		for (int i = 0; i < loc.size(); i++) {
			dijkstra(loc[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			if (answer[i] != INF)
				sum2 += answer[i];
		}
		for (int i = 1; i <= n; i++)
		{
			printf("dist[%d] = %d\n", i, answer[i]);
		}
		printf("%d\n", sum);
		printf("%d\n", sum2);
	}
}

/*
vector <vertex> adj[2000];
vector <int> dist(2000,INF);
vector <int> previous(2000, -1);
void dijkstra(int start)
{
    priority_queue<vertex, vector<vertex>, cmp> pq;
    dist.assign(2000, INF);
    previous.assign(2000, -1);
    dist[start] = 0;
    for (int i = 1; i <= n && i != start; i++)
        pq.push(vertex(i, dist[i]));
    pq.push(vertex(start, dist[start]));
    while (!pq.empty())
    {
        int curr = pq.top().to;
        int curr_weight = pq.top().weight;
        pq.pop();
 
        if (dist[curr] < curr_weight)
            continue;
        for (int i = 0; i < adj[curr].size(); i++)
        {
            int to = adj[curr][i].to;
            int weight = adj[curr][i].weight;
            if (dist[to] > dist[curr] + weight)
            {
                dist[to] = dist[curr] + weight;
                pq.push(vertex(to, dist[to]));
                previous[to] = curr;
            }
        }
    }
}
*/
