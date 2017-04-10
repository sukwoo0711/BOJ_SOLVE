#include <iostream>
#include <cstdio>
#define MOD 10007
using namespace std;
int n;
int dp[10001][10];
int main()
{
	scanf("%d", &n);
	//dp[3][1] = 1로 끝나는 오르막수의 갯수
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= n; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k <= j; k++)
				dp[i][j] += dp[i-1][k]%MOD;

	int ans = 0;
	for (int i = 0; i < 10; i++)
		ans += dp[n][i]%MOD;
	printf("%d\n", ans%MOD);
	return 0;
}
