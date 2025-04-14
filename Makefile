# CC = gcc
# CFLAGS = -Wall

# OBJS = main.o auth.o file_ops.o access_control.o encryption.o malware_scan.o metadata.o overflow_demo.o

# secure_file_system: $(OBJS)
# 	$(CC) $(CFLAGS) -o secure_file_system $(OBJS)

# main.o: main.c auth.h file_ops.h access_control.h encryption.h malware_scan.h metadata.h overflow_demo.h
# auth.o: auth.c auth.h
# file_ops.o: file_ops.c file_ops.h encryption.h
# access_control.o: access_control.c access_control.h
# encryption.o: encryption.c encryption.h
# malware_scan.o: malware_scan.c malware_scan.h encryption.h
# metadata.o: metadata.c metadata.h
# overflow_demo.o: overflow_demo.c overflow_demo.h

# clean:
# 	rm -f *.o secure_file_system


OBJS = main.o auth.o file_ops.o access_control.o encryption.o malware_scan.o metadata.o overflow_demo.o

secure_file_system: $(OBJS)
	$(CC) $(CFLAGS) -o secure_file_system $(OBJS)

main.o: main.c auth.h file_ops.h access_control.h encryption.h malware_scan.h metadata.h overflow_demo.h
overflow_demo.o: overflow_demo.c overflow_demo.h
	