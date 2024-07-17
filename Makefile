
default: waxc

redo: clean default

wax.o: src/wax.c
	gcc -c src/wax.c src/wax_common.c src/wax_header.c -Iinclude

waxc: wax.o
	gcc -o waxc wax_common.o wax_header.o wax.o

clean:
	rm -f wax.o
	rm -f waxc
