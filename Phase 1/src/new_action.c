
#include "proj.h"

int NEW_ACTION(){
//  printf("inside new action");
//  static int counter = 0;
//  counter++;
//  printf(" INSIDE NEW_ACTION");
  int cur_id,last_id;
  FILE *fp = fopen("transID.txt","r+");
  if(fp == NULL){
    return -1;
  }
  fscanf(fp,"%d",&last_id);
  fseek(fp,0,SEEK_SET);
  cur_id = last_id +1;
  fprintf(fp,"%d",cur_id);
  fclose(fp);
  return cur_id;
}
