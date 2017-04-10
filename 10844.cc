/**/
#include <iostream>
#include <cstdio>
#define MOD 1000000000
using namespace std;
int n;
long long int bin[10000][11];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < 10; i++)
		bin[1][i] = 1;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
				bin[i][0] = bin[i - 1][1];
			else if(j==9)
				bin[i][9] = bin[i - 1][8];
			else
				bin[i][j] = bin[i - 1][j - 1] + bin[i - 1][j + 1]%MOD;
		}
	}
	long long int ans = 0;
	for (int i = 0; i < 10; i++)
		ans += bin[n][i]%MOD;
	printf("%lld\n", ans%MOD);
}
