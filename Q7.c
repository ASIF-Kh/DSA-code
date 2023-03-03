#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top;
void push()
{
struct node *ptr, *temp;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter the node data");
        scanf("%d",&item);
        ptr->data=item;
        if(top==NULL)
        {
            ptr->next=NULL;
            top=ptr;

        }
        else
        {

            ptr->data=item;
            ptr->next=top;
            top=ptr;

        }
        printf("\nItem inserted into stack\n");
    }
}
void pop()
{
struct node *ptr;
    if(top==NULL)
    {
        printf("\nUNDERFLOW\n");
    }
    else if (top->next==NULL)
    {
        printf("Item poped :%d",top->data);
        top=NULL;
        free(top);
    }
    else
    {
        printf("Item poped :%d",top->data);
        ptr=top;
        top=top->next;
        free(ptr);
    }
}

void display()
{
    struct node *ptr;
    ptr = top;
    if(top==NULL)
    {
        printf("\nUnderflow");
    }
    else
    {
        printf("\nItems in stack\n");

        while(ptr->next!=NULL)
        {
            printf("%d->",ptr->data);
            ptr=ptr->next;
        }
        printf("%d\n",ptr->data);
    }

}
void main()
{
    int choice= 0;
    while(choice!=7)
    {
        printf("\n*******************Main Menu********************");
        printf("\nChoose one option from the following list ....\n");
        printf("\n================================================");
        printf("\n1.push\n2.pop\n3.display\n4.Exit");
        printf("\nEnter the choice\n");
        scanf("\n%d",&choice);
        switch(choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Please enter valid choice");

        }
    }
}
