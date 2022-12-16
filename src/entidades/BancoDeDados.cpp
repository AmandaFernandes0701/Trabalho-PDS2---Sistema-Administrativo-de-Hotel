#include "BancoDeDados.hpp"

BancoDeDados::BancoDeDados(){}

// TODO: Verificar primeiro se o usuário já está cadastrado?
bool BancoDeDados::cadastrar_hospede(std::string nome, std::string email, std::string senha,
                    std::string cpf, std::string telefone){

    std::ofstream arquivo;
    arquivo.open(this->nome_arquivo_lista_de_hospedes, std::ios::app); // append
    arquivo<<nome<<","<<email<<","<<senha<<","<<
    cpf<<","<<telefone<<std::endl;
    arquivo.close();
    return true;
}

bool BancoDeDados::login(std::string email, std::string senha){
    std::ifstream arquivo;
    std::string linha, segmento;
    bool dados_corretos = false;

    arquivo.open(this->nome_arquivo_lista_de_hospedes, std::ios::in); // read
    // quebra a string por delimitador ','
    while(getline(arquivo, linha, ',')){
        if(linha == email){
            // Checar senha também
            std::cout<<"WOW"<<std::endl;
            getline(arquivo, linha, ',');
            if(linha == senha)
                dados_corretos = true;
            else
                dados_corretos = false;
            break;
        }
    }
    arquivo.close();

    return dados_corretos;
}
BancoDeDados::~BancoDeDados(){}
