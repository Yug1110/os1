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

// 1 cat
// 2 -b
// 3 -n
// 4 >

int main(int argc,char* argv[]){
  char input3[100];
  char input4[100];
  strcpy(input3,argv[0]);
  strcpy(input4,argv[0]);
  char * t=strtok(argv[0]," "); //cat
  t=strtok(NULL," ");

  if(t==NULL){
    char line[100];
    printf("You will exit only after you enter 'exit' because ctrl+d doesn't work in this shell\n");
    while(1){
      gets(line);
      if(line[0]=='e' && line[1]=='x' && line[2]=='i' && line[3]=='t'){
        break;
      }
      puts(line);
    }
  }

  else if(!strcmp(t,"-b")){
    t=strtok(NULL," ");
    char ch;
    FILE *fptr=fopen(t,"r");
    int counter=0;
    do{
      ch=fgetc(fptr);
      if(ch=='\n'){
        counter++;
      }
    }while(ch != EOF);
    fclose(fptr);
    int i=1;
    int count1=0;
    fptr=fopen(t,"r");
    char text[100];
    // printf("counter  %d\n",counter);
    do{
      fgets(text,100,fptr);
      if(text[0]=='\n'){
        printf("\n");
       
      }
      else{
        printf("%d %s",i,text);
        i++;
      }
      count1++;
      // printf("count1  %gcc cad\n",count1);
    }while(count1 != counter+1);
    printf("\n");
  }

  else if(!strcmp(t,"-n")){
    t=strtok(NULL," ");
    char ch;
    FILE *fptr=fopen(t,"r");
    int counter=0;
    do{
      ch=fgetc(fptr);
      if(ch=='\n'){
        counter++;
      }
    }while(ch != EOF);
    fclose(fptr);
    int i=1;
    int j=1;
    int count1=0;
    fptr=fopen(t,"r");
    char text[100];
    do{
    	if(j==1){
    		j++;
    		fgets(text,100,fptr);
    	}
    	else{
      fgets(text,100,fptr);
      printf("%d %s", i, text);
      i++;
      count1++;
      }
    }while(count1 != counter);
    printf("\n");
  }

  else if( t[0]=='-'){
    printf("The command has not been handled or does not exist under cat\n");
  }
  else{
    // printf("Please make sure the files you mention exists\n");
    int check=0;
    int counter = 0;
    char* t1=strtok(input3," "); //cat
    t1=strtok(NULL," ");
    while(t1 != NULL){
      if(t1[0] == '>'){
        check=1;
        break;
      }
      counter++;
      t1=strtok(NULL," ");
    }
    // printf("%d",counter);
    if(check==1 && counter !=0){
      t1=strtok(NULL," ");
      FILE * wptr=fopen(t1,"w");
      fclose(wptr);
      wptr=fopen(t1,"a+");
      char *r=strtok(input4," ");
      FILE *iptr;
      for(int x=0;x<counter;x++){
        r=strtok(NULL," ");
        iptr=fopen(r,"r");
        char ch;
        do{
          ch=fgetc(iptr);
          fprintf((wptr),"%c",ch);
        }while(ch!=EOF);
        fclose(iptr);
      }
      fclose(wptr);
    }
    else if(check==1){
      t1=strtok(NULL," ");
      FILE *wptr=fopen(t1,"w");
      fclose(wptr);
      wptr=fopen(t1,"a+");
      char line[100];
      printf("You will exit only after you enter 'exit' because ctrl+d doesn't work in this shell\n");
      while(1){
        gets(line);
        if(line[0]=='e' && line[1]=='x' && line[2]=='i' && line[3]=='t'){
          break;
        }
        else{
          fputc('\n',wptr);
          fputs(line,wptr);
        }
      }
      fclose(wptr);
    }

    else{
      char* r=strtok(input4," ");
      r=strtok(NULL," ");
      FILE *optr;
      char ch;
      while(r!=NULL){
        optr=fopen(r,"r");
        do{
          ch=fgetc(optr);
          printf("%c",ch);
        }while(ch !=EOF);
        printf("\n");
        fclose(optr);
        r=strtok(NULL," ");
      }
    }
  }
 

 
  return 0;
}
