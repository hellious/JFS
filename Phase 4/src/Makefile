CC = gcc
CFLAGS = -Wall

jfs : read.o write.o abort.o allocate.o commit.o new_action.o recovery.o fault1 fault2 testCase1 testCase2 testCase3 testCase4 testCase5
	$(CC) $(CFLAGS) -o jfs jfs.c read.o write.o abort.o allocate.o commit.o new_action.o recovery.o

fault1 : read.o write.o abort.o allocate.o commit.o new_action.o
	$(CC) $(CFLAGS) -o fault1 fault1.c
fault2 : read.o write.o abort.o allocate.o commit.o new_action.o
	$(CC) $(CFLAGS) -o fault2 fault2.c
testCase1 : read.o write.o abort.o allocate.o commit.o new_action.o
	$(CC) $(CFLAGS) -o testCase1 testCase1.c
testCase2 : read.o write.c abort.o commit.o new_action.o allocate.o
	$(CC) $(CFLAGS) -o testCase2 testCase2.c
testCase3 : read.o write.c abort.o commit.o new_action.o allocate.o
	$(CC) $(CFLAGS) -o testCase3 testCase3.c
testCase4 : read.o write.c abort.o commit.o new_action.o allocate.o
	$(CC) $(CFLAGS) -o testCase4 testCase4.c
testCase5 : read.o write.c abort.o commit.o new_action.o allocate.o
	$(CC) $(CFLAGS) -o testCase5 testCase5.c


read.o : read.c proj.h
	$(CC) $(CFLAGS) -c read.c

write.o : write.c proj.h
	$(CC) $(CFLAGS) -c write.c

abort.o : abort.c proj.h
	$(CC) $(CFLAGS) -c abort.c

allocate.o : allocate.c proj.h
	$(CC) $(CFLAGS) -c allocate.c

commit.o : commit.c proj.h
	$(CC) $(CFLAGS) -c commit.c allocate.c

new_action.o : new_action.c proj.h
	$(CC) $(CFLAGS) -c new_action.c

recovery.o : recovery.c proj.h
	$(CC) $(CFLAGS) -c recovery.c


clean:
			$(RM) jfs testCase1 testCase2 testCase3 testCase4 testCase5 testCase6  *.o
