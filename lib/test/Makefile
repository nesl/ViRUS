all: lib main

lib: 
	cc -Wall -c testlib.c 
	ar -cvq testlib.a testlib.o 
so:
	gcc -Wall -fPIC -c testlib.c 
	gcc -shared -Wl,-soname,libtest.so.1 -o libtest.so.1.0 testlib.o

main:
	cc -o main main.c testlib.a

mainso:
	gcc -Wall -L/opt/lib/ main.c -ltest -o main 

install:
	cp libtest.so.1.0 /opt/lib/

clean:
	rm *so* *o *a main

