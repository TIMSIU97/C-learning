#include<stdio.h>

//指针与函数
//函数的传参方式之复制传参：实参传给形参，形参改变，与实参无关系
void myfun1(int a,int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;

    printf("in fun:a=%d,b=%d\n",a,b);
}

void test1()
{
    int a=100,b=20;
    printf("before fun:a=%d,b=%d\n",a,b);//100 20

    myfun1(a,b);//in fun:20 100

    printf("after fun:a=%d,b=%d\n",a,b);//100 20，实参并无变化
}

//函数传参方式之地址传参，将实参的地址传递给形参，形参对保存地址的内容进行操作，实参也会跟着改变
//如果实参是普通变量，地址传参的形参就要是一级指针
//如果实参是一级指针，地址传参的形参就要是二级指针
void myfun2(int *p,int *q)
{
    int temp;
    temp=*p;
    *p=*q;
    *q=temp;

    printf("in fun:*p=%d,*q=%d\n",*p,*q);
    printf("p=%p,q=%p\n",p,q);
}

void test2()
{
    int a=100,b=20;
    printf("before fun:a=%d,b=%d\n",a,b);//100 20

    myfun2(&a,&b);

    printf("after fun:a=%d,b=%d\n",a,b);//20 100
}

//传一维数组
//void fun1(int p[])//形式1
void fun1(int *p)//常用，通过指针变量传
{
    printf("%d\n",p[2]);
    printf("%d\n",*(p+3));
}

//传二维数组
//void fun2(int p[][4])//形式1
void fun2(int (*p)[4])//通过数组指针传参
{
    //p[x][y]<==>*(*(p+x)+y)，等价关系
    printf("%d\n",p[0][2]);
    printf("%d\n",*(*(p+1)+2));
}

void test3()
{
    int a[2][4]={1,2,3,4,
                5,6,7,8};
    fun2(a);
}

//传指针数组
void fun3(char **q)
{
    int i;
    for ( i = 0; i < 3; i++)
    {
        printf("%s\n",q[i]);
    }
}

void test4()
{
    char *p[3]={"hello","world","kitty"};
    fun3(p);
}

int main()
{
    test4();

    return 0;
}
