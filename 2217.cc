#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, ans, idx;
vector <int> lope;
int main()
{
	scanf("%d", &n);
	lope.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &lope[i]);
	sort(lope.begin(), lope.end());
	for (int i = lope.size(); i >= 1; i--)
	{
		int lope_weight = i*lope[idx++];
		if (lope_weight > ans)
			ans = lope_weight;
	}
	printf("%d\n", ans);
	return 0;
}
