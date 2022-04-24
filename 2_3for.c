#include<stdio.h>

//循环控制

int main()
{
    //for循环
    //for(表达式1；表达式2；表达式3)
    //{
    //    语句
    //}
    //执行顺序：1>2成立>语句>3>2成立>语句>3>2成立>语句>...>2不成立>循环结束

    //求1到100的累加和
    int i;
    int sum=0;
    for ( i = 1; i <=100; i++)
    {
        sum+=i;//sum=sum+i
    }
    printf("1+2+3+...+100=%d\n",sum);


    return 0;
}