#include<stdlib.h>
#include<stdio.h>
struct node
{
    int data;
    struct node* next;
};
struct node *f=NULL;
struct node *r=NULL;

void enqueue(int item)
{
    struct node* t;
    t=(struct node*)malloc(sizeof(struct node));
    t->data=item;
    t->next=NULL;
    if((r==NULL)&&(f==NULL))
    {
        f=r=t;
        r->next=f;
    }
    else
    {
        r->next=t;
        r=t;
        t->next=f;
    }
}
void dequeue()
{
    struct node* t;
    t=f;
    if((f==NULL)&&(r==NULL))
        printf("\nQueue Empty");
    else if(f==r)
    {   printf("Dequeue done on value %d",t->data);
        f=r=NULL;
        free(t);
    }
    else{
        printf("Dequeue done on value %d",t->data);
        f=f->next;
        r->next = f;
        free(t);

    }
}
void show()
{
    struct node* ptr;
    ptr=f;
    if((f==NULL)&&(r==NULL))
        printf("\nEmpty queue\n");
    else
    {
        while(ptr->next!=f){
        printf("%d\n",ptr->data);
        ptr=ptr->next;}
        printf("%d\n",ptr->data);
    }

}

int main()
{
    int ch,n,i,data,l;
    while(ch!=4)
    {
    printf("\n1.Enqueue\n2.Dequeue\n3.Print\n4.Exit");
    printf("\nSelect:");
    scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nInsert:");
            scanf("%d",&data);
            enqueue(data);
            printf("\nEnqueue done\n");
            break;
        case 2:
            dequeue();
            break;
        case 3:
            show();
            break;
        default:
            printf("\nEnter valid value\n");

        }


    }
}
