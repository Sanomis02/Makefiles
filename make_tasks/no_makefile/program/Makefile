CC:=gcc
BIN:=main
SRC:=$(wildcard *.c)
CFLAGS:= -Wall
OBJS:=$(SRC:.c=.o)

.PHONY: all install uninstall clean

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^

install:
	install -d /usr/include
	install -m 644 maths.h /usr/include/maths.h
	install -m 644 usage.h /usr/include/usage.h

uninstall:
	$(RM) /usr/include/maths.h
	$(RM) /usr/include/usage.h

clean:
	$(RM) $(OBJS) $(BIN)
