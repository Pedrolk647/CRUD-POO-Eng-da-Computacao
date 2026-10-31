#pragma once
#include <iostream>
#include <string>
#include "Contrato.h"
#include "ContratoDiplomatico.h"
#include "ContratoEspetacular.h"
#include "ContratoFurtivo.h"
#include <vector>

using namespace std;

class AgenciaMercenarios
{
protected:
    string nome;
    vector<Contrato *> contratos;

public:
    AgenciaMercenarios(string n) : nome(n) {}

    ~AgenciaMercenarios()
    {
        for (Contrato *c : contratos)
        {
            delete c;
        }
    }

    Contrato *criarContrato()
    {
        string tipo, nomeCliente, nomeAlvo, local, cidade;
        float recompensa;
        int dia, dia_c, mes, mes_c, ano, ano_c;
        bool desfecho;
        char barra1, barra2;
        cout << "Digite o tipo de contrato (Diplomatico, Espetacular, Furtivo): ";
        cin >> tipo;
        cin.ignore();
        cout << "Digite o nome do cliente: ";
        getline(cin, nomeCliente);
        cout << "Digite o nome do alvo: ";
        getline(cin, nomeAlvo);
        cout << "Digite a recompensa: ";
        cin >> recompensa;
        cin.ignore();
        cout << "Digite o local: ";
        getline(cin, local);
        cout << "Digite a cidade: ";
        getline(cin, cidade);
        cout << "Digite a data limite da execução (dd/mm/aaaa): ";
        cin >> dia >> barra1 >> mes >> barra2 >> ano;
        cout << "Contrato concluído? (1 para sim, 0 para não): ";
        cin >> desfecho;
        if (desfecho == 1)
        {
            cout << "Digite a data de execução (dd/mm/aaaa): ";
            cin >> dia_c >> barra1 >> mes_c >> barra2 >> ano_c;
        }
        Contrato *contrato = nullptr;
        if (tipo == "Diplomatico")
        {
            string cargo, organizacaoEnvolvida;
            cin.ignore();
            cout << "Digite o cargo do alvo: ";
            getline(cin, cargo);
            cout << "Digite a organização envolvida: ";
            getline(cin, organizacaoEnvolvida);
            if (desfecho == 1)
            {
                contrato = new ContratoDiplomatico(cargo, organizacaoEnvolvida, tipo, nomeCliente, nomeAlvo, recompensa, local, cidade, dia, mes, ano, desfecho, dia_c, mes_c, ano_c);
            }
            else
            {
                contrato = new ContratoDiplomatico(cargo, organizacaoEnvolvida, tipo, nomeCliente, nomeAlvo, recompensa, local, cidade, dia, mes, ano, desfecho);
            }
        }

        else if (tipo == "Espetacular")
        {
            int publicoEstimado;
            bool divulgacaoMidia;
            cout << "Digite o público estimado: ";
            cin >> publicoEstimado;
            cout << "Haverá divulgação na mídia? (1 para sim, 0 para não): ";
            cin >> divulgacaoMidia;
            if (desfecho == 1)
            {
                contrato = new ContratoEspetacular(publicoEstimado, divulgacaoMidia, tipo, nomeCliente, nomeAlvo, recompensa, local, cidade, dia, mes, ano, desfecho, dia_c, mes_c, ano_c);
            }
            else
            {
                contrato = new ContratoEspetacular(publicoEstimado, divulgacaoMidia, tipo, nomeCliente, nomeAlvo, recompensa, local, cidade, dia, mes, ano, desfecho);
            }
        }
        else if (tipo == "Furtivo")
        {
            int tempoLimite, nivelSeguranca;
            cout << "Digite o tempo limite (em minutos): ";
            cin >> tempoLimite;
            cout << "Digite o nível de segurança (1 a 10): ";
            cin >> nivelSeguranca;
            if (desfecho == 1)
            {
                contrato = new ContratoFurtivo(tempoLimite, nivelSeguranca, tipo, nomeCliente, nomeAlvo, recompensa, local, cidade, dia, mes, ano, desfecho, dia_c, mes_c, ano_c);
            }
            else
            {
                contrato = new ContratoFurtivo(tempoLimite, nivelSeguranca, tipo, nomeCliente, nomeAlvo, recompensa, local, cidade, dia, mes, ano, desfecho);
            }
        }
        else
        {
            cout << "Tipo de contrato inválido." << endl;
            return nullptr;
        }
        cout << "Taxa adicional da agência: " << contrato->getTaxa() << endl;
        return contrato;
    }

    void adicionarContrato(Contrato *contrato)
    {
        if (contrato == nullptr)
        {
            cout << "Contrato inválido. Não foi adicionado." << endl;
            return;
        }
        contratos.push_back(contrato);
        cout << "Contrato adicionado com sucesso." << endl;
    }

    void removerContrato(string n)
    {
        int index = Pesquisar(n);
        if (index != -1)
        {
            delete contratos[index];
            contratos.erase(contratos.begin() + index);
            cout << "Contrato removido com sucesso!" << endl;
        }
        else
        {
            cout << "Contrato nao encontrado!" << endl;
        }
    }
    void removerContrato(int index)
    {
        if (index != -1)
        {
            delete contratos[index];
            contratos.erase(contratos.begin() + index);
            cout << "Contrato removido com sucesso!" << endl;
        }
        else
        {
            cout << "Contrato nao encontrado!" << endl;
        }
    }

    void alterarContrato(string n, Contrato *novoC)
    {
        int index = Pesquisar(n);
        if (index != -1)
        {
            delete contratos[index];
            contratos[index] = novoC;
            cout << "Contrato alterado com sucesso!" << endl;
        }
        else
        {
            cout << "Contrato nao encontrado!" << endl;
        }
    }

    void exibirContratos()
    {
        cout << "Contratos da agencia " << nome << ":" << endl;
        for (int i = 0; i < contratos.size(); i++)
        {
            cout << "Contrato " << i + 1 << ": " << contratos[i]->getNomeAlvo() << endl;
        }
    }
    int exibirContratos(string n)
    {
        for (int i = 0; i < contratos.size(); i++)
        {
            if (contratos[i]->getNomeAlvo() == n)
            {
                contratos[i]->exibirContrato();
                return i;
            }
        }
        return -1;
    }

    int Pesquisar(string n)
    {
        for (int i = 0; i < contratos.size(); i++)
        {
            if (contratos[i]->getNomeAlvo() == n)
            {
                return i;
            }
        }
        return -1;
    }

    void exibirRelatorio()
    {
        cout << "Relatório da Agência " << nome << ":" << endl;
        cout << "Total de contratos: " << contratos.size() << endl;
        cout << "Valor total das recompensas (incluindo taxa): ";
        float totalRecompensa = 0;
        for (Contrato *c : contratos)
        {
            totalRecompensa += c->getrecompensa() + c->getTaxa();
        }
        cout << totalRecompensa << endl;
        for (int i = 0; i < contratos.size(); i++)
        {
            cout << "Contrato " << i + 1 << ": " << contratos[i]->getNomeAlvo() << endl;
            contratos[i]->exibirContrato();
            cout << endl;
        }
    }
};