#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, k;
vector <pair<int, int>> pos;
typedef pair<int, int> P;
bool cmp(const P &u, const P &v)
{
	if (u.first < v.first)
		return true;
	else if (u.first == v.first)
	{
		return u.second < v.second;
	}
	else
	{
		return false;
	}
}
int main()
{
	scanf("%d", &n);
	pos.resize(n);
	for (int i = 0; i < n; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		pos[i].first = u;
		pos[i].second = v;
	}
	sort(pos.begin(),pos.end(), cmp);
	for (int i = 0; i < n; i++)
	{
		printf("%d %d\n", pos[i].first, pos[i].second);
	}
}
