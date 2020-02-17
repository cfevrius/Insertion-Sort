CC=gcc
CFLAGS=-Wall -ansi

TARGET=insertion_sort

$(TARGET): main.c list.o node.o
	@echo Linking $@...
	@$(CC) $(CFLAGS) -o $@ $^

list.o: list.c list.h
	@echo Compiling $@...
	@$(CC) $(CFLAGS) -c $< 

node.o: node.c node.h
	@echo Compiling $@...
	@$(CC) $(CFLAGS) -c $< 	

clean:
	@echo cleaning up...
	@rm list.o
	@rm node.o
	@rm insertion_sort

