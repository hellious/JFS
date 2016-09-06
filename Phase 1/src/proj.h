#ifndef PROJ_H
#define PROJ_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define MAX 20

struct log_data{
  char status[20];
//  int action_type
  int transID;
  int dataID;
  char dataVal[MAX];
};

typedef struct log_data Record;

int NEW_ACTION();
void READ_CURRENT_VALUE(int dataID, char *ret_val);
int WRITE_NEW_VALUE(Record* rec);
int COMMIT(int transID);
int ABORT(int transID);

#endif
