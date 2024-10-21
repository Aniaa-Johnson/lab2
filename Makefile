time: main.o ipc.o time.o
	$(CC) -o $@ $?

main.o: main.c
	$(CC) -c $?
ipc.o: ipc.c
	$(CC) -c $?

time.o: time.c 
	$(CC) -c $?
