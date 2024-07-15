
default: waxc

wax.o: src/wax.c
	gcc -c src/wax.c

waxc: wax.o
	gcc -o waxc wax.o

clean:
	rm -f wax.o
	rm -f waxc
