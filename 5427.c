#include <queue>
#include <cstdio>
#include <iostream>
#define EMPTY '.'
#define WALL '#'
#define SANGUN '@'
#define FIRE '*'
using namespace std;
int n, m;
char map[1001][1001];
int visit[1001][1001];
queue <pair<int, int>> mq;	//상근이 큐
queue <pair<int, int>> fq;	//불 큐
int bfs()
{
	/*
		두개의 큐를 각각 돌린다.
		단, 큐가 빌때까지 돌리면 한쪽이 시작하기도전에 끝이나므로
		서로 큐의 size만큼만 돌린다.
	*/
	bool escape = false;
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	while (1)
	{
		int fqsize = fq.size();
		int mqsize = mq.size();
		//printf("FQ %d MQ %d\n", fqsize, mqsize);
		if (fqsize == 0 && mqsize == 0)
			break;
		while (mqsize--)
		{
			//사람큐의 정보 획득
			int px = mq.front().first;
			int py = mq.front().second;
			mq.pop();
			//printf("%d %d\n", px, py);
			if (map[px][py] != SANGUN)
				continue;
			//종료조건 체크
			if (px == 0 || px == n - 1 || py == 0 || py == m - 1)
			{
				escape = true;
				return visit[px][py];
			}
			//4방향으로 전개
			for (int i = 0; i < 4; i++)
			{
				int nx = px + dx[i];
				int ny = py + dy[i];
				if (map[nx][ny] == EMPTY)	//오직 빈 공간일시만 진행할 수 있다.
				{
					if (visit[nx][ny] == 0)
					{
						map[nx][ny] = SANGUN;
						visit[nx][ny] = visit[px][py] + 1;
						mq.push(make_pair(nx, ny));
					}
				}
			}
		}

		while (fqsize--)
		{
			int fx = fq.front().first;
			int fy = fq.front().second;
			fq.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = fx + dx[i];
				int ny = fy + dy[i];
				if (map[nx][ny] == EMPTY || map[nx][ny] == SANGUN)
				{
					map[nx][ny] = FIRE;
					visit[nx][ny] = -1;
					map[fx][fy] = WALL;
					fq.push(make_pair(nx, ny));
				}
			}
		}
	}
	return -1;
}
int main()
{
	int tc;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d %d", &m, &n);
		//초기화를 위해 배열에 원소를 전부 pop한다.
		while (!mq.empty())
		{
			mq.pop();
		}
		while (!fq.empty())
		{
			fq.pop();
		}

		//맵,visit배열 초기화
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				visit[i][j] = 0;
				map[i][j] = EMPTY;
			}

		//맵 정보를 입력받는다.
		for (int i = 0; i < n; i++)
			scanf("%s", &map[i]);
		
		//불의 초기값과 사람의 초기위치를 큐에 따로 저장한다.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == SANGUN) {
					mq.push(make_pair(i, j));
					visit[i][j] = 1;	//상근이는 혼자이므로 체크해도 무방하다.
				}
				if (map[i][j] == FIRE)
					fq.push(make_pair(i, j));
			}
		}
		int res = bfs();
		if (res == -1)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", res);
	}
}
