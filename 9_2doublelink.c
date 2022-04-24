#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//双向链表//一个节点=两个指针域+一个数据域

//创建
typedef struct student{
    //数据域
    int num;
    int score;
    char name[20];
    //指针域
    struct student *front;//上一个节点地址
    struct student *next;//下一个结点地址
}STU;
//链表创建函数
void double_link_creat_head(STU **p_head,STU *p_new)
{
    STU *p_mov=*p_head;
    if(*p_head==NULL)//第一次加入链表为空时
    {
        *p_head=p_new;
        p_new->front=NULL;
        p_new->next=NULL;
    }
    else
    {
        while(p_mov->next!=NULL)
        {
            p_mov=p_mov->next;//找到原链表的最后一个结点
        }
        p_mov->next=p_new;//新节点加入链表
        p_new->front=p_mov;
        p_new->next=NULL;
    }
}
//链表的遍历和双向打印
void double_link_print(STU *head)
{
    STU *pb;
    pb=head;
    while(pb->next!=NULL)//顺序打印
    {
        printf("num=%d score=%d name:%s\n",pb->num,pb->score,pb->name);
        pb=pb->next;
    }
    printf("num=%d score=%d name:%s\n",pb->num,pb->score,pb->name);

    printf("****************************\n");

    while(pb!=NULL)//逆序打印
    {
        printf("num=%d score=%d name:%s\n",pb->num,pb->score,pb->name);
        pb=pb->front;
    }
}
//双向链表的删除
void double_link_delete_num(STU **p_head,int num)
{
    STU *pb,*pf;
    pb=*p_head;
    if(*p_head==NULL)//链表为空
    {
        printf("链表为空\n");
        return;
    }
    while((pb->num!=num)&&(pb->next!=NULL))//找到num匹配的节点
    {
        pb=pb->next;
    }
    if(pb->num == num)//找到了num相同的节点
    {
        if(pb == *p_head)//找到的是头结点
        {
            if((*p_head)->next==NULL)//只有一个节点
            {
                *p_head=pb->next;
            }
            else//有多个节点
            {
                *p_head=pb->next;//head指向下一个节点
                (*p_head)->front=NULL;
            }
        }
        else//找到的不是头结点
        {
            if(pb->next!=NULL)//中间节点
            {
                pf=pb->front;
                pf->next=pb->next;
                (pb->next)->front=pf;
            }
            else//尾节点
            {
                pf=pb->front;
                pf->next=NULL;
            }
        }
        free(pb);//释放节点
    }
    else//没找到
    {
        printf("没有您要删除的节点\n");
    }
}
//双向列表的插入节点
void double_link_insert_num(STU **p_head,STU *p_new)
{
    STU *pb,*pf;
    pb=*p_head;
    if(*p_head == NULL)//链表为空
    {
        *p_head=p_new;
        p_new->front=NULL;
        p_new->next=NULL;
        return;
    }
    while((p_new->num >= pb->num)&&(pb->next!=NULL))//循环查找大于p_new的pb
    {
        pb=pb->next;
    }
    if(p_new->num < pb->num)//如果找到了一个pb比p_new大
    {
        if(pb==*p_head)//找到的是头节点，插在头节点前
        {
            p_new->next=*p_head;
            (*p_head)->front=p_new;
            p_new->front=NULL;
            *p_head=p_new;
        }
        else//中间插入
        {
            pf=pb->front;//pf指向pb的前一个节点

            p_new->next=pb;
            p_new->front=pf;
            pf->next=p_new;
            pb->front=p_new;
        }
    }
    else//所有pb节点都比p_new的小，插在最后
    {
        pb->next=p_new;
        p_new->front=pb;
        p_new->next=NULL;
    }
}
int main()
{
    STU *head=NULL,*p_new=NULL;
    int num,i;
    printf("请输入链表初始个数：\n");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        p_new=(STU*)malloc(sizeof(STU));//申请新节点
        printf("请输入学号、分数、姓名：\n");
        scanf("%d %d %s",&p_new->num,&p_new->score,&p_new->name);
        double_link_creat_head(&head,p_new);//加入链表
    }
    double_link_print(head);
    //删除函数调用
    #if 0
        printf("请输入您要删除的节点的num\n");
        scanf("%d",&num);
        double_link_delete_num(&head,num);
        double_link_print(head);
    #endif
    #if 0
        printf("请输入您要插入的节点的num score name\n");
        p_new=(STU *)malloc(sizeof(STU));//一定要给新结点申请空间
        scanf("%d %d %s",&p_new->num,&p_new->score,&p_new->name);
        double_link_insert_num(&head,p_new);
        double_link_print(head);
    #endif


    return 0;
}