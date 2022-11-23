#include<stdio.h>
#include<time.h>
#include<string.h>
//1 argument--simple date
//2 argument-- u date
//3 argument-- local time

int main(int argc,char* argv[]){
  char* t=strtok(argv[0]," ");//date
  t=strtok(NULL," "); //command
  if(t==NULL){
    time_t t=time(NULL);
    time(&t);
    printf("%s\n",ctime(&t));
  }
  else if(!strcmp(t,"-u")){
    time_t t=time(NULL);
    if(t==-1){
      perror("Error is");
    }
    else{
      struct tm *pt;
      char b1[4],b2[4],b3[4];
      pt=gmtime(&t);
      if(pt==NULL){
        perror("Error is");
      }
      else{
        strftime(b1,4,"%a",pt);
        strftime(b2,4,"%b",pt);
        strftime(b3,4,"%z",pt);
        printf("%s %s %02d:%02d:%02d %d\n",b1,b2,pt->tm_hour,pt->tm_min,pt->tm_sec,pt->tm_year+1900);
      }
    }
  }
  else if(!strcmp(t,"-r")){
    time_t t=time(NULL);
    if(t==-1){
      perror("Error is");
    }
    else{
      struct tm *pt;
      char b1[4],b2[4],b3[6];
      pt=localtime(&t);
      if(pt==NULL){
        perror("Error is");
      }
      else{
        strftime(b1,4,"%a",pt);
        strftime(b2,4,"%b",pt);
        strftime(b3,6,"%z",pt);
        printf("%s, %02d %s %d %02d:%02d:%02d %s\n",b1,pt->tm_mday,b2,pt->tm_year+1900,pt->tm_hour,pt->tm_min,pt->tm_sec,b3);
      }
    }
  }
 
  return 0;
}
