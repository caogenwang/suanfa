#include <stdio.h>
#include <stdlib.h>

int main(int argc,char**argv)
{
    char a[5] = {1,2,3,4,5};
    char *s = a;
    unsigned char flags = s[-1];
    printf("%d\n",flags);
    return 0;
}
