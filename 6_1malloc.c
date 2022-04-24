#include<stdio.h>
#include<string.h>
#include<stdlib.h>//malloc函数的头文件
//动态分配：根据需要大小自由分配所需空间，按需分配
//分配在堆区，一般使用特定的函数进行分配
char *fun()
{
    //堆区开辟空间，手动申请手动释放，更加灵活
    //使用malloc函数的时候一般要进行强制类型转换
    char *str =(char*)malloc(100*sizeof(char));
    str[0]='h';
    str[1]='e';
    str[2]='l';
    str[3]='l';
    str[4]='o';
    str[5]='\0';
    return str;

}

//free函数：只能释放堆区的空间
//free释放空间必须为malloc,calloc,relloc的返回值对应的空间
//注意，当free(p)后，p还指向原先申请的内存，p变成野指针
//所以一般为了放置野指针，会在free完毕后给p赋值NULL
int main()
{
    char *p;
    p=fun();
    printf("p=%s\n",p);

    //free释放空间
    free(p);
    p=NULL;//放置野指针

    return 0;
}