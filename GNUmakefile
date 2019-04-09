PROFILE ?= release
SOURCES := $(wildcard src/*.c)
HEADERS := $(wildcard src/*.h)
INCLUDE := $(wildcard src/inc/*.inc) $(wildcard src/inc/ops/*.c)
CCFLAGS := -std=c99 -Wall -Wno-unused -Wno-multichar -D ten_LIBM
LINK    := -lm
CC      ?= gcc
PREFIX  ?= /usr/local/
LIBDIR ?= $(shell if [ -d $(PREFIX)/lib64 ]; then echo $(PREFIX)/lib64; else echo $(PREFIX)/lib; fi )
INCDIR ?= $(PREFIX)/include

ifeq ($(OS),Windows_NT)
    EXE := .exe
    DLL := .dll
    OBJ := .o
    LIB := .a
else
    EXE := 
    DLL := .so
    OBJ := .o
    LIB := .a
endif

ifeq ($(PROFILE),debug)
    CCFLAGS += -g -O0 -D ten_DEBUG
    POSTFIX := -debug
	POSTDLL := 
	POSTLIB := 
else
    ifeq ($(PROFILE),release)
        CCFLAGS += -O3 -D NDEBUG
        POSTFIX := 
        POSTDLL := strip -w -K "ten_*" libten.o
        POSTLIB := strip -w -K "ten_*" libten.o
    else
        $(error "Invalid build profile")
    endif
endif


.PHONY: build
build: libten$(POSTFIX)$(DLL) libten$(POSTFIX)$(LIB)

libten$(POSTFIX)$(DLL): $(HEADERS) $(INCLUDE) $(SOURCES)
	$(CC) $(CCFLAGS) -shared -fpic $(SOURCES) $(LINK) -o libten$(POSTFIX)$(DLL)
    ifeq ($(PROFILE),release)
	    strip -w -K "ten_*" libten$(POSTFIX)$(DLL)
    endif

libten$(POSTFIX)$(LIB): $(HEADERS) $(INCLUDE) $(SOURCES)
	$(CC) $(CCFLAGS) -c $(SOURCES) $(LINK)
	ld -r *.o -o libten.o
    ifeq ($(PROFILE),release)
	    strip -w -K "ten_*" libten.o
    endif
	ar rcs libten$(POSTFIX)$(LIB) libten.o
	rm *.o

tester$(EXE): $(HEADERS) $(INCLUDE) $(SOURCES) test/tester.c
	$(CC) $(CCFLAGS) -D ten_TEST -D TEST_PATH='"test/"' $(SOURCES) $(LINK) test/tester.c -o tester$(EXE)

.PHONY: install
install:
	mkdir -p $(LIBDIR)
	cp libten$(POSTFIX)$(DLL) libten$(POSTFIX)$(LIB) $(LIBDIR)
	mkdir -p $(INCDIR)
	cp src/ten.h $(INCDIR)


.PHONY: test
clean:
	- rm *$(DLL)
	- rm *$(LIB)
	- rm ten.h
	- rm *.o
	- rm tester
