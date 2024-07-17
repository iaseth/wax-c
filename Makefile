
default: waxc

redo: clean default

wax.o: src/*.c
	gcc -c src/*.c -Iinclude

waxc: wax.o
	gcc -o waxc *.o

clean:
	rm -f *.o
	rm -f waxc
