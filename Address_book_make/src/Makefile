CC:=gcc #nurodomas kompiliatorius
CPPFLAGS:=/usr/include
SRC:=$(wildcard *.c) #Nurodome saltini, c failai
OBJS:=$(SRC:.c=.o) #Paims object failus is c failu
BIN:=main #binary failas
LIB:= -L/usr/lib -llist

.PHONY: all clean

all: $(BIN)

$(BIN): $(OBJS) #Sukompiliuosime pakeistus c failus 
	#$(CC) $(CFLAGS) $(OBJS) -o $@
	$(CC) $^ $(LIB) -o $@

clean: #Po to istriname objekto failus ir BIN
	$(RM) -f $(BIN) $(OBJS)	
