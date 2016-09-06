#include "proj.h"



int main(int argc , char* argv[]){
  char str[30];
  char val[30] = {0};
  Record* rec;
  char temp;
  int temp_id;
  initJFS();
  while(scanf("%s",str) != -1){
    if(strcmp("WRITE_NEW_VALUE",str) == 0){
      rec = (Record *)malloc(sizeof(Record));
      printf("enter the data ID\n");
      scanf("%d",&(rec->dataID));
      rec->transID = NEW_ACTION();
      printf("enter the data value\n");
      scanf("%s",rec->dataVal);
      rec->transID =WRITE_NEW_VALUE(rec);
      printf("WRITE_NEW_VALUE is done for transID : %d\n",rec->transID);
    }
    if(strcmp("READ_CURRENT_VALUE",str) == 0){
      printf("enter the data ID to read\n");
      scanf("%d",&temp_id);
      READ_CURRENT_VALUE(temp_id,val);
      if(strcmp(val,"") != 0)
        printf(" val of Read cureent value is : %s \n",val);
      else
        printf("There are no commit value for given dataID : %d \n",temp_id);
      memset(val,0,30);
    }
    if(strcmp("COMMIT",str) == 0){
      puts("enter the id to commit");
      scanf("%d",&temp_id);
      temp = COMMIT(temp_id);
      if(temp != 0)
        puts("Either there is already comit or abort for given ID");
      else
        printf("Value is commited for transID : %d\n",temp_id);
    }
    if(strcmp("ABORT",str) == 0){
      puts("enter the id to commit");
      scanf("%d",&temp_id);
      temp = ABORT(temp_id);
      if(temp != 0)
        puts("Either there is already comit or abort for given ID");
      else
        printf("Value is aborted for transID : %d\n",temp_id);
    }
    puts("Press Y for another operation and N for exit");
    scanf("%s",&temp);
    if(temp != 'Y')
      break;
  }
  return 0;
}
