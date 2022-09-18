#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//栈的顺序存储结构
//实现二进制转十进制

#define STACK_INIT_SIZE 20
#define STACKINCREMENT  10

typedef char ElemType;
typedef struct bin2dec
{
    ElemType *base;
    ElemType *top;
    int stacksize;
}sqStack;

//初始化栈
void InitStack(sqStack *s)
{
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    s->top = s->base;
    s->stacksize = STACK_INIT_SIZE;
}

//压栈
void Push(sqStack *s, ElemType e)
{
    if(s->top - s->base >= s->stacksize)
    {
        //如果栈满了，要realloc增加空间
        s->base = (ElemType*)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(ElemType));
        if( !s->base )
        {
            exit(0);
        }
    }

    *(s->top) = e;
    s->top++;
}

//弹栈
void Pop(sqStack *s, ElemType *e)
{
    if(s->top == s->base)
    {
        return;
    }
    *e = *--(s->top);
}

//栈长度
int StackLen(sqStack s)
{
    return (s.top - s.base);
}

int main()
{
    ElemType c;
    sqStack s;
    int len,i,sum=0;

    InitStack(&s);

    //初始化栈中的二进制数
    printf("请输入二进制数，输入#符号表示结束\n");
    scanf("%c",&c);
    while(c != '#')
    {
        Push(&s, c);
        scanf("%c",&c);
    }

    getchar();//将键盘输入缓冲区的'\n'(回车)去掉，以免程序混乱

    len = StackLen(s);
    printf("栈的当前容量是：%d\n",len);

    //开始转换二进制数
    for( i=0; i<len; i++)
    {
        Pop(&s, &c);
        sum = sum + (c-48) * pow(2,i);//(c-48)的48是ascii码中的0。pow是幂函数，指2^i
    }

    printf("转化为十进制数是：%d\n", sum);

    return 0;
}