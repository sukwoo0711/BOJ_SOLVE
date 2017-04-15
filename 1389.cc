#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector <int> person[101];
vector <int> dist;
void bfs(int k)
{
	queue <int> q;
	vector<int> check(101);
	check[k] = 0;
	q.push(k);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = 0; i < person[x].size(); i++)
		{
			if (check[person[x][i]] == 0)
			{
				dist[k] += check[x] + 1;
				check[person[x][i]] = check[x] + 1;
				q.push(person[x][i]);
			}
		}
	}
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	dist.resize(n+1);
	for (int i = 0; i < m; i++)
	{
		int to, from;
		scanf("%d %d", &from, &to);
		person[from].push_back(to);
		person[to].push_back(from);
	}
	
	for (int i = 1; i <= n; i++)
		bfs(i);

	int answer = 99999999;
	int kebin = 0;
	for (int i = n; i > 0; i--)
	{
		if (dist[i] <= answer) {
			answer = dist[i];
			kebin = i;
		}
	}
	printf("%d\n", kebin);
	return 0;
}
