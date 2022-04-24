#include<stdio.h>
#include<stdlib.h>

typedef struct linklist{
    int data;
    struct linklist *next;
}node;
typedef struct linklist* NODE;
//创建20个元素的链表
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
//打印链表
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
//释放链表空间
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
//链表长度
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
//中间结点值
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
    printf("输入数字\n");
    printf("1.生成链表\n");
    printf("2.打印链表\n");
    printf("3.链表长度\n");
    printf("4.中间结点值\n");
    printf("0.退出\n");
    while(1)
    {
        scanf("%d",&order);
        switch (order)
        {
        case 1://生成链表
            linklist_create(&head);
            printf("已生成链表\n");
            break;
        case 2://打印链表
            linklist_print(head);
            break;
        case 3:
            int len;
            len=linklist_length(&head);
            printf("链表长度为：%d\n",len);
            break;
        case 4:
            int num;
            num=getmidnode(head);
            printf("中间结点值为：%d\n",num);
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