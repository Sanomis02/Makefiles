CC:=gcc #nurodomas kompiliatorius
CPPFLAGS:=-I$(PWD) #kompiliatoriaus parametrai
SRC:=$(wildcard *.c) #Nurodome saltini, c failai
OBJS:=$(SRC:.c=.o) #Paims object failus is c failu
BIN:=calculator #binary failas

.PHONY: all clean install uninstall

all: $(BIN)

$(BIN): $(OBJS) #Sukompiliuosime pakeistus c failus 
	#$(CC) $(CFLAGS) $(OBJS) -o $@
	$(CC) $^ -o $@
install:
	#install -d /usr/bin
	install -d /usr/bin
	install -m 644 $(BIN) /usr/bin/$(BIN)
	
uninstall:
	$(RM) /usr/bin/$(BIN)

clean: #Po to istriname objekto failus ir BIN
	rm -f $(BIN) $(OBJS)
	
