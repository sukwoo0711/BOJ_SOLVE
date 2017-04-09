#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, c;
long long int pos, low, high, mid, last;
vector<long long int> house;
bool check(long long int range)
{
	int hub = 1;
	long long int limit = house[0];
	for (int i = 1; i < n; i++)
	{

		if ((house[i]-limit) >=range)
		{
			hub += 1;
			limit = house[i];
		}
	}
	return hub >= c;
}

int main()
{
	scanf("%d %d", &n, &c);
	house.resize(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &house[i]);
		last = max(last, house[i]);
	}
	sort(house.begin(), house.end());
	low = 0;
	high = 1000000000ULL;
	long long int ans = low;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (check(mid))
		{
			if (ans < mid)
				ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	printf("%lld\n", ans);
	return 0;
}
