CC:=gcc
CFLAGS:=-Wall
LIB:=libcalculator.so
SRC:=$(wildcard *.c)
OBJS:=$(SRC:.c=.o)

PREFIX:=/usr

.PHONY: all clean install uninstall

all: $(LIB)

$(LIB): $(OBJS)
	$(CC) $(CFLAGS) -shared -fPIC -o $(LIB) $^ $(LDFLAGS)

install: $(LIB)
	install -d $(PREFIX)/lib
	install -d $(PREFIX)/include
	install -m 644 math_functions.h $(PREFIX)/include/math_functions.h
	install -m 644 $(LIB) $(PREFIX)/lib/$(LIB)

uninstall:
	$(RM) $(PREFIX)/include/math_functions.h
	$(RM) $(PREFIX)/lib/$(LIB)

clean:
	$(RM) $(LIB) $(OBJS)
