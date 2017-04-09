#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector <long long int> num;
int card[1000001];
int cnt[1000001];
int n;
int main()
{
	scanf("%d", &n);
	num.resize(n+1);
	for (int i = 0; i < n; i++)
		scanf("%lld", &num[i]);
	
	sort(num.begin(), num.begin()+n);
	int count = 1;
	int answer = 1;
	long long int answer_card = num[0];
	for (int i = 1; i <= n; i++)
	{
		if (num[i] == num[i - 1])
			count++;
		else
			count = 1;
		if (count > answer)
		{
			answer = count;
			answer_card = num[i];
		}
	}
	printf("%lld\n", answer_card);
}
