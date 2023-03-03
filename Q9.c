#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
void enqueue(int item)
{
    struct node *ptr, *temp;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        ptr->data=item;
        if(head==NULL)
        {
            head=ptr;
            ptr->next=head;
        }
        else
        {
            temp=head;
            while(temp->next != head)
            {
               temp=temp->next;
            }
            temp->next=ptr;
            ptr->next=head;
        }
        printf("\nEnqueued");
    }
}
void dequeue()
{
    struct node *ptr = head;
    printf("deleted element from queue: %d",ptr->data);
    head = head->next;
    free(ptr);
}
void display()
{     struct node *ptr;
    ptr = head;
    if(head==NULL)
    {
        printf("\nunderflow");
    }
    else
    {
        printf("\n elements in queue\n");

        while(ptr->next!=head)
        {
            printf("%d->",ptr->data);
            ptr=ptr->next;
        }
        printf("%d\n",ptr->data);
    }
}
 void main()
 {   int choice=0,item;
     while(choice != 7)
     {
         printf("\n*******************Main Menu******************\n");
         printf("\nChoose one option from the following list ....\n");
         printf("\n==============================================\n");
         printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
         printf("\nEnter your choice:");
         scanf("\n%d",&choice);

         switch(choice)
         {
         case 1:
            printf("Enter item to be inserted:");
            scanf("%d",&item);
            enqueue(item);
            break;

         case 2:
            dequeue();
            break;

         case 3:
            display();
            break;

         case 4:
            exit(0);
            break;

         default:
            printf("Please enter valid choices..");
         }
     }
 }
