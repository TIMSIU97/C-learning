#include<stdio.h>
#include<stdlib.h>

//拉丁方阵问题
typedef struct node
{
    int data;
    struct node* next;
}node;
typedef struct node* NODE;


NODE create( int n)
{
    int i=1;
    NODE p,temp,head;
    head=(NODE)malloc(sizeof(node));
    p = head;

    for(; i<=n;i++)
    {
        temp = (NODE)malloc(sizeof(node));
        temp->data = i;
        p->next = temp;
        p = temp;
    }
    p->next = head->next;
    free(head);
    return p->next;//返回第一个结点地址
}

int main()
{
    node *head;
    int num=9;
    int i,j;
    head = (NODE)malloc(sizeof(node));
    head = create(num);

    NODE p,r;
    p=head;
    for(i=0;i<num;i++)
    {
        r=p;
        for(j=0;j<num;j++)
        {
            printf("%-4d",r->data);
            r=r->next;
        }
        printf("\n");
        p=p->next;
    }
    return 0;
}