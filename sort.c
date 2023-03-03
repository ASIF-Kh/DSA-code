#include<stdio.h>
#define size 10
int swap(int* x, int* y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int merge(int lb, int mid, int ub, int arr[])
{
    int lb1=lb;
    int lb2=mid+1;
    int temp[size];
    int k=lb;
    while(lb1<=mid&&lb2<=ub)
    {
        if(arr[lb1]<arr[lb2])
        {
            temp[k]=arr[lb1];
            lb1++;
        }
        else
        {
            temp[k]=arr[lb2];
            lb2++;
        }
        k++;
    }
    while(lb1<=mid)
    {
        temp[k]=arr[lb1];
        k++, lb1++;
    }

    while(lb2<=ub)
    {
      temp[k]=arr[lb2];
        k++, lb2++;
    }
    for(int i=lb; i<=ub; i++)
    {
        arr[i]=temp[i];
    }
}

int mergesort(int lb, int ub,int arr[])
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergesort(lb,mid,arr);
        mergesort(mid+1,ub,arr);
        merge(lb,mid,ub,arr);
    }
}
int partition(int lb,int ub,int arr[])
{
    int start=lb;
    int end=ub;
    int pivot=arr[lb];

    while(start<end)
    {
        while(arr[start]<=pivot)
        {
            start++;
        }
        while(arr[end]>pivot)
        {
            end--;
        }
        if(start<end)
        {
            swap(&arr[start],&arr[end]);
        }
    }
    swap(&arr[lb],&arr[end]);
    return end;
}

int quick(int lb, int ub, int a[])
{
    if(lb<ub)
    {
      int pos=partition(lb,ub,a);
        quick(lb,pos-1,a);
        quick(pos+1,ub,a);
    }
}

int bubble(int lb, int ub, int a[])
{
    for(int i=lb; i<=ub; i++)
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

int main()
{
    int a[size];

    printf("Enter values:\n");
    for(int i=0; i<size; i++)
    {
        scanf("%d",&a[i]);
    }

    bubble(0,size-1,a);


    printf("Sorted values;\n");
    for(int i=0; i<10; i++)
    {
        printf("%d ",a[i]);
    }
}
