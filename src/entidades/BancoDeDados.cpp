#include "BancoDeDados.hpp"
#include <sstream>

BancoDeDados::BancoDeDados(){
    try{
        this->carregar_dados_hospedes();
        this->carregar_dados_quartos();
        this->carregar_dados_reservas();
    }catch (std::exception &erro) {
        std::cout << "Arquivo '" << erro.what() << "' nao encontrado.\n";
        std::cout << "Verifique se o arquivo nao esta salvo em outra pasta.\n";
        std::cout << "Esse arquivo e necessario para o correto funcionamento ";
        std::cout << "do sistema\n";
    }
}

void BancoDeDados::carregar_dados_hospedes(){
    std::ifstream arquivo;
    std::string linha;
    std::string nome, email, senha, cpf, telefone;

    arquivo.open(this->nome_arquivo_lista_de_hospedes, std::ios::in); // read

    if(arquivo.is_open() == false){
        throw std::runtime_error(this->nome_arquivo_lista_de_hospedes);
    }

    while(getline(arquivo, linha)){

        // quebra a string por delimitador ','
        std::stringstream X(linha);
        getline(X, nome, ',');
        getline(X, email, ',');
        getline(X, senha, ',');
        getline(X, cpf, ',');
        getline(X, telefone, ',');

        Hospede *hospede = new Hospede(nome, email, senha, cpf, telefone);
        this->hospedes.push_back(hospede);
    }

    arquivo.close();
}

void BancoDeDados::carregar_dados_quartos(){
    std::ifstream arquivo;
    std::string numero_de_quarto;

    arquivo.open(this->nome_arquivo_lista_de_quartos, std::ios::in); // read

    if(arquivo.is_open() == false){
        throw std::runtime_error(this->nome_arquivo_lista_de_quartos);
    }

    while(getline(arquivo, numero_de_quarto)){
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

    if(arquivo.is_open() == false){
        throw std::runtime_error(this->nome_arquivo_lista_de_reservas);
    }

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

        // Encontrar o hóspede que reservou esse quarto
        Hospede* auxiliar = NULL;
        for(std::vector<Hospede*>::iterator it = this->hospedes.begin(); it != this->hospedes.end(); it++){
            if( (*it)->get_email() == email ){
                auxiliar = *it;
                break;
            }
        }

        Reserva *reserva = new Reserva(data, std::stoi(quarto), auxiliar);
        this->reservas.push_back(reserva);
    }

    arquivo.close();
}

bool BancoDeDados::cadastrar_hospede(std::string nome, std::string email, std::string senha,
				std::string cpf, std::string telefone){

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

void BancoDeDados::reservar_quarto(std::string data, int quarto, std::string email){
    Data data_auxiliar = converter_string_para_data(data);

    // Aloca data dinamicamente para ser incluida na Reserva
    Data* data_para_reservar = new Data();
    data_para_reservar->set_dia(data_auxiliar.get_dia());
    data_para_reservar->set_mes(data_auxiliar.get_mes());
    data_para_reservar->set_ano(data_auxiliar.get_ano());

    Quarto quarto_para_reservar = Quarto(quarto);
    Hospede* hospede = NULL;

    // Encontra o hospede para pegar o "endereço dele"
    for(std::vector<Hospede*>::iterator it = hospedes.begin(); it != hospedes.end(); it++)
        if( (*it)->verificar_email(email) == true){
            hospede = *it;
            break;
        }

    Reserva* nova_reserva = new Reserva(data_para_reservar,
                                quarto_para_reservar, hospede);
    this->reservas.push_back(nova_reserva);
}

void BancoDeDados::imprimir_reservas_do_hospede(std::string email){
    // Imprime a data e o quarto em que o hóspede tem reserva no hotel
    bool tem_reserva = false;
    for(std::vector<Reserva*>::iterator it = this->reservas.begin(); it != this->reservas.end(); it++){
        if((*it)->get_email() == email){
            std::cout<<"Data: "<<(*it)->get_dia()<<"/"<<(*it)->get_mes()<<"/"<<
            (*it)->get_ano()<<", Quarto: "<<(*it)->get_quarto()<<std::endl;
            tem_reserva = true;
        }
    }

    if(tem_reserva == false)
        std::cout<<"Voce nao tem reservas agendadas"<<std::endl;
}

void BancoDeDados::cancelar_reserva(std::string data, std::string quarto, std::string email){
    Data data_auxiliar = converter_string_para_data(data);
    bool tem_reserva = false;

    for(std::vector<Reserva*>::iterator it = this->reservas.begin(); it != this->reservas.end(); it++){
        // Remove reserva na data e no quarto indicado
        if((*it)->get_email() == email && (*it)->verificar_data(data_auxiliar) &&
        (*it)->get_quarto() == std::stoi(quarto)){
            this->reservas.erase(it);
            tem_reserva = true;
            break;
        }
    }

    if(tem_reserva == false)
        std::cout<<"Voce nao tem reservas agendadas nesse dia e nesse quarto"<<
        std::endl<<std::endl;
}

Data BancoDeDados::converter_string_para_data(std::string data_str){
    std::string dia, mes, ano;
    std::stringstream X(data_str);
    Data data;

    // Tenta quebrar a string por delimitador '/'. Caso o formato digitado
    // seja diferente, uma exceção é lançada
    try{
        getline(X, dia, '/');
        data.set_dia(std::stoi(dia));
        getline(X, mes, '/');
        data.set_mes(std::stoi(mes));
        getline(X, ano);
        data.set_ano(std::stoi(ano));
    }catch(std::invalid_argument &erro){
        // erro.what() retorna o erro "stoi"
        // Esse erro ocorre quando a função não consegue
        // converter a string para inteiro
        throw;
    }

    return data;
}

void BancoDeDados::acessar_reservas_pela_data(std::string data_str){
    Data data_para_acessar;

    // Tenta quebrar a string por delimitador '/'. Caso o formato digitado
    // seja diferente, uma exceção é lançada
    try{
        data_para_acessar = converter_string_para_data(data_str);
    }catch(std::invalid_argument &erro){
        throw;
    }

    // Imprime os quartos e nome dos hóspedes com reservas para a data fornecida
    bool tem_reserva = false;
    for(std::vector<Reserva*>::iterator it = this->reservas.begin(); it != this->reservas.end(); it++){
        if((*it)->verificar_data(data_para_acessar) == true){
            std::cout<<"Quarto: "<<(*it)->get_quarto()<<", Hospede: "<<(*it)->get_nome()<<std::endl;
            tem_reserva = true;
        }
    }

    if(tem_reserva == false){
        std::cout<<"Nao existe reservas agendadas para o dia "<<
        data_para_acessar.get_dia()<<"/"<<data_para_acessar.get_mes()<<"/"<<
        data_para_acessar.get_ano()<<std::endl;
    }
    std::cout<<std::endl;
}

void BancoDeDados::verificar_quartos_livres(std::string data_str){
    Data data_para_acessar;

    // Tenta quebrar a string por delimitador '/'. Caso o formato digitado
    // seja diferente, uma exceção é lançada
    try{
        data_para_acessar = converter_string_para_data(data_str);
    }catch(std::invalid_argument &erro){
        throw;
    }

    int quantidade_livres = 0, auxiliar;
    std::vector<int> quartos_ocupados, quartos_livres;

    // Cria lista dos quartos ocupados na data informada
    for(std::vector<Reserva*>::iterator it = this->reservas.begin(); it != this->reservas.end(); it++){
        if((*it)->verificar_data(data_para_acessar) == true)
            quartos_ocupados.push_back((*it)->get_quarto());
    }

    // Obtém lista de quartos desocupados
    for(std::vector<Quarto*>::iterator it = this->quartos.begin(); it != this->quartos.end(); it++){
        auxiliar = (*it)->get_quarto();
        // Se quarto estiver na lista de ocupados, não adicione no vector de quartos livres
        if( std::find(quartos_ocupados.begin(), quartos_ocupados.end(), auxiliar ) != quartos_ocupados.end() )
            continue;
        else{
            quartos_livres.push_back(auxiliar);
            quantidade_livres += 1;
        }
    }

    std::cout<<"Existem "<<quantidade_livres<<" quartos livres no dia "<<
    data_para_acessar.get_dia()<<"/"<<data_para_acessar.get_mes()<<"/"<<
    data_para_acessar.get_ano()<<std::endl;
    std::cout<<"Os quartos livres sao: ";

    // Imprime os quartos livres
    for(std::vector<int>::iterator it = quartos_livres.begin(); it != quartos_livres.end(); it++)
        std::cout<<*it<<" ";
    std::cout<<std::endl<<std::endl;
}

void BancoDeDados::acessar_informacoes_hospedes(std::string nome){
    bool tem_reserva = false;
    for(std::vector<Reserva*>::iterator it = this->reservas.begin(); it != this->reservas.end(); it++){
        if((*it)->get_nome() == nome ){
            std::cout<<"Quarto: "<<(*it)->get_quarto()<<", "<<(*it)->get_dia()<<
            "/"<<(*it)->get_mes()<<"/"<<(*it)->get_ano()<<std::endl;
            tem_reserva = true;
        }
    }

    if(tem_reserva == false)
        std::cout<<"Esse hóspede nao possui reservas agendadas"<<std::endl;
    std::cout<<std::endl;
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

    // Desaloca dados alocados dinamicamente
    for(std::vector<Hospede*>::iterator it = this->hospedes.begin(); it != this->hospedes.end(); it++)
        free(*it);

    for(std::vector<Quarto*>::iterator it = this->quartos.begin(); it != this->quartos.end(); it++)
        free(*it);

    for(std::vector<Reserva*>::iterator it = this->reservas.begin(); it != this->reservas.end(); it++){
        (*it)->~Reserva();
        free(*it);
    }
}
