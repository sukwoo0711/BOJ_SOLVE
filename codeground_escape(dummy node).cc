#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int tc;
int u, v, w, res;
typedef pair<int, int> P;
struct cmp {
	bool operator()(P n1,P n2)
	{
		return n1.second > n2.second;
	}
};
vector <pair<int, int>> adj[100010];
vector <int> shelter(100010, -1);
vector <int> dist(100010, 99999999);
int esc_sum = 0;
void dijk(int root)
{
	priority_queue<P, vector<P>, cmp> pq;
	dist[root] = 0;
	int loc = 0;
	pq.push(make_pair(root, 0));
	while (!pq.empty())
	{
		int now = pq.top().first;
		int ndist = pq.top().second;
		pq.pop();
		
		if (dist[now] < ndist)
			continue;
		//printf("now = %d dist %d\m", now, ndist);
		for (int i = 0; i < adj[now].size(); i++)
		{
			int next = adj[now][i].first;
			int nextdist = adj[now][i].second;
			if (dist[next] > dist[now] + nextdist)
			{
				dist[next] = dist[now] + nextdist;
				pq.push(make_pair(next, dist[next]));
			}
		}
	}
}
int main()
{
	int max_var = 0;
	scanf("%d", &tc);
	for (int i = 1; i <= tc; i++)
	{
		int vnum, edge, stnum;
		scanf("%d %d %d", &vnum, &edge, &stnum);
		for (int i = 0; i < edge; i++)
		{
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			max_var = max(v, max(max_var, u));
			adj[u].push_back(make_pair(v, w));
			adj[v].push_back(make_pair(u, w));
		}
		for (int i = 0; i < stnum; i++)
		{
			int esc;
			scanf("%d", &esc);
			adj[100001].push_back(make_pair(esc, 0));
			shelter[esc] = 1;
		}
		dijk(100001);
		for (int i = 1; i <= max_var; i++)
		{
			printf("dist[%d] = %d\n",i, dist[i]);
			printf("shelter[%d] = %d\n", i, shelter[i]);
		}
		printf("Case %d", tc);
		printf("%d\n", esc_sum);
	}
	return 0;
}
