#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>



int main(int argc, char *argv[]){
    if(argv[1][6]=='-'){
        if(argv[1][7]=='v'){
            strtok(argv[1]," ");
            strtok(NULL," ");
            char *argg=strtok(NULL," ");

            int chk=mkdir(argg,0777);
            if(chk==-1){
                perror("ERROR");
            }

            printf("Created new directory: %s\n", argg);
        }

        else if(argv[1][7]=='m'){
            strtok(argv[1]," ");
            strtok(NULL," ");
            char *str_mode=strtok(NULL," ");
            int md=strtol(str_mode,NULL,8);
            char *argg=strtok(NULL," ");

            if(md<111 || md>777){
                printf("Invalid Mode Entered\n");
            }
            else{
                mkdir(argg,md);
            }
        }
    }
    else{
        strtok(argv[1]," ");
        char *argg=strtok(NULL," ");

        int chk=mkdir(argg,0777);
        if(chk==-1){
            perror("ERROR");
        }
    }
}