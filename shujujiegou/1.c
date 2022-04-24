#include<stdio.h>
#include<stdlib.h>

typedef struct linklist{
    int data;
    struct linklist *next;
}node;
typedef struct linklist* NODE;
//����20��Ԫ�ص�����
void linklist_create(node **head)//
{
    node *r,*p;
    r=*head;
    int i;
    srand(1);

    for(i=0;i<20;i++)
    {
        p=(NODE)malloc(sizeof(node));
        p->data=rand()%100+1;
        p->next=(*head)->next;
        r->next=p;
        r=p;
    }
    r->next=NULL;

}
//��ӡ����
void linklist_print(node *head)//
{
    node *p;
    p=head->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
//�ͷ�����ռ�
void linklist_free(node **p_head)//
{
    node *pb=*p_head;
    while(*p_head!=NULL)
    {
        pb=*p_head;
        *p_head=(*p_head)->next;
        free(pb);
        pb=NULL;
    }
}
//������
int linklist_length(node **head)//
{
    node *p;
    int length=1;
    p=(*head)->next;
    while(p->next!=NULL)
    {
        p=p->next;
        length++;
    }
    return length;
}
//�м���ֵ
int getmidnode(node *head)
{
    NODE search,mid;
    search = mid = head;
    int num;

    while(search->next!=NULL)
    {
        if(search->next->next!=NULL)
        {
            search=search->next->next;
            mid=mid->next;
        }
        else
            search=search->next;
    }
    num=mid->data;

    return num;
}




int main()
{
    //
    node *head;
    head = (NODE)malloc(sizeof(node));
    head->next=NULL;

    int order;
    printf("��������\n");
    printf("1.��������\n");
    printf("2.��ӡ����\n");
    printf("3.������\n");
    printf("4.�м���ֵ\n");
    printf("0.�˳�\n");
    while(1)
    {
        scanf("%d",&order);
        switch (order)
        {
        case 1://��������
            linklist_create(&head);
            printf("����������\n");
            break;
        case 2://��ӡ����
            linklist_print(head);
            break;
        case 3:
            int len;
            len=linklist_length(&head);
            printf("������Ϊ��%d\n",len);
            break;
        case 4:
            int num;
            num=getmidnode(head);
            printf("�м���ֵΪ��%d\n",num);
            break;
        case 0:
            goto BREAKPOINT;
            break;
        }
    }
BREAKPOINT:
    linklist_free(&head);
    return 0;
}