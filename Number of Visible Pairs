#include <stdio.h>
#include <stdlib.h>

typedef struct _dbllistnode
{
    int  item;
	struct _dbllistnode *next;
	struct _dbllistnode *pre;
} CDblListNode;

typedef struct _dbllinkedlist{
   int size;
   CDblListNode *head;
} CDblLinkedList;

void insertNode_AtFront(CDblLinkedList *ptrCDLL, int value);
void deleteList(CDblLinkedList *ptrCDLL);
void printList(CDblLinkedList CDLL);

int numMountainPairs(CDblLinkedList CDLL);

int main()
{
    CDblLinkedList himalayas;
    himalayas.head = NULL;
    himalayas.size = 0;

    int item;
    int i,cases;
    int numP;
    scanf("%d",&cases);
    for(i=0; i<cases; i++)
    {
        while(scanf("%d",&item))
            insertNode_AtFront(&himalayas, item);
        scanf("%*s");

        numP = numMountainPairs(himalayas);
        printList(himalayas);
        printf("%d Pairs.\n",numP);

        deleteList(&himalayas);
    }
    return 0;
}

void insertNode_AtFront(CDblLinkedList *ptrCDLL, int value){
      //create a new node
      CDblListNode* newNode;
      newNode = (CDblListNode *) malloc(sizeof(CDblListNode));
      newNode->item = value;

      if(ptrCDLL->size==0) //first node
      {
          newNode->next = newNode;
          newNode->pre = newNode;
          ptrCDLL->head = newNode;
      }
      else{
        newNode->next = ptrCDLL->head;
        newNode->pre = ptrCDLL->head->pre;

        newNode->pre->next = newNode; //update last node next link;
        ptrCDLL->head->pre = newNode;

        ptrCDLL->head = newNode;
      }
      ptrCDLL->size++;
}

void printList(CDblLinkedList CDLL){

    if(CDLL.head==NULL) return;

    CDblListNode* temp = CDLL.head;
    printf("Current List: ");

    while (temp->next != CDLL.head){
        printf("%d ", temp->item);
        temp = temp->next;

    }
    printf("%d\n",temp->item);
}

void deleteList(CDblLinkedList *ptrCDLL){
    if(ptrCDLL->head==NULL) return;
    CDblListNode *cur = ptrCDLL->head;
    CDblListNode *temp;

    while (cur->next!= ptrCDLL->head) {
        temp=cur->next;
        free(cur);
        cur=temp;
    }

    free(cur);
    ptrCDLL->head =NULL;
    ptrCDLL->size =0;

}

int numMountainPairs(CDblLinkedList CDLL)
{
    // Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

    // Write your code here
    if (CDLL.size == 2) return 1;
    if (CDLL.size == 1 || CDLL.size == 0) return 0;
    int result = 0;
    int forward = 0;
    CDblListNode *cur = CDLL.head;
    CDblListNode *cmpF = cur->next;
    for (int i=1; i<=CDLL.size; i++)   //check all mountains
    {
        //printf("cur: %i\n", cur->item);
        int count  = CDLL.size - i;
        int BC = 0;
        CDblListNode *cmpB = cur->pre;
        while(count)   //check each mountain
        {
            //printf("cmpf: %i\n", cmpF->item);
            forward = 0;
            if (cmpF == cur->next)
            {
              result += 1;
              //printf("(adj) cur: %i cmpF: %i\n", cur->item, cmpF->item);
              forward = 1;
            }
            else
            {
                CDblListNode *temp = cmpF->pre;
                while (temp != cur)
                {
                    if (cmpF->item < temp->item || cur->item < temp->item)
                      break;
                    temp = temp->pre;
                }
                if (temp == cur)
                {
                    result ++;
                    //printf("(front) cur: %i cmpF: %i\n", cur->item, cmpF->item);
                    forward = 1;
                }
            }

            if(!forward)
            {
              BC = 1;
              while(cmpB!=cmpF)   //compare backwards
              {
                  if (cmpB->item > cmpF->item || cmpB->item > cur->item)
                    break;
                  cmpB = cmpB->pre;
              }
              if (cmpB == cmpF) 
              {
                result+=1;  //backwards ok
                //printf("(back) cur: %i cmpF: %i\n", cur->item, cmpF->item);
              }
              cmpB = cur->pre;
            }
            cmpF = cmpF->next;
            count--;
        }
        cur = cur->next;
        cmpF = cur->next;
    }
    return result;
}
