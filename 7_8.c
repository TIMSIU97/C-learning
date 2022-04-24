#include<stdio.h>
#include<string.h>

//字符串切割函数
//char *strtok(char *str,const char *delim);

int main()
{
    char s[]="111:2222222:333:4444444444444:555";
    char *ret;

    ret=strtok(s,":");//第一次切割
    printf("ret=%s\n",ret);

    while((ret=strtok(NULL,":"))!=NULL)//后面的切割都要传NULL
    {
        printf("ret=%s\n",ret);
    }


    return 0;
}