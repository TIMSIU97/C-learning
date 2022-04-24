#include<stdio.h>
#include<string.h>
//结构体变量初始化

struct stu{
    int id;
    char name[20];
    char sex;
    int age;
}zhangsan,lisi={1001,"lisi",'F',19};//这里可以初始化

typedef struct{
    int a;
    int b;
    char c;
}MSG;

void test1()
{
    struct stu wangwu;
    struct stu zhaoliu = {1001,"zhaoliu",'M',20};//常规初始化方法

    MSG msg1,msg2 = {100,200,'w'};

    //结构体变量的使用
    //结构体变量名.结构体成员
    zhangsan.id=1001;
    strcpy(zhangsan.name,"张三");//不能直接="张三"
    zhangsan.sex='M';
    zhangsan.age=20;

    printf("%d - %s - %c - %d\n",zhangsan.id,zhangsan.name\
        ,zhangsan.sex,zhangsan.age);

    printf("%d - %s - %c - %d\n",lisi.id,lisi.name\
        ,lisi.sex,lisi.age);

    printf("%d - %s - %c - %d\n",zhaoliu.id,zhaoliu.name\
        ,zhaoliu.sex,zhaoliu.age);

    printf("%d - %d - %d\n",msg2.a,msg2.b,msg2.c);
}

//结构体中嵌套结构体
typedef struct{
    int year;
    int month;
    int day;
}BD;
typedef struct{
    int id;
    char name[32];
    BD birthday;
}STU;

void test2()
{
    //嵌套结构体的初始化及使用
    STU xiaoming;
    xiaoming.id=1001;
    strcpy(xiaoming.name,"小明");
    xiaoming.birthday.year=2002;
    xiaoming.birthday.month=12;
    xiaoming.birthday.day=25;

    printf("%d - %s - %d-%d-%d\n",xiaoming.id,xiaoming.name,\
            xiaoming.birthday.year,xiaoming.birthday.month,xiaoming.birthday.day);

    STU xiaoli={1001,"小丽",{1997,9,19}};

    printf("%d - %s - %d-%d-%d\n",xiaoli.id,xiaoli.name,\
            xiaoli.birthday.year,xiaoli.birthday.month,xiaoli.birthday.day);
}

int main()
{
    test2();

    return 0;
}