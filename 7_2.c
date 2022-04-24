#include<stdio.h>
#include<string.h>

//字符串拷贝函数
//char *strcpy(char *dest,const char *src);
//字符串包括\0都会被复制
//dest的空间要保证足够大，不然会出问题

//char *strncpy(char *dest,const char *src,size_t n);
//将src的字符串前n个字节，拷贝到dest中。不拷贝\0

int main()
{
    char s1[32]="hello world";
    char s2[32]="abcdefg";

    strcpy(s1,s2);

    printf("s1=%s\n",s1);

    return 0;
}