#include <stdio.h>
#include <stdlib.h>

#define MAX_N 120

typedef struct _btnode{
    char id;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

void buildTree(BTNode** node, char* preO, char* postO);
void inOrder(BTNode *cur);
void preOrder(BTNode *cur);
void postOrder(BTNode *cur);

int main()
{
    char preO[MAX_N];
    char postO[MAX_N];
    scanf("%s",preO);
    scanf("%s",postO);

    BTNode* root=NULL;
    buildTree(&root,preO,postO);
    if(root==NULL) printf("error\n");
    preOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");

    inOrder(root);
    printf("\n");

    return 0;
}
void inOrder(BTNode *cur){
    if (cur == NULL)
        return;

    inOrder(cur->left);
    printf("%c",cur->id);
    inOrder(cur->right);
}
void preOrder(BTNode *cur){
    if (cur == NULL)
        return;

    printf("%c",cur->id);
    preOrder(cur->left);
    preOrder(cur->right);
}
void postOrder(BTNode *cur){
    if (cur == NULL)
        return;

    postOrder(cur->left);
    postOrder(cur->right);
    printf("%c",cur->id);
}

#include <string.h>
BTNode* helper(char*, char*, int*, int, int, int);

BTNode* helper (char *preO, char *postO, int* Index, int L, int H, int size)
{
    // Base case
    if (*Index >= size || L > H) return NULL;

    BTNode* root = malloc(sizeof(BTNode));
    root->id = preO[*Index];
    root->left = root->right = NULL;

    (*Index)++;

    if (L == H)
        return root;
 
    int i;
    for (i = L; i <= H; ++i)
        if (preO[*Index] == postO[i])
            break;

    if (i <= H)
    {
        root->left = helper(preO, postO, Index, L, i, size);
        root->right = helper(preO, postO, Index, i + 1, H-1, size);
    }
 
    return root;
}
 
void buildTree(BTNode** node, char* preO, char* postO)
{
    int size = strlen(preO);
    int Index = 0;
    *node = helper (preO, postO, &Index, 0, size-1, size);
}
