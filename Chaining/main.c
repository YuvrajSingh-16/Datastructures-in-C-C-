#include <stdio.h>
#include <stdlib.h>

#include "Chains.h"

int hash(int key)
{
    return key%10;
}

void Insert(struct node *H[], int key)
{
    int index = hash(key);
    SortedInsert(&H[index], key);
}

int main()

{
    struct node *HT[10];
    struct node *temp;
    int i;

    for(i=0; i<10; i++)
        HT[i]=NULL;

    Insert(HT, 12);
    Insert(HT, 22);
    Insert(HT, 32);
    Insert(HT, 34);

    temp=Search(HT[hash(34)], 34);

    printf("%d ", temp->data);

    return 0;
}


