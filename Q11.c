#include<stdio.h>
#include<stdlib.h>
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
}

void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void bubble(int arr[], int n)
{
 int i,j;
 for(i=0;i<n;i++)
 {
     for(j=0;j<n-i;j++)
     {
         if(arr[j]>arr[j+1])
            swap(&arr[j],&arr[j+1]);
     }
 }
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
void selection(int arr[],int n)
{
    int i,j,min_idx;
    for(i=0;i<n-1;i++)
    {
        min_idx=i;
        for(j=i+1;j<n-1;j++)
        {
            if(arr[j]<arr[min_idx])
                min_idx=j;
        }
        if(min_idx!=i)
        {
            swap(&arr[min_idx],&arr[i]);
        }
    }
}



void merge(int arr[], int l, int mid, int r)
{
    int n1 = (mid - l) + 1;
    int n2 = r - mid;

    int left[n1], right[n2];

    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[l + i];
    }

    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

void quicksort(int number[],int first,int last)
{
    int i,j,pivot,temp;
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;
        while(i<j)
        {
            while(number[i]<=number[pivot])//&&i<last)
                i++;
            while(number[j]>number[pivot])
                j--;
            if(i<j)
            {
             temp=number[i];
             number[i]=number[j];
             number[j]=temp;
            }
        }
        temp=number[pivot];
        number[pivot]=number[j];
        number[j]=temp;
        quicksort(number,first,j-1);
        quicksort(number,j+1,last);
    }
}

void main()
{
    int arr[50] ,sel,size,ch;
    sel=0;
    while(sel!=7)
    {   printf("\n***************MENU****************\n");
        printf("Select the option\n1.Enter values in array\n2.Print Array\n3.Sort using bubbleSort\n4.Sort using selectionSort\n5.Sort using InsertionSort\n6.Sort using MergeSort\n7.Sort using QuickSort\n");
        printf("====================================\n");
        printf("Choice:");
        scanf("%d",&ch);

        switch(ch)
        {
        case(1):
            printf("Enter number of elemnt:");
            scanf("%d",&size);
            printf("Enter elements\n");
            for(int i=0;i<size;i++)
            {
                scanf("%d",&arr[i]);
            }
            break;
        case(2):
            display(arr,size);
            break;
        case(3):
            bubble(arr,size);
        case(4):
            insertion(arr,size);
            break;
        case(5):
            selection(arr,size);
            break;
        case(6):
            mergeSort(arr,0,size-1);
            break;
        case(7):
            quicksort(arr,0,size-1);
            break;
        }
    }
}
