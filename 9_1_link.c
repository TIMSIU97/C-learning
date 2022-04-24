#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//����Ĺ��ɡ���һ�����ڵ㹹��
//�ڵ�һ����ýṹ�����ʽ��֯

//������ṹ��
typedef struct student{
    //������
    int num;
    int score;
    char name[20];
    //ָ����
    struct student *next;
}STU;
//�½ڵ����������
void link_creat_head(STU **p_head,STU *p_new)
{
    STU *p_mov=*p_head;
    if(*p_head==NULL)//����һ�μ�������Ϊ��ʱ��headִ��p_new
    {
        *p_head=p_new;//���½ڵ㸳ֵ��ͷ�ڵ�
        p_new->next=NULL;//ȷ���½ڵ��Ϊ��
    }
    else//�ڶ��μ��Ժ��������
    {
        while(p_mov->next!=NULL)
        {
            p_mov=p_mov->next;//�ҵ�ԭ��������һ���ڵ�
        }

        p_mov->next = p_new;//�����һ���ڵ��ָ�뱣���½ڵ�ĵ�ַ
        p_new->next = NULL;//ȷ���½ڵ��ΪNULL
    }
}


//����ı���
void link_print(STU *head)
{
    STU *p_mov;
    //�����µ�ָ�뱣��������׵�ַ����ֹ�ı�headԭ������
    p_mov = head;
    while(p_mov!=NULL)
    {
        //�ȴ�ӡ��ǰ�ڵ������
        printf("num=%d score=%d name:%s\n",p_mov->num,p_mov->score,p_mov->name);
        //�����Ϻ�ָ�����
        p_mov=p_mov->next;
    }
}

//������ͷ�
void link_free(STU **p_head)
{
    //����һ����ʱָ�뱣��ͷ���ĵ�ַ
    STU *pb=*p_head;

    while(*p_head!=NULL)
    {
        //�ȱ���p_head��ָ����ĵ�ַ
        pb=*p_head;
        //p_head������һ������ַ
        *p_head=(*p_head)->next;
        //�ͷŽ�㡢Ұָ��
        free(pb);
        pb=NULL;
    }
}

//����Ĳ���
//����ѧ�Ų���
void *link_search_num(STU *head,int num)
{
    STU *p_mov;
    //�����ָ�뱣���һ���ڵ�ĵ�ַ
    p_mov=head;
    //��û�е������һ�����ʱѭ������
    while(p_mov!=NULL)
    {
        //����ҵ��ǵ�ǰ�ڵ������.�򷵻ص�ǰ�ڵ�ĵ�ַ
        if(p_mov->num == num)//�ҵ���
            return p_mov;
        else
            p_mov=p_mov->next;
    }
    return NULL;//û���ҵ�
}

void *link_search_name(STU *head,char *name)
{
    STU *p_mov;
    p_mov=head;
    while(p_mov!=NULL)
    {
        if(strcmp(p_mov->name,name)==0)//�ҵ��ˣ��ַ���Ҫ��strcmp
            return p_mov;
        else
            p_mov=p_mov->next;
    }
    return NULL;//û�ҵ�
}

//�������ɾ��
void link_delete_num(STU **p_head,int num)
{
    //�����������ѧ�Ž���ɾ��
    STU *pb,*pf;
    pb = pf = *p_head;
    if(*p_head == NULL)//ԭ����Ϊ�գ�����ɾ��
    {
        printf("����Ϊ��\n");
        return ;
    }
    while(pb->num!=num && pb->next!=NULL)//ѭ���ң���Ҫɾ���Ľ��
    {
        pf=pb;
        pb=pb->next;
    }
    if(pb->num == num)//�ҵ���
    {
        if(pb == *p_head)//�ҵ�����ͷ���
        {
            *p_head=pb->next;
        }
        else//����ͷ���
        {
            pf->next=pb->next;//��ǰһ�����pf��next��ָ�뱣���һ��pb.next�ĵ�ַ
        }
        free(pb);
    }
}

//����Ĳ��룺����ѧ�ŵ�˳�����
void link_insert_num(STU **p_head,STU *p_new)
{
    STU *pb,*pf;
    pb=pf=*p_head;
    if(*p_head == NULL)//ԭ����Ϊ�ձ�ֱ�Ӳ��뵽��һ��
    {
        *p_head = p_new;
        p_new->next=NULL;
        return ;
    }
    //ѭ�����Ҳ���λ��
    while((p_new->num >= pb->num) && (pb->next !=NULL))
    {
        pf=pb;
        pb=pb->next;
    }
    if(p_new->num < pb->num)//�ҵ�һ���ڵ�������Ĵ󣬲���pbǰ��
    {
        if(pb==*p_head)//�ҵ�����ͷ�ڵ㣬������ǰ��
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
    else//û���ҵ�pb��p_new��Ľ�㣬�������
    {
        pb->next=p_new;
        p_new->next=NULL;
    }
}

//���������
void link_order(STU *head)
{
    STU *pb,*pf,temp;
    pf=head;

    if(head == NULL)//head��ַΪ��
    {
        printf("����Ϊ�գ���������\n");
        return;
    }
    if(head->next == NULL)//head��һ����ַΪ��
    {
        printf("ֻ��һ���ڵ㣬��������\n");
        return;
    }
    while(pf->next!=NULL)//��pfָ��Ľڵ���Ϊ��׼��
    {
        pb=pf->next;//pb�ӻ�׼Ԫ�ص���һ��Ԫ�ؿ�ʼ
        while(pb!=NULL)
        {
            if(pf->num > pb->num)//ǰ>��
            {
                //�����ڵ��ֵ����
                temp=*pb;
                *pb=*pf;
                *pf=temp;
                //�����ڵ��ָ���򽻻�
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

//���������
STU *link_reverse(STU *head)
{
    STU *pf,*pb,*r;//��������ָ��
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
    printf("�����������ʼ������\n");
    scanf("%d",&num);

    for(i=0;i<num;i++){
        p_new=(STU*)malloc(sizeof(STU));//����һ���½ڵ�
        //���½ڵ㸳ֵ
        printf("������ѧ�š����������֣�\n");
        scanf("%d %d %s",&p_new->num,&p_new->score,&p_new->name);

        link_creat_head(&head,p_new);//���½ڵ��������
    }

    link_print(head);

//���Һ����ĵ���
#if 0
    STU *pb;
    while(1)
    {
        printf("��������Ҫ���ҵ�ѧ����ѧ��\n");
        scanf("%d",&num);
        pb=link_search_num(head,num);
        if(pb!=NULL)
            printf("�ҵ��� num=%d score=%d name:%s\n",pb->num,pb->score,pb->name);
        else
            printf("û���ҵ���Ҫ���ҵĽ��\n");
    }
#endif
//����ڵ㺯������
#if 0
    while(1)
    {
        printf("��������Ҫ����Ľ���num score name\n");
        p_new=(STU *)malloc(sizeof(STU));//����һ���½��
        scanf("%d %d %s",&p_new->num,&p_new->score,&p_new->name);
        link_insert_num(&head,p_new);
        link_print(head);
    }
#endif
//ɾ����������
#if 0
    printf("��������Ҫɾ����ѧ��\n");
    scanf("%d",&num);
    link_delete_num(&head,num);
    link_print(head);
#endif
//����������
#if 0
    printf("****************\n");
    link_order(head);
    link_print(head);
#endif
//����������
#if 0
    printf("*******************\n");
    head=link_reverse(head);
    link_print(head);
#endif


    link_free(&head);//�ͷ������ڴ�//����ʱ��ͷ����ַ

    return 0;
}