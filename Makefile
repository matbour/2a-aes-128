CC=gcc
CFLAGS=

AES128: init utils.o expandKey.o addRoundKey.o subBytes.o shiftRows.o mixColumns.o aes.o main.o
	mkdir -p build
	gcc -o build/AES128 \
		objects/main.o \
		objects/aes.o \
		objects/utils.o \
		objects/expandKey.o \
		objects/addRoundKey.o \
		objects/subBytes.o \
		objects/shiftRows.o \
		objects/mixColumns.o $(CFLAGS)
clean:
	rm objects/*.o AES128

init:
	mkdir -p objects
utils.o: init
	gcc -o objects/utils.o -c src/utils.c $(CFLAGS)
expandKey.o: init
	gcc -o objects/expandKey.o -c src/expandKey.c $(CFLAGS)
addRoundKey.o: init
	gcc -o objects/addRoundKey.o -c src/addRoundKey.c $(CFLAGS)
subBytes.o: init
	gcc -o objects/subBytes.o -c src/subBytes.c $(CFLAGS)
shiftRows.o: init
	gcc -o objects/shiftRows.o -c src/shiftRows.c $(CFLAGS)
mixColumns.o: init
	gcc -o objects/mixColumns.o -c src/mixColumns.c $(CFLAGS)
aes.o: init
	gcc -o objects/aes.o -c src/aes.c $(CFLAGS)
main.o: init
	gcc -o objects/main.o -c src/main.c $(CFLAGS)