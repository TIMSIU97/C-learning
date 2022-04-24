#include<stdio.h>
#include<string.h>

//字符串匹配函数
//char *strstr(const char *haystack,const char *needle);
//在haystack字符串中查找needle的字符串，首次匹配。找到了返回字符串首地址，否则NULL

int main()
{
    char s[]="1234:4567:666:789:666:777";
    char *ret=strstr(s,"666");

    if(ret==NULL)
        printf("没找到\n");
    else
        printf("找到了，在%d位置\n",ret -s);

    return 0;
}