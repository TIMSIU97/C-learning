#include<stdio.h>
#include<stdlib.h>//头文件

//字符串转换数值
//atoi/atol/atof
//int atoi(const char *nptr);将字符串转为整数返回

int main()
{
    char s1[]="7856";
    int ret1=atoi(s1);

    printf("ret1=%d\n",ret1);

    char s2[]="3.1415926";
    double ret2=atof(s2);

    printf("ret2=%lf\n",ret2);


    return 0;
}

