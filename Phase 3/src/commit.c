#include "proj.h"


extern pthread_mutex_t m_log_lock;
int COMMIT(int transID){
//  printf(" present in the commit");
  char *line = NULL;
  char temp1[10],temp2[10],temp3[12];
  int dup_commit = 0;
  Record* rec = (Record *)malloc(sizeof(Record));
  Record* result = (Record *)malloc(sizeof(Record));
  // open log file to get for ID
  FILE *fp = fopen("Log.txt","r");
  FILE *fd = fopen("Log.txt","a");
  result->transID = -1;
  if(fp == NULL){
    puts(" error wile opening file");
    return -1;
  }
  pthread_mutex_lock(&m_log_lock);
  while((fscanf(fp,"%s %s %d %s %d %s %s",rec->status,temp1,&(rec->transID),temp2,&(rec->dataID),temp3,rec->dataVal))!= -1){
//    sscanf(line,"%s %s %d %s %d %s %s",rec->status,temp1,&(rec->transID),temp2,&(rec->dataID),temp3,rec->dataVal);
    if(rec->transID == transID && (strcmp(rec->status,"PENDING")==0)){
      // if ID is present then store record for commit the value at end
      result->transID = rec->transID;
      result->dataID = rec->dataID;
      strcpy(result->dataVal,rec->dataVal);
      dup_commit = 0;
    }
    if(rec->transID == transID && ((strcmp(rec->status,"COMMIT")==0)||(strcmp(rec->status,"ABORT")==0))){
// the commit  for given ID is already committe or aborted then dont commit
      dup_commit = 1;
    }
    free(line);
  }
  if(!dup_commit && result->transID != -1){
    fseek(fd,0,SEEK_END);
    strcpy(temp1,"transID:");
    strcpy(temp2,"dataID:");
    strcpy(temp3,"dataVal:");
    fprintf(fd,"%s %s %d %s %d %s %s\n","COMMIT",temp1,result->transID,temp2,result->dataID,temp3,result->dataVal);
    ALLOCATE(result);
    fclose(fd);
  }else{
    fclose(fd);
    fclose(fp);
    pthread_mutex_unlock(&m_log_lock);
    return -2;
  }
  fclose(fp);
  pthread_mutex_unlock(&m_log_lock);
  free(rec);
  free(result);
  return 0;
}
