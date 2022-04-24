#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//结构体指针

struct stu{
    int id;
    char name[32];
    char sex;
    int age;
};

int main()
{
    //定义一个结构体指针变量
    struct stu *s;
    //在堆区开辟结构体空间，并将其地址保存在结构体指针变量s
    s=(struct stu *)malloc(sizeof(struct stu));
    //结构体指针变量的成员使用
    s->id=1001;
    strcpy(s->name,"张三");
    s->sex='B';
    s->age=20;

    printf("%d - %s - %c - %d\n",s->id,s->name,s->sex,s->age);

    return 0;
}