#include "proj.h"

int isValidForAbort(int);

void populatFile(){
  char temp1[10],temp2[10],temp3[12];
  fp = fopen("Log.txt","r");
  Record* temp = (Record*)malloc(sizeof(Record));
  while(fscanf(fp,"%s %s %d %s %d %s %s\n",temp->status,temp1,&temp->transID,temp2,&temp->dataID,temp3,temp->dataVal)!=-1){
    if(strcmp(temp->status,"COMMIT")==0){
      // as there is commit it should be written in the in disk file
      ALLOCATE(temp);
    }
  }
     fclose(fp);
}

void RECOVERY(){
  puts("strating recovery");
  char temp1[10],temp2[10],temp3[12];
  Record* current = NULL;
  Record* temp = (Record*) malloc(sizeof(Record));
  Block* blk = NULL, *temp_blk;
  fp = fopen("Log.txt","r");
  while(fscanf(fp,"%s %s %d %s %d %s %s\n",temp->status,temp1,&temp->transID,temp2,&temp->dataID,temp3,temp->dataVal)!=-1){
      // as there is commit it should be written in the in disk file
      if(strcmp(temp->status,"PENDING")==0){
        temp_blk = (Block*)malloc(sizeof(Block));
        temp_blk->rec = temp;
  //      printf("Trabs : %d\n",temp->transID);
        temp_blk->next = blk;
        blk = temp_blk;
        temp = (Record*) malloc(sizeof(Record));
      }
  }
  fclose(fp);
  temp_blk = blk;
  while(temp_blk != NULL){
    current = temp_blk->rec; // current record to search
    if(isValidForAbort(current->transID)){
      fp = fopen("Log.txt","a");
    //  fseek(fp,0,SEEK_END);
      fprintf(fp,"%s %s %d %s %d %s %s\n","ABORT",temp1,current->transID,temp2,current->dataID,temp3,current->dataVal);
      fclose(fp);
    }
    temp_blk = temp_blk->next;
  }
  populatFile();
}


int isValidForAbort(int transID){
  int is_valid = 1;
  char temp1[10],temp2[10],temp3[12];
  Record* rec = (Record *)malloc(sizeof(Record));
  fd = fopen("Log.txt","r");
  fseek(fd,0,SEEK_SET);
  while((fscanf(fd,"%s %s %d %s %d %s %s",rec->status,temp1,
    &(rec->transID),temp2,&(rec->dataID),temp3,rec->dataVal))!= -1){
    //  printf("T:: %d\n",transID );
    if(rec->transID == transID && (strcmp(rec->status,"COMMIT") == 0 || strcmp(rec->status,"ABORT") == 0) ){
      is_valid = 0;
      fclose(fd);
      return is_valid;
    }
  }
  fclose(fd);
  return is_valid;
}
