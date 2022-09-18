#include<stdio.h>
#include<stdlib.h>

#define OK     1
#define ERROR  0

typedef char    ElemType;
typedef int     Status;

//˫��ѭ������

typedef struct dualnode
{
    ElemType data;
    struct dualnode* prior;
    struct dualnode* next;
}node, *NODE;

//��ʼ������
Status InitList(node **L)
{
    node *p,*q;
    int i;

    *L = (NODE)malloc(sizeof(node));
    if(!(*L))
        return ERROR;

    (*L)->next = (*L)->prior = NULL;
    p=(*L);

    for(i=0; i<26; i++)//ѭ������26���˫������
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

//�ַ�λ�ƺ���
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

    printf("������һ��������\n");
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