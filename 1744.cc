//Beakjoon_greedy_1744
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long int lli;
int n;
priority_queue <lli, vector<lli>, greater<>> minque;
priority_queue <lli, vector<lli>, less<>> maxque;
long long int sum;
int main()
{
	scanf("%d", &n);
	while (n--)
	{
		lli num;
		scanf("%lld", &num);
		if (num > 0)
			maxque.push(num);
		else
			minque.push(num);
	}
	while (!minque.empty())
	{
		if (minque.size() >= 2) {
			long long num1 = minque.top();
			minque.pop();
			long long num2 = minque.top();
			minque.pop();
			sum += (num1*num2);
		}
		else
		{
			sum += minque.top();
			minque.pop();
		}
	}
	while (!maxque.empty())
	{
		if (maxque.size() >= 2) {
			lli num1 = maxque.top();
			maxque.pop();
			lli num2 = maxque.top();
			maxque.pop();
			if (num1 + num2 > num1*num2)
				sum += (num1 + num2);
			else
				sum += (num1*num2);
		}
		else
		{
			sum += maxque.top();
			maxque.pop();
		}
	}
	printf("%lld\n", sum);
	return 0;
}
