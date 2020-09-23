#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*Head;

void create(int A[], int n){
    int i;
    struct Node *t, *last;
    Head=(struct Node*)malloc(sizeof(struct Node));
    Head->data=A[0];
    Head->next=Head;
    last=Head;

    for(i=1; i<n; i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p){
    do{
        printf("%d\n", p->data);
        p=p->next;
    }while(p!=Head);
}

void RDisplay(struct Node *h){
    static int flag=0;
    if(h!=Head || flag==0)
    {
        flag=1;
        printf("%d ", h->data);
        RDisplay(h->next);
    }

}

int Len(struct Node *p){
    int count=0;

    do{
        count++;
        p=p->next;
    }while(p!=Head);
    return count;
}

void Delete(struct Node *p, int index){
    struct Node *q=NULL;
    if(index<0 || index>Len(p))
        return;
    if(index==1){
        Head=Head->next;
        free(p);
    }else{
        for(int i=1; i<index-1; i++)
            p=p->next;
        q=p->next;
        p->next=q->next;
        free(q);
    }
}

void Insert(struct Node *p, int index, int x){
    struct Node *t;
    if(index<0 || index > Len(p))
        return;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;


    if(Head==NULL){
            Head=t;
            t->next=t;
        }

    if(index==0){
            do{
                p=p->next;
            }while(p->next!=Head);
            p->next=t;
            t->next=Head;
            Head=t;
                }
        else{
        for(int i=1; i<index-1; i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}

void Reverse(struct Node *p){
    struct Node *q=NULL, *r=NULL;

    do{
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }while(q!=Head);
    p->next=q;
}

int main()

{
    int A[]={2,3,4,5,6};
    create(A, 5);
    printf("Display Before insertion :-- \n");
    RDisplay(Head);
        printf("\n\n");

   /* Insert(Head, 0, 1);
    Insert(Head, 4, 8);
    printf("Display after insertion :-- \n");*/
    Delete(Head, 4);
    //Reverse(Head);
        Display(Head);
    return 0;
}
