#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#define INF 99999999
using namespace std;

int res=INF;
int k, n, m;
int c[201][201];
int visit[201][201][31];
struct p {
	int x, y, count;
	p(int a, int b, int c) : x(a), y(b), count(c) {};
};

void input()
{
	scanf("%d", &k);
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &c[i][j]);
}

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int jx[8] = { -1,-2,-2,-1,1,2,2,1 };
int jy[8] = { -2,-1,1,2,-2,-1,1,2 };

void bfs(int x, int y, int _k)
{
	queue<p> q;
	visit[x][y][_k] = 0;
	q.push(p(x, y, 0));
	while (!q.empty())
	{
		int px = q.front().x;
		int py = q.front().y;
		int jump = q.front().count;
		q.pop();
		if (px == n - 1 && py == m - 1) 
			return;
		//with no jump
		for (int i = 0; i < 4; i++)
		{
			int nx = px + dx[i];
			int ny = py + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if (c[nx][ny] == 0 && visit[nx][ny][jump] == 0)
			{
				visit[nx][ny][jump] = visit[px][py][jump] + 1;
				q.push(p(nx, ny, jump));
			}
		}
		//with jump
		for (int i = 0; i < 8 && jump<k; i++)
		{
			int nx = px + jx[i];
			int ny = py + jy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (c[nx][ny] == 0 && visit[nx][ny][jump+1] ==0)
			{
				visit[nx][ny][jump + 1] = visit[px][py][jump] + 1;
				q.push(p(nx, ny, jump + 1));
			}
		}
	}
}

int main()
{
	input();
	bfs(0, 0, 0);
	for (int i = 0; i <= k; i++) 
		if (visit[n - 1][m - 1][i] != 0) 
			res = min(res, visit[n - 1][m - 1][i]);
	
	if (res == INF)
		puts("-1");
	else
		printf("%d\n", res);
	return 0;
}
