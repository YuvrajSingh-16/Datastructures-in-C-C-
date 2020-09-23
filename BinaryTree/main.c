#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"

struct Node *root=NULL;

void TreeCreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    printf("Enter root value :- ");
    scanf("%d", &x);
    root=(struct Node *)malloc(sizeof(struct Node));
    root->data=x;

    root->lchild=root->rchild=NULL;
    enqueue(&q, root);

    while(!isEmptyQueue(q)){
        p=dequeue(&q);
        printf("Enter the Left child of %d :- ", p->data);
        scanf("%d", &x);
        if(x!=-1){
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q, t);
        }

        printf("Enter the Right child of %d :- ", p->data);
        scanf("%d", &x);
        if(x!=-1){
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q, t);
        }
    }
}

void preorder(struct Node *p){
    if(p){
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void Inorder(struct Node *p){
    if(p){
        Inorder(p->lchild);
        printf("%d ", p->data);
        Inorder(p->rchild);
    }
}

void Postorder(struct Node *p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        printf("%d ", p->data);
    }
}

void Ipreorder(struct Node *p){
    struct Stack stk;
    Stackcreate(&stk, 100);

    while(p || !isEmptyStack(stk))
    {
        if(p){
            printf("%d ", p->data);
            push(&stk, p);
            p=p->lchild;
        }else{
            p=pop(&stk);
            p=p->rchild;
        }
    }
}

void Iinorder(struct Node *p){
    struct Stack stk;
    Stackcreate(&stk, 100);

    while(p || !isEmptyStack(stk))
    {
        if(p){
            push(&stk, p);
            p=p->lchild;
        }else{
            p=pop(&stk);
            printf("%d ", p->data);
            p=p->rchild;
        }
    }
}

void Levelorder(struct Node *root) {
    struct Queue q;
    create(&q, 100);

    printf("%d ",root->data);
    enqueue(&q, root);

    while(!isEmptyQueue(q)){
            root=dequeue(&q);
    if(root->lchild){
            printf("%d ",root->lchild->data);
            enqueue(&q, root->lchild);
            }
    if(root->rchild){
            printf("%d ",root->rchild->data);
            enqueue(&q, root->rchild);
            }
      }
}

 int Count(struct Node *root){
    if(root)
        return count(root->lchild)+count(root->rchild)+1;
    return 0;
 }



int Height(struct Node *root) {
    int x=0,y=0;
        if(root==NULL)
            return 0;
        x=Height(root->lchild);
        y=Height(root->rchild);

        return x>y?x+1:y+1;
}

int count(struct Node *p){
    int x=0,y=0;

    if(p!=NULL){
        x=count(p->lchild);
        y=count(p->rchild);

        return x+y+1;
    }return 0;
}

int countLeaf(struct Node *p){
    int x=0,y=0;
    if(p!=NULL){
        x=countLeaf(p->lchild);
        y=countLeaf(p->rchild);

        if(p->lchild==NULL && p->rchild==NULL)
            return x+y+1;
        else
            return x+y;
    }else
        return 0;
}

int NodeDeg1(struct Node *p){
    int x=0,y=0;
    if(p!=NULL){
        x=NodeDeg1(p->lchild);
        y=NodeDeg1(p->rchild);

        if(p->lchild!=NULL ^ p->rchild!=NULL)
            return x+y+1;
        else
            return x+y;
    }
}

int main()

{
    TreeCreate();printf("\nPreoder:-- ");
    Ipreorder(root);printf("\nInorder:-- ");Iinorder(root);
    printf("\nPostorder:-- ");Postorder(root);

    printf("Count :- %d", Count(root));
    printf("Count Leaf :- %d", countLeaf(root));
    printf("Nodes with degree one :- %d", NodeDeg1(root));
    printf("Height :- %d" ,Height(root));
    return 0;
}
