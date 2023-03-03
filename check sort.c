#include<stdio.h>
int swap(int* x, int*y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
//int bubblesort(int lb, int ub, int a[])
//{
//    for(int i=0;i<=ub;i++)
//    {
//        for(int j=0; j<=ub-i; j++)
//        {
//            if(a[j]>a[j+1])
//            {
//                swap(&a[j],&a[j+1]);
//            }
//        }
//    }
//}


int partition(int lb, int ub,int a[])
{
    int start=lb;
    int end=ub;
    int pivot=a[lb];

    while(start<end)
    {
        while(a[start]<=pivot)
            start++;
        while(a[end]>pivot)
            end--;
        if(start<end)
            swap(&a[start],&a[end]);
    }
    swap(&a[lb],&a[end]);
    return end;
}


int quicksort(int lb, int ub, int a[])
{
    if(lb<ub)
    {
        int pos=partition(lb,ub,a);
        quicksort(lb,pos-1,a);
        quicksort(pos+1,ub,a);
    }
}



int main()
{
    int a[10]={1,4,7,8,5,2,-8,6,9,0};
    quicksort(0,9,a);

    for(int i=0; i<10; i++)
    {
        printf("%d ",a[i]);
    }
}
