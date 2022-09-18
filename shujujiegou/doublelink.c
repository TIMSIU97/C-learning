#include<stdio.h>
#include<stdlib.h>

#define OK     1
#define ERROR  0

typedef char    ElemType;
typedef int     Status;

//双向循环链表

typedef struct dualnode
{
    ElemType data;
    struct dualnode* prior;
    struct dualnode* next;
}node, *NODE;

//初始化链表
Status InitList(node **L)
{
    node *p,*q;
    int i;

    *L = (NODE)malloc(sizeof(node));
    if(!(*L))
        return ERROR;

    (*L)->next = (*L)->prior = NULL;
    p=(*L);

    for(i=0; i<26; i++)//循环创建26结点双向链表
    {
        q = (NODE)malloc(sizeof(node));
        if(!q)
            return ERROR;

        q->data = 'A'+i;
        q->next = p->next;
        q->prior = p;
        p->next = q;

        p = q;
    }
    p->next = (*L)->next;
    (*L)->next->prior = p;
    (*L)->prior = p;

    return OK;
}

//字符位移函数
void Caesar(node **L, int i)
{
    if(i > 0)
    {
        do
        {
            (*L) = (*L)->next;
        }while( --i );
    }
    if(i < 0)
    {
        do
        {
            (*L) = (*L)->prior;
        } while ( ++i );
    }
}


int main()
{
    NODE L;
    int i,n;

    InitList(&L);

    printf("请输入一个整数：\n");
    scanf("%d",&n);

    Caesar(&L, n);
    if(n > 0)
    {
        for(i=0; i<26; i++)
        {
            L = L->next;
            printf("%c ",L->data);
        }
    }
    if(n < 0)
    {
        L = L->prior;
        for(i=0; i<26; i++)
        {
            L = L->next;
            printf("%c ",L->data);
        }
    }

    return 0;
}