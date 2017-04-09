#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int nums[10001];
int n;
int last;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int m;
		scanf("%d", &m);
		nums[m]++;
		if (last < m)
			last = m;
	}

	for (int i = 1; i <= last; i++)
	{
		if (nums[i] == 0)
			continue;
		else
			for (int j = 0; j < nums[i]; j++) 
				printf("%d\n", i);
		
	}
}
