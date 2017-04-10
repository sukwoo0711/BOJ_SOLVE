#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
int sub[21];
using namespace std;
int total, num;
int sum;
int cnt;
void dfs(int n)
{
	//종료조건
	if (n == num)
		return;
	//조건 만족했을 시 카운트조건
	if (sum + sub[n] == total)
		cnt++;
	//해당 부분집합을 포함안시키고 탐색
	dfs(n + 1);
	//해당 부분집합을 포함시키고 탐색
	sum += sub[n];
	dfs(n + 1);
	sum -= sub[n];
}
int main()
{
	scanf("%d %d", &num, &total);
	for (int i = 0; i < num; i++)
		scanf("%d", &sub[i]);
	dfs(0);
	printf("%d\n", cnt);
	return 0;
}
