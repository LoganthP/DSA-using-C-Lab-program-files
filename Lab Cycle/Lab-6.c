#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int data;
    struct node *next, *prev;
} NODE;

NODE* getnode() 
{
    NODE *x;
    x = (NODE*)malloc(sizeof(NODE));
    printf("\n Enter Data of Node to be Inserted: ");
    scanf("%d", &x->data);
    x->next = x->prev = NULL;
    return x;
}

NODE* insert_front(NODE* first) 
{
    NODE *temp;
    temp = getnode();
    if (first == NULL) 
    {
        first = temp;
    } 
    else 
    {
        temp->next = first;
        first->prev = temp;
        first = temp;
    }
    return first;
}

NODE* insert_left(NODE* first) 
{
    NODE *temp, *cur, *pre;
    int data;
    
    if (first == NULL) 
    {
        printf("List is empty. Inserting node as the first node.\n");
        first = getnode();
    } 
    else 
    {
        printf("Enter the node data to which the new node should be inserted to the left: ");
        scanf("%d", &data);
        
        temp = getnode();
        cur = first;

        while (cur != NULL && cur->data != data) 
        {
            pre = cur;
            cur = cur->next;
        }
        
        if (cur == NULL) 
        {
            printf("No such node is present in the list\n");
        } 
        else if (cur == first) 
        {
            temp->next = first;
            first->prev = temp;
            first = temp;
        } 
        else 
        {
            pre->next = temp;
            temp->prev = pre;
            temp->next = cur;
            cur->prev = temp;
        }
    }
    
    return first;
}

NODE* delete_node(NODE* first) 
{
    NODE *cur;
    int data;
    
    if (first == NULL) 
    {
        printf("List is empty\n");
        return first;
    }

    printf("Enter the data of the NODE to be deleted: ");
    scanf("%d", &data);

    cur = first;

    if (first->data == data) 
    {  
        first = first->next;
        if (first != NULL) 
        {
            first->prev = NULL;
        }
        free(cur);
        return first;
    }

    while (cur != NULL && cur->data != data) 
    {
        cur = cur->next;
    }

    if (cur == NULL) 
    {
        printf("No such node is present in the list\n");
    } 
    else 
    {
        if (cur->next != NULL) 
        {
            cur->next->prev = cur->prev;
        }
        if (cur->prev != NULL) 
        {
            cur->prev->next = cur->next;
        }
        free(cur);
    }
    
    return first;
}

void display(NODE* first) 
{
    NODE *cur;
    if (first == NULL) 
    {
        printf("No nodes present\n");
    } 
    else 
    {
        cur = first;
        while (cur != NULL) 
        {
            printf("-->%d", cur->data);
            cur = cur->next;
        }
        printf("\n");
    }
}

int main() 
{
    NODE *first = NULL;
    int ch;
    
    while (1) 
    {
        printf("\n1. Insert Front\t 2. Insert Left\t 3. Delete\t 4. Display\t 5. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ch);
        
        switch (ch) 
        {
            case 1:
                first = insert_front(first);
                break;
            case 2:
                first = insert_left(first);
                break;
            case 3:
                first = delete_node(first);
                break;
            case 4:
                display(first);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    
    return 0;
}