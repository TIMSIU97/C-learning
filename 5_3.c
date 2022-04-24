#include<stdio.h>

//main函数传参
//argc:标识命令终端传入的参数的个数
//argv:是一个指针数组，用于保存每一个命令终端传入的参数
int main(int argc,char *argv[])
{
    int i;
    printf("argc=%d\n",argc);
    for ( i = 0; i < argc; i++)
    {
        printf("argv[%d]=%s\n",i,argv[i]);
    }
    
    return 0;
}