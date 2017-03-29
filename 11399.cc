#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> ptr;
int main() {
	int i, j;
	int N, K;
	int sum = 0;
	scanf("%d", &N);
	ptr.resize(N);
	for (i = 0; i < N; i++) {
		scanf("%d", &ptr[i]);
	}
	sort(ptr.begin(), ptr.end());
	/*
	1		1
	12		3
	123		6
	1234	10
	12345	15
	-----------
	35
	*/
	for (i = 0; i < N; i++) {
		for (j = 0; j <= i; j++) {
			sum += ptr[j];
		}
	}
	
	printf("%d\n", sum);
	return 0;
}
