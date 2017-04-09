#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int n, k;
int num[5000000];

int main()
{
	scanf("%d %d", &n, &k);
	k -= 1;
	for (int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	nth_element(num, num + k, num + n);
	cout << num[k] << endl;
	return 0;
}
