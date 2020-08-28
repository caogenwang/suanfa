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
    // char *p = "wwwwwwwwwww";
    // fwrite(p,strlen(p),2,f);
    // char buf[256] = {0};
    // int n = 0;
    // while((n = fread(buf, 3, 1, f))>0)
    // {
    //     printf("%s",buf);
    // }
    FILE * f2 = fopen(argv[2],"w");//f指向的位置在堆上
    if (f2 == NULL)
    {
        fclose(f2);
        perror("fopen failed()");
        exit(1);
    }
    
    int ch = 0;
    while (1)
    {
        ch = fgetc(f1);
        if(ch==EOF)
            break;
        printf("%c\n",ch);
        fputc(ch,f2);
    }
    fclose(f1);
    fclose(f2);
    puts("OK");
    return 0;
}
