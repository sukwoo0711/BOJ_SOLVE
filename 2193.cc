#include <iostream>
#include <cstdio>

using namespace std;
long long n;
long long int bin[10000][2];
int main()
{
	scanf("%lld", &n);
	//base condition
	bin[1][0] = 1;
	bin[1][1] = 1;
	/*
		3자리 이친수 => 1000, 1001, 1010 으로 3가지 경우임.
	*/
	for (int i = 2; i <= n; i++)
	{
		bin[i][0] = bin[i - 1][0] + bin[i - 1][1];
		bin[i][1] = bin[i - 1][0];
	}
	printf("%lld\n",bin[n][1]);
  return 0;
}
