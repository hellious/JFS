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
  Record *rec = (Record *)malloc(sizeof(Record));
  rec->dataID = 1;
  int ret_val;
  strcpy(rec->dataVal ,"YAHOO");
  printf("Running third Test Case For Commit\n");
  printf(" Calling NEW_ACTION for new transaction ID\n");
  rec->transID = NEW_ACTION();
  printf("Calling WRITE_NEW_VALUE for dataId %d value %s\n",rec->dataID,rec->dataVal);
  WRITE_NEW_VALUE(rec);
  printf("Calling COMMIT for transID %d \n",rec->transID);
  COMMIT(rec->transID);
  printf("Calling ABORT for transID %d \n",rec->transID);
  ret_val = ABORT(rec->transID);
  if(ret_val == 0){
    printf("ABORT is sucessfull\n");
  }else{
    printf(" ABORT is not done as previously COMMIT\n");
    printf(" TEST CASE three successfull\n");
  }
  return 0;
}
