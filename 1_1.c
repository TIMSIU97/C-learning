#include<stdio.h>

//测试基本数据类型的所占内存大小

int main()
{
    char a;
    short b;
    int c;
    long d;
    float e;
    double f;
    //sizeof可以获取数据类型所占内存大小
    printf("%d\n",sizeof(a));//1
    printf("%d\n",sizeof(b));//2
    printf("%d\n",sizeof(c));//4
    printf("%d\n",sizeof(d));//4 >>long类型占4个字节，说明编译器为32位
    printf("%d\n",sizeof(e));//4
    printf("%d\n",sizeof(f));//8
    return 0;
}