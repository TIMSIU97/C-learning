#include<stdio.h>

//字符串与指针

int main()
{
    char string[100]="I love C!";//数组初始化字符串

    char *str="I love C!";//不推荐，字符串指针，不可修改内容

    char *str=(char*)malloc(10*sizeof(char));//在堆区动态申请空间，首地址给str赋值

    return 0;
}