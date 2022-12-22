#include "menu.cpp"


/* OBS: Login do funcionário
    email = "funcionario@hotel.com";
    senha = "pds2";
*/

int main()
{
    int escolha, opcao;
    bool FLAG = true;

    std::cout<<"\n\n !!! Sistema do hotel iniciado !!!\n\n";

    while(FLAG == true){
        std::cout<<"Digite"<<std::endl;
        std::cout<<"1 para logar no sistema"<<std::endl;
        std::cout<<"2 para cadastrar no sistema"<<std::endl;
        std::cout<<"3 para sair do sistema"<<std::endl;
        std::cout<<"Valor: ";
        std::cin>>escolha;
        std::cout<<std::endl;

        switch (escolha)
        {
        case 1:
            int retorno;
            std::cout<<"Digite:"<<std::endl;
            std::cout<<"1 para logar hospede"<<std::endl;
            std::cout<<"2 para logar funcionario"<<std::endl;
            std::cout<<"3 para cancelar operacao de login"<<std::endl;
            std::cout<<"Valor: ";
            std::cin>>opcao;
            std::cout<<std::endl;

            if(opcao == 1){
                retorno = logar_hospede();
                if(retorno == true)
                    funcoes_hospede();
            }
            else if(opcao == 2){
                retorno = logar_funcionario();
                if(retorno == true)
                    funcoes_funcionario();
            }

            break;
        case 2:{
            bool retorno = cadastrar_no_sistema();
            if(retorno == true)
                FLAG = false;
            break;

        }
        case 3:
            FLAG = false;
            std::cout<<"\n\n !!! Sistema do hotel encerrado !!!\n\n";
            break;
        default:
            std::cout<<"Valor '"<<escolha<<"' digitado errado"<<std::endl;
            std::cout<<"Por favor, digite corretamente um dos valores "<<
            "apresentados"<<std::endl<<std::endl;
            break;
        }
    }

    return 0;
}
