#include "proj.h"


extern Block* head;
int ALLOCATE(Record* rec){
  Block* temp2 = head;
  Block* temp = NULL;
  int flag = 1;
  while(temp2 != NULL){
    // if data id is present then change the vaue of datavalue onlye
    if(temp2->rec->dataID == rec->dataID){
      strcpy(temp2->rec->dataVal,rec->dataVal);
      flag = 0;
    }
    temp2 = temp2->next;
  }
  // if dataid is not present then add to the list
  if(temp2 == NULL && flag){
    temp = (Block*) malloc(sizeof(Block));
    temp->rec = (Record*)malloc(sizeof(Record));
    temp->rec->dataID = rec->dataID;
    strcpy(temp->rec->dataVal,rec->dataVal);
    temp->next = head;
    head = temp;
  }
//  print(head);
  return 0;
}
// to print the in memory disk file for storng the cell data
void print(Block* head){
  Block* blk = head;
  while(blk != NULL){
    printf(" value is numm %d %s \n",blk->rec->dataID,blk->rec->dataVal);
    blk = blk->next;
  }
}
void DEALLOCATE(){
  free(head);
}
