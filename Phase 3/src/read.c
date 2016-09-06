
#include "proj.h"

extern Block* head;
void READ_CURRENT_VALUE(int dataID, char* val){

// reading from the in memory cell storage
// head is the linked list which is story cell data 
Block* temp = head ;
while(temp != NULL){
  if(temp->rec->dataID == dataID){
    strcpy(val,temp->rec->dataVal);
    return;
  }
  temp = temp->next;
}
  return ;
}
