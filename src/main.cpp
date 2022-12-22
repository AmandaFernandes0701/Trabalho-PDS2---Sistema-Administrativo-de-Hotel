#include "BancoDeDados.hpp"
#include <iostream>


int main()
{
    BancoDeDados banco_de_dados = BancoDeDados();
    int escolha;
    bool FLAG = true;

    while(FLAG == true){
        std::cout<<"Digite:"<<std::endl;
        std::cout<<"1 para cadastrar hospede"<<std::endl;
        std::cout<<"2 para logar hospede"<<std::endl;
        std::cout<<"3 para logar funcionario"<<std::endl;
        std::cout<<"4 para reservar quarto"<<std::endl;
        std::cout<<"5 para funcionario acessar reservas pela data"<<std::endl;
        std::cout<<"6 para funcionario verificar quartos livres pela data"<<std::endl;
        std::cout<<"7 para funcionario visualizar informacoes do hospede"<<std::endl;
        std::cout<<"8 para sair"<<std::endl;
        std::cin>>escolha;

        switch (escolha)
        {
            case 1:{
                std::string nome, email, senha, cpf, telefone;

                std::cin.ignore(); // https://pt.stackoverflow.com/a/319643
                std::cout<<"Digite o seu nome: ";
                std::getline(std::cin, nome);
                std::cout<<"Digite o seu email: ";
                std::cin>>email;
                std::cout<<"Digite uma senha: ";
                std::cin>>senha;
                std::cout<<"Digite o seu CPF: ";
                std::cin>>cpf;
                std::cout<<"Digite o seu telefone: ";
                std::cin>>telefone;

                // TODO: Verificar se dados foram preenchidos corretamente
                bool retorno = banco_de_dados.cadastrar_hospede(nome, email, senha, cpf, telefone);
                if(retorno == false)
                    std::cout<<"Cadastro nao realizado"<<std::endl;
                else
                    std::cout<<"Cadastro realizado com sucesso"<<std::endl;

                break;
            }
            case 2:{

                std::string email, senha;

                std::cout<<"Digite o seu email: ";
                std::cin>>email;
                std::cout<<"Digite a sua senha: ";
                std::cin>>senha;

                bool retorno = banco_de_dados.login_hospede(email, senha);
                if(retorno == false){
                    std::cout<<"Falha no login\nVerifique se digitou ";
                    std::cout<<"o email e senha corretamente."<<std::endl;
                }else
                    std::cout<<"Login correto"<<std::endl;

                break;
            }
            case 3:{

                std::string email, senha;

                std::cout<<"Digite o seu email: ";
                std::cin>>email;
                std::cout<<"Digite uma senha: ";
                std::cin>>senha;

                bool retorno = banco_de_dados.login_funcionario(email, senha);
                if(retorno == false){
                    std::cout<<"Falha no login\nVerifique se digitou ";
                    std::cout<<"o email e senha corretamente."<<std::endl;
                }else
                    std::cout<<"Login correto"<<std::endl;

                break;
            }
            case 4:{

                // std::string data;
                // std::cout<<"Digite a data (DD/MM/YYYY) para ver os quartos disponíveis: ";
                // std::cin>>data;
                // std::cout<<"Verificando os quartos disponíveis nessa data..."<<std::endl;
                // std::vector<std::string> quartos = hospede->verificar_quartos_disponiveis(&banco_de_dados, data);
                // if(quartos.size() == 0){
                //     std::cout<<"Não há quartos livres nessa data"<<std::endl;
                // }else{
                //     // Imprima os quartos disponíveis
                //     // Pergunte ao usuário qual quarto ele quer
                //     reservar_quarto(numero_quarto, data);
                // }

                break;
            }
            case 5:{

                std::string data;

                std::cout<<"Digite a data que queira acessar as reservas no ";
                std::cout<<"formato DD/MM/AAAA: ";
                std::cin>>data;

                banco_de_dados.acessar_reservas_pela_data(data);

                break;
            }
            case 6:{

                std::string data;

                std::cout<<"Digite a data que queira verificar os quartos ";
                std::cout<<"livres no formato DD/MM/AAAA: ";
                std::cin>>data;

                banco_de_dados.verificar_quartos_livres(data);

                break;
            }
            case 7:{

                std::string nome;

                std::cout<<"Digite o nome do hospede que queira verificar as informacoes."<<std::endl;
                std::cout<<"OBS: O nome tem que estar escrito de forma exata: ";
                std::cin.ignore();
                std::getline(std::cin, nome);

                banco_de_dados.acessar_informacoes_hospedes(nome);

                break;
            }
            case 8:{
                FLAG = false;
                break;
            }
            default:
                break;
        }
    }

    return 0;
}
