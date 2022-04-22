#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000 //The size of the array

enum ExpType {OPT,OPERAND};

typedef struct _stackNode{
    char item;
    struct _stackNode *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void push(Stack *sPtr, char item);
int pop(Stack *sPtr);
char peek(Stack s);
int isEmptyStack(Stack s);

typedef struct _listnode
{
    int  item;
    enum ExpType type;
	struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
   int size;
   ListNode *head;
} LinkedList;

void insertNode(LinkedList *llPtr, int item,enum ExpType type);
int deleteNode(LinkedList *llPtr);
void removeAllNodes(LinkedList *llPtr);
int isEmptyLinkedList (LinkedList ll);


void in2PreLL(char* infix, LinkedList *inExpLL);

void printExpLL(LinkedList inExp);

int main()
{
    char infix[SIZE];

    //printf("Enter an infix expression:\n");
    scanf("%[^\n]%*c",infix);

    LinkedList inExpLL;
    inExpLL.head = NULL;
    inExpLL.size = 0;

    in2PreLL(infix, &inExpLL);

    printExpLL(inExpLL);

    removeAllNodes(&inExpLL);
    return 0;
}

void printExpLL(LinkedList inExpLL)
{
    ListNode* temp = NULL;
    temp = inExpLL.head;
    while(temp!= NULL){
        if(temp->type == OPERAND)
            printf(" %d ",temp->item);
        else
            printf(" %c ",(char)(temp->item));
        temp = temp->next;
    }
    printf("\n");
}

void insertNode(LinkedList *LLPtr, int item, enum ExpType type) {
    ListNode *newNode;
    newNode = malloc(sizeof(ListNode));
    if(newNode==NULL) exit(0);

    newNode->item = item;
    newNode->type = type;
    newNode->next = LLPtr->head;
    LLPtr->head=newNode;
    LLPtr->size++;
}

int deleteNode(LinkedList *LLPtr) {
    if(LLPtr==NULL || LLPtr->size==0){
        return 0;
    }
    else{
       ListNode *temp = LLPtr->head;
       LLPtr->head = LLPtr->head->next;

       free(temp);
       LLPtr->size--;
       return 1;
    }
}

int isEmptyLinkedList (LinkedList ll) {
    if(ll.size==0) return 1;
    else return 0;
}

void removeAllNodes(LinkedList *LLPtr)
{
	while(deleteNode(LLPtr));
}

void push(Stack *sPtr, char item){
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

char peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}

int checkP(char, char);
#include <ctype.h>
#include <string.h>
#include <math.h>


int checkP(char sign1, char sign2)   //1 if sign1<=sign2
{
    if (sign1 == '*' || sign1 == '/')
    {
        if (sign2 == '+' || sign2 == '-') return 1;
    }
    return 0;
}

void in2PreLL(char* infix, LinkedList *inExpLL)
{
    //Write your code here
    Stack S;
    S.size = 0;
    int i, len, temp;
    len = strlen(infix);

    for (i = 0; i < len/2; i++)
    {
        temp = infix[i];
        infix[i] = infix[len - i - 1];
        infix[len - i - 1] = temp;
    }
    char *cur = infix;

    while(*cur)
    {
        //printf("%c\n", *cur);
        if(isdigit(*cur))
        {
            int insert = *cur - '0';
            cur = cur+1;
            int count = 1;
            while (isdigit(*cur))
            {
                insert += (*cur - '0') * pow(10,count);
                cur = cur+1;
                count+=1;
            }
            cur -= 1;
            //printf("number: %i\n", insert);
            insertNode(inExpLL, insert, OPERAND);
        }
        else if (*cur == ')')
        {
            push(&S, *cur);
        }
        else if (*cur == '(')
        {
            while(peek(S)!=')')
            {
                insertNode(inExpLL, peek(S), OPT);
                //printf("insert: %c\n", peek(S));
                pop(&S);
            }
            pop(&S);
        }
        else
        {
            while(!isEmptyStack(S) && peek(S) != ')' && checkP(peek(S),*cur))  //peek(S)<*cur??
            {
                insertNode(inExpLL, peek(S), OPT);
                pop(&S);
            }
            push(&S, *cur);
        }
        cur += 1;
    }
    while(!isEmptyStack(S))
    {
        insertNode(inExpLL, peek(S), OPT);
        pop(&S);
    }

}
