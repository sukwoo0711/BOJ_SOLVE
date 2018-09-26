#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
typedef struct {
	int key;
}element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

int h[16] = { 0,9,7,6,5,4,3,2,2,1,3,8 };
//현재 요소의 개수가 heap_size인 힙h에 item을 삽입한다.
void insert_max_heap(HeapType *h,element item)
{
	/*
		1.힙의 크기를 1 증가시킨다.
		2.증가된 힙의 위치에 새 노드를 삽입한다.
		3.i(index)가 루트노드가 아니고, i번째 노드가 i의 부모노드보다 클 경우
		4.i번째 노드와 i의 부모노드와 교환.
	*/
	int i;
	i = ++(h->heap_size);

	//트리를 거슬러 올라가면서 부모노드와 비교하는 과정
	while ((i != 1) && (item.key > h->heap[i / 2].key))
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;	//새로운 노드를 삽입.
}
element delete_max_heap(HeapType *h)
{
	/*
		1.루트 노드 값을 반환하기 위해 item변수로 옮긴다.
		2.말단 노드를 루트노드로 옮긴다.
		3.힙의 크기를 하나 줄인다.
		4.루트의 왼쪽 자식부터 비교를 시작한다.
		5.i가 힙의 크기보다 작으면서 오른쪽 자식이 더 클 경우 두개의 자식중 큰 값의 인덱스를 largest로 옮긴다.
		6.largest의 부모노드가 largest보다 클 경우 중지
		7.그렇지 않으면 largest와 largest의 부모노드를 교환한다.
	*/
	int parent, child;
	element item, temp;

	item = h->heap[1];					//첫번째 최상위 노드(max 값) 반환될 값
	temp = h->heap[(h->heap_size)--];	//마지막으로 삽입된 노드의 값(heapify()로 인하여 낮은값이 위치할 것임, 최하위는 아님)
	parent = 1;
	child = 2;
	//i가 힙의 크기보다 작을 경우에만 동작. (내려가는 과정)
	while (child <= h->heap_size)
	{
		//현재 노드의 자식노드중 더 큰 자식을 찾는다.(now *2, now*2+1);
		if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key)
		{	//Heap사이즈보다 작고	  root의 왼쪽과 오른쪽을 비교하여, 오른쪽이 더 큰 경우
			child++;	//왼쪽노드 말고 오른쪽노드로 탐색하고자 함.
		}
		if (temp.key >= h->heap[child].key)	//찾은 자식의 키값이 최상위로 올라온 노드보다 작거나 같은 경우
			break;							//종료한다.

		h->heap[parent] = h->heap[child];	//부모노드와 자식노드를 교환한다. (더 높은 key를 지닌 자식이 있는지 확인하러 내려간다)
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;					
	return item;
}
void init(HeapType *h)
{
	h->heap_size = 0;
}
int main()
{
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };
	element e4, e5, e6;
	HeapType heap;
	
	init(&heap);
	insert_max_heap(&heap, e1);
	insert_max_heap(&heap, e2);
	insert_max_heap(&heap, e3);

	e4 = delete_max_heap(&heap);
	printf("<%d>", e4.key);
	e5 = delete_max_heap(&heap);
	printf("<%d>", e5.key);
	e6 = delete_max_heap(&heap);
	printf("<%d>\n", e6.key);

	system("pause");
	return 0;
}
