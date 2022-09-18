#include<stdio.h>

//汉诺塔递归

//函数功能：将 n 个盘子，从 x 借助 y 搬到 z
void move(int n, char x, char y, char z)
{
    if(n == 1)
    {
        printf("%c --> %c\n",x,z);//从x搬到z
    }
    else
    {
        move(n-1,x,z,y);//把n-1层的盘子，借助z搬到y
        printf("%c --> %c\n",x,z);//把第n个盘子从x搬到z
        move(n-1,y,x,z);//把剩下的n-1个盘子，从y借助x搬到z
    }
}

int main()
{
    int n;
    printf("请输入汉诺塔盘子数量:\n");
    scanf("%d",&n);

    move(n,'X','Y','Z');

    return 0;
}