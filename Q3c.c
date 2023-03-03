#include<stdio.h>
#include<stdlib.h>
//circular linked list
struct node
{
    int data;
    struct node *next;
};
struct node *head;

void begininsert()
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
        if(head==NULL)
        {
            head=ptr;
            ptr->next=head;
        }
        else
        {
            temp = head;
            while(temp->next != head)
                temp=temp->next;
            ptr->next=head;
            temp->next=ptr;
            head=ptr;
        }
        printf("\nnode inserted\n");
    }
}

void show()
{
    struct node *ptr;
    ptr = head;
    if(head==NULL)
    {
        printf("\nnothing to print");
    }
    else
    {
        printf("\n printing values...\n");

        while(ptr->next!=head)
        {
            printf("%d->",ptr->data);
            ptr=ptr->next;
        }
        printf("%d\n",ptr->data);
    }
}

void lastinsert()
{
    struct node *ptr, *temp;
    int item;
    ptr=(struct node *)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter Data:");
        scanf("%d",&item);
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
        printf("\nnode inserted");
    }
}
void indexinsert()
{   int index,item;
    struct node *ptr;
    ptr=head;
    printf("Enter DATA");
    scanf("%d",&item);
    printf("Enter position");
    scanf("%d",&index);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data= item;

    for(int i=1;i<index;i++)
    {
        ptr=ptr->next;
    }
    newnode->next=ptr->next;
    ptr->next=newnode;
    printf("\nnode inserted\n");
}
void begindelete()
{
    struct node *ptr;
    if(head==NULL)
    {
        printf("\nUNDERFLOW\n");
    }
    else if (head->next==head)
    {
        head=NULL;
        free(head);
        printf("\nnode deleted");
    }
    else
    {
        ptr=head;
        while(ptr->next != head)
        {
            ptr=ptr->next;
        }
        ptr->next=head->next;
        free(head);
        head=ptr->next;
        printf("\nnode deleted\n");
    }
}

void lastdelete()
{
    struct node *ptr, *preptr;
     if(head==NULL)
    {
        printf("\nUNDERFLOW\n");
    }
    else if (head->next==head)
    {
        head=NULL;
        free(head);
        printf("\nnode deleted");
    }
    else
    {
        ptr=head;
        while(ptr->next!=head)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        preptr->next=ptr->next;
        free(ptr);
        printf("\nnode deleted\n");
    }

}
void indexdelete()
{   int index;
    struct node *ptr, *preptr;
    ptr=head;
    printf("Enter position");
    scanf("%d",&index);
    for(int i=1;i<index;i++)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
        preptr->next=ptr->next;
        free(ptr);
    printf("\nnode inserted\n");
}
void main()
{
    int sel=0;
    while(sel!=8)
    {
    printf("-------------MENU--------------");
    printf("\nSelect the following operation\n1.Insert at Beginning\n2.Insert last\n3.insert at index\n4.Deletion at begining\n5.Deletion at last\n6.Deletion at index\n7.Print");
    printf("\nEnter selected option:");
    scanf("%d",&sel);
    switch (sel)
    {
        case 1:
            begininsert();
            break;
        case 2:
            lastinsert();
            break;
        case 3:
            indexinsert();
            break;
        case 4:
            begindelete();
            break;
        case 5:
            lastdelete();
            break;
        case 6:
            indexdelete();
            break;
        case 7:
            show();
            break;
    }
    }

}

