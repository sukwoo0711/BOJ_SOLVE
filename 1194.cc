#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
#pragma warning(disable:4996)
using namespace std;
int n, m;
char map[51][51];
int visit[51][51][27];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int mx, my;
struct p {
	int x;
	int y;
	int key;
	p(int a, int b, int c) : x(a), y(b), key(c) {};
};

int gogo(int x, int y)
{
	queue <p> q;
	visit[x][y][0] = 1;
	q.push(p(x, y, 0));
	while (!q.empty())
	{
		int px = q.front().x;
		int py = q.front().y;
		int pk = q.front().key;
	
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = px + dx[i];
			int ny = py + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (map[nx][ny] == '.' && visit[nx][ny][pk] == 0)
			{
				visit[nx][ny][pk] = visit[px][py][pk] + 1;
				q.push(p(nx, ny, pk));
			}
			else if (map[nx][ny] >= 'a' && map[nx][ny] <= 'f' && visit[nx][ny][pk] == 0)
			{
				int temp = pk;
				int knum = map[nx][ny] - 'a';
				//KEY ADD
				visit[nx][ny][pk | (1 << knum)] = visit[px][py][pk] + 1;
				q.push(p(nx, ny, pk | (1 << knum)));
			}
			else if (map[nx][ny] >= 'A' && map[nx][ny] <= 'F' && visit[nx][ny][pk] == 0)
			{
				int dnum = map[nx][ny] - 'A';
				int doorbit = 1 << dnum;
				//KEY OKAY = > GO
				if (pk&doorbit)
				{
					visit[nx][ny][pk] = visit[px][py][pk] + 1;
					q.push(p(nx, ny, pk));
				}
				//KEY NO = >CONTINUE;
				else
					continue;

			}
			else if (map[nx][ny] == '1')
				return visit[px][py][pk];
		}
	}
	return -1;
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", &map[i]);
	for(int i=0;i<n;i++)
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == '0')
			{
				mx = i;
				my = j;
				map[i][j] = '.';
			}
		}
	printf("%d\n", gogo(mx, my));
	return 0;
}
