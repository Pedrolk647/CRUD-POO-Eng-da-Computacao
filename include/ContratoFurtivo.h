#pragma once
#include "Contrato.h"
#include <iostream>
#include <string>

using namespace std;

class ContratoFurtivo : public Contrato
{
protected:
    int tempoLimite, nivelSeguranca;

public:
    ContratoFurtivo(int tempo, int nS, string t, string nC, string nA, float rec, string l, string c, int d, int m, int a, bool desf, int dc = 0, int mc = 0, int ac = 0) : Contrato(t, nC, nA, rec, l, c, d, m, a, desf, dc, mc, ac)
    {
        this->tempoLimite = tempo;
        this->nivelSeguranca = nS;
        if (nivelSeguranca < 1 || nivelSeguranca > 10)
        {
            cout << "Nivel de seguranca invalido! Deve ser entre 1 e 10." << endl;
            while (nivelSeguranca < 1 || nivelSeguranca > 10)
            {
                cout << "Digite o nivel de seguranca (1 a 10): ";
                cin >> nivelSeguranca;
            }
        }
        float taxa = 5;
        if (tempoLimite < 60)
        {
            taxa += 10;
        }
        if (nivelSeguranca > 5)
        {
            taxa += 15;
        }
        setTaxa(taxa);
    };
    void exibirContrato()
    {
        cout << "Cliente: " << this->getnomeCliente() << ";" << endl;
        cout << "Local: " << this->getlocal() << ", " << this->cidade << endl;
        cout << "Tempo limite: " << this->tempoLimite << ";" << endl;
        cout << "Nivel de segurança: " << this->nivelSeguranca << ";" << endl;
        cout << "Tipo de contrato: " << this->tipo << ", Alvo: " << this->getNomeAlvo() << ";" << endl;
        cout << "Data limite: " << this->dataLimite.getDia() << ", " << this->dataLimite.getMesString() << ", " << this->dataLimite.getAno() << ";" << endl;
        if (this->desfecho)
            cout << "Data de conclusão: " << this->dataConclusao.getDia() << ", " << this->dataConclusao.getMesString() << ", " << this->dataConclusao.getAno() << ";" << endl;
        cout << "Taxa adicional da agência: " << this->getTaxa() << ";" << endl;
        cout << "Recompensa do executor: " << this->getrecompensa() << ";" << endl;
    }
};