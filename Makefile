CC = g++
CFLAGS  = -g -Wall -std=c++11
INCLUDE_FLAGS = -I include/

# default: trabalho

Pessoa:	Pessoa.o
	$(CC) $(CFLAGS) -o Pessoa build/Pessoa.o

Pessoa.o:  src/entidades/Pessoa.cpp
	@mkdir -p build
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c src/entidades/Pessoa.cpp -o build/Pessoa.o

Hospede:  Hospede.o
	$(CC) $(CFLAGS) -o Hospede build/Hospede.o

Hospede.o:  src/entidades/Hospede.cpp
	@mkdir -p build
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c src/entidades/Hospede.cpp -o build/Hospede.o

# main: main.o Pessoa.o Hospede.o
# 	$(CC) $(CFLAGS) -o main build/main.o build/Pessoa.o build/Hospede.o

# main.o: src/main.cpp src/entidades/Pessoa.cpp src/entidades/Hospede.cpp
# 	@mkdir -p build
# 	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c src/main.cpp -o build/main.o

# trabalho: Pessoa.o Hospede.o main.o
# 	$(CC) $(CFLAGS) -o trabalho build/main.o build/Pessoa.o build/Hospede.o

clean:
	@rm -rf ./build trabalho
