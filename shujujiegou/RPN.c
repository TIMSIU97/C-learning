#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

//逆波兰计算器

#define STACK_INIT_SIZE 20
#define STACKINCREMENT  10
#define MAXBUFFER       10

typedef double ElemType;
typedef struct
{
    ElemType *base;
    ElemType *top;
    int stacksize;
}sqStack;

void Pop()
{
}

void Push()
{
}









int main()
{
    sqStack s;
    char c;
    double d,e;
    char str[MAXBUFFER];//缓冲区
    printf("请按逆波兰表达式输入带计算数据，数据与运算符之间用空格隔开，以#作为结束标志：\n");
    scanf("%c",&c);

    while (c != '#')
    {
        while( isdigit(c) || c=='.')
        {
            str[i++] = c;
            str[i] = '\0';
            if( i >= 10)
            {
                printf("出错：输入的单个数据过大！\n");
                return -1;
            }
            scanf("%c", &c);
            if( c == ' ')
            {
                d = atof(str);//字符串转换为double型
                Push(&s, d);
                i=0;
                break;
            }
        }
        switch (c)
        {
        case '+':
            Pop(&s, &e);
            Pop(&s, &d);
            Push(&s, d+e);
            break;
        case '-':
            Pop(&s, &e);
            Pop(&s, &d);
            Push(&s, d-e);
            break;
        case '*':
            Pop(&s, &e);
            Pop(&s, &d);
            Push(&s, d*e);
            break;
        case '/':
            Pop(&s, &e);
            Pop(&s, &d);
            if(e != 0)
            {
                Push(&s, d/e);
            }
            else
            {
                printf("\n出错：除数为零\n");
                return -1;
            }
            break;
        }

        scanf("%c",&c);
    }
    Pop(&s, &d);
    printf("最终的计算结果为：%f\n",d);

    return 0;

}