CC = g++
CFLAGS  = -Wall -std=c++11
INCLUDE_FLAGS = -I include/

default: trabalho

pessoa:	pessoa.o
	$(CC) $(CFLAGS) -o pessoa build/pessoa.o

pessoa.o:  src/entidades/Pessoa.cpp
	@mkdir -p build
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c src/entidades/Pessoa.cpp -o build/pessoa.o

hospede:  hospede.o
	$(CC) $(CFLAGS) -o hospede build/hospede.o

hospede.o:  src/entidades/Hospede.cpp
	@mkdir -p build
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c src/entidades/Hospede.cpp -o build/hospede.o

funcionario:  funcionario.o
	$(CC) $(CFLAGS) -o funcionario build/funcionario.o

funcionario.o:  src/entidades/Funcionario.cpp
	@mkdir -p build
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c src/entidades/Funcionario.cpp -o build/funcionario.o

data: data.o
	$(CC) $(CFLAGS) -o data build/data.o

data.o: src/entidades/Data.cpp
	@mkdir -p build
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c src/entidades/Data.cpp -o build/data.o

quarto: quarto.o
	$(CC) $(CFLAGS) -o quarto build/quarto.o

quarto.o: src/entidades/Quarto.cpp
	@mkdir -p build
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c src/entidades/Quarto.cpp -o build/quarto.o

reserva: reserva.o
	$(CC) $(CFLAGS) -o reserva build/reserva.o

reserva.o: src/entidades/Reserva.cpp
	@mkdir -p build
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c src/entidades/Reserva.cpp -o build/reserva.o

banco: banco.o
	$(CC) $(CFLAGS) -o banco build/banco.o

banco.o: src/entidades/BancoDeDados.cpp
	@mkdir -p build
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c src/entidades/BancoDeDados.cpp -o build/banco.o

main: main.o
	$(CC) $(CFLAGS) -o main build/main.o

main.o: src/main.cpp
	@mkdir -p build
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c src/main.cpp -o build/main.o

trabalho: pessoa.o hospede.o funcionario.o banco.o data.o quarto.o reserva.o main.o
	$(CC) $(CFLAGS) -o trabalho build/main.o build/pessoa.o build/hospede.o build/funcionario.o build/banco.o build/data.o build/quarto.o build/reserva.o

clean:
	@rm -rf ./build trabalho
