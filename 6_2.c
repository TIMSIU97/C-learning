#include<stdio.h>
#include<stdlib.h>

//calloc函数
//void *calloc(size_t nmemb,size_t size);
//nmemb:要申请的空间的块数
//size:每块的字节数


int main(){
    char *p=(char *)calloc(3,100);

    return 0;
}

//realloc函数
//void *realloc(void *s,unsigned int newsize);
//功能：在原先s指向的内存上重新申请内存，新的内存的大小为newsize个字节

void test1()
{
    char *p;
    p=(char *)malloc(100);

    p=(char *)realloc(p,150);//增加空间
}

void test2()
{
    char *p;
    p=(char *)malloc(100);

    p=(char *)realloc(p,50);//减少空间
}