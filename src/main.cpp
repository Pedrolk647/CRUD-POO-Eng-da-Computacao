#include <iostream>
#include "AgenciaMercenarios.h"
#include "ContratoDiplomatico.h"
#include "ContratoEspetacular.h"
#include "ContratoFurtivo.h"

using namespace std;

int main()
{
    AgenciaMercenarios agencia("APBC");
    int n;
    agencia.carregarArquivo();

    cout << "Bem-vindo ao sistema de gerenciamento da APBC (Agência Paraibana de Contratos)." << endl;

    do
    {
        cout << "--------------------------------------------------------------" << endl;
        cout << "Digite a opcao desejada: " << endl;
        cout << " 1 - Inserir contrato \n 2 - Listar todos os contratos \n 3 - Exibir um contrato (pesquisar por nome do alvo) \n 4 - Alterar contrato (pesquisar por nome do alvo) \n 5 - Remover contrato(pesquisar por nome do alvo) \n 6 - Exibir Relatório da Agência \n 7 - Sair" << endl;
        cout << ">> ";
        cin >> n;
        switch (n)
        {
        case 1:
        {
            Contrato *contrato = agencia.criarContrato();
            agencia.adicionarContrato(contrato);
            break;
        }
        case 2:
            agencia.exibirContratos();
            break;
        case 3:
        {
            string nomeAlvo;
            cout << "Digite o nome do alvo do contrato que deseja exibir: ";
            cin.ignore();
            getline(cin, nomeAlvo);
            int index = agencia.exibirContratos(nomeAlvo);
            if (index == -1)
            {
                cout << "Contrato não encontrado." << endl;
            }
            break;
        }
        case 4:
        {
            string nomeAlvoAlterar;
            cout << "Digite o nome do alvo do contrato que deseja alterar: ";
            cin.ignore();
            getline(cin, nomeAlvoAlterar);
            Contrato *novoContrato = agencia.criarContrato();
            agencia.alterarContrato(nomeAlvoAlterar, novoContrato);
            break;
        }
        case 5:
        {
            string nomeAlvoRemover;
            cout << "Digite o nome ou índice do alvo do contrato que deseja remover: ";
            cin.ignore();
            getline(cin, nomeAlvoRemover);
            agencia.removerContrato(nomeAlvoRemover);
            break;
        }
        case 6:

            agencia.exibirRelatorio();
            break;
        case 7:
            cout << "Saindo do sistema..." << endl;
            break;
        default:
            cout << "Opcao invalida. Tente novamente." << endl;
            break;
        }

        cout << "--------------------------------------------------------------" << endl;
    } while (n != 7);
    agencia.salvarArquivo();
    return 0;
}