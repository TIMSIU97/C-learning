#include<stdio.h>

//定义一个共用体

union un{
    int a;
    int b;
    int c;
};

int main()
{
    //定义共用体变量
    union un myun;
    myun.a=100;
    myun.b=200;
    myun.c=300;
    //共用体所有成员共用同一块内存
    printf("a=%d,b=%d,c=%d\n",myun.a,myun.b,myun.c);

    return 0;

}