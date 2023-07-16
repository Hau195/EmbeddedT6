#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void add_node(node **linked_list, int value)
{

    node *temp, *p;
    temp = createNode(value);
    
     if(*linked_list == NULL)
    {
        *linked_list = temp;
    }
    else
    {
        if(temp->value < (*linked_list)->value)
        {
            temp->next = *linked_list;
            *linked_list = temp;
        }
        else
        {
        p = *linked_list;
        while((p->next != NULL) && (temp->value >= p->next->value))
        {
            p = p->next;
        }
        temp->next = p->next;
        p->next = temp;
        }
    }
}




int main(int argc, char const *argv[])
{
    node *linked_list = NULL;

    srand(time(NULL));
    for (int i = 0; i < 10000; i++) {
        int value = rand() % 10000 + 1;
        add_node(&linked_list, value);
    }

    add_node(&linked_list, 7);





}