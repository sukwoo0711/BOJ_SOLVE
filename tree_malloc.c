#include <stdio.h>
#include <stdlib.h>
struct node{
 int data;
 node* next;
};
node *head, *tail;
void init()
{
 head = (node*)malloc(sizeof(node));
 tail = (node*)malloc(sizeof(node));
 head->next = tail;
 head->data = 0;
 tail->next = NULL;
 tail->data = -1;
}
void printNode()
{
 int count = 0;
 node* curr;
 curr = (node*)malloc(sizeof(node));
 curr = head->next;
 while (count<10)
 {
  printf("%d ", curr->data);
  curr = curr->next;
  count++;
 }
 free(curr);
}
void initNode(int item)
{
 node* n, *curr;
 n = (node*)malloc(sizeof(node));
 n->data = item;
 curr = (node*)malloc(sizeof(node));
 curr = head;
 while (curr->next != tail)
 {
  curr = curr->next;
 }
 //curr = back of last node
 curr->next = n;
 n->next = tail;
}
void appendNode(int item)
{
 node* n, *curr;
 n = (node*)malloc(sizeof(node));
 n->data = item;
 curr = (node*)malloc(sizeof(node));
 curr = head;
 while (curr->next != tail)
 {
  curr = curr->next;
 }
 //curr = back of last node
 curr->next = n;
 n->next = tail;
}
void deleteNode(int idx, int count)
{
 node* exNode;
 node* curr;
 exNode = (node*)malloc(sizeof(node));
 curr = (node*)malloc(sizeof(node));
 curr = head;
 int navi = 0;
 while (curr->next != tail)
 {
  curr = curr->next;
  navi++;
  if (navi == idx)
   break;
 }
 exNode = curr;
 for (int i = 0; i < count; i++)
  curr = curr->next;
 exNode->next = curr->next;
}
void insertNode(int idx, int data)
{
 node* item;
 node* curr;
 curr = (node*)malloc(sizeof(node));
 item = (node*)malloc(sizeof(node));
 curr = head;
 int navi = 0;
 //printf("idx data %d %d\n", idx, data);
 while (curr->next!=tail)
 {
  if (navi == idx)
   break;
  navi++;
  curr = curr->next;
 }
 item->data = data;
 item->next = curr->next;
 curr->next = item;
}
int main()
{
 int num, tc;
 for (int q = 1; q <= 10; q++)
 {
  init();
  scanf("%d", &num);
  int obj = 0, idx, n, k, count;
  char cmd[2];
  for (int i = 0; i < num; i++)
  {
   scanf("%d", &obj);
   initNode(obj);
  }
  scanf("%d", &count);
  for (int i = 0; i < count; i++)
  {
   scanf("%s", &cmd);
   if (cmd[0] == 'I')
   {
    scanf("%d %d ", &idx, &n);

    for (int j = 0; j < n; j++)
    {
     scanf("%d", &k);
     insertNode(idx + j, k);
    }
   }
   else if (cmd[0] == 'D')
   {
    scanf("%d %d ", &idx, &n);
    deleteNode(idx, n);
   }
   //A 2 421257 796813 ]
   else if (cmd[0] == 'A')
   {
    scanf("%d", &idx);
    for (int j = 0; j < idx; j++)
    {
     int tmp = 0;
     scanf("%d", &tmp);
     appendNode(tmp);
    }
   }
  }
  printf("#%d ", q);
  printNode();
  printf("\n");
 }
 return 0;
}
