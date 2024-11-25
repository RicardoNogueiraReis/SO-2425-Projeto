# Variáveis
CC = gcc
CFLAGS = -Wall -pthread
DEBUG_FLAGS = -g
SRC = main.c utils/parameters.c adts/esquina.c entities/cidadao.c entities/supermercado.c utils/data.c algoritmos/fscs.c

SRC_TESTE = main-teste.c utils/parameters.c adts/esquina.c entities/cidadao.c entities/supermercado.c utils/data.c algoritmos/fscs.c

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

# ============== +
# Teste de dados |
# ============== +
teste: clean
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC_TESTE)

teste-valgrind: clean
	clear
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -o $(TARGET) $(SRC_TESTE)
	valgrind --leak-check=full ./$(TARGET) $(ARGS)