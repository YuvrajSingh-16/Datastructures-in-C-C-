#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size){
    q->size=size;
    q->front=q->rear=-1;
    q->Q = (int *)malloc(q->size*sizeof(int));
}

void InsertRear(struct Queue *q, int x){
    if(q->rear==q->size-1){
        printf("Queue is Full");
    }else{
        q->rear++;
        q->Q[q->rear]=x;
    }
}

int DeleteRear(struct Queue *q){
    int x=-1;

    if(q->rear==q->front)
        printf("Deletion from rear not possible\n");
    else{
        x=q->Q[q->rear];
        q->rear--;
    }
    return x;
}

void InsertFront(struct Queue *q, int x){
    if(q->front == -1){
        printf("Insertion from front not possible\n");
    }else{
        q->Q[q->front]=x;
        q->front--;
    }
}

int DeleteFront(struct Queue *q){
    int x=-1;

    if(q->front == q->rear)
        printf("Queue is Empty\n");
    else{
        q->front++;
        x=q->Q[q->front];
    }return x;
}

void Display(struct Queue q){
    for(int i=q.front+1; i<=q.rear; i++){
        printf("%d ", q.Q[i]);
    }printf("\n");
}

int main()

{

    struct Queue q;
    create(&q, 7);

      InsertRear(&q, 10);
      InsertRear(&q, 20);
      InsertRear(&q, 30);

      Display(q);

      printf("Deleted from front - %d \n", DeleteFront(&q));
      InsertFront(&q, 60);
      printf("Deleted from rear - %d \n", DeleteRear(&q));

      Display(q);

    return 0;

}
