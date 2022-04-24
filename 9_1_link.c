#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//链表的构成——一个个节点构成
//节点一般采用结构体的形式组织

//定义结点结构体
typedef struct student{
    //数据域
    int num;
    int score;
    char name[20];
    //指针域
    struct student *next;
}STU;
//新节点加入链表函数
void link_creat_head(STU **p_head,STU *p_new)
{
    STU *p_mov=*p_head;
    if(*p_head==NULL)//当第一次加入链表为空时，head执行p_new
    {
        *p_head=p_new;//将新节点赋值于头节点
        p_new->next=NULL;//确保新节点后为空
    }
    else//第二次及以后加入链表
    {
        while(p_mov->next!=NULL)
        {
            p_mov=p_mov->next;//找到原链表的最后一个节点
        }

        p_mov->next = p_new;//用最后一个节点的指针保存新节点的地址
        p_new->next = NULL;//确保新节点后为NULL
    }
}


//链表的遍历
void link_print(STU *head)
{
    STU *p_mov;
    //定义新的指针保存链表的首地址，防止改变head原本链表
    p_mov = head;
    while(p_mov!=NULL)
    {
        //先打印当前节点的数据
        printf("num=%d score=%d name:%s\n",p_mov->num,p_mov->score,p_mov->name);
        //输出完毕后，指针后移
        p_mov=p_mov->next;
    }
}

//链表的释放
void link_free(STU **p_head)
{
    //定义一个临时指针保存头结点的地址
    STU *pb=*p_head;

    while(*p_head!=NULL)
    {
        //先保存p_head的指向结点的地址
        pb=*p_head;
        //p_head保存下一个结点地址
        *p_head=(*p_head)->next;
        //释放结点、野指针
        free(pb);
        pb=NULL;
    }
}

//链表的查找
//按照学号查找
void *link_search_num(STU *head,int num)
{
    STU *p_mov;
    //定义的指针保存第一个节点的地址
    p_mov=head;
    //当没有到达最后一个结点时循环继续
    while(p_mov!=NULL)
    {
        //如果找到是当前节点的数据.则返回当前节点的地址
        if(p_mov->num == num)//找到了
            return p_mov;
        else
            p_mov=p_mov->next;
    }
    return NULL;//没有找到
}

void *link_search_name(STU *head,char *name)
{
    STU *p_mov;
    p_mov=head;
    while(p_mov!=NULL)
    {
        if(strcmp(p_mov->name,name)==0)//找到了，字符串要用strcmp
            return p_mov;
        else
            p_mov=p_mov->next;
    }
    return NULL;//没找到
}

//链表结点的删除
void link_delete_num(STU **p_head,int num)
{
    //根据数据域的学号进行删除
    STU *pb,*pf;
    pb = pf = *p_head;
    if(*p_head == NULL)//原链表为空，不用删除
    {
        printf("链表为空\n");
        return ;
    }
    while(pb->num!=num && pb->next!=NULL)//循环找，找要删除的结点
    {
        pf=pb;
        pb=pb->next;
    }
    if(pb->num == num)//找到了
    {
        if(pb == *p_head)//找到的是头结点
        {
            *p_head=pb->next;
        }
        else//不是头结点
        {
            pf->next=pb->next;//让前一个结点pf。next的指针保存后一个pb.next的地址
        }
        free(pb);
    }
}

//链表的插入：按照学号的顺序插入
void link_insert_num(STU **p_head,STU *p_new)
{
    STU *pb,*pf;
    pb=pf=*p_head;
    if(*p_head == NULL)//原链表为空表，直接插入到第一个
    {
        *p_head = p_new;
        p_new->next=NULL;
        return ;
    }
    //循环查找插入位置
    while((p_new->num >= pb->num) && (pb->next !=NULL))
    {
        pf=pb;
        pb=pb->next;
    }
    if(p_new->num < pb->num)//找到一个节点比新来的大，插在pb前面
    {
        if(pb==*p_head)//找到的是头节点，插在最前面
        {
            p_new->next=*p_head;
            *p_head=p_new;
        }
        else
        {
            pf->next=p_new;
            p_new->next=pb;
        }
    }
    else//没有找到pb比p_new大的结点，插在最后
    {
        pb->next=p_new;
        p_new->next=NULL;
    }
}

//链表的排序
void link_order(STU *head)
{
    STU *pb,*pf,temp;
    pf=head;

    if(head == NULL)//head地址为空
    {
        printf("链表为空，不用排序\n");
        return;
    }
    if(head->next == NULL)//head下一个地址为空
    {
        printf("只有一个节点，不用排序\n");
        return;
    }
    while(pf->next!=NULL)//以pf指向的节点作为基准点
    {
        pb=pf->next;//pb从基准元素的下一个元素开始
        while(pb!=NULL)
        {
            if(pf->num > pb->num)//前>后
            {
                //两个节点的值交换
                temp=*pb;
                *pb=*pf;
                *pf=temp;
                //两个节点的指针域交换
                temp.next=pb->next;
                pb->next=pf->next;
                pf->next=temp.next;
            }
            else
                pb=pb->next;
        }
        pf=pf->next;
    }
}

//链表的逆序
STU *link_reverse(STU *head)
{
    STU *pf,*pb,*r;//定义三个指针
    pf=head;
    pb=pf->next;

    while(pb!=NULL)
    {
        r=pb->next;
        pb->next=pf;
        pf=pb;
        pb=r;
    }
    head->next=NULL;
    head=pf;
    return head;
}



int main()
{
    STU *head=NULL,*p_new=NULL;
    int num,i;
    printf("请输入链表初始个数：\n");
    scanf("%d",&num);

    for(i=0;i<num;i++){
        p_new=(STU*)malloc(sizeof(STU));//申请一个新节点
        //给新节点赋值
        printf("请输入学号、分数、名字：\n");
        scanf("%d %d %s",&p_new->num,&p_new->score,&p_new->name);

        link_creat_head(&head,p_new);//将新节点加入链表
    }

    link_print(head);

//查找函数的调用
#if 0
    STU *pb;
    while(1)
    {
        printf("请输入您要查找的学生的学号\n");
        scanf("%d",&num);
        pb=link_search_num(head,num);
        if(pb!=NULL)
            printf("找到了 num=%d score=%d name:%s\n",pb->num,pb->score,pb->name);
        else
            printf("没有找到您要查找的结点\n");
    }
#endif
//插入节点函数调用
#if 0
    while(1)
    {
        printf("请输入您要插入的结点的num score name\n");
        p_new=(STU *)malloc(sizeof(STU));//申请一个新结点
        scanf("%d %d %s",&p_new->num,&p_new->score,&p_new->name);
        link_insert_num(&head,p_new);
        link_print(head);
    }
#endif
//删除函数调用
#if 0
    printf("请输入您要删除的学号\n");
    scanf("%d",&num);
    link_delete_num(&head,num);
    link_print(head);
#endif
//排序函数调用
#if 0
    printf("****************\n");
    link_order(head);
    link_print(head);
#endif
//逆序函数调用
#if 0
    printf("*******************\n");
    head=link_reverse(head);
    link_print(head);
#endif


    link_free(&head);//释放链表内存//调用时传头结点地址

    return 0;
}