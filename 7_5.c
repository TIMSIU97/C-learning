#include<stdio.h>
#include<string.h>

//字符查找函数
//char *strchr(const char *s,int c);
//找到了返回字符的地址，没找到返回NULL
int main()
{
    char s[]="hel6lo wor6ld";
    
    //char *ret=strchr(s,'6');
    char *ret=strrchr(s,'6');

    if(ret == NULL)
        printf("找不到\n");
    else
        printf("找到了在 %d\n",ret-s);


    return 0;
}