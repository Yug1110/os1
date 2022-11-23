#include <dirent.h>
#include <errno.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#include<pthread.h>

char* glo;

void* fun1(void* argument){
  char* newvar=(char*)argument;
  int j=system(newvar);
  return NULL;
}

void thread(char* argument){
  char* var=malloc(sizeof(char)* 2500);
  strcpy(var,glo);
  strcat(var,"/");
  strcat(var,argument);
 
  pthread_t nthread;
  pthread_create(&nthread,NULL,fun1,var);
  pthread_join(nthread,NULL);
}



int main(int argc,char **argv){
  glo= malloc(sizeof(char)*100);
  getcwd(glo,100);
 
 
  char s1[100];
  char input[100];
  char copy[100];
  char copy1[100];

  while(1){
    printf("YUG$$%s ",getcwd(s1,100));
    gets(input);
    strcpy(copy,input);
    strcpy(copy1,input);

    char* token=strtok(input," ");
    if(!strcmp(token,"exit")){
      printf("exitted\n");
      break;
    }
    else if(token[strlen(token)-1]=='t' && token[strlen(token)-2]=='&'){
      copy1[strlen(token)-2]=' ';
      copy1[strlen(token)-1]=' ';
      // printf("%s",copy1);
      // char* ash=malloc(sizeof(char)*1000);
     
      // char* t=strtok(copy1," ");
      // while(t!=NULL){
        // strcat(ash,t);
        // t=strtok(NULL," ");
      // }
      thread(copy1);
      // break;
    }

   else if(!strcmp(token,"cd")){
      token=strtok(NULL," ");
      if(token==NULL){
        printf("you didn't mention any directory so we have shifted you to home directory");
        chdir("/home");
      }
      else if(token[0]=='~'){
        chdir("/home");
      }
      else if(!strcmp(token,"..")){
        chdir("..");
      }
      else if(token[0]=='-'){
        printf("Either the command is wrong oer not handled");
      }
      else{
        if(chdir(token) != 0){
          perror("failed");
        }
      }
    }

    else if (!strcmp(token, "echo")) {
      token = strtok(NULL, " ");
      if (strcmp(token, "-e") == 0) {
        int check = 0;
        token = strtok(NULL, " ");
        while (token != NULL) {
          if (token[0] == '\\' && token[1] == 'b') {
            for (int i = 2; i < strlen(token); i++) {
              printf("%c", token[i]);
            }

          } else if (token[0] == '\\' && token[1] == 'c') {
            printf(" ");
            check = 1;
            break;
          } else if (token[0] == '\\' && token[1] == 'n') {
            printf("\n");
            for (int i = 2; i < strlen(token); i++) {
              printf("%c", token[i]);
            }
          } else if (token[0] == '\\' && token[1] == 't') {
            printf("  ");
            for (int i = 2; i < strlen(token); i++) {
              printf("%c", token[i]);
            }
          } else {
            for (int i = 0; i < strlen(token); i++) {
              if (token[i] != '"') {
                printf("%c", token[i]);
              }
            }
          }
          token = strtok(NULL, " ");
        }
        if (check == 0) {
          printf("\n");
        }
      }

      else if (!strcmp(token, "-n")) {
        token = strtok(NULL, " ");
        while (token != NULL) {
          printf(" ");
          for (int i = 0; i < strlen(token); i++) {
            if (token[i] == '"' || token[i] == '\\') {
              continue;
            } else {
              printf("%c", token[i]);
            }
          }
          token = strtok(NULL, " ");
        }
      } else {

        while (token != NULL) {
          printf(" ");
          for (int i = 0; i < strlen(token); i++) {
            if (token[i] == '"' || token[i] == '\\') {
              continue;
            } else {
              printf("%c", token[i]);
            }
          }
          token = strtok(NULL, " ");
        }
        printf("\n");
      }
    }

    else if(!strcmp(token,"pwd")){
      token=strtok(NULL," ");
      if(token==NULL || !strcmp(token,"-L") || !strcmp(token,"-P")){
        printf("%s\n",getcwd(s1,100));
      }
      else{
        printf("Either command doesn't exist or not found in pwd's commands");
      }
    }

    else if(!strcmp(token,"ls")){
      int id=fork();
      if(id<0){
        printf("Could not fork\n");
      }
      else if(id==0){
        // execl("./ls",copy,NULL);
        char* hi=malloc(sizeof(char)*1000);
        strcpy(hi,glo);
        strcat(hi,"/ls");
        execl(hi,copy,NULL);
      }
      else{
        wait(NULL);
      }
     
    }
    else if(!strcmp(token,"cat")){
      int id=fork();
      if(id<0){
        printf("Could not fork\n");
      }
      else if(id==0){
        char* hi=malloc(sizeof(char)*1000);
        strcpy(hi,glo);
        strcat(hi,"/cat");
        execl(hi,copy,NULL);
        // execl("./cat",copy,NULL);
      }
      else{
        wait(NULL);
      }
     
    }
    else if(!strcmp(token,"date")){
      int id=fork();
      if(id<0){
        printf("Could not fork\n");
      }
      else if(id==0){
        // execl("./date",copy,NULL);
        char* hi=malloc(sizeof(char)*1000);
        strcpy(hi,glo);
        strcat(hi,"/date");
        execl(hi,copy,NULL);
      }
      else{
        wait(NULL);
      }
     
    }
    else if(!strcmp(token,"mkdir")){
      int id=fork();
      if(id<0){
        printf("Could not fork\n");
      }
      else if(id==0){
        // execl("./mkdir",copy,NULL);
        char* hi=malloc(sizeof(char)*1000);
        strcpy(hi,glo);
        strcat(hi,"/mkdir");
        execl(hi,copy,NULL);
      }
      else{
        wait(NULL);
      }
     
    }
    else if(!strcmp(token,"rm")){
      int id=fork();
      if(id<0){
        printf("Could not fork\n");
      }
      else if(id==0){
        // execl("./rm",copy,NULL);
        char* hi=malloc(sizeof(char)*1000);
        strcpy(hi,glo);
        strcat(hi,"/rm");
        execl(hi,copy,NULL);
      }
      else{
        wait(NULL);
      }
     
    }
    else{
      printf("Wrong command entered\n");
    }
   
  }
}
