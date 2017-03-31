#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
//dfs solve
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
void dfs(int rx, int ry, int bx, int by, int direction,int count)
{
	//rx,ry,bx,by,direction,count
	//end condition
	if (count > 9)
		return;
	if (result)	
		return;
	for (int i = 0; i < 4 && !result; i++)
	{
		int loop = 1;
		bool ok = true;
		bool red = false;
		bool blue = false;

		//red ball rolling 
		while (ok)
		{
			nrx = rx + dx[i] * loop;
			nry = ry + dy[i] * loop;
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
		//blue ball rolling
		while (ok)
		{
			nbx = bx + dx[i] * loop;
			nby = by + dy[i] * loop;
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
		//end check
		{
			if (red == true && blue == false)
				result = true;
			else if (blue == true)
				continue;
		}
		//merge check
		if (nbx == nrx && nby == nry)
		{
			if (i == 0)	//direction => up
			{
				if (bx > rx)
					nbx = nrx + 1;
				else
					nrx = nbx + 1;
			}
			else if (i == 1)	//direction =>down
			{
				if (bx < rx)
					nbx = nrx - 1;
				else
					nrx = nbx - 1;
			}
			else if (i == 2)	//direction =>left
			{
				if (by > ry)
					nby = nry + 1;
				else
					nry = nby + 1;
			}
			else if (i == 3)	//direction =>right
			{
				if (by < ry)
					nby = nry - 1;
				else
					nry = nby - 1;
			}
		}
		//find next case
		if(visit[nrx][nry][nbx][nby]==0)
			dfs(nrx, nry, nbx, nby, i, count + 1);
	}
}

int main()
{
	int rx, ry, bx, by;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", &map[i]);
	//find ball position
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
	
	//dfs search start
	dfs(rx, ry, bx, by, 0, 0);
	
	if (result)
		printf("1\n");
	else
		printf("0\n");
	return 0;
}
