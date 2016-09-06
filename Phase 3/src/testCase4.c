#include "proj.h"
#include "write.c"
#include "commit.c"
#include "read.c"
#include "abort.c"
#include "new_action.c"
#include "recovery.c"
#include "allocate.c"
int main()
{

  initJFS();
  int ret_val;
  Record *rec = (Record *)malloc(sizeof(Record));
  rec->dataID = 1;
  strcpy(rec->dataVal ,"YAHOO");
  printf("Running Fourth Test Case For Commit\n");
  printf(" Calling NEW_ACTION for new transaction ID\n");
  rec->transID = NEW_ACTION();
  printf("Calling WRITE_NEW_VALUE for dataId %d value %s\n",rec->dataID,rec->dataVal);
  WRITE_NEW_VALUE(rec);
  printf("Calling ABORT for transID %d \n",rec->transID);
  ABORT(rec->transID);
  printf("Calling COMMIT for transID %d \n",rec->transID);
  ret_val = COMMIT(rec->transID);
  if(ret_val != 0){
    printf("COMMMIT was not successful as Abort with same ID is called before\n");
    printf("Test Case fourth sucessfull\n");
  }else{
    printf(" Test Case fourth failed\n");
  }
  return 0;
}
