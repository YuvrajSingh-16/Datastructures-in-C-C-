#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void Create(int A[], int n){
    struct Node *t, *last;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->prev=NULL;
    first->data=A[0];
    first->next=NULL;
    last = first;

    for(int i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->prev = last;
        t->data = A[i];
        t->next = last->next;
        last->next=t;
        last = t;
    }
}

int Len(struct Node *p){
    int count=0;
    do{
        count++;
        p=p->next;
    }while(p);
    return count;
}

void Display(struct Node *d){
    while(d){
        printf("%d\n", d->data);
        d=d->next;
    }
    printf("\n");
}

void D2(struct Node *t){
    for(int i=0; i<Len(first); i++){
        printf("%d ", t->data);
    t=t->next;
    }
}

void Insert(struct Node *p, int index, int x){
    struct Node *t=NULL;
    t->data=x;t->prev=t->next=NULL;

    if(index<0 || index>Len(p))
        return;

    if(index==0){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->next=first;
        first=t;
        }
    else{
        for(int i=1; i<index-1; i++)
            p=p->next;
        t->next=p->next;
        t->prev=p;
        if(p->next)p->next->prev=t;
        p->next=t;
    }

}

int Delete(struct Node *p, int pos){
    struct Node *q=NULL;
    int x=0;

    if(pos<1 || pos>Len(p))
        return -1 ;
    if(pos==1){
        x=first->data;
        first=first->next;
        if(first)first->prev=NULL;
        free(q);

    }else{
        for(int i=1; i<pos-1; i++)
            p=p->next;
        q=p->next;
        x=q->data;
        q=p->next;
        p->next=q->next;
        q->next->prev=p;
        free(q);
    }
        return x;
}

void Reverse(struct Node *p){
    struct Node *q;

    while(p){
        q=p->next;
        p->next=p->prev;
        p->prev=q;

        p=p->prev;
        if(p!=NULL && p->next==NULL)
            first=p;
    }
}

int main()

{
    int A[]={1,2,3,4,5,34,45,23};
    Create(A, 8);
    Display(first);
    printf("\n\nLength=%d\n\n", Len(first));

    Reverse(first);
    D2(first);

    return 0;
}
