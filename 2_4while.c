#include<stdio.h>

//while循环
//while(表达式)
//{
//    语句
//}
//执行顺序：表达式为真>执行语句>...>表达式为假>结束循环

//求1到100累加和
int main()
{
    int i=1;
    int sum=0;
    while(i<=100)
    {
        sum+=i;
        i++;
    }
    printf("1+2+3+...+100=%d\n",sum);

    //do...while循环
    //do{
    //     语句
    // }while(表达式);
    //执行顺序：先执行语句>while表达式为真>执行语句>...>while表达式为假>循环结束
    //注意：无论条件是否成立，do后面的语句都会执行一次，所以尽量少用do...while
    return 0;
}