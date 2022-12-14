.PHONY: all library program install uninstall clean

all: library program

library:
	$(MAKE) -C ./library

program: 
	$(MAKE) -C ./program

install: $(MAKE) -C ./library install
install: $(MAKE) -C ./program install

uninstall: 
	$(MAKE) -C ./library uninstall
	$(MAKE) -C ./program uninstall

clean: 
	$(MAKE) -C ./library clean
	$(MAKE) -C ./program clean
