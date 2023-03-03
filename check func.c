#include<stdio.h>
int check(int a[])
{
    a[1]=5;
}

int main()
{
    int a[1]={0};
    check(a);
    printf("%d",a[1]);
}
