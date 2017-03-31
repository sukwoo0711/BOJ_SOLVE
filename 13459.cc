#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
//bfs solve
struct p {
	int rx, ry, bx, by;
	int count;
	p(int a, int b, int c, int d,int e) :rx(a), ry(b), bx(c), by(d), count(e) {};
};
queue <p> q;
char map[11][11];
bool visit[11][11][11][11];
int n, m;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int nrx, nry, nbx, nby;
bool result = false;

void bfs(int rx, int ry, int bx, int by, int cnt)
{
	bool finish = false;	
	visit[rx][ry][bx][by] = 1;
	q.push(p(rx, ry, bx, by, cnt));
	while (!q.empty() && !finish)
	{
		int prx = q.front().rx;	int pry = q.front().ry;	int pbx = q.front().bx;	int pby = q.front().by;	int count = q.front().count;
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int loop = 1;
			//red
			bool ok = true;
			bool red = false;
			bool blue = false;
			while (ok)
			{
				nrx = prx + dx[i] * loop;
				nry = pry + dy[i] * loop;
				if (map[nrx][nry] == '#')
				{
					nrx -= dx[i];
					nry -= dy[i];
					ok = false;
				}
				if (map[nrx][nry] == 'O')
				{
					red = true;
					break;
				}
				loop++;
			}
			loop = 1;
			ok = true;
			//blue
			while (ok)
			{
				nbx = pbx + dx[i] * loop;
				nby = pby + dy[i] * loop;
				if (map[nbx][nby] == '#')
				{
					nbx -= dx[i];
					nby -= dy[i];
					ok = false;
				}
				if (map[nbx][nby] == 'O')
				{
					blue = true;
					break;
				}
				loop++;
			}
			//ball clear check;
			if (red == true && blue == false)
				result = true;
			else if (blue == true)
				continue;
			/*
				clear condition = red = true, blue = false
				case0	1	2	3
				R	0	0	1	1	
				B	0	1	0	1
				case 0 : keep going
				case 1 : fail to clear => continue
				case 2 : clear =>result is 1
				case 3 : fail to clear => continue
			*/

			//merged ball check;
			if (nbx == nrx && nby == nry)
			{
				if (i == 0)	//direction => up
				{
					if (pbx > prx)
						nbx = nrx + 1;
					else
						nrx = nbx + 1;
				}
				else if (i == 1)	//direction =>down
				{
					if (pbx < prx)
						nbx = nrx - 1;
					else
						nrx = nbx - 1;
				}
				else if (i == 2)	//direction =>left
				{
					if (pby > pry)
						nby = nry + 1;
					else
						nry = nby + 1;
				}
				else if (i == 3)	//direction =>right
				{
					if (pby < pry)
						nby = nry - 1;
					else
						nry = nby - 1;
				}
			}
			//check visit
			if (visit[nrx][nry][nbx][nby] == 1)
				continue;
			if (count < 9) {
				visit[nrx][nry][nbx][nby] = 1;
				q.push(p(nrx, nry, nbx, nby, count + 1));
			}
		}
	}
}
int main()
{
	int rx, ry, bx, by;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", &map[i]);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 'B')
			{
				bx = i; by = j;
			}
			if (map[i][j] == 'R')
			{
				rx = i; ry = j;
			}
		}
	}
	bfs(rx, ry, bx, by, 0);
	if (result)
		printf("1\n");
	else
		printf("0\n");
	return 0;
}
