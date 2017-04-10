//BFS SOLVE
#include <iostream>
#include <queue>
#include <cstdio>
#include <vector>
using namespace std;
int n, loop;
bool check[1000001];
void bfs(int r)
{
	queue<int> q;
	q.push(r);
	while (!q.empty())
	{
		loop++;
		int qs = q.size();
		for (int i = 0; i < qs; i++) {

			int p = q.front();
			q.pop();
      if (p == 1)
				return;
			if (p - 1 >= 0 && !check[p-1]) {
				q.push(p - 1);
				check[p - 1] = true;
			}
			if (p % 2 == 0 && !check[p/2]){
				q.push(p / 2);
				check[p / 2] = true;
			}
			if (p % 3 == 0 && !check[p/3]){
				q.push(p / 3);
				check[p / 3] = true;
			}
		}
	}
}
int main()
{
	scanf("%d", &n);
	bfs(n);
	printf("%d\n", loop-1);
}
