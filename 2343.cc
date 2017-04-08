#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
long long int low, high, mid, ans;
int n, e;
vector<int> lesson;
bool check(long long int time)
{
	int rable = 1;
	long long int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (sum + lesson[i] > time)
		{
			sum = lesson[i];
			rable++;
		}
		else
		{
			sum += lesson[i];
		}
	}
	return rable <= e;
}
int main()
{
	//길이가 N인 블루레이로 다 담을 수 있는가?
	//있다 => 블루레이 길이를 줄여보자.
	//없다 => 블루레이 길이를 늘려보자.
	//블루레이 길이 
	int max_track=0;
	scanf("%d %d", &n, &e);
	lesson.resize(n);
	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &lesson[i]);
		if (max_track < lesson[i])
			max_track = lesson[i];
	//	printf("lesson[%d] = %d\n", i, lesson[i]);
	}
	/*
	if (n == e)
	{
		for (int i = 0; i < n; i++)
		{
			if (ans < lesson[i])
				ans = lesson[i];
		}
		printf("%d\n", ans);
		return 0;
	}
	*/
	high = 1000000000;
	low = 0;
	while (low <= high)
	{
		//printf("mid = %d\n", mid);
		mid = (high + low) / 2;
		if (check(mid) && mid >= max_track)
		{
			ans = mid;
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
