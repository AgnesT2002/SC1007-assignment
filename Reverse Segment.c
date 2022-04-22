#include <stdio.h>
#include <stdlib.h>

struct _listNode{
    float item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

void printList(ListNode *head);
void deleteList(ListNode **ptrHead);
ListNode * findNode(ListNode *cur, int index);
int insertNode(ListNode **ptrHead, int index, float item);

ListNode *reverseSegment(ListNode* head, int start, int end);

int main()
{
    ListNode *head = NULL, *temp;
	float f = 0.0;
	int S, E;

	scanf("%d %d",&S, &E);

	while (scanf("%f", &f)){
		if (head == NULL){
			head = (ListNode*) malloc(sizeof(ListNode));
			temp = head;
		}
		else{
			temp->next = (ListNode*) malloc(sizeof(ListNode));
			temp = temp->next;
		}
		temp->item = f;
	}
	temp->next = NULL;

	head = reverseSegment(head,S,E);
	printList(head);
	deleteList(&head);
	return 0;

}

void printList(ListNode *head){
    while(head !=NULL){
        printf("%.2f ",head->item);
        head = head->next;
    }
    printf("\n");
}

void deleteList(ListNode **ptrHead){
    ListNode *cur = *ptrHead;
    ListNode *temp;
    while (cur!= NULL) {
		temp=cur->next;
		free(cur);
		cur=temp;
	}
	*ptrHead=NULL;
}

ListNode *findNode(ListNode* cur, int index)
{
   if (cur==NULL || index<0)
      return NULL;
   while(index>0){
      cur=cur->next;
      if (cur==NULL)
         return NULL;
      index--;
   }
   return cur;
}

int insertNode(ListNode **ptrHead, int index, float item){
    ListNode  *pre, *newNode;
    // If empty list or inserting first node, update head pointer
    if (index == 0){
        newNode = malloc(sizeof(ListNode));
        newNode->item = item;
        newNode->next = *ptrHead;
        *ptrHead = newNode;
        return 1;
    }
    // Find the nodes before and at the target position
    // Create a new node and reconnect the links
    else if ((pre = findNode(*ptrHead, index-1)) != NULL){
        newNode = malloc(sizeof(ListNode));
        newNode->item = item;
        newNode->next = pre->next;
        pre->next = newNode;
        return 1;
    }
    return 0;
}


ListNode *reverseSegment(ListNode* head, int start, int end)
{

	// Write your code here
  if (start>end) return head;
	ListNode *cur = head;
	int size = 0;
	while (cur)
	{
		size+=1;
		cur = cur->next;
	}
	if (start < 0 || end >= size || (start==0 && end ==0)) return head;

  	ListNode *temp = NULL;
  	ListNode *preS = NULL, *aftE = NULL;
	cur = head;
	for (int count = 0; count<=start; count++)
	{
		if (count == start) break;
    	else cur = cur->next;
	}
  	for (int count = start; count<=end; count++)
	{
      	insertNode(&temp,0, cur->item);
      	cur = cur->next;
	}
	ListNode *tail = temp;
	while (tail->next)
	{
		tail = tail->next;
	}

	if (start == 0 && end == size-1) return temp;
	else if (start == 0)
	{
		aftE = findNode(head, end+1);
		tail->next = aftE;
		return temp;
	}
	else if (end == size-1)
	{
		preS = findNode(head, start-1);
		preS->next = temp;
		return head;
	}
	else
	{
		preS = findNode(head, start-1);
		aftE = findNode(head, end+1);
		tail->next = aftE;
		preS->next = temp;
		return head;
	}

}
