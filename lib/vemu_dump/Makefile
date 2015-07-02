all: lib 

lib: 
	arm-none-linux-gnueabi-gcc -Wall -c vemulib.c 
	arm-none-linux-gnueabi-ar -cvq vemulib.a vemulib.o 
so:
	arm-none-linux-gnueabi-gcc -Wall -fPIC -c vemulib.c 
	arm-none-linux-gnueabi-gcc -shared -Wl,-soname,libvemu.so.1 -o libvemu.so.1.0 vemulib.o


clean:
	rm *so* *o *a 

