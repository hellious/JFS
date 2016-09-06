#include "proj.h"
#include "write.c"
#include "commit.c"
#include "read.c"
#include "new_action.c"
#include<pthread.h>

pthread_t pid1,pid2;
void fun(void *data){
  pthread_t pid = pthread_self();
  int ret_val;
  Record *rec = (Record *)malloc(sizeof(Record));
  rec->dataID = *((int *)data);
  initJFS();
  strcpy(rec->dataVal ,"YAHOO");
  printf(" Calling NEW_ACTION for new transaction ID\n");
  rec->transID = NEW_ACTION();
  printf("Calling WRITE_NEW_VALUE for dataId %d value %s and\n",rec->dataID,rec->dataVal);
  WRITE_NEW_VALUE(rec);
  if(pid == pid2){
    printf("Calling COMMIT for transID %d \n",rec->transID);
    ret_val = COMMIT(rec->transID);
    if(ret_val < 0){
      puts("Test Case 4 failed");
    }else{
      puts("Test Case 4 succesfully passed");
    }
  }
}
int main()
{
  int a[] = {1,2};
  printf("Running 4 TC : Pending write in one thread and commit in other thread for diff dataID\n");
  pthread_create(&pid1,NULL,(void *)&fun,(void *)&a[1]);
  puts("Thread 1 started for dataID 1");
  pthread_create(&pid2,NULL,(void *)&fun,(void *)&a[0]);
  puts("Thread 2 started for dataID 2");
  pthread_join(pid1,NULL);
  pthread_join(pid2,NULL);
  return 0;
}
