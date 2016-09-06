
#include "proj.h"


void READ_CURRENT_VALUE(int dataID, char* val){

//printf(" INSIDE READ_CURRENT_VALUE");
char temp1[10],temp2[10],temp3[12];
Record* rec = (Record *)malloc(sizeof(Record));
// open log file to get for ID
FILE *fp = fopen("Log.txt","r");
if(fp == NULL){
  puts(" error wile opening file");
  return ;
}
while((fscanf(fp,"%s %s %d %s %d %s %s",rec->status,temp1,&(rec->transID),temp2,&(rec->dataID),temp3,rec->dataVal))!= -1){
  if(rec->dataID == dataID && (strcmp(rec->status,"COMMIT")==0)){
    // if ID is present then store record for commit the value at end
    strcpy(val,rec->dataVal);
    }
  }
  fclose(fp);
  return ;
}
