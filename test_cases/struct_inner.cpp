#include <stdio.h>

struct student1
{
    int a;
    int b;
    char name[4];
    struct struct_inner
    {
        struct struct_inner *next;
        int span;
    }level[];//这种定义方式不占用内存
}__attribute__((packed)); 

int main(int argc, char const *argv[])
{
    student1 *s1;
    printf("%d\n",sizeof(*s1));
}