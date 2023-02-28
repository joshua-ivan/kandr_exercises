base:
	gcc -Wall -c $(ex).c

test: base
	gcc -Wall -c $(ex)-test.c
	gcc -o $(ex)-test $(ex).o $(ex)-test.o
	./$(ex)-test

main: base
	gcc -Wall -c $(ex)-main.c
	gcc -o $(ex)-main $(ex).o $(ex)-main.o

clean:
	rm -f ./*.o
	rm -f *-test
	rm -f *-main

