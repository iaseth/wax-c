
default: waxc

redo: clean default

wax.o: src/wax.c
	gcc -c src/wax.c -Iinclude

waxc: wax.o
	gcc -o waxc wax.o

clean:
	rm -f wax.o
	rm -f waxc
