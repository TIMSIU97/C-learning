#include<stdio.h>

//goto循环
//goto主要用于在一个函数里面实现代码的跳转，也可以实现循环
int main()
{
    //使用goto实现跳转
    printf("1111111111111111\n");
    goto NEXT;

    printf("2222222222222222\n");

    printf("3333333333333333\n");

NEXT:
    printf("4444444444444444\n");
    printf("hello world\n");

    /////实现循环，求1到100的累加
    printf("************************\n");
    int i=1;
    int sum=0;

LOOP:
    sum+=i;
    i++;

    if (i<=100)
    {
        goto LOOP;
    }
    printf("1+2+3+...+100=%d\n",sum);
    //注意：在平时编写代码，尽量少用goto，可读性比较差


    return 0;
}