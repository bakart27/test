#include "ll.h"
#include "main.h"

struct nodell *insertll(struct nodell *head,int *input)
{
    struct nodell *tail=head;
    struct nodell *newnode;
    newnode=malloc(sizeof(struct nodell));
    newnode->data=input;
    newnode->next=NULL;
    if(head==NULL)
        head=newnode;
    else
    {
        while(tail->next!=NULL)
            tail=tail->next;
        tail->next=newnode;
    }
    return head;
}

struct nodell *search(struct nodell *head,int *target)
{
    struct nodell *current=head;
    while((current!=NULL)&&(current->data != target))
        current=current->next;
        //printf("%d\n", *current->data);
    return current;
}
