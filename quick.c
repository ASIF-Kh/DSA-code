#include<stdio.h>
#include<stdlib.h>
#define size 10

int swap(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int bubblesort(int lb, int ub, int a[])
{
    for(int i=0;i<=ub;i++)
    {
        for(int j=0; j<=ub-i; j++)
        {
            if(a[j]>a[j+1])
            {
                swap(&a[j],&a[j+1]);
            }
        }
    }
}

int partition(int lb, int ub, int arr[])
{
    int start=lb;
    int end=ub;
    int pivot=arr[lb];

    while(start<end)
    {
        while(arr[start]<=pivot)
            start++;

        while(arr[end]>pivot)
            end--;
        if(start<end)
        {
            swap(&arr[start],&arr[end]);
        }
    }
    swap(&arr[end],&arr[lb]);
    return end;
}
int quicksort(int lb,int ub,int arr[])
{
    if(lb<ub)
    {
        int pos=partition(lb,ub,arr);
        quicksort(lb,pos-1,arr);
        quicksort(pos+1,ub,arr);
    }
}



int main()
{
int a[size];

    printf("Enter values:\n");
    for(int i=0; i<size; i++)
    {
        scanf("%d",&a[i]);
    }

    quicksort(0,size-1,a);


    printf("Sorted values;\n");
    for(int i=0; i<10; i++)
    {
        printf("%d ",a[i]);
    }
}
