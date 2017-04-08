#include <vector>
#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define BIBER 'D'
#define DOCHI 'S'
#define ROCK 'X'
#define WATER '*'
#define EMPTY '.'
using namespace std;

typedef pair<int, int> P;

int n, m;
int goalX, goalY, startX, startY;
char map[51][51];
int visit[51][51];
queue <P> bq;	//비버의 정보를 저장할 큐
queue <P> wq;	//물의 정보를 저장할 큐
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void bfs(int sx, int sy)
{
	visit[sx][sy] = 1;
	bq.push(make_pair(sx, sy));
	while (!bq.empty())
	{
		int bqsize = bq.size();
		int wqsize = wq.size();
		
		//물을 확장해보자
		while (wqsize--)
		{
			int wx = wq.front().first;
			int wy = wq.front().second;
			wq.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = wx + dx[i];
				int ny = wy + dy[i];
				//범위를 벗어나면 아무것도 하지말자
				if (nx < 0 || ny < 0 || nx >= n || ny >= m)
					continue;
				//물은 비어있으면 어디든지 갈 수 있으니까 아예 맵을 바꿔버리자.
				if (map[nx][ny] == EMPTY) {
					map[nx][ny] = WATER;
					wq.push(make_pair(nx, ny));
				}
			}
		}
		//비버도 움직여보자.
		while (bqsize--)
		{
			int bx = bq.front().first;
			int by = bq.front().second;
			bq.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = bx + dx[i];
				int ny = by + dy[i];
				//범위를 벗어나면 아무것도 하지말자
				if (nx < 0 || ny < 0 || nx >= n || ny >= m)
					continue;
				//범위 내에 있다면, 다음칸의 정보를 확인해보자.
				if (map[nx][ny] == EMPTY || map[nx][ny] == BIBER)
				{
					//다음칸이 갈 수 있는 공백이거나, 친구인 비버의 굴 이라면
					if (visit[nx][ny] == 0)
					{
						visit[nx][ny] = visit[bx][by] + 1;
						bq.push(make_pair(nx, ny));
					}
					//비버를 만났으니까 물의 상태를 볼것도없이 성공이다.
					if (nx == goalX && ny == goalY)
						return;
				}
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", &map[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == BIBER)
			{
				goalX = i; goalY = j;
			}
			if (map[i][j] == DOCHI)
			{
				startX = i; startY = j;
			}
			if (map[i][j] == WATER)
				wq.push(make_pair(i, j));
		}
	}

	bfs(startX, startY);
	visit[goalX][goalY] == 0 ? printf("KAKTUS\n") : printf("%d\n", visit[goalX][goalY] - 1);
	return 0;
}
