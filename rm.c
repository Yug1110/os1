#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

// 1 -r
// 2 -i
// 3 normal

int main(int argc,char* argv[]){

  char* t=strtok(argv[0]," "); //rm
  t=strtok(NULL," "); //-

  if(!strcmp(t,"-r")){
    t=strtok(NULL," "); // filename
    if(remove(t)==0){
      printf("%s deleted \n",t);
    }
    else{
      printf("%s unble to delete\n",t);
    }
   
  }

  else if(!strcmp(t,"-i")){
    t=strtok(NULL," ");
    if(access(t,F_OK)==0){
      printf("Do you want to removeit(y/n): ");
      char a;
      scanf("%c",&a);
      if(a=='y'){
        if(remove(t)==0){
          printf("%s deleted\n",t);
        }
        else{
          printf("%s unable to delete",t);
        }
      }
      else{
        printf("rm command terminated\n");
      }
    }
    else{
      printf("The file doesn't exist");
    }
  }

  else if(t[0]=='-'){
    printf("Either the command does not exist or not handled in rm");
  }
  else{
    while(t!=NULL){
      if(remove(t)==0){
        printf("%s deleted\n",t);
      }
      else{
        printf("%s unable to delete\n",t);
      }
      t=strtok(NULL," ");
    }
  }
 
 
  return 0;
}
