all: so mainso

#PREFIX=arm-none-linux-gnueabi-

CC=$(PREFIX)gcc
AR=$(PREFIX)ar

lib: 
	$(CC) -O3 -Wall -c varmathlib.c v_exp.c v_log.c v_cos.c v_sin.c v_atan.c virus.c vmon.c
	$(AR) -cvq varmathlib.a varmathlib.o v_exp.o v_log.o v_cos.o v_sin.o v_atan.o
	$(AR) -cvq viruslib.a vmon.o virus.o 
	

so:
	$(CC) -O3 -Wall -fPIC -c varmathlib.c v_exp.c v_log.c v_cos.c v_sin.c v_atan.c  virus.c vmon.c
	$(CC) -O3 -shared -Wl,-soname,libvarmath.so.1 -o libvarmath.so.1.0 varmathlib.o v_exp.o v_log.o v_cos.o v_sin.o v_atan.o
	$(CC) -O3 -shared -Wl,-soname,libvirus.so.1 -o libvirus.so.1.0 vmon.o virus.o 
	

main:
	$(CC) -static -o main main.c -Wl,--whole-archive  viruslib.a  -Wl,--whole-archive varmathlib.a   -Wl,--no-whole-archive -lm

mainso:
	$(CC) -Wall -L/opt/lib main.c -Wl,-no-as-needed -lvirus -Wl,-no-as-needed -lvarmath -lm -o main 

install:
	cp libvarmath.so.1.0 libvirus.so.1.0 /opt/lib/

clean:
	rm *so *o *a main

