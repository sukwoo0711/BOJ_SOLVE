#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> a, dp;
int main()
{
	int n;
	scanf("%d", &n);
	a.resize(n);
	dp.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	reverse(a.begin(), a.end());
	dp[0] = 1;
	int ans = dp[0];
	for (int i = 1; i < n; i++)
	{
		int big = 0;
		for (int j = 0; j < i; j++)
			if (a[j] < a[i])
				if (dp[j] > big)
					big = dp[j];
		dp[i] = big + 1;
		ans = max(dp[i], ans);
	}
	printf("%d\n",ans);
	return 0;
}
