#include <stdio.h>
#define ROOT 1
int h[2001];
int index = 1;
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void insert(int item)
{
	int child = index;
	int parent = child / 2;
	h[index++] = item;
	//힙의 인덱스가 루트가 아니면서, 부모가 자기자신보다 작을때까지 교환
	while (child != 1 && h[child] < h[parent])
	{
		//부모가 자식노드보다 크다 => swap
		swap(&h[child], &h[parent]);
		child = parent;
		parent = parent / 2;
	}
}
int delete_min_heap()
{
	//리턴 할 최소값을 저장한다.
	int retValue = h[ROOT];	//최소힙의 루트를 리턴한다.
	int tmp = h[ROOT] = h[--index];	//제일 마지막에 삽입된 노드를 최상의 루트로 넣는다.
	int parent = 1;
	int child = 2;
	//비교할 대상이 heapsize안에 있고, 좌 우를 비교하여 더 작은값을 확인하여 index를 세팅한다.
	while (child <= index)
	{
		//현재 자식의 노드중에 더 작은값을 찾자.
		if ((child < index) && (h[child] > h[child + 1]))
		{
			//child<index 주의할 것. child가 index영역까지 가게되면, child++시 index의 범위를 벗어난 부분도 참고됨.
			child++;
		}
		//왼쪽 자식보다 값이 클 경우
		if (h[parent] <= h[child])
			break;
		swap(&h[parent], &h[child]);
		parent = child;
		child *= 2;
	}
	h[parent] = tmp;
	return retValue;
}
int main()
{
	/* MIN HEAP */
	int n, m;
	scanf("%d", &n);

	{
	for (int i = 0; i < n; i++) {
			scanf("%d", &m);
			insert(m);
		}
		for (int i = 0; i < n; i++)
			printf("%d\n", delete_min_heap());
	}
	return 0;
}
