#include<stdio.h>

int main()
{
    //字符类型输出时注意%c与%d
    char ch1='w';///w的ascii码为119
    printf("ch1=%c %d\n",ch1,ch1);

    char ch2=97;///97在ascii码中等价于字母a
    printf("ch2=%c %d\n",ch2,ch2);
///////////////////////////////////////格式化输出字符//////////////////////////////////////
    int a=100;
    printf("a=%d\n",a);//十
    printf("a=%o\n",a);//八-144
    printf("a=%#o\n",a);//八进制带前导符-0144，规范
    printf("a=%x\n",a);//十六-64
    printf("a=%#x\n",a);//十六进制带前导符-0X64

    float b=3.1415926;//浮点型
    double c=2345.2345;
    printf("b=%f\n",b);
    printf("c=%lf\n",c);

    char d='y';//字符变量
    printf("d=%c %d\n",d,d);

    char e[]="hello world";//字符串变量
    printf("e=%s\n",e);

    int f=999;//输出地址----%p
    printf("&f = %p\n",&f);//////&:取一个变量的地址，一般地址用十六进制数表示-000000f49f9ff7c4

    printf("*****************************\n");

    int m=456;
    printf("%d%d\n",m,m);

    printf("%5d%5d\n",m,m);// %5d:输出的宽度为5，右对齐，如果实际宽度小于5则左边补空格；如果大于5则无效
    printf("%05d%05d\n",m,m);// %05d:输出宽度为5，右对齐，左补0
    printf("%-5d%-5d\n",m,m);// %-5d：输出宽度为5，左对齐，右补空格
    
    float n=3.678;
    printf("n=%f\n",n);//默认保留6位小数
    printf("n=%.2f\n",n);//%.2f:小数点后保留2位且可以四舍五入




    return 0;
    
}