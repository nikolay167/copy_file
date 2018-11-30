#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *fi,*target ;
    char fr[256] = { };
    char fo[256] = { };
    char buf[1024];

    printf("Enter input file name: ");
    scanf("%255s", fr);

    fi = fopen(fr, "r");

    if(!fi) {
        printf("Failed to open input file\n");
        return -1;
      }

    printf("Enter the target file:\n");
    scanf("%255s",fo);

    target = fopen(fo,"w");

    if(!target) {
        printf("Failed to open input file\n");
        return -1;
      }


    while(!feof(fi)) {
       memset(buf, 0, 1024);
       fread(buf, 1, 1024, fi);
       fwrite(buf , 1 , 1024 , target );


    }


    fclose(fi);
    fclose(target);
    return 0;

}
