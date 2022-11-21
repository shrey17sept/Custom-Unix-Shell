#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

void fileRead(char *file){
    int f=open(file,O_RDONLY);
    char ch;
    if(f<0){
        perror("ERROR");
        return;
    }
    else{
        int chk=read(f,&ch,1);
        while(chk){
            if(chk<0){
                perror("ERROR");
                return;
            }
            
            size_t rd=write(STDIN_FILENO, &ch ,1);
            if(rd<0){
                if(errno!=EINTR){
                    perror("ERROR");
                    return;
                }
            }
            chk=read(f,&ch,1);
        }
        if(close(f)<0){
            perror("ERROR");
        }

    }
}

void nfileRead(char *file){
    int f=open(file,O_RDONLY);
    char ch;
    if(f<0){
        perror("ERROR");
        return;
    }
    else{
        int chk=read(f,&ch,1);
        char i='1';
        write(STDIN_FILENO,&i,1);
        char ws='\t';
        write(STDIN_FILENO,&ws,1);

        while(chk){
            if(chk<0){
                perror("ERROR");
                return;
            }
            
            size_t rd=write(STDIN_FILENO, &ch ,1);
            if(ch=='\n'){
                i++;
                write(STDIN_FILENO,&i,1);
                char ws='\t';
                write(STDIN_FILENO,&ws,1);
            }
            if(rd<0){
                if(errno!=EINTR){
                    perror("ERROR");
                    return;
                }
            }
            chk=read(f,&ch,1);
        }
        if(close(f)<0){
            perror("ERROR");
        }

    }
}

void efileRead(char *file){

    
    int f=open(file,O_RDONLY);
    char ch;
    if(f<0){
        perror("ERROR");
        return;
    }
    else{
        int chk=read(f,&ch,1);
        while(chk){
            if(chk<0){
                perror("ERROR");
                return;
            }
            size_t rd;
            
            
            if(ch=='\n'){
                char dollar='$';
                rd=write(STDIN_FILENO, &dollar, 1);
            }

            rd=write(STDIN_FILENO, &ch ,1);
            if(rd<0){
                if(errno!=EINTR){
                    perror("ERROR");
                    return;
                }
            }
            chk=read(f,&ch,1);
        }
        if(close(f)<0){
            perror("ERROR");
        }

    }
    
    
}

int main(int argc, char *argv[]){
    if(argv[1][4]=='-'){
        if(argv[1][5]=='n'){
            strtok(argv[1]," ");
            strtok(NULL," ");
            char *file=strtok(NULL," ");
            nfileRead(file);
        }
        else if(argv[1][5]=='e'){
            strtok(argv[1]," ");
            strtok(NULL," ");
            char *file=strtok(NULL," ");
            efileRead(file);
        }
    }
    else{
        strtok(argv[1]," ");
        char *file=strtok(NULL," ");
        fileRead(file);
        
    }
    printf("\n");
    return 0;
}