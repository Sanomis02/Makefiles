CC:=gcc
CFLAGS:=-Wall
LIB:=liblist.so
SRC:=$(wildcard *.c)
OBJS:=$(SRC:.c=.o)

.PHONY: all clean install uninstall

PREFIX:=/usr

all: $(LIB)

$(LIB): $(OBJS)
	$(CC) $(CFLAGS) -shared -fPIC -o $(LIB) $^ $(LDFLAGS)

install: $(LIB)
	install -d $(PREFIX)/lib
	install -d $(PREFIX)/include
	install -m 644 list.h $(PREFIX)/include/list.h
	install -m 644 $(LIB) $(PREFIX)/lib/$(LIB)

uninstall:
	$(RM) $(PREFIX)/include/list.h
	$(RM) $(PREFIX)/lib/$(LIB)

clean:
	$(RM) $(LIB) $(OBJS)
