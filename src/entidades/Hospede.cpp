#include "Hospede.hpp"

bool Hospede::login(string email, string senha){
    if(this->email != email || this->senha != senha)
        return false;

    return true;
}

/*
    OBS: "Conecta" no banco de dados do hotel e realiza o cadastro
*/
bool cadastrar(string email, string senha){

}
