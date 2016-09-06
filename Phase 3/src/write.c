#include "proj.h"

extern pthread_mutex_t m_log_lock;

int WRITE_NEW_VALUE(Record* rec){
  //printf(" INSIDE WRITE_NEW_VALUE");
  char temp1[10],temp2[10],temp3[12];
  fp = fopen("Log.txt","a");
  if(fp == NULL)
    return -1;
  pthread_mutex_lock(&m_log_lock);
  strcpy(temp1,"transID:");
  strcpy(temp2,"dataID:");
  strcpy(temp3,"dataVal:");
  if(isValidWrite(rec->dataID)){
    fseek(fp,0,SEEK_END);
    fprintf(fp,"%s %s %d %s %d %s %s\n","PENDING",temp1,rec->transID,temp2,rec->dataID,temp3,rec->dataVal);
  }else{
    puts("Other pending write for same dataID is still waiting to be committed");
    puts("Not updating current pending WRITE");
  }
  fclose(fp);
  pthread_mutex_unlock(&m_log_lock);
  //deleteFileLock();
  return rec->transID;
}

int isValidWrite(int dataID){
  int is_valid = 1;
  char temp1[10],temp2[10],temp3[12];
  Record* rec = (Record *)malloc(sizeof(Record));
  fd = fopen("Log.txt","r");
  fseek(fd,0,SEEK_SET);
  while((fscanf(fd,"%s %s %d %s %d %s %s",rec->status,temp1,
    &(rec->transID),temp2,&(rec->dataID),temp3,rec->dataVal))!= -1){
    if(rec->dataID == dataID && strcmp(rec->status,"PENDING") == 0){
      is_valid = 0;
    }else{
      is_valid = 1;
    }
  }
  fclose(fd);
  return is_valid;
}
