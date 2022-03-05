#include <stdio.h>
#include <stdlib.h>

struct _listNode{
    int item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

void printList(ListNode *head);
void deleteList(ListNode **ptrHead);

int insertNode(ListNode **ptrHead, int item);

void triPartition(ListNode** head, int pivot);

int main()
{
    ListNode *head = NULL, *temp;
	int i = 0;
	int pivot = 0;

	scanf("%d",&pivot);

	while (scanf("%d", &i)){
		if (head == NULL){
			head = (ListNode*) malloc(sizeof(ListNode));
			temp = head;
		}
		else{
			temp->next = (ListNode*) malloc(sizeof(ListNode));
			temp = temp->next;
		}
		temp->item = i;
	}
	temp->next = NULL;

	triPartition(&head, pivot);
	printList(head);
	deleteList(&head);

	return 0;
}

void printList(ListNode *head){
    while(head !=NULL){
        printf("%d ",head->item);
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

int insertNode(ListNode **ptrHead, int item){
    ListNode  *pre = *ptrHead, *newNode;
    // If empty list or inserting first node, update head pointer
    if (*ptrHead == NULL){
        newNode = malloc(sizeof(ListNode));
        newNode->item = item;
        newNode->next = NULL;
        *ptrHead = newNode;
        return 1;
    }
    // Find the nodes before and at the target position
    //applies only to insert at last node
    else 
    {
        while(pre->next) 
        {
          pre = pre->next;
          //printf("last\n");
        } //pre is the last node

        newNode = malloc(sizeof(ListNode));
        newNode->item = item;
        newNode->next = NULL;
        pre->next = newNode;
        return 1;
    }
    return 0;
}

void triPartition(ListNode** head, int pivot){
	  // Write your code here
	  ListNode *cur = *head;
	  ListNode *less=NULL, *more=NULL;

    //count how many element same as pivot
    int same = 0;
    while(cur)
    {
      if (cur->item == pivot) 
      {
        same++;
      }
      else if (cur->item < pivot) 
      {
        insertNode(&less, cur->item);
      }
      else 
      {
        insertNode(&more, cur->item);
      }
      cur = cur->next;
    }

    ListNode *curL = less, *curM = more;
    while(curL->next) curL = curL->next;

    //starting from less list, add nodes same as pivot
    for(int count=1; count<=same; count++)
    {
      insertNode(&less, pivot);
      curL = curL->next;
    }

    //add nodes more than pivot
    while(curM)
    {
      insertNode(&less, curM->item);
      curM = curM->next;
    }
    *head = less;
    printList(*head);
    
}
