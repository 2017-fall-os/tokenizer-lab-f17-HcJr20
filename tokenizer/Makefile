all: test

CFLAGS = -g -O2

test: test.o tokenizer.o
	cc -o test test.o tokenizer.o 
clean:
	rm -f  *.o test test.exe
demo: test
	./test
