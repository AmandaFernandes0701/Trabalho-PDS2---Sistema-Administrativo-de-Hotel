#include "BancoDeDados.hpp"
#include <sstream>

BancoDeDados::BancoDeDados(){
    this->carregar_dados_hospedes();
    this->carregar_dados_quartos();
    this->carregar_dados_reservas();
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

void BancoDeDados::carregar_dados_reservas(){
    std::ifstream arquivo;
    std::string linha;
    std::string temp, dia, mes, ano, quarto, email;

    arquivo.open(this->nome_arquivo_lista_de_reservas, std::ios::in); // read

    while(getline(arquivo, linha)){

        std::stringstream X(linha);
        Data *data = new Data();

        // quebra a string por delimitador '/'
        getline(X, dia, '/');
        data->set_dia(std::stoi(dia));
        getline(X, mes, '/');
        data->set_mes(std::stoi(mes));
        getline(X, ano, ',');
        data->set_ano(std::stoi(ano));

        getline(X, quarto, ',');
        getline(X, email);
        // std::cout<<data->get_dia()<<"|"<<data->get_mes()<<"|"<<data->get_ano()<<"|"<<quarto<<"|"<<email<<std::endl;

        // Encontrar o hóspede que reservou esse quarto
        Hospede* auxiliar = NULL;
        for(std::vector<Hospede*>::iterator it = this->hospedes.begin(); it != this->hospedes.end(); it++){
            if( (*it)->get_email() == email ){
                auxiliar = *it;
                break;
            }
        }

        // TODO
        // Lançar exceção caso hóspede não esteja cadastrado no sistema

        Reserva *reserva = new Reserva(data, std::stoi(quarto), auxiliar);
        this->reservas.push_back(reserva);
    }

    arquivo.close();
}

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

    for(std::vector<Hospede*>::iterator it = this->hospedes.begin(); it != this->hospedes.end(); it++){
        arquivo<<(*it)->get_nome()<<","<<(*it)->get_email()<<","<<(*it)->get_senha()<<","<<(*it)->get_cpf()<<","<<(*it)->get_telefone()<<std::endl;
    }
    arquivo.close();
}

void BancoDeDados::salvar_dados_reservas(){
    std::ofstream arquivo;
    arquivo.open(this->nome_arquivo_lista_de_reservas, std::ios::out); // write

    for(std::vector<Reserva*>::iterator it = this->reservas.begin(); it != this->reservas.end(); it++){
        arquivo<<(*it)->get_dia()<<"/"<<(*it)->get_mes()<<"/"<<(*it)->get_ano()<<","<<(*it)->get_quarto()<<","<<(*it)->get_email()<<std::endl;
    }
    arquivo.close();
}

BancoDeDados::~BancoDeDados(){
    this->salvar_dados_hospedes();
    this->salvar_dados_reservas();
}
