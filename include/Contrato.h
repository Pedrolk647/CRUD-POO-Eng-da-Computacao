#pragma once
#include <iostream>
#include <string>
#include "Data.h"

using namespace std;

class Contrato
{
private:
    string nomeCliente, nomeAlvo, local;
    float recompensa, preco;

protected:
    string tipo, cidade;
    Data dataLimite, dataConclusao;
    bool desfecho;

public:
    Contrato(string t, string nC, string nA, float rec, string l, string c, int d, int m, int a, bool desf, int dc, int mc, int ac)
    {
        tipo = t;
        nomeCliente = nC;
        nomeAlvo = nA;
        recompensa = rec;
        local = l;
        cidade = c;
        dataLimite.setDia(d);
        dataLimite.setMes(m);
        dataLimite.setAno(a);
        desfecho = desf; // Precisamos saber se o trabalho foi feito ou não.
        if (desfecho)
        {
            dataConclusao.setDia(dc);
            dataConclusao.setMes(mc);
            dataConclusao.setAno(ac);
        }
    }
    string getnomeCliente()
    {

        return this->nomeCliente;
    }
    string getNomeAlvo()
    {

        return this->nomeAlvo;
    }
    string getlocal()
    {

        return this->local;
    }
    string getCidade()
    {

        return this->cidade;
    }
    Data getDataLimite()
    {
        return this->dataLimite;
    }
    Data getDataConclusao()
    {
        return this->dataConclusao;
    }
    string getTipo()
    {
        return this->tipo;
    }
    bool getDesfecho()
    {

        return this->desfecho;
    }
    float getrecompensa()
    {

        return this->recompensa;
    }
    void setrecompensa(float rec)
    {

        this->recompensa = rec;
    }
    float getTaxa()
    {

        return this->recompensa * (preco / 100);
    }
    void setTaxa(float p)
    {

        this->preco = p;
    }
    virtual ~Contrato() = default;
    virtual void exibirContrato() = 0;
};