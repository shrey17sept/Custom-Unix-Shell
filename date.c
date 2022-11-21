#include <stdio.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <sysexits.h>

void datee(char *arg){
    if(!arg){
        time_t t=time(NULL);
        struct tm *tm=localtime(&t);

        printf("%s", asctime(tm));
        printf("IST\n");
    }
    else if(strcmp(arg,"-R")==0){
        time_t t=time(NULL);
        struct tm *tm=localtime(&t);

        printf("%s", asctime(tm));
        printf("+0530\n");
    }
    else if(strcmp(arg,"-u")==0){
        time_t t=time(NULL);
        struct tm *tm=gmtime(&t);
        
        printf("%s", asctime(tm));
        printf("UTC\n");
    }
    else{
        printf("No such command found\n");
    }
}

int main(int argc, char *argv[]){
    datee(argv[1]);

    return 0;
}