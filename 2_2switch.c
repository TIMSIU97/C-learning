#include<stdio.h>

//switch语句
//注意：switch(表达式){};表达式只能是字符型或整形的，不能是浮点型
//case语句后的表达式不需要大括号

int main()
{
    int a=200;
    switch(a/100)
    {
        case 1:
            printf("%d/100=1\n",a);
            break;
        case 2:
            printf("%d/100=2\n",a);
            break;
        default:
            printf("无结果\n",a);
            break;

    }

    return 0;
}