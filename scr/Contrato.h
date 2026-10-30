#pragma once   
#include <iostream>
#include <string>

using namespace std;

//Vaca;FURTIVO;Barao Imaginario;Vilao Mascarado;5000.00;90000;Cobertura Ficticia;Gotham City;3;12;1;Girafa

class Contrato {
private: 
    string nomeCliente,nomeAlvo,local;
    float recompensa;
    
protected:
    string tipo, cidade;
    int preco, dia, mes, ano;
    //float recompensa;
    bool desfecho;

public:
    Contrato(string t, string nC, string nA, float rec, int p, string l, string c, int d, int m, int a, bool desf){
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
        desfecho = desf;//Precisamos saber se o trabalho foi feito ou não. Se não, o trabalhador não recebe.
        if(desfecho == false){

            this->recompensa = 0.0;

        }
    }
    string getnomeCliente(){

        return this->nomeCliente; 

    }
    string getnomeAlvo(){

        return this->nomeAlvo; 

    }
    string getlocal(){

        return this->local; 

    }

    float getrecompensa(){

        return this->recompensa; 

    }
    void setrecompensa(float rec){

        this->recompensa = rec;

    }
    virtual ~Contrato();
    virtual void exibirContrato() = 0;
    

};