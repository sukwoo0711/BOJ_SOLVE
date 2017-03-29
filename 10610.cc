#include <vector>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
using namespace std;
int n,sum;
int a[1000001];
int main()
{
	string num = "";
	string ans = "";
	cin >> num;
	n = num.length();	
	int idx = n;
	for (int i = 0; i < n; i++)
		a[i] = (int)num[i]-'0';
	
	reverse(a, a+idx);
	
	for (int i = 0; i < idx; i++)
		sum += a[i];
	
	if (sum % 3 != 0) {
		printf("-1\n");
		return 0;
	}
	else
	{
		sort(a, a + idx);
		if (a[0] != 0) {
			printf("-1\n");
			return 0;
		}
		else {
			reverse(a, a + idx);
			for (int i = 0; i < idx; i++)
				ans += a[i] + '0';
			cout << ans << endl;
		}
	}
}
