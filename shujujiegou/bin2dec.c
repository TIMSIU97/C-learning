#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//ջ��˳��洢�ṹ
//ʵ�ֶ�����תʮ����

#define STACK_INIT_SIZE 20
#define STACKINCREMENT  10

typedef char ElemType;
typedef struct bin2dec
{
    ElemType *base;
    ElemType *top;
    int stacksize;
}sqStack;

//��ʼ��ջ
void InitStack(sqStack *s)
{
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    s->top = s->base;
    s->stacksize = STACK_INIT_SIZE;
}

//ѹջ
void Push(sqStack *s, ElemType e)
{
    if(s->top - s->base >= s->stacksize)
    {
        //���ջ���ˣ�Ҫrealloc���ӿռ�
        s->base = (ElemType*)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(ElemType));
        if( !s->base )
        {
            exit(0);
        }
    }

    *(s->top) = e;
    s->top++;
}

//��ջ
void Pop(sqStack *s, ElemType *e)
{
    if(s->top == s->base)
    {
        return;
    }
    *e = *--(s->top);
}

//ջ����
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

    //��ʼ��ջ�еĶ�������
    printf("�������������������#���ű�ʾ����\n");
    scanf("%c",&c);
    while(c != '#')
    {
        Push(&s, c);
        scanf("%c",&c);
    }

    getchar();//���������뻺������'\n'(�س�)ȥ��������������

    len = StackLen(s);
    printf("ջ�ĵ�ǰ�����ǣ�%d\n",len);

    //��ʼת����������
    for( i=0; i<len; i++)
    {
        Pop(&s, &c);
        sum = sum + (c-48) * pow(2,i);//(c-48)��48��ascii���е�0��pow���ݺ�����ָ2^i
    }

    printf("ת��Ϊʮ�������ǣ�%d\n", sum);

    return 0;
}