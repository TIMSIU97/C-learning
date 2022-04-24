#include<stdio.h>

//指针数组
int main()
{
    //定义以及赋值指针数组
    int *p[10];
    int a;
    p[1]=&a;
    int b[10];
    p[2]=&b[3];

    //大多数情况下，指针数组都用来保存多个字符串
    char *name[5]={"follow me","basic","greatwall","fountain","cum"};
    int i;
    for(i=0;i<5;i++)
    {
        printf("%s\n",name[i]);
    }

    return 0;
}