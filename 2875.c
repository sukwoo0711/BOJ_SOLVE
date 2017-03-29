//BOJ 2875
#include <stdio.h>
int n, m, k;
int main()
{
	int team = 0;
	scanf("%d %d %d", &n, &m, &k);
	while (n + m > k + 3)
	{
		if (n >= 2 && m >= 1)
		{
			n -= 2;
			m -= 1;
			team++;
		}
		else
			break;
	}
	printf("%d\n", team);
}
