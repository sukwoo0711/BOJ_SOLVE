#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> a, dp,incr,decr;
int main()
{
	int n;
	scanf("%d", &n);
	a.resize(n);
	incr.resize(n);
	decr.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	//Calc LIS
	incr[0] = 1;
	int ans1 = incr[0];
	for (int i = 1; i < n; i++)
	{
		int big = 0;
		for (int j = 0; j < i; j++)
			if (a[j] < a[i])
				if (incr[j] > big)
					big = incr[j];
		incr[i] = big + 1;
		ans1 = max(incr[i], ans1);
	}
	//calc reversed LIS
	decr[0] = 1;
	int ans2 = decr[0];
	reverse(a.begin(), a.end());
	for (int i = 1; i < n; i++)
	{
		int big = 0;
		for (int j = 0; j < i; j++)
			if (a[j] < a[i])
				if (decr[j] > big)
					big = decr[j];
		decr[i] = big + 1;
		ans2 = max(decr[i], ans2);
	}
	reverse(decr.begin(), decr.end());
	
	int answer = 0;
	for (int i = 0; i < n; i++)
		answer = max(answer, incr[i] + decr[i] - 1);
	printf("%d\n", answer);
	return 0;
}
