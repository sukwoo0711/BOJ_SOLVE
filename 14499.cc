#include <iostream>
#include <cstdio>
#include <vector>
int sx, sy, n, m, cmd_count,cmd;


int dice[7];
int map[21][21];
//동 서 남 북 1 2 4 3 
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int tx, ty;
void print()
{
	printf("[%d]\n", dice[3]);
	printf("[%d][%d][%d][%d]\n", dice[1], dice[2], dice[6], dice[5]);
	printf("[%d]\n", dice[4]);
}
void roll(int dir)
{
	//동서남북 어디로굴리던 주사위는 4개의 위치만바뀜
	int temp[5] = { 0, };
	/*
	dice 전개도(1의 뒷면은 6, 앞면과 뒷면의 총 합은 7이므로
	[3]
	[1][2][6][5]
	[4]
	*/
	if (dir == 1)//동쪽으로 shift
	{
		temp[1] = dice[1];
		temp[2] = dice[2];
		temp[3] = dice[6];
		temp[4] = dice[5];

		dice[5] = temp[1];
		dice[1] = temp[2];
		dice[2] = temp[3];
		dice[6] = temp[4];

	}
	else if (dir == 2)	//서쪽으로 shift
	{

		temp[1] = dice[1];
		temp[2] = dice[2];
		temp[3] = dice[6];
		temp[4] = dice[5];

		dice[2] = temp[1];
		dice[6] = temp[2];
		dice[5] = temp[3];
		dice[1] = temp[4];
	}
	else if (dir == 3)//북
	{
		temp[1] = dice[3];
		temp[2] = dice[1];
		temp[3] = dice[4];
		temp[4] = dice[6];

		dice[6] = temp[1];
		dice[3] = temp[2];
		dice[1] = temp[3];
		dice[4] = temp[4];
	}
	else if (dir == 4)
	{
		temp[1] = dice[3];
		temp[2] = dice[1];
		temp[3] = dice[4];
		temp[4] = dice[6];

		dice[1] = temp[1];
		dice[4] = temp[2];
		dice[6] = temp[3];
		dice[3] = temp[4];
	}
}
int main()
{
	scanf("%d %d %d %d %d", &n, &m, &sx, &sy, &cmd_count);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);
	tx = sx;
	ty = sy;
	dice[6] = map[sx][sy];
	for (int i = 0; i < cmd_count; i++)
	{
		scanf("%d", &cmd);
		int nx = tx + dx[cmd - 1];
		int ny = ty + dy[cmd - 1];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;
		roll(cmd);
		tx = nx;
		ty = ny;
		if (map[nx][ny] == 0)
			map[nx][ny] = dice[6];
		else
		{
			dice[6] = map[nx][ny];
			map[nx][ny] = 0;
		}
		printf("%d\n", dice[1]);
	}
	return 0;
}
