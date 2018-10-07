#include <stdio.h>
#include <stdlib.h>
#define MAX_TABLE 20000
typedef struct w {
	int len;
	char data[50];
}Data;

Data data[10001];

int hashTable[20001];
void input_HashTable(int idx, char a[])
{
	while (hashTable[idx] != 0)
	{
		idx = (idx + 1) % MAX_TABLE;
	}
	hashTable[idx] = atoi(a);
}
int makeHashIndex(char data[])
{
	int i = 0;
	long long int hash = 5087;
	while (i = *data++)
	{
		hash = (((hash << 4) + hash) + i) % MAX_TABLE;
	}
	return hash % MAX_TABLE;
}
bool checkCollapse(int idx, char a[])
{
	int data = atoi(a);
	printf("Collapse check = %d\n", data);
	if (hashTable[idx])
	{
		//해시태이블이 비어있지 않은경우, 본인의 데이터와 맞는지 확인.
		while (hashTable[idx] && hashTable[idx] != data)
		{
			idx = (idx + 1) % MAX_TABLE;
		}
		if (hashTable[idx] == data)
			return 1;
		else
			return 0;
	}
	return 0;
}
void myStrcpy(char src[], char dst[],int len)
{
	for (int i = 0; i < len; i++)
		dst[i] = src[i];
}
int myStrlen(char a[])
{
	int len = 0;
	while (a[++len]) {};
	return len;
}
int main()
{
	int tc, n;
	scanf("%d", &tc);
	for (int k = 1; k <= tc; k++)
	{
		for (int i = 0; i < 20000; i++)
			hashTable[i] = 0;
		bool result = false;
		
		scanf("%d", &n);
		int lenMax = 0, lenMin = 0;
		for (int i = 0; i < n; i++)
		{
			char str[50];
			scanf("%s", &str);
			int len = myStrlen(str);
			data[i].len = len;
			myStrcpy(str, data[i].data, len);
			if (len > lenMax)
				lenMax = len;
			if (len < lenMin)
				lenMin = len;
		}

		for (int i = lenMin; i <= lenMax; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (data[j].len >= i)
				{
					char cmpStr[50];
					//myStrcpy(cmpStr, data[j].data, i);
					for (int q = 0; q < i; q++) {
						cmpStr[q] = data[j].data[q];
					}
				
					int index = makeHashIndex(cmpStr);
				
					if (checkCollapse(index, cmpStr))
					{
						//충돌할 경우, 비교하려는 데이터와 맞는지 비교해서, 만약 일치하면 이미 삽입되있는 내용임.
						result = true;
						break;
					}
					else
					{
						//충돌하지 않으면 그냥 집어넣으면됨.
						input_HashTable(index, cmpStr);
					}
				}
			}
		}
		if (result)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
