#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>

void ls(char opt){

    struct dirent *d;
	DIR *drr = opendir(".");
    if(!drr){
        perror("ERROR");
        return;
    }

    if(opt=='\0'){
        while((d=readdir(drr))!=NULL){
            if(d->d_name[0]=='.'){
                continue;
            }
            printf("%s ",d->d_name);
        }
        printf("\n");
    }
    else if(opt=='a'){
        while((d=readdir(drr))!=NULL){
            printf("%s ",d->d_name);
        }
        printf("\n");
    }
    else if(opt=='l'){
        while((d=readdir(drr))!=NULL){
            printf("%s\n",d->d_name);
        }
    }
    else{
        printf("Invalid option\n");
    }
}

int main(int argc, char *argv[]){
    if(argv[1][3]=='-'){
        if(argv[1][4]=='a'){
            ls('a');
        }
        else if(argv[1][4]=='l'){
            ls('l');
        }
        else{
            printf("Invalid option\n");
        }
    }
    else{
        ls('\0');
    }
    return 0;
}