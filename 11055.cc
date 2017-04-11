#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
long long a[1001];
long long dp[1001];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	dp[1] = a[1];
	long long ans = dp[1];
	for (int i = 2; i <= n; i++)
	{
		long long int big = 0;
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i])
			{
				big = max(big, dp[j]);
			}
		dp[i] = big + a[i];
		ans = max(dp[i], ans);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
