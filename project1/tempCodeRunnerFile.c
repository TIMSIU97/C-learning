#include<stdio.h>

//数组指针
void test1()
{
    //定义数组指针
    int a[3][5];
    int (*p)[5];

    printf("a=%p\n",a);
    printf("a+1=%p\n",a+1);

    p=a;

    printf("p=%p\n",p);
    printf("p+1=%p\n",p+1);
    //此时p相当于a
}

//数组指针的用法
//可以将二维数组的首地址传递到另一个函数里面
//此时函数的形参要定义为数组指针
void fun(int(*p)[5])
{
    p[0][1]=101;
}
void test2()
{
    int i,j;
    int a[3][5]={0};
    fun(a);
    for(i=0;i<3;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    test2();
    return 0;
}

