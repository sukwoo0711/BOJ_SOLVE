#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int tc, n;
int s[100001][2];
int dp[100001][2];
int main()
{
	scanf("%d", &tc);
	for(int q=0;q<tc;q++)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			cin >> s[i][0];
		for (int i = 0; i < n; i++)
			cin >> s[i][1];
		for (int i =0; i < n; i++)
		{
			dp[i][0] = max(max(dp[i - 1][1] + s[i][0], dp[i - 2][0] + s[i][0]), dp[i - 2][1] + s[i][0]);
			dp[i][1] = max(max(dp[i - 1][0] + s[i][1], dp[i - 2][0] + s[i][1]), dp[i - 2][0] + s[i][1]);
		}
		printf("%d\n", max(dp[n - 1][0], dp[n - 1][1]));
		for (int i = 0; i < n; i++)
			dp[i][0] = dp[i][1] = s[i][0] = s[i][1] = 0;
	}
}
