#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <pwd.h>
#include <sys/wait.h>
#include <pthread.h>

void echo(char cmd[]){
    if(cmd[5]=='-'){
        if(cmd[6]=='e'){
            int itr=9;
            char i=cmd[itr];
            while(i!='"'){
                if(i=='\0'){
                    break;
                }
                if(i=='\\'){
                    if(cmd[itr+1]=='n'){
                        printf("\n");
                        itr++;
                    }
                    else if(cmd[itr+1]=='t'){
                        printf("\t");
                        itr++;
                    }
                    else if(cmd[itr+1]=='\\'){
                        printf("\\");
                        itr++;
                    }
                    else if(cmd[itr+1]=='b'){
                        printf("\b");
                        itr++;
                    }
                    else if(cmd[itr+1]=='?'){
                        printf("\?");
                        itr++;
                    }
                    else{
                        printf("\\");
                    }
                }
                else{
                    printf("%c",i);
                }

                itr++;
                i=cmd[itr];
            }

            printf("\n");
        }
        else if(cmd[6]=='n'){
            int itr=9;
            char i=cmd[itr];
            while(i!='"'){
                if(i=='\0'){
                    break;
                }
                printf("%c",i);
                itr++;
                i=cmd[itr];
            }
        }
        else{
            printf("No such command found\n");
        }
    }
    else if(cmd[5]=='"'){
        int itr=6;
        char i=cmd[itr];
        while(i!='"'){
            if(i=='\0'){
                break;
            }
            printf("%c",i);
            itr++;
            i=cmd[itr];
        }
        printf("\n");
    }
    else{
        printf("No such command found\n");
    }
}


void pwd(char cmd[]){
    if(cmd[4]=='-'){
        if(cmd[5]=='P'){
            char cwd[256];
            char *ig=getcwd(cwd,sizeof(cwd));
            if(ig==NULL){
                perror("ERROR");
            }
            else{
                printf("%s",ig);
            }
        }
        else if(cmd[5]=='L'){
            char buff[PATH_MAX];
            char cwd[256];
            char *rp=realpath(cwd,buff);
            char *ig=getcwd(cwd,sizeof(cwd));
            if(ig==NULL){
                perror("ERROR");
            }
            else{
                printf("%s",ig);
            }
        }
        else{
            printf("No such command found");
        }
    }
    else{
        char cwd[256];
        char *ig=getcwd(cwd,sizeof(cwd));
        if(ig==NULL){
            perror("ERROR");
        }
        else{
            printf("%s",ig);
        }
    }
}

void cd(char *arg){
    char cwdd[256];
    if(!arg){
        if(chdir(getenv("HOME"))==0){
            char *ig=getcwd(cwdd,sizeof(cwdd));
            printf("%s\n",ig);
        }
        else{
            perror("ERROR");
        }
    }

    else if(strcmp(arg,"~")==0 || strcmp(arg,"--")==0){
        if(chdir(getenv("HOME"))==0){
            char *ig=getcwd(cwdd,sizeof(cwdd));
            printf("%s\n",ig);
        }
        else{
            perror("ERROR");
        }
    }

    else if(strcmp(arg,"-")==0){
        chdir("..");
        char *ig=getcwd(cwdd,sizeof(cwdd));
        if(ig==NULL){
            perror("ERROR");
        }
        else{
            printf("%s\n",ig);
        }
    }

    else if(chdir(arg)==0){
        char *ig=getcwd(cwdd,sizeof(cwdd));
        if(ig==NULL){
            perror("ERROR");
        }
        else{
            printf("%s\n",ig);
        }
    }
    else{
        perror("ERROR");
    }
}

void *funcName(void *arg){
    system(arg);
}

int main(){

    printf("\n----------------------------------------TERMINAL----------------------------------------\n");

    while(1){

        printf("$ ");
        char cmd[100];
        scanf("%[^\n]%*c",cmd);

        if(cmd[0]=='\0' || cmd[0]=='\n'){
            char igg;
            scanf("%c",&igg);
            continue;
        }

        int igSize=strlen(cmd);

        cmd[igSize]=' ';
        char typ_cmd[100];
        int itr=0;
        char i=cmd[itr];

        cmd[igSize+1]='\0';

        while(i!=' '){
            typ_cmd[itr]=i;
            itr++;
            i=cmd[itr];
        }

        typ_cmd[itr]='\0';



        if(strcmp(typ_cmd,"echo")==0){
            echo(cmd);
        }

        else if(strcmp(typ_cmd,"pwd")==0){
            pwd(cmd);
            printf("\n");
        }

        else if(strcmp(typ_cmd,"cd")==0){

            char cmd_cpy[100];
            strcpy(cmd_cpy,cmd);
            strtok(cmd_cpy," ");
            char *arg_cd=strtok(NULL," ");

            cd(arg_cd);
        }

        else if(strcmp(typ_cmd,"date")==0){

            char cmd_cpy[100];
            strcpy(cmd_cpy,cmd);
            strtok(cmd_cpy," ");
            char *arg_dat=strtok(NULL," ");
            pid_t proID;
            int waitt;

            if((proID=fork())==0){
                char *argvv[]={"./date",arg_dat,NULL};
                execvp("./date",argvv);
                    
                exit(0);
            }
            else{

                pid_t time;
                time=wait(&waitt);
            }
        }

        else if(strcmp(typ_cmd,"cat")==0){
            
            pid_t proID;
            int waitt;

            char cmd_cpy[100];
            strcpy(cmd_cpy,cmd);

            if((proID=fork())==0){
                char *argvv[]={"./cat",cmd_cpy,NULL};
                execvp("./cat",argvv);
                exit(0);
            }
            else{
                pid_t time;
                time=wait(&waitt);
            }
        }

        else if(strcmp(typ_cmd,"mkdir")==0){
            pid_t proID;
            int waitt;

            char cmd_cpy[100];
            strcpy(cmd_cpy,cmd);

            if((proID=fork())==0){
                char *argvv[]={"./mkdir",cmd_cpy,NULL};
                execvp("./mkdir",argvv);
                exit(0);
            }
            else{
                pid_t time;
                time=wait(&waitt);
            }
        }

        else if(strcmp(typ_cmd,"rm")==0){
            pid_t proID;
            int waitt;

            char cmd_cpy[100];
            strcpy(cmd_cpy,cmd);

            if((proID=fork())==0){
                char *argvv[]={"./rm",cmd_cpy,NULL};
                execvp("./rm",argvv);
                exit(0);
            }
            else{
                pid_t time;
                time=wait(&waitt);
            }
        }

        else if(strcmp(typ_cmd,"ls")==0){
            
            char cmd_cpy[100];
            strcpy(cmd_cpy,cmd);
            pid_t proID;
            int waitt;

            if((proID=fork())==0){
                char *argvv[]={"./ls",cmd_cpy,NULL};
                execvp("./ls",argvv);
                exit(0);
            }
            else{
                pid_t time;
                time=wait(&waitt);
            }

        }

        else if(strcmp(typ_cmd,"exit")==0){
            break;
        }

        else{
            printf("No such command found\n");
        }

    }

    return 0;
}
