#include "proj.h"
#include "write.c"
#include "commit.c"
#include "read.c"
#include "new_action.c"
int main()
{
  char result[20];
  Record *rec = (Record *)malloc(sizeof(Record));
  rec->dataID = 1;
  strcpy(rec->dataVal ,"YAHOO");
  printf("Running First Test Case For Commit\n");
  printf(" Calling NEW_ACTION for new transaction ID");
  rec->transID = NEW_ACTION();
  printf("Calling WRITE_NEW_VALUE for dataId %d value %s and\n",rec->dataID,rec->dataVal);
  WRITE_NEW_VALUE(rec);
  printf("Calling COMMIT for transID %d \n",rec->transID);
  COMMIT(rec->transID);
  printf("Calling READ_CURRENT_VALUE on dataId %d \n",rec->dataID);
  READ_CURRENT_VALUE(rec->dataID,result);
  if(strcmp(result,rec->dataVal) == 0){
    printf("Test Case 1 sucessfull\n");
  }
  return 0;
}
