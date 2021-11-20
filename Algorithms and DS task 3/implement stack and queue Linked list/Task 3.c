#include <stdio.h>
#include <stdlib.h>

struct nodeS
{
    int data;
    struct nodeS *next;
}*temp2;

void pop(int *e)
{
    int item;
    struct nodeS *p;
    if (temp2 == NULL)
        return;
    else
        {
            *e = temp2 -> data;
            p = temp2;
            temp2 = temp2 -> next;
            free(p);
        }
}

void displayS()
{
    int i;
    struct nodeS *p;
    p = temp2;
    if(p == NULL)
        return;
    else
        while(p!= NULL)
            {
                printf("%d ",p -> data);
                p = p -> next;
            }
}

void push (int data)
{
struct nodeS *p = (struct nodeS*)malloc(sizeof(struct nodeS));
if(p == NULL)
    return;
else
    {
        if(temp2 == NULL)
        {
            p -> data = data;
            p -> next = NULL;
            temp2 = p;
        }
        else
        {
            p -> data = data;
            p -> next = temp2;
            temp2 = p;
        }
    }
}

struct nodeQ
{
int data;
struct nodeQ *link;
}*front, *rear;

void inQ(int e)
{
    struct nodeQ *temp;
    temp = (struct nodeQ*)malloc(sizeof(struct nodeQ));
    temp->data=e;
    temp->link = NULL;
    if (rear == NULL)
        front = rear = temp;
    else
    {
        rear->link = temp;
        rear = temp;
    }
}

void dQ(int *e)
{
    struct nodeQ *temp;
    temp = front;
    if (front == NULL)
            front = rear = NULL;
    else
        {
            *e = front->data;
            front = front->link;
            free(temp);
        }
}

void displayQ()
{
    struct nodeQ *temp;
    temp = front;
    int i = 0;
    if (front == NULL)
        return;
    else
        while (temp)
        {
            printf("%d ", temp->data);
            temp = temp->link;
            i++; 
        }
}

void main()
{
    int x,y;
    printf("Elements in Queue BEFORE dequeuing:\n");
    inQ(32);
    inQ(321);
    inQ(12);
    inQ(7);
    displayQ();
    dQ(&x);
    printf("\nDequeued : %d\n",x);
    printf("Elements in Queue AFTER dequeuing:\n");
    displayQ();
    printf("\n\nElements in Stack BEFORe popping (its reversed): \n");
    push(5);
    push(23);
    push(6);
    push(2);
    displayS();
    pop(&y);
    printf("\nPopped : %d\n",y);
    printf("Elements in Stack AFTER popping: \n");
    displayS();

}