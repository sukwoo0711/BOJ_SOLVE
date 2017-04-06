#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int n, k, m, dest;
vector<int > adj[200001];
int visit[200001];

void bfs(int st)
{
	queue <int> q;
	visit[st] = 1;
	q.push(st);
	int times = 0;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < adj[now].size(); i++)
		{
			int next = adj[now][i];
			if (visit[next] == 0)
			{
				visit[adj[now][i]] = visit[now]+1;
				q.push(adj[now][i]);
			}
		}
		
	}
}
int main()
{
	cin >> dest >> k >> m;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < k; j++)
		{
			int t;
			cin >> t;
			adj[100000 + i].push_back(t);
			adj[t].push_back(100000 + i);
		}
	}
	bfs(1);
	printf("%d\n", (visit[dest]+1)/2);
	return 0;
}
