
#include "proj.h"

extern FILE* fp;
extern pthread_mutex_t m_trans_lock;
extern pthread_mutex_t m_log_lock;
extern pthread_mutex_t m_cell_lock;

void initJFS(){
  // for initialising lock for new transaction
  pthread_mutex_init(&m_trans_lock,NULL);
  pthread_mutex_init(&m_log_lock,NULL);
  pthread_mutex_init(&m_cell_lock,NULL);
  RECOVERY();
}

int NEW_ACTION(){
//  printf("inside new action");
  int cur_id,last_id;
  FILE *fp = fopen("transID.txt","r+");
  if(fp == NULL){
    return -1;
  }
  pthread_mutex_lock(&m_trans_lock);
  fscanf(fp,"%d",&last_id);
  fseek(fp,0,SEEK_SET);
  cur_id = last_id +1;
  fprintf(fp,"%d",cur_id);
  fclose(fp);
  pthread_mutex_unlock(&m_trans_lock);
  return cur_id;
}
