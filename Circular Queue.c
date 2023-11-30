#include<stdio.h>
#include<stdlib.h>
#define size 5
int queue[size];
int front=-1,rear=-1;
void enqueue(int value)
{
if((front==0&&rear==size-1)||(rear==(front-1)&(size-1)))
{
printf("Queue is full \n");
}
else if(front==-1)
{
front=rear=0;
queue[rear]=value;
}
else
{
rear++;
queue[rear]=value;
}
}
void dequeue()
{
if(front==-1)
{
printf("Queue is empty");
}
else if(front==rear)
{
printf("Deleted element: %d \n",queue[front]);
front=rear=-1;
}
else if(front==size-1)
{
printf("Deleted element: %d \n",queue[front]);
front=0;
}
else
{
printf("Deleted element: %d \n",queue[front]);
front++;
}
}
int search(int value)
{
if(front==-1)
{
printf("Queue is empty, cannot search elements. \n");
return -1;
}
else
{
int i=front;
if(front<=rear)
{
while(i<=rear)
{
if(queue[i]==value)
{
printf("Entered %d found at %d. \n",value,i);
return i;
}
i++;
}
}
else
{
while(i<=size-1)
{
if(queue[i]==value)
{
printf("Element %d found at index %d. \n",value,i);
return i;
}
i++;
}
i=0;
while(i<=rear)
{
if(queue[i]==value)
{
printf("Element %d found at index %d. \n",value,i);
return i;
}
i++;
}
}
printf("Element %d not found in the queue. \n",value,i);
return -1;
}
}
void display()
{
if(front==-1)
{
printf("Queue is empty. \n");
}
else
{
int i=front;
printf("Queue elements: ");
if(front<=rear)
{
while(i<=rear)
{
printf("%d",queue[i]);
i++;
}
}
while(i<=size-1)
{
printf("%d",queue[i]);
i++;
}
i=0;
while(i<=rear)
{
printf("%d",queue[i]);
i++;
}
}
printf("\n");
}
int main()
{
int choice,value;
do
{
printf("1.Enqueue.\n");
printf("2.Dequeue.\n");
printf("3.Searching.\n");
printf("4.Display.\n");
printf("5.Exit.\n");
printf("Enter your choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1:
        printf("Enter the values to be enqueued : ");
        scanf("%d",&value);
        enqueue(value);
        break;
case 2:
        dequeue();
        break;
case 3:
        printf("Enter the element you want to search : ");
        scanf("%d",&value);
        search(value);
        break;
case 4:
        display(value);
        break;
case 5:
        exit(0);
        break;
default:
        printf("Invalid choice. \n");
}
}
while(choice!=5);
return 0;
}