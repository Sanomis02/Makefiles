.PHONY: all library program install uninstall clean

all: library program

library:
	$(MAKE) -C ./library #make library viduje no_makefile/library direktorijoje, -C flag deka
program:
	$(MAKE) -C ./program

install:
	$(MAKE) -C ./library install
	$(MAKE) -C ./program install

uninstall:
	$(MAKE) -C ./library uninstall
	$(MAKE) -C ./program uninstall

clean:
	$(MAKE) -C ./library clean
	$(MAKE) -C ./program clean
