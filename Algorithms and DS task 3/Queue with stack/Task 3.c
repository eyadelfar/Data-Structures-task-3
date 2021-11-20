#include<stdio.h>
#include<stdlib.h>
# define MAXSIZE 20 
int s[MAXSIZE],top = -1;

int pop()
{
    return s[top--]; 
}
void push(int x)
{
    if(top == MAXSIZE-1)
        return;
    else
    {
        s[++top] = x;	
    }
}
void enqueue(int x)
{
	push(x);
}
void print()
{
	int i;
	for(i=0;i<=top;i++)
		printf("%d ",s[i]);
}

int dequeue()
{	
	int item,result;
	if(top == -1)
		return -1;
	else if(top == 0)
		return pop();
	item = pop();
	result = dequeue();
	push(item);
	return result;
}
int main()
{
    enqueue(32);
    enqueue(15);
    enqueue(3);
    enqueue(7);
    print();
    dequeue();
    printf("\n");
    print();
	}