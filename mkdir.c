#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

// 1 -v
// 2 -p
// 3 normal

int main(int argc,char* argv[]){
  char input2[100];
  strcpy(input2,argv[0]);
  char *t=strtok(argv[0]," ");//mkdir
  t=strtok(NULL," "); //option

  if(!strcmp(t,"-v")){
    int c;
    t=strtok(NULL," ");
    while(t!=NULL){
      c=mkdir(t,0777);
      if(c==-1){
        printf("%s directory not created\n",t);
      }
      else{
        printf("%s directory created\n",t);
      }
      t=strtok(NULL," ");
    }
  }

  else if(!strcmp(t,"-p")){
    int c;
    t=strtok(NULL," ");

    char *dir=strtok(input2," "); //mkdir
    dir =strtok(NULL," "); //-p
    dir=strtok(NULL,"/");
    c=mkdir(dir,0777);
    if(c==-1){
      printf("%s Directory not created\n",dir);
    }else{
      printf("%s Directory created\n",dir);
    }

    c=mkdir(t,0777);
    if(c==-1){
      printf("%s Directory not created\n",t);
    }else{
      printf("%s Directory created\n",t);
    }
   
  }

  else if(t[0]=='-'){
    printf("Either the command does not exist or is not handeled in mkdir");
  }
  else if(t==NULL){
    printf("You need to provide a directory name");
  }
  else{
    // t=strtok(NULL,"  ");
    // printf("%s heloo\n",t);
    int c=mkdir(t,0777);
    if(c==-1){
      printf("%s directory not created\n",t);
    }
    else{
      printf("%s directory created\n",t);
    }
  }
}
