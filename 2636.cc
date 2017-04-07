#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
char map[101][101];

bool chk[101][101];
void dfs(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= M|| chk[x][y])
		return;
	chk[x][y] = true;
	if (map[x][y] == 0)
		map[x][y] = 2;
	if (map[x + 1][y] == 0)
		dfs(x + 1, y);
	if (map[x - 1][y] == 0)
		dfs(x - 1, y);
	if (map[x][y - 1] == 0)
		dfs(x, y - 1);
	if (map[x][y + 1] == 0)
		dfs(x, y + 1);
	//map[x][y] = 2;

}
void flood_fill(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= M || chk[x][y])
		return;
	chk[x][y] = true;
	if (map[x][y] == 0)
		map[x][y] = 2;
	if (map[x + 1][y] != 1)
		flood_fill(x + 1, y);
	if (map[x - 1][y] != 1)
		flood_fill(x - 1, y);
	if (map[x][y - 1] != 1)
		flood_fill(x, y - 1);
	if (map[x][y + 1] != 1)
		flood_fill(x, y + 1);
}
void print()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("[%d]", map[i][j]);
		}
		puts("");
	}
}
int main()
{
	int ans = 0;
	int clock = 0;
	queue <pair<int, int> > q;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for(int j=0;j<M;j++)
		scanf("%d", &map[i][j]);
	dfs(0, 0);
	int kk = max(N, M);
	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { 1,-1,0,0 };
	int last = 0;
	for (int k = 0; k < kk; k++)
	{
		//print();
		bool change = false;
		clock++;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				int dup = 0;
				if (map[i][j] == 1)
				{
					change = true;
					for (int d = 0; d < 4; d++)
					{
						int nx = i + dx[d];
						int ny = j + dy[d];
						if (map[nx][ny] == 2)
							dup++;	
					}
					if (dup >= 1)
						q.push(make_pair(i, j));
					
				}
			}
		}
		for (int li = 0; li < N; li++)
			for (int lj = 0; lj < M; lj++)
				if (map[li][lj] == 1)
					last++;
		if (last != 0)
			ans = last;
		if (!change)
			break;
		else
			last = 0;
		while (!q.empty())
		{
			int px = q.front().first;
			int py = q.front().second;
			q.pop();
			map[px][py] = 2;
		}
		//dfs re;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				chk[i][j] = false;
		flood_fill(0, 0);

	}
	//print();
	printf("%d\n", clock-1);
	printf("%d\n", ans);
	return 0;
}
