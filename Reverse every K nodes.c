#include <stdio.h>
#include <stdlib.h>

struct _listNode{
    int item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

void printList(ListNode *head);
void deleteList(ListNode **ptrHead);

ListNode *findNode(ListNode* cur, int index);
int insertNode(ListNode **ptrHead, int index, int item);
int Reverse(ListNode *cur,ListNode **ptrNewHead);

void reverseKNodes(ListNode** head, int K);

int main()
{
    ListNode *head = NULL, *temp;
	int i = 0;
	int K = 0;

	scanf("%d",&K);

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


	reverseKNodes(&head, K);
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

int insertNode(ListNode **ptrHead, int index, int item){
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

int Reverse(ListNode *cur,ListNode **ptrNewHead)
{
    int size = 0;
    //copy list
    while(cur != NULL)
    {
        insertNode(ptrNewHead, size, cur->item);
        cur = cur->next;
        size++;
    }

    //reverse copied list
    ListNode *prev = NULL;
    ListNode *current = *ptrNewHead;
    ListNode *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *ptrNewHead = prev;
    return 1;
}

void reverseKNodes(ListNode** head, int K){
	//Write your code here
	if (K<=0 || K==1) return;

	ListNode *cur = *head;
  ListNode *con = *head;
	int size = 0;
	while(cur)
	{
		size+=1;
		cur = cur->next;
	}

	if (K>size) return;
  
  	//printf("size: %i\n", size);
	int rounds;
	cur = *head;
	for(rounds=1; rounds<=(size/K); rounds++)
	{
      ListNode *toR = NULL;
      for (int i=0; i<K; i++) 
      {
        insertNode(&toR,)
        con = con->next;
      }

  }
}
