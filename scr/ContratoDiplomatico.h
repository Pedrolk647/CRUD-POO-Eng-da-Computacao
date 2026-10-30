#pragma once
#include "Contrato.h"
#include <iostream>
#include <string>

using namespace std;

class ContratoDiplomatico: public Contrato{
    protected:
        string mediador;
        bool terminaEmAcordo;
    public:
        
        ContratoDiplomatico(string med,bool tea,string t, string nC, string nA,float rec, int p, string l, string c, int d, int m, int a, bool desf):Contrato(t, nC, nA, rec, p, l, c, d, m ,a,desf){

            this->mediador = med;
            this->terminaEmAcordo = tea;

            if(terminaEmAcordo == true){

                this->setrecompensa(0.0);

            }

        }

        void exibirContrato(){
            cout<<"Cliente: " << this->getnomeCliente() <<";" <<endl;
            cout<<"Tipo de execução: "<< this->tipo<< ", Alvo: " << this->getnomeAlvo() << ";"<<endl;
            cout<<"Local: "<< this->getlocal() << ", "<< this->cidade; 
            cout<<"Mediador: " << this->mediador << endl;
            cout<<"Data: "<< this->dia <<  ", "<< this->mes << ", "<< this->ano << ";"<<endl;
            cout<<"Preço cobrado ao cliente: "<< this->preco<< ";" <<endl;
            cout<<"Recompensa ao assassino: " << this->getrecompensa() <<";"<<endl;   
        
        }
        
};