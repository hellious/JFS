#include "proj.h"
#include "write.c"
#include "commit.c"
#include "read.c"
#include "abort.c"
#include "new_action.c"
int main()
{
  // for two continous commit first is succesful
  char result[20];
  Record *rec = (Record *)malloc(sizeof(Record));
  rec->dataID = 1;
  int ret_val;
  strcpy(rec->dataVal ,"YAHOO");
  printf("Running Second Sixth Case For Commit\n");
  printf(" Calling NEW_ACTION for new transaction ID");
  rec->transID = NEW_ACTION();
  printf("Calling WRITE_NEW_VALUE for dataId %d value %s\n",rec->dataID,rec->dataVal);
  WRITE_NEW_VALUE(rec);
  printf("Calling COMMIT for transID %d \n",rec->transID);
  COMMIT(rec->transID);
  printf("Calling COMMIT for transID %d \n",rec->transID);
  ret_val = COMMIT(rec->transID);
  if(ret_val == 0){
    printf("Test Case sixth failed\n");
  }else{
    printf(" Scond COMMIT was not done\n");
    printf("Test Case sixth passed\n");
  }
  return 0;
}
