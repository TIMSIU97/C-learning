#include<stdio.h>
#include<string.h>

//字符串追加函数
//char *strcat(char *dest,const char *src);
//将src追加到dest后面，追加时追加\0。同样要保证dest空间够大

//char *strncat(char *dest,const char *src,size_t n);
//追加src前n个字符，到dest字符串的后面

int main()
{
    char s1[32]="hello world";
    char s2[32]="abcdef";

    //strcat是从s1的\0位置开始追加，直到s2的第一个\0后结束
    strcat(s1,s2);

    printf("s1=%s\n",s1);//s1=hello worldabcdef

    return 0;
}