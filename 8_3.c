#include<stdio.h>
#include<string.h>

//结构体数组

typedef struct{
    int num;
    char name[20];
    float score;
}STU;

int main()
{
    //定义一个结构体数组
    STU edu[3]={
        {101,"lucy",78},
        {102,"bob",59.5},
        {103,"tom",85}
    };

    //输出元素
    int j;
    for(j=0;j<3;j++)
    {
        printf("%d - %s - %.2f\n",edu[j].num,edu[j].name,\
        edu[j].score);
    }

    int i;
    float sum=0;
    for(i=0;i<3;i++)
    {
        sum+=edu[i].score;
    }

    printf("平均成绩为%.2f\n",sum/3);

    return 0;
}