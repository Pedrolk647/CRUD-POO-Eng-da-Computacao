#pragma once
#include "Contrato.h"
#include <iostream>
#include <string>

class ContratoEspetacular : public Contrato
{
private:
    int publicoEstimado;
    bool divulgacaoMidia;

public:
    ContratoEspetacular(int pE, bool dM, string t, string nC, string nA, float rec, string l, string c, int d, int m, int a, bool desf, int dc = 0, int mc = 0, int ac = 0) : Contrato(t, nC, nA, rec, l, c, d, m, a, desf, dc, mc, ac)
    {

        this->publicoEstimado = pE;
        this->divulgacaoMidia = dM;
        float taxa = 10;
        if (publicoEstimado > 10000)
        {
            taxa += 20;
        }
        if (divulgacaoMidia)
        {
            taxa += 10;
        }
        setTaxa(taxa);
    }

    void exibirContrato()
    {
        cout << "Nome do alvo: " << this->getNomeAlvo() << endl;
        cout << "Local: " << this->getlocal() << ", " << this->cidade;
        cout << "Publico estimado: " << this->publicoEstimado << ";" << endl;
        cout << "Divulgacao na midia: " << (this->divulgacaoMidia ? "Sim" : "Nao") << ";" << endl;
        cout << "Tipo de contrato: " << this->tipo << ";" << endl;
        cout << "Cliente: " << this->getnomeCliente() << ";" << endl;
        cout << "Data limite: " << this->dataLimite.getDia() << ", " << this->dataLimite.getMesString() << ", " << this->dataLimite.getAno() << ";" << endl;
        if (this->desfecho)
            cout << "Data de conclusão: " << this->dataConclusao.getDia() << ", " << this->dataConclusao.getMesString() << ", " << this->dataConclusao.getAno() << ";" << endl;
        cout << "Taxa adicional da agência: " << this->getTaxa() << ";" << endl;
        cout << "Recompensa do executor: " << this->getrecompensa() << ";" << endl;
    }
    int getPublicoEstimado()
    {
        return this->publicoEstimado;
    }
    bool getDivulgacaoMidia()
    {
        return this->divulgacaoMidia;
    }
};