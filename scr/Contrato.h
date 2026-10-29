#pragma once   
#include <iostream>
#include <string>

using namespace std;

Vaca;FURTIVO;Barao Imaginario;Vilao Mascarado;5000.00;90000;Cobertura Ficticia;Gotham City;3;12;1;Girafa

class Contrato {
protected:
    string tipo, nomeCliente, nomeAlvo, local, cidade;
    int preco, dia, mes, ano;
    float recompensa;

public:
    Contrato(string t, string nC, string nA, float rec, int p, string l, string c, int d, int m, int a){
        tipo = t;
        nomeCliente = nC;
        nomeAlvo = nA;
        recompensa = rec;
        preco = p;
        local = l;
        cidade = c;
        dia = d;
        mes = m;
        ano = a;
    }
    virtual ~Contrato();
    virtual void exibirContrato() = 0;
    

};