#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[10001];
int dp[10001];
int ans;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	//10  20 10 30 20 50, dp[n] = n숫자를 마지막으로 하는 증가하는 수열의 길이.
	//ex(dp[4] = 3,
	dp[0] = 1;	//자기자신만 봤을때는 마지막으로 증가하는 수열임.
	for (int i = 1; i < n; i++)
	{
		int big = 0;
		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[i])
			{
				if (dp[j] > big)
					big = dp[j];
			}
		}
		ans = max(dp[i] = big + 1,ans);
	}
	printf("%d\n", ans);
	return 0;
}
