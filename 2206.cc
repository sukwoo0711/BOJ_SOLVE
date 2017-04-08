#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct p {
	int x, y, cnt;
	p(int a, int b, int c) : x(a), y(b), cnt(c) {};
};

char map[1001][1001];
int visit[1001][1001][2];
int N, M;

void input()
{
	for (int i = 0; i < N; i++)
		scanf("%s", &map[i]);
}
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
void bfs(int x, int y)
{
	queue <p> que;
	visit[x][y][0] = 1;
	que.push(p(x, y, 0));
	while (!que.empty())
	{
		int px = que.front().x;
		int py = que.front().y;
		int pz = que.front().cnt;
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = px + dx[i];
			int ny = py + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M)
				continue;
			//벽이 아닐경우
			if (map[nx][ny] == '0')
			{
				//방문한 적이 없는 경우 || 방문을 하긴했는데 최단거리가 아닐경우
				if (visit[nx][ny][pz] == 0 || visit[nx][ny][pz] > visit[px][py][pz]+1)
				{
					visit[nx][ny][pz] = visit[px][py][pz] + 1;
					que.push(p(nx, ny, pz));
				}
			}
			//벽을 만났을 경우
			else if (map[nx][ny] == '1')
			{
				//점프한 적이 있는지 없는지를 확인
				if (pz > 0)
					continue;
				//점프한 적이 없다면, 한번은 뛸 수 있으니까 뜀.
				//VISIT을 확인하지 않는 이유는, 단 한번밖에 뛸 수 없으니까 무조건 0인게 보장됨.
				visit[nx][ny][pz + 1] = visit[px][py][pz] + 1;
				que.push(p(nx, ny, pz + 1));
			}
		}
	}
}
int ans = 0;
int check(int a, int b)
{
	int retval = 0;
	if (a == 0 && b == 0)
		return -1;
	else
	{
		if (a == 0)
			return b;
		else if (b == 0)
			return a;
		else
			a > b ? retval = b : retval =  a;
		return retval;
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	input();
	bfs(0, 0);
	printf("%d\n", check(visit[N - 1][M - 1][0], visit[N - 1][M - 1][1]));
	return 0;
}
