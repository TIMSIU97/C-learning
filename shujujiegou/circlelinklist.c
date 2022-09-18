#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;
typedef struct node* NODE;

node *create(int n)
{
    NODE p=NULL, head;
    head=(NODE)malloc(sizeof(node));
    p=head;
    NODE s;
    int i=1;

    if(n!=0)
    {
        while(i<=n)
        {
            s=(NODE)malloc(sizeof(node));
            s->data=i++;
            p->next=s;
            p=s;
        }
        s->next=head->next;//�ջ�
    }
    free(head);//ͷ���ɾ��

    return s->next;//���ص�һ�����
}

int main()
{
    int n=41,m=3,i;
    node *p=create(n);
    NODE temp;

    m%=n;//m=n%m=41%3=2

    while(p!=p->next)
    {
        for(i=1;i<m-1;i++)
        {
            p=p->next;
        }

        printf("%d->",p->next->data);

        temp=p->next;
        p->next=temp->next;
        free(temp);

        p=p->next;
    }

    printf("%d\n",p->data);

    return 0;
}
