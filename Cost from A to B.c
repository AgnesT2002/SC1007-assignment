#include <stdio.h>
#include <stdlib.h>

typedef struct _btnode{
    int nodeV;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

typedef struct _queuenode{
    BTNode* node;
    struct _queuenode *next;
}QueueNode;

typedef struct _queue{
   int size;
   QueueNode *head;
   QueueNode *tail;
} Queue;

void printBTNode(BTNode *root, int space,int left);
//Prototypes of Interface functions for Queue structure
void enqueue(Queue *qPtr, BTNode * node);
int dequeue(Queue *qPtr);
BTNode* getFront(Queue q);
int isEmptyQueue(Queue q);

int twoNodesCost(BTNode* node, int nodeV1,int nodeV2);

int main()
{
    BTNode* root = (BTNode*) malloc(sizeof(BTNode));

    Queue q;
    q.head = NULL;
    q.tail = NULL;
    q.size = 0;

    BTNode* node;
    enqueue(&q,root);

    int nodeV;
    char opL, opR;

    while(!isEmptyQueue(q)){
            scanf("%d %c %c",&nodeV,&opL,&opR);
            node = getFront(q);dequeue(&q);
            node->nodeV = nodeV;

            if(opL != '@'){
                node->left = (BTNode*) malloc(sizeof(BTNode));
                enqueue(&q,node->left);
            }
            else node->left =NULL;
            if(opR != '@'){
                node->right = (BTNode*) malloc(sizeof(BTNode));
                enqueue(&q,node->right);
            }
            else
                node->right = NULL;
    }

    int v1,v2;
    scanf("%d %d",&v1,&v2);
    int cost = twoNodesCost(root,v1,v2);

    printBTNode(root,0,0);

    printf("Distance is %d\n",cost);
    return 0;
}

void enqueue(Queue *qPtr, BTNode *node){
    QueueNode *newNode;
    newNode = malloc(sizeof(QueueNode));
    newNode->node = node;
    newNode->next = NULL;

    if(isEmptyQueue(*qPtr))
        qPtr->head=newNode;
    else
        qPtr->tail->next = newNode;

    qPtr->tail = newNode;
    qPtr->size++;
}

int dequeue(Queue *qPtr){
    if(qPtr==NULL || qPtr->head==NULL){ //Queue is empty or NULL pointer
        return 0;
    }
    else{
       QueueNode *temp = qPtr->head;
       qPtr->head = qPtr->head->next;
       if(qPtr->head == NULL) //Queue is emptied
           qPtr->tail = NULL;

       free(temp);
       qPtr->size--;
       return 1;
    }
}

BTNode* getFront(Queue q){
    return q.head->node;
}

int isEmptyQueue(Queue q){
    if(q.size==0) return 1;
    else return 0;
}
void printBTNode(BTNode *root,int space,int left){
      if (root != NULL)
      {

          int i;
          for (i = 0; i < space-1; i++)
                 printf("|\t");


          if(i<space){
            if(left==1)
              printf("|---");
            else
              printf("|___");
          }

          printf("%d\n", root->nodeV);

          space++;
          printBTNode(root->left, space,1);
          printBTNode(root->right, space,0);
      }
}

typedef struct _listnode{
    int item;
    struct _listnode *next;
} ListNode;
typedef ListNode StackNode;

typedef struct _linkedlist{
   int size;
   ListNode *head;
} Stack;

void push(Stack *sPtr, char item);
int pop(Stack *sPtr);

void push(Stack *sPtr, char item){
    StackNode *newNode;
    newNode= malloc(sizeof(StackNode));
    newNode->item = item;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr){
    if(sPtr==NULL || sPtr->head==NULL){
        return 0;
    }
    else{
       StackNode *temp = sPtr->head;
       sPtr->head = sPtr->head->next;
       free(temp);
       sPtr->size--;
       return 1;
    }
}
/////////////////////////////////////////////////////////////////

BTNode* findLCA(BTNode*, int, int);
int pathfinder(BTNode*, int);

BTNode* findLCA(BTNode* root, int nodeV1, int nodeV2)
{
    if(root==NULL) return root;

    if(root->nodeV == nodeV1 || root->nodeV == nodeV2) return root;

    BTNode *L = findLCA(root->left, nodeV1, nodeV2);
    BTNode *R = findLCA(root->right, nodeV1, nodeV2);

    if(L!=NULL && R!=NULL) return root;

    if(L==NULL) return R;

    else return L;
}

static int path[100];
static int sum = 0;
int pathfinder(BTNode *LCA, int value)
{
    if (!LCA) return 0;

    sum += LCA->nodeV;

    if (LCA->nodeV == value) return 1;

    if (pathfinder(LCA->left, value) || pathfinder(LCA->right, value))
        return 1;

    else
    {
        sum -= LCA->nodeV;
        return 0;
    }
}

int twoNodesCost(BTNode* node, int nodeV1,int nodeV2)
{

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail


// Write your code here
    BTNode *LCA = findLCA(node, nodeV1, nodeV2);
    printf("LCA: %i\n", LCA->nodeV);

    pathfinder(LCA, nodeV1);
    //printf("sum: %i\n", sum);

    pathfinder(LCA, nodeV2);
    //printf("sum: %i\n", sum);

    return sum - LCA->nodeV;

}
