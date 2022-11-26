#include "funcionario.hpp"
#include "user.hpp"
#include <map>

int main()
{
    Funcionario funci;
    User user;
    std::string nome_d = "Gabriel Luiz de Almeida";
    std::string email_d = "gabrielexenplo@gmail.com";
    std::string senha_d = "251017mg";
    std::string CPF_d = "202.483.127-31";
    std::string telefone_d = "31 97136-4334";
    unsigned int chave_d = 75752650;
    // std::getline(std::cin, nome_d);
    // std::cin >> email_d >> senha_d >> CPF_d >> telefone_d;
    funci = Funcionario(nome_d, email_d, senha_d, CPF_d, telefone_d, chave_d);
    user = User(nome_d, email_d, senha_d, CPF_d, telefone_d);


    std::cout << "Nome: " << user.getNome() << std::endl;
    std::cout << "Email: " << user.getEmail() << std::endl;
    std::cout << "senha: " << user.getSenha() << std::endl;
    std::cout << "CPF: " << user.getCPF() << std::endl;
    std::cout << "Telefone: " << user.getTelefone() << std::endl;
    std::cout << "\n"
              << std::endl;
    std::cout << "Nome: " << funci.getNome() << std::endl;
    std::cout << "Email: " << funci.getEmail() << std::endl;
    std::cout << "senha: " << funci.getSenha() << std::endl;
    std::cout << "CPF: " << funci.getCPF() << std::endl;
    std::cout << "Telefone: " << funci.getTelefone() << std::endl;
    std::cout << "Chave: " << funci.getChave() << std::endl;
}