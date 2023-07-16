#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct node{
    int value;
    struct node *next;
}node;

node* createNode(int value)
{
    node *ptr = (node*)malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;

    return ptr;
}

void push_back(node **array, int value)
{
    node *temp, *p;
    temp = createNode(value);

    if(*array == NULL)
    {
        *array = temp;
    }
    else
    {
        p = *array;
        while(p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

int get(node *array, int index)
{
    int i = 0;
    while(array->next != NULL && index != i)
    {
        array = array->next;
        i++;
    }
    return array->value;
}

void insert(node **array, int value, int pos)
{
    node *temp, *p;

    p = *array;
    temp = createNode(value);

    int i = 1;

    if(pos == 0)
    {
        temp->next = *array;
        *array = temp;
    }
    else
    {
        while(p->next != NULL && pos != i)
        {
            p = p->next;
            i++;
        }

        temp->next = p->next;
        p->next = temp;
    }
    
}

void erase(node **array, int pos)
{
    node *p, *temp = NULL;

    p = *array;

    int i = 1;

    while(p->next != NULL && pos != i)
    {
        p = p->next;
        i++;
    }

    temp = p->next;

    p->next = p->next->next;

    free(temp);
}

int size(node **array){

    if(*array == NULL)
    {
        return 0;
    }
    else{
    node *p = NULL;

    p = *array;

    int i = 1;

    while(p->next != NULL )
    {
        p = p->next;
        i++;
    }
    printf("Size of array: %d\n", i);
    return i;
    }
}

bool empty(node **array)
{
    node *p = NULL;

    p = *array;

    int i = 0;

    // while(p->next != NULL && i == 0)
    // {
    //     p = p->next;
    //     i++;
    // }
    if(p == NULL)
    {
        printf("empty array");
        return true;
    }
    else{
        printf("Not empty array");
        return false;
    }
}

int main(int argc, char const *argv[])
{
    node *array = NULL; // 0xc1

    push_back(&array, 7);

    push_back(&array, 4);

    push_back(&array, 8);

    push_back(&array, 15);

    push_back(&array, 24);
    
    insert(&array, 23, 2);

    size(&array);

    erase(&array, 3);
    
    size(&array);

    empty(&array);

    return 0;
}