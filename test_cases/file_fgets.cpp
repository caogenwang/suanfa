#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr,"Usage error: <src_file>%s <dest_file>%s",argv[1],argv[2]);
    }
    
    FILE * f1 = fopen(argv[1],"rw");//f指向的位置
    if (f1 == NULL)
    {
        // fprintf(stderr,"fopen failed()，error:%d\n",errno);
        fclose(f1);
        perror("fopen failed()");
        exit(1);
    }
    FILE * f2 = fopen(argv[2],"w");//f指向的位置在堆上
    if (f2 == NULL)
    {
        fclose(f2);
        perror("fopen failed()");
        exit(1);
    }
    char buf[256] = {0};
    int ch = 0;
    while (fgets(buf,5,f1) != NULL)
    {
        fputs(buf,f2);
    }
    fclose(f1);
    fclose(f2);
    puts("OK");
    return 0;
}
