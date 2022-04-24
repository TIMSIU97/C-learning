#include<stdio.h>

//指针函数--指针作为函数的返回值

char *fun1()
{
    //函数内定义的变量用静态局部定义，不然会释放
    static char str[100]="hello world";
    return str;
}

void test1()
{
    char *p;
    p=fun1();
    printf("p=%s\n",p);
}

//函数指针--指针保存函数的地址
//函数的名字就是函数的首地址，即函数的入口地址
//定义方法：返回值类型  （*函数指针变量名）（形参列表）
//常用于将一个函数作为参数传递给另一个函数，要用到函数指针

int add(int x,int y)
{
    return x+y;
}

int sub(int x,int y)
{
    return x-y;
}

int mux(int x,int y)
{
    return x*y;
}

int dive(int x,int y)
{
    return x/y;
}

int process(int (*p)(int,int),int a,int b)
{
    int ret;
    ret=(*p)(a,b);
    return ret;
}

int main()
{
    int num;
    num=process(add,2,3);
    printf("num=%d\n",num);

    num=process(sub,2,3);
    printf("num=%d\n",num);

    num=process(mux,2,3);
    printf("num=%d\n",num);

    num=process(dive,2,3);
    printf("num=%d\n",num);


    return 0;
}