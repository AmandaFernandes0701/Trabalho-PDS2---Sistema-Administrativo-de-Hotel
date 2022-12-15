#include "Hospede.hpp"

bool Hospede::login(string email, string senha){
    // TODO
    // Conecta ao banco de dados e verifica login
}

bool Hospede::cadastrar(BancoDeDados* banco_de_dados){
    // TODO: Ler nome completo sem erro
    // TODO: Verificar se dados foram preenchidos corretamente
    string nome, email, senha, cpf, telefone;
    cout<<"Digite todos os dados de cadastro"<<endl;
    cin>>nome; // não le espaço
    cin>>email;
    cin>>senha;
    cin>>cpf;
    cin>>telefone;

    bool retorno = banco_de_dados->cadastrar_hospede(nome, email,
                    senha, cpf, telefone);
    if(retorno == true)
        cout<<"Cadastro realizado com sucesso"<<endl;
    else
        cout<<"Cadastro não realizado"<<endl;
    return false;
}
