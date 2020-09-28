#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st){
    printf("Enter Size - ");
    scanf("%d", &st->size);
    st->top=-1;
    st->S=(int *)malloc(st->size*sizeof(int));
}

void Display(struct Stack st){
    for(int i=st.top; i>=0; i--){
        printf("%d ",st.S[i]);
    printf("\n");
    }
}

void push(struct Stack *st, int x){
    if(st->top==st->size-1)
        printf("Stack overflow\n");
    else
     {
     st->top++;
     st->S[st->top]=x;
     }
}

int pop(struct Stack *st){
    int x=-1;
    if(st->top==-1)
      {
          printf("Stack Underflow\n");
      }
    else{
        x=st->S[st->top--];
    }return x;
}

int isEmpty(struct Stack st){
    if(st.top==-1)
        return 1;
    return 0;
}

int stackTop(struct Stack st){
    if(!isEmpty(st))
        return st.S[st.top];
    return -1;
}

int isOperand(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/' || x=='(' || x==')' || x=='^')
        return 0;
    else
        return 1;
}

int Evaluate(char *postfix){
    struct Stack st;
    st.size=strlen(postfix);
    st.top=-1;
    st.S=(int *)malloc(st.size*sizeof(int));

    int i, x1, x2, r;

    for(i=0; postfix[i]!='\0'; i++){

        if(isOperand(postfix[i]))
            push(&st, postfix[i]-'0');

        else{
            x2=pop(&st); x1=pop(&st);
            switch(postfix[i])
            {
                case '+': r=x1+x2;  break;
                case '-': r=x1-x2;  break;
                case '*': r=x1*x2;  break;
                case '/': r=x1/x2;  break;
            }push(&st, r);
        }
    }
    return pop(&st);
}

int main()
{
    char *postfix = "234*+82/-";
    printf("Solution -- %d", Evaluate(postfix));
    return 0;
}
