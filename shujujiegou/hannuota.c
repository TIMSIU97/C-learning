#include<stdio.h>

//��ŵ���ݹ�

//�������ܣ��� n �����ӣ��� x ���� y �ᵽ z
void move(int n, char x, char y, char z)
{
    if(n == 1)
    {
        printf("%c --> %c\n",x,z);//��x�ᵽz
    }
    else
    {
        move(n-1,x,z,y);//��n-1������ӣ�����z�ᵽy
        printf("%c --> %c\n",x,z);//�ѵ�n�����Ӵ�x�ᵽz
        move(n-1,y,x,z);//��ʣ�µ�n-1�����ӣ���y����x�ᵽz
    }
}

int main()
{
    int n;
    printf("�����뺺ŵ����������:\n");
    scanf("%d",&n);

    move(n,'X','Y','Z');

    return 0;
}