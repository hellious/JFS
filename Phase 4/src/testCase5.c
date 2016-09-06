#include "proj.h"
#include "write.c"
#include "commit.c"
#include "read.c"
#include "new_action.c"
#include "abort.c"
#include "recovery.c"
#include "allocate.c"
#include<pthread.h>

  pthread_t pid1,pid2;
void fun(void *data){
  int ret_val;
  char result[20];
  pthread_t pid = pthread_self();
  Record *rec = (Record *)malloc(sizeof(Record));
  rec->dataID = *((int *)data);
  if(pid == pid2){
    strcpy(rec->dataVal ,"YAHOO");
  }else{
    strcpy(rec->dataVal ,"GOOGLE");
  }
  printf(" Calling NEW_ACTION for new transaction ID\n");
  rec->transID = NEW_ACTION();
  printf("Calling WRITE_NEW_VALUE for dataId %d value %s and\n",rec->dataID,rec->dataVal);
  WRITE_NEW_VALUE(rec);
  if(pid == pid1){
    printf("Calling COMMIT for transID %d \n",rec->transID);
    ret_val = COMMIT(rec->transID);
    if(ret_val < 0){
      printf(" There was no commit operation done as transID pending write was not there\n");
    }
  }else{
    printf("Calling ABORT for transID %d \n",rec->transID);
    ABORT(rec->transID);
    printf("Calling READ_CURRENT_VALUE on dataId %d \n",rec->dataID);
    READ_CURRENT_VALUE(rec->dataID,result);
    if(strcmp(result,"YAHOO") == 0){
      printf("Test Case 5 succesfully passed\n");
    }
  }
}
int main()
{
  int a[] = {1,1};
  initJFS();
  printf("Running 5 TC : MultiThread Scenario for abort and commit for same dataID\n");
  pthread_create(&pid1,NULL,(void *)&fun,(void *)&a[1]);
  puts("Thread 1 started for dataID 1");
  pthread_create(&pid2,NULL,(void *)&fun,(void *)&a[0]);
  puts("Thread 2 started for dataID 1");
  pthread_join(pid1,NULL);
  pthread_join(pid2,NULL);
  return 0;
}
