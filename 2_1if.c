#include<stdio.h>

//控制语句

int main()
{
    ////if语句
    int n=40;
    if(n>=50)
    {
        printf("%d>=50",n);
    }
    else
    {
        printf("%d<=50\n",n);
    }

    //if, else if, else
    if (n>50)
    {
        printf("%d>50",n);
    }
    else if (n==50)
    {
        printf("%d=50",n);
    }
    else
    {
        printf("%d<50",n);
    }
    
    return 0;
}