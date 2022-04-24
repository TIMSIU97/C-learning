#include<stdio.h>

//枚举的定义方式
enum week{
    mon=3,tue,wed,thu,fri=4,sat,sun
};//枚举元素可以赋值，用来代表元素从几开始编号

int main()
{
    //定义枚举变量
    enum week day=mon;
    printf("%d\n",day);
    day=thu;
    printf("%d\n",day);
}