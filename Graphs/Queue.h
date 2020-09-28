#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdlib.h>

struct node{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

void enqueue(int x){
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    if(t==NULL)
        printf("Queue is full\n");
    else{
        t->data=x;
        t->next=NULL;
        if(front==NULL)
            front=rear=t;
        else{
            rear->next=t;
            rear=t;
        }
    }
}

int dequeue(){
    int x=-1;
    struct node *t;

    if(front==NULL)
        printf("Queue is empty\n");
    else{
        t=front;
        front=front->next;
        x=t->data;
        free(t);
    }return x;
}

int isEmpty()
{
    return front==NULL;
}

#endif // QUEUE_H_INCLUDED
