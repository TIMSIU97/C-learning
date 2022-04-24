#include<stdio.h>

//const修饰全局变量
const int a=100;
void test1()
{
    //全局变量只能使用，不能更改
    printf("a=%d\n",a);

    //a=666;//报错
    printf("a=%d\n",a);

    int *p=&a;
    //*p=888;//报错
    printf("a=%d\n",a);
}

//const修饰局部变量
void test2()
{
    const int b=200;
    printf("b=%d\n",b);

    //b=666;//报错
    printf("b=%d\n",b);

    int *p=&b;
    *p=888;
    printf("b=%d\n",b);//b=888
}

//const修饰指针变量
void test3()
{
    int c=100;
    int *p=&c;
    //const int *p=&c;//*p=777报错
    //int *const p=&c;//p=&d报错
    printf("*p=%d\n",*p);

    c=666;
    printf("*p=%d\n",*p);

    *p=777;
    printf("*p=%d\n",*p);

    int d=888;
    p=&d;
    printf("*p=%d\n",*p);
}

int main()
{
    test3();

    return 0;
}