# Variáveis
CC = gcc
CFLAGS = -Wall -pthread
DEBUG_FLAGS = -g
SRC = main.c utils/Parameters.c adts/Vertex.c Entities/Cidadao.c Entities/supermercado.c utils/data.c

TARGET = prog

# Targets
default: clean
	clear
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# make go ARGS="instances_2.txt 2 1000"
go: default
	./$(TARGET) $(ARGS)

run: default
	clear
	./$(TARGET)

debug: clean
	clear
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -o $(TARGET) $(SRC)

valgrind: debug
	valgrind --leak-check=full ./$(TARGET) $(ARGS)

clean:
	rm -f $(TARGET)
	clear
