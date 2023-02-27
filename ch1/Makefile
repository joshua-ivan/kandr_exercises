kandr-01-11:
	gcc -Wall -c 11.c

kandr-01-11-test: kandr-01-11
	gcc -Wall -c 11-test.c
	gcc -o 11-test 11.o 11-test.o

kandr-01-11-main: kandr-01-11
	gcc -Wall -c 11-main.c
	gcc -o 11-main 11.o 11-main.o

kandr-01-13:
	gcc -Wall -c 13.c

kandr-01-13-test: kandr-01-13
	gcc -Wall -c 13-test.c
	gcc -o 13-test 13.o 13-test.o

kandr-01-13-main: kandr-01-13
	gcc -Wall -c 13-main.c
	gcc -o 13-main 13.o 13-main.o

kandr-01-14:
	gcc -Wall -c 14.c

kandr-01-14-test: kandr-01-14
	gcc -Wall -c 14-test.c
	gcc -o 14-test 14.o 14-test.o

kandr-01-14-main: kandr-01-14
	gcc -Wall -c 14-main.c
	gcc -o 14-main 14.o 14-main.o

kandr-01-16:
	gcc -Wall -c 16.c

kandr-01-16-test: kandr-01-16
	gcc -Wall -c 16-test.c
	gcc -o 16-test 16.o 16-test.o
	./16-test

kandr-01-16-main: kandr-01-16
	gcc -Wall -c 16-main.c
	gcc -o 16-main 16.o 16-main.o

clean:
	rm -f ./*.o
	rm -f *-test
	rm -f *-main

