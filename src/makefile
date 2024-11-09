default:
	clear
	gcc -Wall -o prog main.c -pthread
go:
	gcc -Wall -o prog main.c -pthread
	./prog
run:
	clear
	./prog
debug:
	clear
	gcc -Wall -o prog -g main.c -lm -pthread
valgrind:
	clear
	gcc -Wall -o prog -g main.c -lm
	valgrind --leak-check=full ./prog
clean:
	rm -f prog
