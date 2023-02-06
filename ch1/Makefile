kandr-01-11:
	gcc -Wall -c 11.c

kandr-01-11-test: kandr-01-11
	gcc -Wall -c 11-test.c
	gcc -o 11-test 11.o 11-test.o

kandr-01-11-main: kandr-01-11
	gcc -Wall -c 11-main.c
	gcc -o 11-main 11.o 11-main.o

clean:
	rm -f ./*.o
	rm -f 11-test
	rm -f 11-main

