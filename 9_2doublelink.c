#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//˫������//һ���ڵ�=����ָ����+һ��������

//����
typedef struct student{
    //������
    int num;
    int score;
    char name[20];
    //ָ����
    struct student *front;//��һ���ڵ��ַ
    struct student *next;//��һ������ַ
}STU;
//����������
void double_link_creat_head(STU **p_head,STU *p_new)
{
    STU *p_mov=*p_head;
    if(*p_head==NULL)//��һ�μ�������Ϊ��ʱ
    {
        *p_head=p_new;
        p_new->front=NULL;
        p_new->next=NULL;
    }
    else
    {
        while(p_mov->next!=NULL)
        {
            p_mov=p_mov->next;//�ҵ�ԭ��������һ�����
        }
        p_mov->next=p_new;//�½ڵ��������
        p_new->front=p_mov;
        p_new->next=NULL;
    }
}
//����ı�����˫���ӡ
void double_link_print(STU *head)
{
    STU *pb;
    pb=head;
    while(pb->next!=NULL)//˳���ӡ
    {
        printf("num=%d score=%d name:%s\n",pb->num,pb->score,pb->name);
        pb=pb->next;
    }
    printf("num=%d score=%d name:%s\n",pb->num,pb->score,pb->name);

    printf("****************************\n");

    while(pb!=NULL)//�����ӡ
    {
        printf("num=%d score=%d name:%s\n",pb->num,pb->score,pb->name);
        pb=pb->front;
    }
}
//˫�������ɾ��
void double_link_delete_num(STU **p_head,int num)
{
    STU *pb,*pf;
    pb=*p_head;
    if(*p_head==NULL)//����Ϊ��
    {
        printf("����Ϊ��\n");
        return;
    }
    while((pb->num!=num)&&(pb->next!=NULL))//�ҵ�numƥ��Ľڵ�
    {
        pb=pb->next;
    }
    if(pb->num == num)//�ҵ���num��ͬ�Ľڵ�
    {
        if(pb == *p_head)//�ҵ�����ͷ���
        {
            if((*p_head)->next==NULL)//ֻ��һ���ڵ�
            {
                *p_head=pb->next;
            }
            else//�ж���ڵ�
            {
                *p_head=pb->next;//headָ����һ���ڵ�
                (*p_head)->front=NULL;
            }
        }
        else//�ҵ��Ĳ���ͷ���
        {
            if(pb->next!=NULL)//�м�ڵ�
            {
                pf=pb->front;
                pf->next=pb->next;
                (pb->next)->front=pf;
            }
            else//β�ڵ�
            {
                pf=pb->front;
                pf->next=NULL;
            }
        }
        free(pb);//�ͷŽڵ�
    }
    else//û�ҵ�
    {
        printf("û����Ҫɾ���Ľڵ�\n");
    }
}
//˫���б�Ĳ���ڵ�
void double_link_insert_num(STU **p_head,STU *p_new)
{
    STU *pb,*pf;
    pb=*p_head;
    if(*p_head == NULL)//����Ϊ��
    {
        *p_head=p_new;
        p_new->front=NULL;
        p_new->next=NULL;
        return;
    }
    while((p_new->num >= pb->num)&&(pb->next!=NULL))//ѭ�����Ҵ���p_new��pb
    {
        pb=pb->next;
    }
    if(p_new->num < pb->num)//����ҵ���һ��pb��p_new��
    {
        if(pb==*p_head)//�ҵ�����ͷ�ڵ㣬����ͷ�ڵ�ǰ
        {
            p_new->next=*p_head;
            (*p_head)->front=p_new;
            p_new->front=NULL;
            *p_head=p_new;
        }
        else//�м����
        {
            pf=pb->front;//pfָ��pb��ǰһ���ڵ�

            p_new->next=pb;
            p_new->front=pf;
            pf->next=p_new;
            pb->front=p_new;
        }
    }
    else//����pb�ڵ㶼��p_new��С���������
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
    printf("�����������ʼ������\n");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        p_new=(STU*)malloc(sizeof(STU));//�����½ڵ�
        printf("������ѧ�š�������������\n");
        scanf("%d %d %s",&p_new->num,&p_new->score,&p_new->name);
        double_link_creat_head(&head,p_new);//��������
    }
    double_link_print(head);
    //ɾ����������
    #if 0
        printf("��������Ҫɾ���Ľڵ��num\n");
        scanf("%d",&num);
        double_link_delete_num(&head,num);
        double_link_print(head);
    #endif
    #if 0
        printf("��������Ҫ����Ľڵ��num score name\n");
        p_new=(STU *)malloc(sizeof(STU));//һ��Ҫ���½������ռ�
        scanf("%d %d %s",&p_new->num,&p_new->score,&p_new->name);
        double_link_insert_num(&head,p_new);
        double_link_print(head);
    #endif


    return 0;
}