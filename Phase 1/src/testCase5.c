#include "proj.h"
#include "write.c"
#include "commit.c"
#include "read.c"
#include "abort.c"
#include "new_action.c"
int main()
{
  // test case where commit is trying to write unknown pending write ID
  char result[20];
  Record *rec = (Record *)malloc(sizeof(Record));
  rec->dataID = 1;
  int ret_val, temp_transID = 3;
  strcpy(rec->dataVal ,"YAHOO");
  printf("Running Second Test Case For Commit\n");
  printf("Calling WRITE_NEW_VALUE for dataId %d value %s\n",rec->dataID,rec->dataVal);
  rec->transID = WRITE_NEW_VALUE(rec);
  printf("Calling COMMIT for transID %d \n",temp_transID);
  ret_val = COMMIT(temp_transID);
  if(ret_val == 0){
    printf("COMMIT is sucessfull\n");
  }else{
    printf(" COMMIT is not SUCCESSFULL as no pending write with transID\n");
    printf(" Test case 5 passed\n");
  }
  return 0;
}
