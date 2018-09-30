#include <stdio.h>
#include <stdlib.h>
#define MAX_TABLE 300000
int n, m, a, b;
long long int arr[300000];	//해시 테이블

int hash(const char *str)	//str
{
	unsigned long hash = 90007;
	int c;

	while (c = *str++)
	{
		hash = (((hash << 5) + hash) + c) % MAX_TABLE;
		//32배하는 이유 : A-Z까지 26의 가지수(C가 가질수 있는 크기 0~26), 이 경우에는 0부터 10까지 들어오니까 SHIFT 4를 하면 안겹침.
	}
	return hash % MAX_TABLE;
}

void input_HashTable(int idx, char a[])
{
	//해시태이블이 비어있는지 확인 후, 비어있다면 삽입
	//비어있지 않다면, 아랫주소로 이동해서 삽입한다.
	while (arr[idx] != 0)
	{
		idx = (idx+1)%MAX_TABLE;
	}
	arr[idx] = atoi(a);
}
int find(int idx, char a[])
{
	//먼저 충돌이 안일어났다고 생각하고 비교
	int data = atoi(a);
	if (arr[idx]){
		while (arr[idx] && arr[idx] != data){
			idx = (idx + 1) % MAX_TABLE;
		}
		if (arr[idx] == data)
			return 1;
		else
			return 0;
	}
	else{
		return 0;
	}
}
int main()
{
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		char str[33];
		scanf("%s", &str);
		int idx = hash(str);
		input_HashTable(idx, str);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		char fstr[33];
		scanf("%s", &fstr);
		int idx = hash(fstr);
		printf("%d\n",find(idx, fstr));
	}
}
