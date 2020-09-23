#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*Head=NULL;

void Create(int A[], int n){
    struct Node *t, *last;

    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->prev=Head;
    Head->data=A[0];
    Head->next=Head;
    last = Head;

    for(int i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->prev = last;
        t->data = A[i];
        t->next = last->next;
        last->next=t;
        last = t;
    }
    last->next=Head;
}

int Len(struct Node *p){
    int count=0;

    do{
        count++;
        p=p->next;
    }while(p!=Head);
    return count;
}

void Display(struct Node *d){
    do{
        printf("%d\n", d->data);
        d=d->next;
    }while(d!=Head);
    printf("\n");
}

void D2(struct Node *t){
    for(int i=0; i<Len(Head); i++){
        printf("%d ", t->data);
    t=t->next;
    }
}

void Insert(struct Node *p, int index, int x){
    struct Node *t;
    t->data=x;t->prev=t->next=NULL;

    if(index<0 || index>Len(p))
        return;

    if(Head==NULL)
        {
            Head=t;
            t->next=t;
            t->prev=t;
        }

    else if(index==0){
        t=(struct Node *)malloc(sizeof(struct Node));

        t->prev=Head->prev;
        t->next=Head;
        Head->prev->next=t;
        Head->prev=t;
        Head=t;
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
    if(pos==1&&Head->next){
        x=Head->data;
        Head->next->prev=Head->prev;
        Head->prev->next=Head->next;
        Head=Head->next;
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

int main()

{
    int A[]={1,2,3,4,5,34,45,23};
    Create(A, 8);
    Display(Head);
    printf("\n\nLength=%d\n\n", Len(Head));
    Insert(Head, 5, 54);
    Delete(Head, 6);
    D2(Head);


    return 0;
}
