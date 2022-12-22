# Instruções gerais sobre o sistema
## Sistema de Hotel
### Esse sistema tem o objetivo de gerenciar um sistema de reservas em um hotel.
### O sistema permite algumas utilidades, como:
- Hóspedes podem agendar ou cancelar uma reserva
- Funcionários podem verificar as reservas em uma determinada data, verificar os quartos livres em outra data ou verificar as informações de um determinado hóspede


## Para compilar o programa e os testes
- Na pasta raiz do programa, digite o comando `make` no terminal para compilar todo o código implementado, o que inclui também os testes unitários
## Para executar o programa
- Na pasta raiz do programa, onde o executável de nome `trabalho` foi gerado, digite `./trabalho` no terminal para executar o programa
## Para executar os testes
- Na pasta raiz do programa, onde o executável de nome `testar` foi gerado, digite `./testar` no terminal para executar os todos os testes unitários e visualizar o resultado

## Para gerar o Doxygen do programa
- Depois de instalar o Doxygen.
    - Para Windows, você pode usar esse [link](https://www.doxygen.nl/files/doxygen-1.9.5-setup.exe)
- Na pasta raiz do programa, gere o doxygen usando o arquivo de configuração `Doxyfile`, com o seguinte comando: `doxygen Doxyfile`.
- Vai ser criado uma pasta com nome **html**.
- Dentro da pasta **html**, o arquivo `index.html` precisa ser aberto para que se possa navegar na documentação gerada da implementação de todo o sistema.
