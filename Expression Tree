#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 200 //The number digit limitation

typedef struct _btnode{
	int item;
	struct _btnode *left;
	struct _btnode *right;
} BTNode;   // You should not change the definition of BTNode

typedef struct _node{
     BTNode* item;
     struct _node *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void deleteTree(BTNode **root);

void createExpTree(BTNode** root,char* prefix);
void printTree(BTNode *node);
void printTreePostfix(BTNode *node);
double computeTree(BTNode *node);

void push(Stack *sPtr,  BTNode* item);
int pop(Stack *sPtr);
BTNode *peek(Stack s);
int isEmptyStack(Stack s);

int main()
{
    char prefix[SIZE];
    BTNode* root=NULL;

    //printf("Enter an prefix expression:\n");
    gets(prefix);

    createExpTree(&root, prefix);

    // printf("The Infix Expression:\n");
    printTree(root);
    printf("\n");
    //printf("The Postfix (Reverse Polish) Expression:\n");
    printTreePostfix(root);
    printf("\n");
    //printf("Answer ");
    printf("%.2f\n", computeTree(root));
    deleteTree(&root);
    return 0;
}

void push(Stack *sPtr, BTNode *item){
    StackNode *newNode;
    newNode = malloc(sizeof(StackNode));
    newNode->item = item;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr){
    if(sPtr == NULL || sPtr->head == NULL){
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

BTNode *peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}

void deleteTree(BTNode **root){
    BTNode* temp;
    if(*root !=NULL)
    {
        temp = (*root)->right;
        deleteTree(&((*root)->left));
        free(*root);
        *root = NULL;
        deleteTree(&temp);
    }
}

#include <ctype.h>
#include <math.h>

static int i = 0;
void createExpTree(BTNode** root,char* prefix)
{
    //Write your code here

    if (*(prefix+i) == '\0') return;

    while(*(prefix+i) == ' ')
    {
      i++;
    }

    BTNode *Node = malloc(sizeof(BTNode));
    Node->left = Node->right = NULL;

    if (isdigit(*(prefix+i)))  //char is number
    {
        //printf("Test digit: %c\n", *(prefix+i));
        int insert = *(prefix+i) - '0';
        i++;
        int count = 10;
        while (isdigit(*(prefix+i)))
        {
            insert = insert*count + (*(prefix+i) - '0');
            i++;
        }

        Node->item = insert;
    }

    if (!isdigit(*(prefix+i)) && *(prefix+i)!=' ')      //operator
    {
        //printf("Test operand: %c\n", *(prefix+i));
        switch(*(prefix+i))
        {
            case '+':
                Node->item = 10001;
                break;

            case '-':
                Node->item = 10002;
                break;

            case '*':
                Node->item = 10003;
                break;

            case '/':
                Node->item = 10004;
                break;
        }
        i++;
        createExpTree(&(Node->left), prefix);
        createExpTree(&(Node->right), prefix);
    }
    *root = Node;
}


void printTree(BTNode *node){
    //Write your code here
    //inorder: LTR
    //printf("Enter print tree\n");
    if (node == NULL)
    {
        //printf("dud\n");
        return;
    }


    printTree(node->left);


    //printf("%d ", node->item);
    switch(node->item)
        {
            case 10001:
                printf("%c ", '+');
                break;

            case 10002:
                printf("%c ", '-');
                break;

            case 10003:
                printf("%c ", '*');
                break;

            case 10004:
                printf("%c ", '/');
                break;

            default:
                printf("%d ", node->item);
                break;
        }

    printTree(node->right);
}


void printTreePostfix(BTNode *node){
    //Write your code here
    //postorder: LRT
    if (node == NULL)
    {
        //printf("dud\n");
        return;
    }


    printTreePostfix(node->left);

    printTreePostfix(node->right);

    //printf("%d ", node->item);
    switch(node->item)
        {
            case 10001:
                printf("%c ", '+');
                break;

            case 10002:
                printf("%c ", '-');
                break;

            case 10003:
                printf("%c ", '*');
                break;

            case 10004:
                printf("%c ", '/');
                break;

            default:
                printf("%d ", node->item);
                break;
        }

}

double computeTree(BTNode *node){     //dosent work
    //Write your code here
    double x, y;
    if (node==NULL) return 0;

    if (node->left == NULL && node->right == NULL) 
        return (double) node->item;

    x = computeTree(node->left);
    y = computeTree(node->right);


    //operators
    if (node->item == 10001) return x + y;
    else if (node->item == 10002) return x - y;
    else if (node->item == 10003) return x * y;
    else if (node->item == 10004) return x / y;
    //else return ((double) node->item);

}

#include <ctype.h>
#include <math.h>

static int i = 0;
void createExpTree(BTNode** root,char* prefix)
{
    //Write your code here

    if (*(prefix+i) == '\0') return;

    while(*(prefix+i) == ' ')
    {
      i++;
    }

    BTNode *Node = malloc(sizeof(BTNode));
    Node->left = Node->right = NULL;

    if (isdigit(*(prefix+i)))  //char is number
    {
        //printf("Test digit: %c\n", *(prefix+i));
        int insert = *(prefix+i) - '0';
        i++;
        int count = 10;
        while (isdigit(*(prefix+i)))
        {
            insert = insert*count + (*(prefix+i) - '0');
            i++;
        }

        Node->item = insert;
    }

    if (!isdigit(*(prefix+i)) && *(prefix+i)!=' ')      //operator
    {
        //printf("Test operand: %c\n", *(prefix+i));
        switch(*(prefix+i))
        {
            case '+':
                Node->item = 10001;
                break;

            case '-':
                Node->item = 10002;
                break;

            case '*':
                Node->item = 10003;
                break;

            case '/':
                Node->item = 10004;
                break;
        }
        i++;
        createExpTree(&(Node->left), prefix);
        createExpTree(&(Node->right), prefix);
    }
    *root = Node;
}


void printTree(BTNode *node){
    //Write your code here
    //inorder: LTR
    //printf("Enter print tree\n");
    if (node == NULL)
    {
        //printf("dud\n");
        return;
    }


    printTree(node->left);


    //printf("%d ", node->item);
    switch(node->item)
        {
            case 10001:
                printf("%c ", '+');
                break;

            case 10002:
                printf("%c ", '-');
                break;

            case 10003:
                printf("%c ", '*');
                break;

            case 10004:
                printf("%c ", '/');
                break;

            default:
                printf("%d ", node->item);
                break;
        }

    printTree(node->right);
}


void printTreePostfix(BTNode *node){
    //Write your code here
    //postorder: LRT
    if (node == NULL)
    {
        //printf("dud\n");
        return;
    }


    printTreePostfix(node->left);

    printTreePostfix(node->right);

    //printf("%d ", node->item);
    switch(node->item)
        {
            case 10001:
                printf("%c ", '+');
                break;

            case 10002:
                printf("%c ", '-');
                break;

            case 10003:
                printf("%c ", '*');
                break;

            case 10004:
                printf("%c ", '/');
                break;

            default:
                printf("%d ", node->item);
                break;
        }

}

double computeTree(BTNode *node){     //dosent work
    //Write your code here
    double x, y;
    if (node==NULL) return 0;

    if (node->left == NULL && node->right == NULL) 
        return (double) node->item;

    x = computeTree(node->left);
    y = computeTree(node->right);


    //operators
    if (node->item == 10001) return x + y;
    else if (node->item == 10002) return x - y;
    else if (node->item == 10003) return x * y;
    else if (node->item == 10004) return x / y;
    //else return ((double) node->item);

}
