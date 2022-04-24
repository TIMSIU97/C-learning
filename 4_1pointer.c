#include<stdio.h>

//指针
//指针变量p存放着a的地址，p=&a取地址运算，*p相当于指针指向的变量

int main()
{
    int n=100;
    int *p;
    p=&n;
    printf("n=%d %d\n",n,*p);

    printf("*******************************\n");

    char *a;
    short *b;
    int *c;
    long *d;
    float *e;
    double *f;
    //指针变量的大小：32位为4字节，64位为8字节
    printf("sizeof(a)=%d\n" , sizeof(a));
    printf("sizeof(b)=%d\n" , sizeof(b));
    printf("sizeof(c)=%d\n" , sizeof(c));
    printf("sizeof(d)=%d\n" , sizeof(d));
    printf("sizeof(e)=%d\n" , sizeof(e));
    printf("sizeof(f)=%d\n" , sizeof(f));
    return 0;
}