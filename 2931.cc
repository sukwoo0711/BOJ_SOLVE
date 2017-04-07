#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int startX, startY, destX, destY;
char map[26][26];
int N, M,blk;
//위 아래 왼쪽 오른쪽 방향
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
char tools[7] = { '|','+','-','1','2','3','4' };
int fx, fy;
char tool;
void dfs(int x, int y,int direction, int getBlk, int fixCount)
{
	if (x < 0 || y < 0 || x >= N || y >= M)
		return;
	if (x == destX && y == destY)
	{
		if(getBlk >=blk)
		printf("%d %d %c\n", fx+1, fy+1, tool);
	}
	if (map[x][y] == '.')
	{
		if (fixCount == 1) {
			for (int i = 0; i < 7; i++)
			{
				map[x][y] = tools[i];
				fx = x; fy = y; tool = tools[i];
				dfs(x, y, direction, getBlk, fixCount - 1);
				map[x][y] = '.';
			}
		}
	}
	if (map[x][y] == '-')
	{
		if (direction == 1 || direction == 0)
			return;
		int nx = x + dx[direction];
		int ny = y + dy[direction];
		dfs(nx, ny,direction,getBlk + 1, fixCount);
	}
	if (map[x][y] == '|')
	{
		if (direction == 2 || direction == 3)
			return;
		int nx = x + dx[direction];
		int ny = y + dy[direction];
		dfs(nx, ny, direction, getBlk + 1, fixCount);
	}
	if (map[x][y] == '+')
	{
		bool blank = false;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < M)
				if (map[nx][ny] == '.')
					blank = true;
		}
		if (!blank||fixCount) 
		{
			int nx = x + dx[direction];
			int ny = y + dy[direction];
			dfs(nx, ny, direction, getBlk + 1, fixCount);
		}
	}
	if (map[x][y] == '1')
	{
		if (direction == 1 || direction == 3)
			return;
		if (direction == 0)
			dfs(x + dx[3], y + dy[3], 3, getBlk + 1, fixCount);
		else if (direction == 2)
			dfs(x + dx[1], y + dy[1], 1, getBlk + 1, fixCount);
	}
	if (map[x][y] == '2')
	{
		if (direction == 0 || direction == 3)
			return;
		if (direction == 1)
			dfs(x + dx[3], y + dy[3], 3, getBlk + 1, fixCount);
		else if (direction == 2)
			dfs(x + dx[0], y + dy[0], 0, getBlk + 1, fixCount);
	}
	if (map[x][y] == '3')
	{
		if (direction == 0 || direction == 2)
			return;
		if (direction == 1)
			dfs(x + dx[2], y + dy[2], 2, getBlk + 1, fixCount);
		else if (direction == 3)
			dfs(x + dx[0], y + dy[0], 0, getBlk + 1, fixCount);
	}
	if (map[x][y] == '4')
	{
		if (direction == 1 || direction == 2)
			return;
		if (direction == 0)
			dfs(x + dx[2], y + dy[2], 2, getBlk + 1, fixCount);
		else if (direction == 3)
			dfs(x + dx[1], y + dy[1], 1, getBlk + 1, fixCount);
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%s", &map[i]);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if(map[i][j] == 'M')
			{
				startX = i; startY = j;
			}
			else if (map[i][j] == 'Z')
			{
				destX = i; destY = j;
			}
			else if (map[i][j] != '.')
			{
				blk++;
			}
		}
	}
	blk = blk + 1;
	int startDir = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = startX + dx[i];
		int ny = startY + dy[i];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M)
			continue;
		if (map[nx][ny] != '.')
		{
			startDir = i;
			dfs(startX + dx[i], startY + dy[i], i, 0, 1);
			//break;
		}
	}
	return 0;
}
