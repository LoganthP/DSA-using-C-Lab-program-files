#include<stdio.h>
#include<stdlib.h>

typedef struct node 
{
    int data;
    struct node *link;
} NODE;

NODE *LLone, *LLtwo, *unionLL, *interLL;

NODE* insert(NODE** first, int num) 
{
    NODE* newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = num;
    newnode->link = *first;
    *first = newnode;
    return *first;
}

int search(NODE* first, int num) 
{
    while (first != NULL) 
    {
        if (first->data == num) 
        {
            return 1;
        }
        first = first->link;
    }
    return 0;
}

NODE* findunion(NODE* LLone, NODE* LLtwo) 
{
    unionLL = NULL;
    NODE* temp = LLone;
    while (temp != NULL) 
    {
        insert(&unionLL, temp->data);
        temp = temp->link;
    }
    while (LLtwo != NULL) 
    {
        if (!search(LLone, LLtwo->data)) 
        {
            insert(&unionLL, LLtwo->data);
        }
        LLtwo = LLtwo->link;
    }
    return unionLL;
}

NODE* intersection(NODE* LLone, NODE* LLtwo) 
{
    interLL = NULL;
    while (LLone != NULL) 
    {
        if (search(LLtwo, LLone->data)) 
        {
            insert(&interLL, LLone->data);
        }
        LLone = LLone->link;
    }
    return interLL;
}

void printlist(NODE* cur) 
{
    while (cur != NULL) 
    {
        printf("-->%d", cur->data);
        cur = cur->link;
    }
}

void main() 
{
    int i, LLonecount, LLtwocount, temp;
    printf("\n Enter the number of nodes in the first linked list: \n");
    scanf("%d", &LLonecount);
    printf("Enter data of first linked list: \n");
    for (i = 0; i < LLonecount; i++) 
    {
        scanf("%d", &temp);
        insert(&LLone, temp);
    }

    printf("First Linked List:\n");
    printlist(LLone);

    printf("\n Enter the number of nodes in the second linked list: \n");
    scanf("%d", &LLtwocount);
    printf("Enter data of second linked list: \n");
    for (i = 0; i < LLtwocount; i++) 
    {
        scanf("%d", &temp);
        insert(&LLtwo, temp); 
    }

    printf("Second Linked List:\n");
    printlist(LLtwo);

    findunion(LLone, LLtwo);
    intersection(LLone, LLtwo);

    printf("\n Union Linked List: \n");
    printlist(unionLL);

    printf("\n Intersection Linked List: \n");
    printlist(interLL);
}