#include <stdio.h>

struct student1
{
    char name[7];//8
    int id;//4
    char subject[5];//8
}; 

typedef struct redisObject {
    unsigned type:4;
    unsigned encoding:4;
    unsigned lru:24; /* LRU time (relative to global lru_clock) or
                            * LFU data (least significant 8 bits frequency
                            * and most significant 16 bits access time). */
    int refcount;
    void *ptr;
} robj;

struct __attribute__ ((aligned(4))) student2
{
    int id;//4
    char buf[];
};

struct zskiplistLevel {
        int *forward;
        unsigned long span;
};

struct student3
{
    char name[7];//8
    int id;//8
    char subject[5];//8
}__attribute__ ((aligned(8))); 

struct student4
{
    char name[7];// 7
    int id;// 4
    char subject[5];// 5
}__attribute__((packed)); 

int main(int argc, char const *argv[])
{
    printf("student1:%lu\n",sizeof(struct student1));// 20 默认是4字节对齐

    struct student2 stu2 = {0};
    printf("student2:%lu\n",sizeof(struct redisObject));// 20
    // printf("address:stu2,%p,id:%p,buf:%p\n",&stu2,&stu2.id,&stu2.buf);

    printf("student3:%lu\n",sizeof(struct student3));// 24

    printf("student4:%lu\n",sizeof(struct student4));// 16

    return 0;
}
