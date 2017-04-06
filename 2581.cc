#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
vector <int> prime(10001, -1);
void eratos()
{
	//unsorted value = -1
	//prime = 1;
	//not prime = 0;
	for (int i = 2; i <= 10000; i++)
	{
		if (prime[i] == -1)
		{
			prime[i] = true;
			for (int j = 2; j <= 10000 / i; j++)
			{
				prime[i*j] = 0;
			}
		}
	}
}
int main()
{
	int s, e;
	long long int sum = 0;
	eratos();
	scanf("%d %d", &s, &e);
	int flag = 0;
	for (int i = s; i <= e; i++)
	{
		if (prime[i] == 1) {
			if (flag == 0) 
			{
				flag = i;
			}
			sum += i;
		}
	}
	printf("%d\n", sum == 0 ? -1 : sum);
	if (sum != 0)
		printf("%d\n", flag);
}
