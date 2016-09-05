encrypt: encrypt.o shift.o
	gcc -o encrypt encrypt.o shift.o

decrypt: decrypt.o shift.o
	gcc -o decrypt decrypt.o shift.o

encrypt.o: encrypt.c
	gcc -c -std=c99 encrypt.c

decrypt.o: decrypt.c
	gcc -c -std=c99 decrypt.c

shift.o: shift.c shift.h
	gcc -c shift.c

clean:
	rm *.o encrypt decrypt
