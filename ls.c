#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

//normal
// -a
//-l

void run_ls(const char *directory,int count_a,int count_l)
{
struct dirent *dt;
DIR *dhir = opendir(directory);
  int check=0;
if (!dhir)
{
if (errno = ENOENT)
{
perror("directory is not present");
}
else
{
perror("directory annot be read");
}
check=1;
}
  if(check==0){
while ((dt = readdir(dhir)) != NULL)
{
if (!count_a && dt->d_name[0] == '.'){
continue;
      }
printf("%s  ", dt->d_name);
if(count_l){
    printf("\n");
    }
}
if(count_l==0)
printf("\n");
    }
}


int main(int argc,char* argv[]){
  char* t=strtok(argv[0]," ");//ls
  t=strtok(NULL," "); //option
  if(t==NULL){
    run_ls(".",0,0);
  }
  else if(!strcmp(t,"-a")){
    run_ls(".",1,0);
  }
  else if(!strcmp(t,"-l")){
    run_ls(".",0,1);
  }
  else{
    printf("You might have entered a wrong comand\n");
  }

 
 
  return 0;
}
