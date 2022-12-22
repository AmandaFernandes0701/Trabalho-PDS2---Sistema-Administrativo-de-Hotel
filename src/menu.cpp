#include "BancoDeDados.hpp"
#include <iostream>

BancoDeDados banco_de_dados = BancoDeDados();

// variável útil para acessar o email do usuário logado
std::string EMAIL_LOGADO = "";


/**
 * @brief Menu para obter dados para o cadastro do hóspede no sistema
 * 
 * @return bool true se cadastro foi feito com sucesso
 * @return bool false se cadastro não foi realizado
 */
bool cadastrar_no_sistema(){
    std::string nome, email, senha, cpf, telefone;

    std::cin.ignore();
    std::cout<<"\n!!! Iniciando o sistema de cadastro do hospede !!!\n\n";

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

    bool retorno = banco_de_dados.cadastrar_hospede(nome, email, senha, cpf,
                                                    telefone);
    if(retorno == false){
        std::cout<<"\nCadastro nao realizado\n"<<std::endl;
        return false;
    }
    else{
        std::cout<<"\n\nCadastro realizado com sucesso\n";
        std::cout<<"\n!!! Agora o sistema sera encerrado !!!\n\n";

        return true;
    }
}


/**
 * @brief Menu responsável por tratar o login do hóspede
 * 
 * @return bool true se os dados de login estão corretos
 * @return bool false se os dados de login estão errados
 */
bool logar_hospede(){
    std::string email, senha;

    std::cout<<"Digite o seu email: ";
    std::cin>>email;
    std::cout<<"Digite a sua senha: ";
    std::cin>>senha;

    bool retorno = banco_de_dados.login_hospede(email, senha);
    if(retorno == false){
        std::cout<<"Falha no login\nVerifique se digitou ";
        std::cout<<"o email e senha corretamente."<<std::endl;
        return false;
    }else{
        std::cout<<std::endl<<"Login correto!"<<std::endl;
        std::cout<<"\n\n !!! Hospede logado no sistema !!!\n\n";
        EMAIL_LOGADO = email;
        return true;
    }

}


/**
 * @brief Menu responsável por tratar o login do funcionário
 * 
 * @return bool true se os dados de login estão corretos
 * @return bool false se os dados de login estão errados
 */
bool logar_funcionario(){
    std::string email, senha;

    std::cout<<"Digite o seu email: ";
    std::cin>>email;
    std::cout<<"Digite uma senha: ";
    std::cin>>senha;

    bool retorno = banco_de_dados.login_funcionario(email, senha);
    if(retorno == false){
        std::cout<<"Falha no login\nVerifique se digitou ";
        std::cout<<"o email e senha corretamente."<<std::endl;
        return false;
    }else{
        std::cout<<"Login correto"<<std::endl;
        std::cout<<"\n\n !!! Funcionario logado no sistema !!!\n\n";
        return true;
    }

}


/**
 * @brief Menu responsável por interagir e tratar das escolhas do
 * hóspede no sistema
 */
void funcoes_hospede(){
    int escolha;
    bool FLAG = true;

    while(FLAG == true){
        std::cout<<"Digite:"<<std::endl;
        std::cout<<"1 para reservar quarto"<<std::endl;
        std::cout<<"2 para cancelar reserva de quarto"<<std::endl;
        std::cout<<"3 para sair"<<std::endl;
        std::cout<<"Valor: ";

        std::cin>>escolha;

        if(escolha == 1){
            std::string data;
            int quarto;

            std::cout<<"Digite a data que queira realizar a reserva de ";
            std::cout<<"quarto do hotel no formato DD/MM/AAAA: ";

            std::cin>>data;
            std::cout<<"\nVerificando os quartos disponiveis nessa data...\n\n";

            try{
                banco_de_dados.verificar_quartos_livres(data);
            }catch(std::invalid_argument &erro){
                // Exceção capturada e tratada sem terminar o programa garante
                //  que qualquer dado na memória em tempo de execução poderá
                // ser salvo posteriormente nos arquivos .txt
                std::cout<<"A data digitada '"<< data <<
                "' esta no formato errado.\n";
                std::cout<<"Voce deve digitar a data seguindo o formato "<<
                "DD/MM/AAAA.\n";
                std::cout<<"Exemplo: 23/12/2022\n\n";
                continue;
            }

            std::cout<<"Escolha um dos quartos livres para reservar nessa data: ";
            std::cin>>quarto;

            banco_de_dados.reservar_quarto(data, quarto, EMAIL_LOGADO);

            std::cout<<"\nReserva realizada!"<<std::endl<<std::endl;

        }else if(escolha == 2){
            std::string data, quarto;
            int opcao;
            std::cout<<"Deseja verificar quais sao as suas reservas agendadas?\n";
            std::cout<<"Digite 1 para sim ou 0 para nao: ";
            std::cin>>opcao;

            if(opcao == 1){
                banco_de_dados.imprimir_reservas_do_hospede(EMAIL_LOGADO);
            }

            std::cout<<"\nDigite qual a data e o quarto que queira cancelar: ";
            std::cin>>data>>quarto;

            try{
                banco_de_dados.cancelar_reserva(data, quarto, EMAIL_LOGADO);
            }catch(std::invalid_argument &erro){
                // Exceção capturada e tratada sem terminar o programa garante
                //  que qualquer dado na memória em tempo de execução poderá
                // ser salvo posteriormente nos arquivos .txt
                std::cout<<"A data digitada '"<< data <<
                "' esta no formato errado.\n";
                std::cout<<"Voce deve digitar a data seguindo o formato "<<
                "DD/MM/AAAA.\n";
                std::cout<<"Exemplo: 23/12/2022\n\n";
                continue;
            }

        }
        else if(escolha == 3){
            FLAG = false;
            std::cout<<"\n\n !!! Usuario deslogado do sistema !!!\n\n";
        }

    }
}


/**
 * @brief Menu responsável por interagir e tratar das escolhas do
 * funcionário no sistema
 */
void funcoes_funcionario(){
    int escolha;
    bool FLAG = true;

    while(FLAG == true){
        std::cout<<"Digite:"<<std::endl;
        std::cout<<"1 para acessar reservas pela data"<<std::endl;
        std::cout<<"2 para verificar quartos livres pela data"<<std::endl;
        std::cout<<"3 para visualizar informacoes do hospede"<<std::endl;
        std::cout<<"4 para sair"<<std::endl;
        std::cout<<"Valor: ";
        std::cin>>escolha;

        switch (escolha)
        {
            case 1:{

                std::string data;

                std::cout<<"Digite a data que queira acessar as reservas no ";
                std::cout<<"formato DD/MM/AAAA: ";
                std::cin>>data;

                try{
                    banco_de_dados.acessar_reservas_pela_data(data);
                }catch(std::invalid_argument &erro){
                    // Exceção capturada e tratada sem terminar o programa garante
                    //  que qualquer dado na memória em tempo de execução poderá
                    // ser salvo posteriormente nos arquivos .txt
                    std::cout<<"A data digitada '"<< data <<
                    "' esta no formato errado.\n";
                    std::cout<<"Voce deve digitar a data seguindo o formato "<<
                    "DD/MM/AAAA.\n";
                    std::cout<<"Exemplo: 23/12/2022\n\n";
                    continue;
                }

                break;
            }
            case 2:{

                std::string data;

                std::cout<<"Digite a data que queira verificar os quartos ";
                std::cout<<"livres no formato DD/MM/AAAA: ";
                std::cin>>data;

                try{
                    banco_de_dados.verificar_quartos_livres(data);
                }catch(std::invalid_argument &erro){
                    // Exceção capturada e tratada sem terminar o programa garante
                    //  que qualquer dado na memória em tempo de execução poderá
                    // ser salvo posteriormente nos arquivos .txt
                    std::cout<<"A data digitada '"<< data <<
                    "' esta no formato errado.\n";
                    std::cout<<"Voce deve digitar a data seguindo o formato "<<
                    "DD/MM/AAAA.\n";
                    std::cout<<"Exemplo: 23/12/2022\n\n";
                    continue;
                }

                break;
            }
            case 3:{

                std::string nome;

                std::cout<<"Digite o nome do hospede que queira verificar as informacoes."<<std::endl;
                std::cout<<"OBS: O nome tem que estar escrito de forma exata: ";
                std::cin.ignore();
                std::getline(std::cin, nome);
                std::cout<<std::endl;

                banco_de_dados.acessar_informacoes_hospedes(nome);

                break;
            }
            case 4:{
                FLAG = false;
                std::cout<<"\n\n !!! Usuario deslogado do sistema !!!\n\n";
                break;
            }
            default:
                std::cout<<"Valor '"<<escolha<<"' digitado errado"<<std::endl;
                std::cout<<"Por favor, digite corretamente um dos valores "<<
                "apresentados"<<std::endl<<std::endl;
                break;
        }
    }

}
