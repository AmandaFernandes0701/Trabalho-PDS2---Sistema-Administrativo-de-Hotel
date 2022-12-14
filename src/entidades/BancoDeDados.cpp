#include "BancoDeDados.hpp"

BancoDeDados::BancoDeDados(){}

// TODO: Verificar primeiro se o usuário já está cadastrado?
bool BancoDeDados::cadastrar_hospede(string nome, string email, string senha,
                    string cpf, string telefone){
    // TODO: criar Exceção caso arquivo não seja encontrado
    ofstream arquivo;
    arquivo.open(nome_arquivo_lista_de_hospedes, ios::app); // append

    arquivo<<nome<<","<<email<<","<<senha<<","<<
    cpf<<","<<telefone<<endl;
    arquivo.close();
    return true;
}

BancoDeDados::~BancoDeDados(){}
