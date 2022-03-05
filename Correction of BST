#include <stdio.h>
#include <stdlib.h>

typedef struct _btnode{
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

typedef struct _queueNode{
	BTNode *data;
	struct _queueNode *next;
}QueueNode;

typedef struct _queue{
   int size;
   QueueNode *head;
   QueueNode *tail;
} Queue;

typedef struct _stackNode{
	BTNode *data;
	struct _stackNode *next;
}StackNode;

typedef struct _stack
{
    int size;
	StackNode *top;
}Stack;

//Prototypes of Interface functions for Queue structure
void enqueue(Queue *qPtr, BTNode * data);
int dequeue(Queue *qPtr);
BTNode* getFront(Queue q);
int isEmptyQueue(Queue q);

BTNode* createNode(int item);
void printBTNode(BTNode *root, int space, int left);
void deleteTree(BTNode **root);

//Prototypes of Interface functions for Stack structure
void push(Stack *sPtr, BTNode *data);
int pop(Stack *sPtr);
BTNode* peek(Stack s);
int isEmptyStack(Stack s);

void BSTCorrection(BTNode* root);

int main()
{
    BTNode* root = NULL;
    BTNode* temp = NULL;
    Queue q;
    q.head = NULL;
    q.tail = NULL;
    q.size = 0;

    int item;
    int flag=1;
    printf("Enter a list of numbers for a Binary Tree, terminated by any non-digit character: \n");
    while(scanf("%d",&item))
    {
        if(root==NULL)
        {
            if(item!=-1){
                root =createNode(item);
                enqueue(&q,root);
            }
        }
        else{
            while(!isEmptyQueue(q)){
                temp = getFront(q);
                if(flag){
                    if(item != -1){
                        temp->left = createNode(item);
                        enqueue(&q,temp->left);
                    }
                    flag = 0;
                    break;
                }
                else if(temp->right==NULL){
                    if(item!=-1){
                        temp->right = createNode(item);
                        enqueue(&q,temp->right);
                    }
                    dequeue(&q);
                    flag=1;
                    break;
                }
                else  dequeue(&q);
            }
        }
    }
    scanf("%*s");

    printf("The input binary search tree:\n");
    printBTNode(root,0,0);
    printf("\n");
    printf("The corrected binary search tree:\n");
    BSTCorrection(root);

    printBTNode(root,0,0);

    deleteTree(&root);

    return 0;
}
BTNode* createNode(int item)
{
    BTNode* node = (BTNode*) malloc(sizeof(BTNode));
	node->item = item;
	node->left = node->right = NULL;
	return node;
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

          printf("%d\n", root->item);

          space++;
          printBTNode(root->left, space,1);
          printBTNode(root->right, space,0);
      }
}

void deleteTree(BTNode **root){
    if (*root != NULL)
	{
		deleteTree(&((*root)->left));
		deleteTree(&((*root)->right));
		free(*root);
		*root = NULL;
	}
}
void enqueue(Queue *qPtr, BTNode *data){
    QueueNode *newNode;
    newNode = malloc(sizeof(QueueNode));
    newNode->data = data;
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
    return q.head->data;
}

int isEmptyQueue(Queue q){
    if(q.size==0) return 1;
    else return 0;
}

void push(Stack *sPtr, BTNode *data){
    StackNode *newNode;
    newNode= (StackNode *)malloc(sizeof(StackNode));
    newNode->data = data;
    newNode->next = sPtr->top;
    sPtr->top = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr){
    if(sPtr==NULL || sPtr->top==NULL){
        return 0;
    }
    else{
       StackNode *temp = sPtr->top;
       sPtr->top = sPtr->top->next;
       free(temp);
       sPtr->size--;
       return 1;
    }
}

BTNode* peek(Stack s){
    return s.top->data;
}

int isEmptyStack(Stack s){
     if(s.size==0) return 1;
     else return 0;
}

void BSTCorrection(BTNode* root)
{
// Write your code here
    if (root->left==NULL && root->right==NULL) return;

    BTNode* cur = root;
    Queue IO;
    IO.head = NULL;
    IO.tail = NULL;
    IO.size = 0;

    Stack s;
    s.size = 0;
    s.top = NULL;

    int done = 0;

    //Get the inorder traversal into a queue
    while(!done)
    {
        if(cur != NULL)
        {
            push(&s, cur);
            cur = cur->left;
        }
        else
        {
            if (!isEmptyStack(s))
            {
                cur = peek(s);
                pop(&s);
                enqueue(&IO, cur);
                //printf("insert: %i\n", IO.head->data);
                cur = cur->right;
            }
            else done=1;
        }
    }

//    printf("Inorder:\n");
//    while(!isEmptyQueue(IO))
//    {
//        printf("%i\n", getFront(IO)->item);
//        dequeue(&IO);
//    }

    //Find the 2 values that are in wrong positions
    BTNode *temp1=NULL, *temp2=NULL;
    int val1=0, val2=0;
    int found = 0;
    if (IO.size == 2)
    {
      val1 = getFront(IO)->item;
      dequeue(&IO);
      val2 = getFront(IO)->item;
      if(val1<val2) return;    //input is a correct tree
    }
    else
    {
      while(1)
      {
          temp1 = getFront(IO);
          dequeue(&IO);
          temp2 = getFront(IO);

          if(temp1->item > temp2->item)
          {
              val1 = temp1->item;
              //printf("val1: %i\n", temp1->item);
              break;   //found first wrong value
          }
      }
      //BTNode *PWV = temp2;
      temp2 = temp1;
      temp1 = getFront(IO);
      //printf("intermmediate: T1: %i T2: %i\n", temp1->item, temp2->item);

      while(IO.size != 1)
      {

          while(temp1->item < temp2->item)
          {

              val2 = temp1->item;
              //printf("val2: %i\n", temp1->item);
              dequeue(&IO);
              if(IO.size == 0)
              {
                  found = 1;
                  break;
              }
              temp1 = getFront(IO);  //found second wrong value
          }
          if (found==1) break;
          temp2 = temp1;
          dequeue(&IO);
          temp1 = getFront(IO);
      }
    }
    printf("values: %i, %i\n", val1, val2);                                 //correct uptill here
    BTNode *node1 = NULL, *node2 = NULL;  //pointers to 2 wrong nodes

    //Traverse through the tree and find address of 2 wrong nodes
    //printf("inorder: ");
    cur = root;
	while(cur != NULL)
    {
        //if ((*node1)!=NULL && (*node2)!=NULL) break;

		if (cur->left == NULL)
        {
            //printf("%i ", cur->item);
			if (cur->item == val1) node1 = cur;
			else if(cur->item == val2) node2 = cur;
			cur = cur->right;
        }
		else
        {
			//Find the previous (prev) of cur
			BTNode *prev = cur->left;
			while(prev->right != NULL && prev->right != cur)
				prev = prev->right;

			//Make cur as right child of its prev
			if(prev->right == NULL)
            {
				prev->right = cur;
				cur = cur->left;
            }

			//fix the right child of prev
			else
            {
				prev->right = NULL;
				//printf("%i ", cur->item);
				if (cur->item == val1) node1 = cur;
                else if(cur->item == val2) node2 = cur;
				cur = cur->right;
            }
        }
    }

    //printf("node1: %i\n", (node1)->item);
    //printf("node2: %i\n", (node2)->item);

    //swap values
    int temp = node1->item;
    node1->item = node2->item;
    node2->item = temp;
}
