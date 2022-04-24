#include<stdio.h>
#include<string.h>//字符串相关函数头文件

//获取字符串长度函数
//size_t strlen(const char *s);

int main()
{
    char s1[100]="hello";
    printf("s1_len=%d\n",strlen(s1));//s1_len=5,而不是100
    printf("s1_size=%d\n",sizeof(s1));

    char *s2="hello";
    printf("s2_len=%d\n",strlen(s2));
    printf("s2_size=%d\n",sizeof(s2));//这里的S2是指针变量，大小一定为8
    
    return 0;
}