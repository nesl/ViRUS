all: main

main:
	arm-none-linux-gnueabi-gcc -O3 -static -Wl,--whole-archive varmathlib.a vemulib.a -lm -Wl,--no-whole-archive  whetstone.c -o whetstone-arm 

clean:
	rm whetstone whetstone-arm

