#include<stdio.h>

//类型转换//
//自动转换原则：内存小的类型，向内存大的类型转换，以保证精度不降低
int main()
{
    printf("%d\n",5/2);///表达式（5/2）中全是int，结果也是int---2
    printf("%lf\n",5.0/2);//表达式出现了带小数点的实数，参加运算的成员全变成double，结果也是double-----2.500000

    ////表达式中有符号，也有无符号数，全员变为无符号数参加运算，结果也是无符号数
    int a=-8;
    unsigned int b=7;
    if (a+b>0)
    {
        printf("a+b>0\n");
    }
    else
    {
        printf("a+b<=0\n");
    }

    //赋值语句中，等号右边的类型自动转换为左边的类型
    int m;
    float n=5.8f;//后面加f表示5.8是float类型，不加是double
    m=n;
    printf("m=%d\n",m);///m=5=int n
    printf("n=%f\n",n);///n=5.800000
    /////////////自动类型转换只在运算过程中临时转换，并不影响变量的值和其类型


    ////强制类型转换：通过类型转换运算实现
    ////（类型说明符）（表达式）
    ////如:(float)a;    (int)(x+y);
    int x=10;
    int y=4;
    float w;
    w=x/y;//x,y为Int
    printf("w=%f\n",w);////输出2.000000
    w=(float)x/(float)y;//强转x,y为float
    printf("w=%f\n",w);////输出2.500000

    return 0;
}