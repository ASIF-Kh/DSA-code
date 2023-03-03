#include<stdio.h>

int linearsearch(int arr[],int size,int value)
{
    for(int i=0; i<size;i++)
    {
        if(arr[i]==value)
            return i;
    }
    return -1;
}
void insertion(int arr[], int n)
{
    for(int step=1;step<n;step++)
    {
        int key=arr[step];
        int j=step-1;

        while(key<=arr[j]&&j>=0)
        {
        arr[j+1]=arr[j];
        --j;
        }
        arr[j+1]=key;
    }
}
void show(int a[],int s)
{
    for(int i =0;i<s;i++)
    printf("\n%d",a[i]);
}
int binarysearch(int a[],int s, int sear)
{
    int first=0;
    int last=s-1;
    int middle=(first+last)/2;
    while(first<=last)
    {
        if(a[middle]<sear)
        first=middle+1;
        else if(a[middle]==sear){
            return middle;
            break;
        }
        else
            last=middle+1;
        middle=(first+last)/2;
    }
    if(first>last)
        return -1;
}

int main()
{
    int size, arr[100], value,pos,sel;
    printf("Enter number of element:");
    scanf("%d",&size);
    printf("\nEnter Elements\n");
    for(int i=0; i<size; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter value to search:");
    scanf("%d",&value);
    printf("choose method of search\n1.Linear Seaech\n2.Binary Search\nchoose:");
    scanf("%d",&sel);
    switch(sel)
    {
case(1):
    pos=linearsearch(arr,size,value);
    break;
case(2):
    insertion(arr,size);
    printf("Sorted Array\n");
    show(arr,size);
    pos=binarysearch(arr,size,value);
    break;
    }

    if(pos>=0)
    {
        printf("\nPosition of %d is %d",value,pos+1);
    }
    else
    {
        printf("\nValue not found");
    }
}
