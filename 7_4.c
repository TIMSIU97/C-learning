#include<stdio.h>
#include<string.h>

//字符串比较函数
//int strcmp(const char *s1,const char *s2);
//逐个字符去比较ascii码，一旦比较出大小返回。s1大返回1，s2大返回-1，相等返回0

//int strncmp(const char *s1,const char *s2,size_t n);
//比较两个字符串前n个字节

int main()
{
    char s1[]="hello";
    char s2[]="hella";
    //strcmp函数一个一个字符比较，只要出现不一样的，就立即返回
    //int ret=strcmp(s1,s2);
    int ret=strncmp(s1,s2,4);

    if(ret==0)
        printf("s1=s2\n");
    else if(ret>0)
        printf("s1>s2\n");
    else
        printf("s1<s2\n");

    return 0;
}