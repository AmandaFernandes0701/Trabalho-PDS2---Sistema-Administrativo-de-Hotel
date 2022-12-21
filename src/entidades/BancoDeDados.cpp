#include "BancoDeDados.hpp"
#include <sstream>

BancoDeDados::BancoDeDados(){
    this->carregar_dados_hospedes();
    this->carregar_dados_quartos();

    // TODO:
    // Inicializar com os dados já salvos nos .txt
    // this->carregar_dados_reservas();
}

void BancoDeDados::carregar_dados_hospedes(){
    std::ifstream arquivo;
    std::string linha;
    std::string nome, email, senha, cpf, telefone;

    arquivo.open(this->nome_arquivo_lista_de_hospedes, std::ios::in); // read

    while(getline(arquivo, linha)){

        // quebra a string por delimitador ','
        std::stringstream X(linha);
        getline(X, nome, ',');
        getline(X, email, ',');
        getline(X, senha, ',');
        getline(X, cpf, ',');
        getline(X, telefone, ',');
        // std::cout<<nome<<"|"<<email<<"|"<<senha<<"|"<<cpf<<"|"<<telefone<<std::endl;
        Hospede *hospede = new Hospede(nome, email, senha, cpf, telefone);
        this->hospedes.push_back(hospede);
    }

    arquivo.close();
}

void BancoDeDados::carregar_dados_quartos(){
    std::ifstream arquivo;
    std::string numero_de_quarto;

    arquivo.open(this->nome_arquivo_lista_de_quartos, std::ios::in); // read

    while(getline(arquivo, numero_de_quarto)){
        // std::cout<<numero_de_quarto<<"|"<<std::stoi(numero_de_quarto)<<std::endl;
        Quarto *quarto = new Quarto( std::stoi(numero_de_quarto) );
        this->quartos.push_back(quarto);
    }

    arquivo.close();
}

// void BancoDeDado::carregar_dados_reservas(){}

bool BancoDeDados::cadastrar_hospede(std::string nome, std::string email, std::string senha,
				std::string cpf, std::string telefone){

    // TODO: Verificar primeiro se o usuário já está cadastrado?
    Hospede *hospede = new Hospede(nome, email, senha, cpf, telefone);
    this->hospedes.push_back(hospede);

    return true;
}

bool BancoDeDados::login_hospede(std::string email, std::string senha){
    bool dados_corretos = false;

    for(std::vector<Hospede*>::iterator it = hospedes.begin(); it != hospedes.end(); it++){
        if( (*it)->verificar_email(email) == true){
            if( (*it)->verificar_senha(senha) == true)
                dados_corretos = true;
            break;
        }
    }

    return dados_corretos;
}

bool BancoDeDados::login_funcionario(std::string email, std::string senha){
    bool dados_corretos = false;
    Funcionario *funcionario = new Funcionario();

    if(funcionario->verificar_email(email))
        if(funcionario->verificar_senha(senha))
            dados_corretos = true;

    return dados_corretos;
}

void BancoDeDados::salvar_dados_hospedes(){
    std::ofstream arquivo;
    arquivo.open(this->nome_arquivo_lista_de_hospedes, std::ios::out); // write

    for(std::vector<Hospede*>::iterator it = hospedes.begin(); it != hospedes.end(); it++){
        arquivo<<(*it)->get_nome()<<","<<(*it)->get_email()<<","<<(*it)->get_senha()<<","<<(*it)->get_cpf()<<","<<(*it)->get_telefone()<<std::endl;
    }
    arquivo.close();
}

BancoDeDados::~BancoDeDados(){
    this->salvar_dados_hospedes();
}
