//https://www.acmicpc.net/problem/1149

#include <cstdio>
#include <iostream>
#include <algorithm>
#define INF 99999999
using namespace std;

int house[1001][3];
int dp[1001][3];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d %d", &house[i][0], &house[i][1], &house[i][2]);
	dp[0][0] = house[0][0];	dp[0][1] = house[0][1];	dp[0][2] = house[0][2];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++)
		{
			if (j == 0)
				dp[i][j] = min(dp[i - 1][j + 1], dp[i - 1][j + 2]) + house[i][j];
			else if (j == 1)
				dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j + 1]) + house[i][j];
			else
				dp[i][j] = min(dp[i - 1][j - 2], dp[i - 1][j -1]) + house[i][j];
		}
	}
	int ans = INF;
	for (int i = 0; i < 3; i++)
		ans = min(ans, dp[n - 1][i]);
	printf("%d\n", ans);
}
