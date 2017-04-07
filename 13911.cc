#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 999999999
using namespace std;
int V, E, u, v, w;
vector <pair<int, int>> adj[10011];
typedef pair<int, int> P;
struct cmp {
	bool operator()(P p1, P p2)
	{
		return p1.second > p2.second;
	}
};
vector <int> mdist(10011, INF);
vector <int> sdist(10011, INF);
vector <bool> house(10011, true);
void mdijk(int s)
{
	priority_queue<P, vector<P>, cmp> pq;
	mdist[s] = 0;
	pq.push(make_pair(s, 0));
	while (!pq.empty())
	{
		P data = pq.top();
		pq.pop();
		if (mdist[data.first] < data.second)
			continue;
		for (int i = 0; i < adj[data.first].size(); i++)
		{
			int around = adj[data.first][i].first;
			int a_dist = adj[data.first][i].second;
			if (mdist[around] > mdist[data.first] + a_dist)
			{
				mdist[around] = mdist[data.first] + a_dist;
				pq.push(make_pair(around, mdist[around]));
			}
		}
	}
}
void sdijk(int s)
{
	priority_queue<P, vector<P>, cmp> pq;
	sdist[s] = 0;
	pq.push(make_pair(s, 0));
	while (!pq.empty())
	{
		P data = pq.top();
		pq.pop();
		if (sdist[data.first] < data.second)
			continue;
		for (int i = 0; i < adj[data.first].size(); i++)
		{
			int around = adj[data.first][i].first;
			int a_dist = adj[data.first][i].second;
			if (sdist[around] > sdist[data.first] + a_dist)
			{
				sdist[around] = sdist[data.first] + a_dist;
				pq.push(make_pair(around, sdist[around]));
			}
		}
	}
}
int main()
{
	scanf("%d %d", &V, &E);
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	//mac info / starbucks info
	int mnum, mlimit, mac,snum, slimit, star;
	scanf("%d %d", &mnum, &mlimit);
	for (int i = 0; i < mnum; i++)
	{
		scanf("%d", &mac);
		house[mac] = false;
		adj[10001].push_back(make_pair(mac, 0));
	}
	mdijk(10001);
	scanf("%d %d", &snum, &slimit);
	for (int i = 0; i < snum; i++)
	{
		scanf("%d", &star);
		house[star] = false;
		adj[10002].push_back(make_pair(star, 0));
	}
	sdijk(10002);
	
	int res = INF;
	for (int i = 1; i <= V; i++)
	{
		if (house[i] == false)
			continue;
		if (mdist[i] <= mlimit && sdist[i] <= slimit)
			res = min(res, mdist[i] + sdist[i]);
	}
	res == INF ? puts("-1") : printf("%d\n", res);
	return 0;
}
