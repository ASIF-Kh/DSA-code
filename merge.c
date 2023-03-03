#include<stdio.h>

int merge(int lb,int mid, int ub, int arr[])
{
    int temp[10];
    int i=lb;
    int j=mid+1;
    int k=lb;

    while(i<=mid&&j<=ub)
    {
        if(arr[i]<=arr[j])
        {
            temp[k]=arr[i];
            i++,k++;
        }
        else
        {
            temp[k]=arr[j];
            j++,k++;
        }
    }
    if(i>mid)
    {
        while(j<=ub)
        {
            temp[k]=arr[j];
            k++,j++;
        }
    }
    else
    {
        while(i<=mid)
        {
            temp[k]=arr[i];
            k++,i++;
        }
    }
    for(int l=lb; l<=ub; l++)
    {
        arr[l]=temp[l];
    }

}

int mergesort(int lb, int ub, int arr[])
{
    if(lb<ub)
    {   int mid=(ub+lb)/2;
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
        while(start<=pivot)
        {
            start++;
        }
        while(end>pivot)
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






int main()
{
    int arr[5]={5,7,3,4,9};
    mergesort(0,4,arr);

    for(int i=0; i<5; i++)
    {
        printf("%d\n",arr[i]);
    }
}
