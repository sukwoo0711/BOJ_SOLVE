#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int destX, destY, destZ;
struct p {
	int x, y;
	int row;
	p() {};
	p(int a, int b, int c) : x(a), y(b), row(c) {};
};
int n;
char map[51][51];
p check(int x, int y)
{
	p ret;
	//Down
	if (x + 2 <= n - 1) {
		if (map[x + 1][y] == 'B' && map[x + 2][y] == 'B') {
			ret = p(x + 1, y, 1);
			map[x][y] = map[x + 1][y] = map[x + 2][y] = '0';
		}
	}
	//RIGHT
	if (y + 2 <= n - 1) {
		if (map[x][y + 1] == 'B' && map[x][y + 2] == 'B') {
			ret = p(x, y + 1, 0);
			map[x][y] = map[x][y + 1] = map[x][y + 2] = '0';
		}
	}
	return ret;
}

int visit[51][51][51];
void bfs(int x, int y, int row)
{
	queue <p> q;
	q.push(p(x, y, row));
	while (!q.empty())
	{
		int px = q.front().x;
		int py = q.front().y;
		int prow = q.front().row;
		q.pop();

		if (px == destX && py == destY && prow == destZ)
			return;

		if (px > n || px <0 || py>n || py < 0)
			continue;
		if (prow == 0)
		{
			//위로 이동할때
			bool chk = true;
			if (px - 1 >= 0) {
				for (int i = -1; i <= 1; i++)
				{
					if (map[px - 1][py + i] == '1') {
						chk = false;
						break;
					}
				}

				if (visit[px - 1][py][prow] == 0 && chk)
				{
					visit[px - 1][py][prow] = visit[px][py][prow] + 1;
					q.push(p(px - 1, py, prow));
				}
			}
			chk = true;
			if (px + 1 <= n - 1) {
				for (int i = -1; i <= 1; i++)
				{
					if (map[px + 1][py + i] == '1') {
						chk = false;
						break;
					}
				}
				if (visit[px + 1][py][prow] == 0 && chk)
				{
					visit[px + 1][py][prow] = visit[px][py][prow] + 1;
					q.push(p(px + 1, py, prow));
				}
			}
			//누운상태로 >>이동
			if (map[px][py + 2] == '0')
			{
				if (visit[px][py + 1][prow] == 0)
				{
					visit[px][py + 1][prow] = visit[px][py][prow] + 1;
					q.push(p(px, py + 1, prow));
				}
			}
			if (map[px][py - 2] == '0')
			{
				if (visit[px][py - 1][prow] == 0)
				{
					visit[px][py - 1][prow] = visit[px][py][prow] + 1;
					q.push(p(px, py - 1, prow));
				}
			}
			if (px == n - 1 || px == 0 || py == n - 1 || py == 0)
				continue;
			bool test = false;
			for (int i = -1; i <= 1; i++)
				for (int j = -1; j <= 1; j++)
					if (map[px + i][py + j] == '1')
						test = true;
			if (test == false)
			{
				if (visit[px][py][1] == 0) {
					visit[px][py][1] = visit[px][py][0] + 1;
					q.push(p(px, py, 1));
				}
			}

		}

		else if (prow == 1)	//가로로 선 경우 이동할 수 있는 케이스를 찾아보자
		{
			//1 앞으로 이동할 때
			bool chk = true;
			if (py + 1 <= n - 1) {
				for (int i = -1; i <= 1; i++)
				{
					if (map[px + i][py + 1] == '1') {	//앞방향 통나무 이동공간 확인
						chk = false;
						break;
					}
				}
			}
			if(chk)
			{
				if (visit[px][py + 1][prow] == 0)
				{
				visit[px][py + 1][prow] = visit[px][py][prow] + 1;
				q.push(p(px, py + 1, prow));
				}
			}
			//1 뒤로 이동할때
			chk = true;
			if (py - 1 >= 0) {
				for (int i = -1; i <= 1; i++)
				{
					if (map[px + i][py - 1] == '1') {
						chk = false;
						break;
					}
				}
				if (visit[px][py - 1][prow] == 0 && chk)
				{
					visit[px][py - 1][prow] = visit[px][py][prow] + 1;
					q.push(p(px, py - 1, prow));
				}
			}
			//아래로 이동할때
			if (map[px + 2][py] == '0')
			{
				if (visit[px + 1][py][prow] == 0)
				{
					visit[px + 1][py][prow] = visit[px][py][prow] + 1;
					q.push(p(px + 1, py, prow));
				}
			}
			//위로 이동할때
			if (map[px - 2][py] == '0')
			{
				if (visit[px - 1][py][prow] == 0)
				{
					visit[px - 1][py][prow] = visit[px][py][prow] + 1;
					q.push(p(px - 1, py, prow));
				}
			}

			if (px == n - 1 || px == 0 || py == n - 1 || py == 0)
				continue;
			bool test = false;

			for (int i = -1; i <= 1; i++)
			{
				for (int j = -1; j <= 1; j++)
				{
					if (map[px + i][py + j] == '1')
					{
						//			printf("check arr %d %d\n", px + i, py + j);
						test = true;
					}
				}
			}
			if (test == false)
			{
				if (visit[px][py][0] == 0)
					visit[px][py][0] = visit[px][py][1] + 1;
				q.push(p(px, py, 0));
			}
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", map[i]);
	bool change = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 'E' && !change)
			{
				//down check;
				if (i + 1 <= n - 1)
				{
					if (map[i + 1][j] == 'E')
					{
						destX = i + 1;
						destY = j;
						destZ = 1;
						map[i][j] = map[i + 1][j] = map[i + 2][j] = '0';
					}
				}
				//right check;
				if (j + 2 <= n - 1)
				{
					if (map[i][j + 1] == 'E')
					{
						destX = i;
						destY = j + 1;
						destZ = 0;
						map[i][j] = map[i][j + 1] = map[i][j + 2] = '0';
					}
				}
				change = true;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 'B') {
				p recv = check(i, j);
				bfs(recv.x, recv.y, recv.row);
				break;
			}
		}
	}
	printf("%d\n", visit[destX][destY][destZ]);
	return 0;
}
