#include "proj.h"
#include "write.c"
#include "commit.c"
#include "read.c"
#include "new_action.c"
#include<pthread.h>

  pthread_t pid1,pid2;
void fun(void *data){
  char result[20];
  int ret_val;
  Record *rec = (Record *)malloc(sizeof(Record));
  rec->dataID = *((int *)data);
  initJFS();
  strcpy(rec->dataVal ,"YAHOO");
  printf(" Calling NEW_ACTION for new transaction ID\n");
  rec->transID = NEW_ACTION();
  printf("Calling WRITE_NEW_VALUE for dataId %d value %s and\n",rec->dataID,rec->dataVal);
  WRITE_NEW_VALUE(rec);
  printf("Calling COMMIT for transID %d \n",rec->transID);
  ret_val = COMMIT(rec->transID);
  if(ret_val < 0){
    printf(" There was no commit operation done as transID pending write was not there\n");
  }else{
    printf("Calling READ_CURRENT_VALUE on dataId %d \n",rec->dataID);
    READ_CURRENT_VALUE(rec->dataID,result);
    if(strcmp(result,rec->dataVal) == 0){
      printf("Read the correct value\n");
    }
  }
}
int main()
{
  int a[] = {1,1};
  printf("Running First Test Case For Showing MultiThread Scenario\n");
  pthread_create(&pid1,NULL,(void *)&fun,(void *)&a[1]);
  puts("Thread 1 started for dataID 1");
  pthread_create(&pid2,NULL,(void *)&fun,(void *)&a[0]);
  puts("Thread 2 started for dataID 1");
  pthread_join(pid1,NULL);
  pthread_join(pid2,NULL);
  return 0;
}
