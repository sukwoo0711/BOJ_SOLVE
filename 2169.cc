#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[1001][1001] = { {-999999}, };
int map[1001][1001];
vector<int>aleft(1100, -9999999);
vector<int>aright(1100, -99999999);
int n,m;

int main()
{
	scanf("%d %d", &n,&m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &map[i][j]);

	dp[0][0] = map[0][0];
	for (int i = 1; i <= m; i++)
		dp[1][i] = dp[1][i - 1] + map[1][i];

	for (int j = 2; j <= n; j++)
	{
		for (int k = 1; k <= m; k++)
		{
			aright[k] = max(dp[j - 1][k] + map[j][k], aright[k - 1] + map[j][k]);
			dp[j][k] = aright[k];
		}
		for (int k = m; k >= 0; k--)
		{
			aleft[k] = max(dp[j - 1][k] + map[j][k], aleft[k + 1] + map[j][k]);
			dp[j][k] = max(dp[j][k], aleft[k]);
		}
	}
	printf("%d\n", dp[n][m]);
	return 0;
}
