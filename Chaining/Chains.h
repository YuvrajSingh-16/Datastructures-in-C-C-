#ifndef CHAINS_H_INCLUDED
#define CHAINS_H_INCLUDED

#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void SortedInsert(struct node **H, int x)
{
    struct node *t, *q=NULL, *p=*H;

    t=malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;

    if(*H==NULL)
        *H=t;
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==*H){
            t->next=*H;
            *H=t;
        }
        else{
            t->next=q->next;
            q->next=t;
        }


    }
}

struct node *Search(struct node *p, int key){
    while(p!=NULL){
        if(key==p->data)
            return p;
        p=p->next;
    }
    return NULL;
}

#endif // CHAINS_H_INCLUDED
