#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
/*
1
4 4
0 0 0 0
1 0 0 0
0 0 1 0
0 1 0 0
*/

int k, n, m;
int c[201][201];
int visit[201][201][31];
struct p {
	int x, y, count;
	p(int a, int b, int c) : x(a), y(b), count(c) {};
};
void init()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int x = 0; x < k; x++) {
				visit[i][j][x] = 99999999;
			}
		}
	}

}
void print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("[%d]", visit[i][j][0]);
		}
		puts("");
	}
	puts("");
}
void input()
{
	scanf("%d", &k);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &c[i][j]);

}
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int jx[8] = { -1,-2,1,2,1,2,2,1 };
int jy[8] = { -2,-1,1,2,-2,1,1,2 };
void bfs(int x, int y, int k)
{
	queue<p> q;
	visit[x][y][k] = 1;
	q.push(p(x, y, 0));
	while (!q.empty())
	{
		int px = q.front().x;
		int py = q.front().y;
		int jump = q.front().count;
		q.pop();
		//with no jump
		for (int i = 0; i < 4; i++)
		{
			int nx = px + dx[i];
			int ny = py + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;

			if (c[nx][ny]==0 && visit[nx][ny][jump] >=visit[px][py][jump]+1)
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
			if (c[nx][ny] == 0 && visit[nx][ny][jump] >= visit[px][py][jump] + 1)
			{
				visit[nx][ny][jump+1] = visit[px][py][jump] + 1;
				q.push(p(nx, ny, jump+1));
			}
		}
		print();
	}
}

int main()
{
	//input line();
	input();
	init();
	bfs(0, 0, 0);
	printf("%d\n", visit[n - 1][m - 1][0]);
	printf("%d\n", visit[n - 1][m - 1][1]);

	return 0;
}
