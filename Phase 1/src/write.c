#include "proj.h"

int WRITE_NEW_VALUE(Record* rec){

  //printf(" INSIDE WRITE_NEW_VALUE");
  char temp1[10],temp2[10],temp3[12];
  FILE *fp = fopen("Log.txt","a");
  if(fp == NULL)
    return -1;
  fseek(fp,0,SEEK_END);
  strcpy(temp1,"transID:");
  strcpy(temp2,"dataID:");
  strcpy(temp3,"dataVal:");
  fprintf(fp,"%s %s %d %s %d %s %s\n","PENDING",temp1,rec->transID,temp2,rec->dataID,temp3,rec->dataVal);
  fclose(fp);
  return rec->transID;
}
