#include <cstdio>
#include <iostream>

using namespace std;
int dp[12];
int n, m, tc;
int main()
{
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d", &n);
		/*
			dp[n] = n을 1,2,3의 합으로 나타낼 수 있는 가지수.
			dp[5] 를 예로들어 살펴보자.
			dp[5]가 1,2,3의 합으로 나타낼 수 있는 5의 가지수라면

			dp[4]+1 = dp[5]이다.
			dp[3]+2 = dp[5]이다.
			dp[2]+3 = dp[5]이다.

			dp[5] = dp[4] + dp[3] + dp[2];
			왜냐면, dp[2]는 2를 표현할 수 있는 모든 가지수인데,
			5를 표현하기위해선 dp[2]에서 3을 더하면 그게 5를 표현할 수 있는 모든 가지수이다.
		*/
		//기본케이스를 채워준다.
		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 2;
		//dp[3] = dp[0]+3->1가지경우 + dp[1]+2 -> 1가지 경우 + dp[2]+1 ->2가지경우 =>4가지경우
		for (int i = 3; i <= n; i++)
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		printf("%d\n", dp[n]);
		for (int i = 0; i <= 12; i++)
			dp[i] = 0;
	}
	return 0;
}
