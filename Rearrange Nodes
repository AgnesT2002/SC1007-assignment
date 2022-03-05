#include <stdio.h>
#include <stdlib.h>

struct _listNode{
    int item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

typedef struct _linkedList{
    ListNode *head;
    int size;
}LinkedList;

void printList(LinkedList ll);
void deleteList(LinkedList* llptr);
int insertNode(LinkedList *ll, int index, int item);


//added helper function
LinkedList rejoin (LinkedList left, LinkedList right, int size);

LinkedList rearrange (LinkedList ll);

int main()
{
    LinkedList ll;

    ll.head = NULL;
    ll.size = 0;
    ListNode* temp;

	int i = 0;

	while (scanf("%d", &i)){
		if (ll.head == NULL){
			ll.head = (ListNode*) malloc(sizeof(ListNode));
			temp = ll.head;
		}
		else{
			temp->next = (ListNode*) malloc(sizeof(ListNode));
			temp = temp->next;
		}
		temp->item = i;
		ll.size++;
	}
	temp->next = NULL;

	ll=rearrange(ll);

	printList(ll);
    deleteList(&ll);
	return 0;
}

void printList(LinkedList ll){
    ListNode* temp = ll.head;

    while(temp !=NULL){
        printf("%d ",temp->item);
        temp = temp->next;
    }
    printf("\n");
}
void deleteList(LinkedList* llptr){
    ListNode *cur = llptr->head;
    ListNode *temp;
    while (cur!= NULL) {
		temp=cur->next;
		free(cur);
		cur=temp;
	}
	llptr->head=NULL;
	llptr->size =0;
}

//My helper 2
LinkedList rejoin (LinkedList left, LinkedList right, int size)
{
    LinkedList temp;
	  temp.head = NULL;
	  temp.size = 1;
	  ListNode *cur = NULL;
    ListNode *curL = left.head;
    ListNode *curR = right.head;

    ListNode *newNode = malloc(sizeof(ListNode)); 
    temp.head = newNode;
    newNode->next = NULL;
    newNode->item = curR->item;
    cur = newNode;
    curR = curR->next;


    while(temp.size != size && curL && curR)
    {
      if (temp.size %2 == 1) 
      {
        ListNode *tt = malloc(sizeof(ListNode)); 
        tt->next = NULL;
        tt->item = curL->item;
        cur->next = tt;
        curL = curL->next;

      }
      else
      {
        ListNode *tr = malloc(sizeof(ListNode));
        tr->next = NULL;
        tr->item = curR->item;
        cur->next = tr;
        curR = curR->next;
      }
      temp.size += 1;
      cur = cur->next;
    }

    if (curL && !curR)
    {
        cur->next = curL;
    }
    else if (curR && !curL)
    {
        cur->next = curR;
    }
    return temp;
}

LinkedList rearrange (LinkedList ll){
// Write your code here
  if (ll.size == 1) return ll; 
	ListNode *cur = ll.head;

	LinkedList left;
	left.head = NULL;
	left.size = 0;

	LinkedList right;
	right.head = NULL;
	right.size = 0;

	int part = (ll.size) / 2;
  	left.size = part;
  	right.size = ll.size - part;

	for (int count=1; count<part; count++) cur = cur->next;

	right.head = cur->next;
	cur->next = NULL;
	left.head = ll.head;

	LinkedList new1 = rejoin(left, right, ll.size);

	//deleteList(&left);
	//deleteList(&right);

	left.head = NULL;
	left.size = 0;

	right.head = NULL;
	right.size = 0;

	ListNode *cur2 = new1.head;

	for (int count=1; count<part; count++) cur2 = cur2->next;

	right.head = cur2->next;
	cur2->next = NULL;
	left.head = new1.head;

	LinkedList result = rejoin(right, left, ll.size);
	//deleteList(&left);
	//deleteList(&right);
	//deleteList(&new1);

	return result; 
}
