#include <queue>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int n,k;
int visit[200001];
int bfs(int s)
{
	queue <int> q;
	int ncount = 0;
	visit[s] = 0;
	q.push(s);
	while (!q.empty())
	{
		int now = q.front();
	//	printf("now %d\n", now);
		if (now == k) {
		ncount = ncount + 1;
		}
		q.pop();
		if (now-1 >=0 && visit[now - 1] >= visit[now]+1)
		{
			visit[now - 1] = visit[now] + 1;
			q.push(now - 1);
		}
		if (now+1 <=100000 && visit[now + 1] >= visit[now]+1)
		{
			visit[now + 1] = visit[now] + 1;
			q.push(now + 1);
		}
		if (now*2<=100000 && visit[now * 2] >= visit[now]+1)
		{
			visit[now * 2] = visit[now] + 1;
			q.push(now * 2);
		}
	}
	return ncount;
}
int main()
{
	int ret;
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= 200000; i++)
		visit[i] = 9999999999;
	ret = bfs(n);
	printf("%d\n%d\n",visit[k],ret);
}
