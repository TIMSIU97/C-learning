#include<stdio.h>

//结构体：保存多个不同类型的数据
//定义结构体变量（全局变量）
struct stu1{
    int num;
    char name[20];
    char sex;
};

//定义结构体的同时顺便初始化
struct stu2{
    int num;
    char name[20];
    char sex;
}tim,siu,coco;

//无名结构体变量定义
struct {
    int num;
    char name[20];
    char sex;
}brad,pit;

//给结构体类型取别名
typedef struct{//用typedef可以不用写结构体名
    int num;
    char name[20];
    char sex;
}STU;


int main()
{
    //定义三个struct stu类型的变量
    struct stu1 lily,bob,lilei;

    //typedef取名后，相当于重新起了一个类型名STU，定义变量时，不用加struct
    STU A,B,C;

    return 0;
}