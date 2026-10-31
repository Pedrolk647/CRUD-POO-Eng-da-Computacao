#pragma once
#include "Contrato.h"
#include <iostream>
#include <string>

using namespace std;

class ContratoDiplomatico : public Contrato
{
protected:
    string cargo, organizacaoEnvolvida;

public:
    ContratoDiplomatico(string car, string org, string t, string nC, string nA, float rec, string l, string c, int d, int m, int a, bool desf, int dc = 0, int mc = 0, int ac = 0) : Contrato(t, nC, nA, rec, l, c, d, m, a, desf, dc, mc, ac)
    {
        this->cargo = car;
        this->organizacaoEnvolvida = org;
        setTaxa(50);
    }

    void exibirContrato()
    {
        cout << "Nome do alvo: " << this->getNomeAlvo() << endl;
        cout << "Local: " << this->getlocal() << ", " << this->cidade << endl;
        cout << "Cargo do alvo: " << this->cargo << endl;
        cout << "Organização envolvida: " << this->organizacaoEnvolvida << endl;
        cout << "Tipo de contrato: " << this->tipo << ", Alvo: " << this->getNomeAlvo() << ";" << endl;
        cout << "Cliente: " << this->getnomeCliente() << ";" << endl;
        cout << "Data limite: " << this->dataLimite.getDia() << ", " << this->dataLimite.getMesString() << ", " << this->dataLimite.getAno() << ";" << endl;
        if (this->desfecho)
            cout << "Data de conclusão: " << this->dataConclusao.getDia() << ", " << this->dataConclusao.getMesString() << ", " << this->dataConclusao.getAno() << ";" << endl;
        cout << "Taxa adicional da agência: " << this->getTaxa() << ";" << endl;
        cout << "Recompensa do executor: " << this->getrecompensa() << ";" << endl;
    }
};