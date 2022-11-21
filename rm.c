#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    if(argv[1][3]=='-'){
        if(argv[1][4]=='v'){
            strtok(argv[1]," ");
            strtok(NULL," ");
            char *argg=strtok(NULL," ");

            if(unlink(argg)==0){
                printf("File Removed: %s\n",argg);
            }
            else{
                perror("ERROR");
            }
        }
        if(argv[1][4]=='d'){
            strtok(argv[1]," ");
            strtok(NULL," ");
            char *argg=strtok(NULL," ");

            if(rmdir(argg)==0){}
            else{
                perror("ERROR");
            }
        }
    }
    else{
        strtok(argv[1]," ");
        char *argg=strtok(NULL," ");

        if(unlink(argg)==0){}
        else{
            perror("ERROR");
        }
    }
    
    return 0;
}