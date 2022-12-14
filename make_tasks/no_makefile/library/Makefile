CC:=gcc
BIN:=main
CFLAGS:=-Wall
LIB:=libreader.so #Dinamine biblioteka
SRC:=$(wildcard *.c)
OBJS:=$(SRC:.c=.o)

PREFIX:=/usr

.PHONY: all install uninstall clean

all:$(BIN)

$(BIN): main.o $(LIB)
	$(CC) -L$(PWD) $(CFLAGS) $< -o $(BIN) -lreader #gcc -L<library_path> main.o -o main

main.o: main.c #Prerequisite: main.c failas, pakitus laikui, kompiliuojame faila bet jo nesulinkiname.
	$(CC) -c $^ #gcc -c main.c

$(LIB): file_reader.o
	$(CC) -shared -o $(LIB) $^ #gcc -shared -o libreader.so file_reader.o

file_reader.o: file_reader.c
	$(CC) -c $(CFLAGS) -fPIC $^ #gcc -c -Wall -fPIC file_reader.c | PIC position independent code, nepriklauso generuoto masininio kodo pozicija

install:
	install -d $(PREFIX)/lib #instaliuojame direktorijoje /usr/lib jei nera failo
	install -d $(PREFIX)/include #instaliuojame /usr/include jei nera failo
	install -m 644 $(LIB) $(PREFIX)/lib/$(LIB) #instaliuojame biblioteka ./usr/lib/libreader.so su octal-mode 644
	install -m 644 file_reader.h $(PREFIX)/include/file_reader.h #instaliuojame file_reader.h ./usr/include/file_reader.h , octal-mode 644

uninstall: #Pasaliname failus kuriuos instaliavome
	$(RM) $(LIB) $(PREFIX)/lib/$(LIB)
	$(RM) $(LIB) $(PREFIX)/include/file_reader.h

clean: #svara
	$(RM) $(OBJS) $(LIB) $(BIN)

