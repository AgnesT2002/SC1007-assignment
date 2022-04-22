#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode{
    int key;
    struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
   int size;
   ListNode *head;
} HashTableNode;

typedef struct _hashTable{
   int hSize; //size of hash table
   int nSize; //number of inserted keys
   HashTableNode *Table;
} HashTable;

int Hash(int,int);

ListNode* HashSearch(HashTable, int);
int HashInsert(HashTable *, int);

//In Practice, we will not do it
void HashPrint(HashTable);

int main()
{
    int opt;
    int size;

    int i;
    int key;

    //Create a HashTable
    HashTable Q3Hash;
    Q3Hash.hSize = 0;
    Q3Hash.nSize = 0;
    Q3Hash.Table = NULL;

    printf("============= Hash Table ============\n");
    printf("|1. Create a hash table             |\n");
    printf("|2. Insert a key to the hash table  |\n");
    printf("|3. Search a key in the hash table  |\n");
    printf("|4. Print the hash table            |\n");
    printf("|5. Quit                            |\n");
    printf("=====================================\n");

    printf("Enter selection: ");
    scanf("%d",&opt);
    while(opt>=1 && opt <=4){
        switch(opt){
        case 1:
            printf("Enter the size of hash table:\n");
            scanf("%d",&Q3Hash.hSize);

            Q3Hash.nSize = 0;

            Q3Hash.Table = (HashTableNode *) malloc(sizeof(HashTableNode)*(Q3Hash.hSize));

            for(i=0;i<Q3Hash.hSize;i++){
               Q3Hash.Table[i].head = NULL;
               Q3Hash.Table[i].size = 0;
            }
            printf("HashTable is created.\n");
            break;
        case 2: //Insertion
            printf("Enter a key to be inserted:\n");
            scanf("%d",&key);

            if(HashInsert(&Q3Hash,key))
                printf("%d is inserted.\n",key);
            else
                printf("%d is a duplicate. No key is inserted.\n",key);
            break;
        case 3: //Search
            printf("Enter a key for searching in the HashTable:\n");
            scanf("%d",&key);
            ListNode* node = HashSearch(Q3Hash, key);

            if(node!=NULL)
                printf("%d is found.\n",key);
            else
                printf("%d is not found.\n",key);
            break;
        case 4:
            HashPrint(Q3Hash);
            break;
        }

    printf("Enter selection: ");
    scanf("%d",&opt);
    }

    for(i=0;i<Q3Hash.hSize;i++)
    {
        while(Q3Hash.Table[i].head)
        {
            ListNode *temp;
            temp = Q3Hash.Table[i].head;
            Q3Hash.Table[i].head = Q3Hash.Table[i].head->next;
            free(temp);
        }
    }
    free(Q3Hash.Table);

    return 0;

}

int Hash(int key,int hSize)
{
    return key%hSize;
}

ListNode* HashSearch(HashTable Q3Hash, int key)
{
    //write your code here
    if (Q3Hash.hSize == 0) return NULL;

    int val = Hash(key, Q3Hash.hSize);
    ListNode *temp = Q3Hash.Table[val].head;

    while (temp != NULL)
    {
        if (temp->key == key) return temp;
        temp = temp->next;
    }
    return NULL;  //not found
}

int HashInsert(HashTable* Q3HashPtr, int key)
{
    //write your code here
    //Close addressing Hash Table
    int val = Hash(key, Q3HashPtr->hSize);   //get hash value
    ListNode *insert = malloc(sizeof(ListNode));
    insert->key = key;
    insert->next = NULL;
    ListNode *temp = Q3HashPtr->Table[val].head;
    if(temp == NULL)  //hash slot is empty
    {
        Q3HashPtr->Table[val].head = insert;
        return 1;
    }
    while (temp->next)  //get to the end of the slot
    {
        if (temp->key == key) return 0; //hash slot alr has that key
        temp = temp->next;
    }

    if (temp->key == key) return 0;
    else     //insert new node
    {
        temp->next = insert;
        return 1;
    }
}

void HashPrint(HashTable Q3Hash)
{
    int i;
    ListNode *temp;
    for(i=0;i<Q3Hash.hSize;i++)
    {
        temp =Q3Hash.Table[i].head;
        printf("%d:  ",i);
        while(temp !=NULL)
        {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("\n");
    }
}

/* Testcase
Input:
1
3
2
1
2
2
2
3
2
4
2
5
2
6
2
7
2
8
2
9
3
9
3
10
4
5

Output:
============= Hash Table ============
|1. Create a hash table             |
|2. Insert a key to the hash table  |
|3. Search a key in the hash table  |
|4. Print the hash table            |
|5. Quit                            |
=====================================
Enter selection: Enter number of data to be inserted:
HashTable is created.
Enter selection: Enter a key to be inserted:
1 is inserted.
Enter selection: Enter a key to be inserted:
2 is inserted.
Enter selection: Enter a key to be inserted:
3 is inserted.
Enter selection: Enter a key to be inserted:
4 is inserted.
Enter selection: Enter a key to be inserted:
5 is inserted.
Enter selection: Enter a key to be inserted:
6 is inserted.
Enter selection: Enter a key to be inserted:
7 is inserted.
Enter selection: Enter a key to be inserted:
8 is inserted.
Enter selection: Enter a key to be inserted:
9 is inserted.
Enter selection: Enter a key for searching in the HashTable:
9 is found.
Enter selection: Enter a key for searching in the HashTable:
10 is not found.
Enter selection: Enter a key to be deleted:
11 is not existing.
Enter selection:
0:  9 -> 6 -> 3 ->
1:  7 -> 4 -> 1 ->
2:  8 -> 5 -> 2 ->
Enter selection:
*/
