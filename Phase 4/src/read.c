
#include "proj.h"

extern Block* head;
extern pthread_mutex_t m_cell_lock;
void READ_CURRENT_VALUE(int dataID, char* val){

// reading from the in memory cell storage
// head is the linked list which is story cell data
pthread_mutex_lock(&m_cell_lock);
Block* temp = head ;
while(temp != NULL){
  if(temp->rec->dataID == dataID){
    strcpy(val,temp->rec->dataVal);
    pthread_mutex_unlock(&m_cell_lock);
    return;
  }
  temp = temp->next;
}
pthread_mutex_unlock(&m_cell_lock);
return ;
}
