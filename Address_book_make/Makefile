.PHONY: all lib bin clean

all: lib bin

lib: 
	$(MAKE) -C ./lib

bin:
	$(MAKE) -C ./src
	
clean:
	$(MAKE) -C ./lib clean
	$(MAKE) -C ./src clean
