#include "proj.h"
#include "write.c"
#include "commit.c"
#include "read.c"
#include "new_action.c"
#include "recovery.c"
#include "allocate.c"
int main()
{
  puts(" ## Running TC for Fault scenario ##");
  //char result[20];
  Record *rec = (Record *)malloc(sizeof(Record));
  rec->dataID = 3;
  strcpy(rec->dataVal ,"YAHOO");
  printf(" Calling NEW_ACTION for new transaction ID\n");
  rec->transID = NEW_ACTION();
  printf("Calling WRITE_NEW_VALUE for dataId %d value %s and\n",rec->dataID,rec->dataVal);
  WRITE_NEW_VALUE(rec);
  printf("Calling COMMIT for transID %d \n",rec->transID);
  COMMIT(rec->transID);
  rec->dataID = 4;
  strcpy(rec->dataVal ,"GOOGLE");
  printf(" Calling NEW_ACTION for new transaction ID\n");
  rec->transID = NEW_ACTION();
  printf("Calling WRITE_NEW_VALUE for dataId %d value %s and\n",rec->dataID,rec->dataVal);
  WRITE_NEW_VALUE(rec);
  printf("Calling COMMIT for transID %d \n",rec->transID);
  COMMIT(rec->transID);
  printf(" System getting crashed \n");
  return 0;
}
