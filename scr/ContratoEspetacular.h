#pragma once
#include "Contrato.h"
#include <iostream>
#include <string>

class ContratoEspetacular: public Contrato{
    protected:
        int niveisDeExplosoes;
        bool persegueCarro;
    public:
        ContratoEspetacular(int exp,bool pC,string t, string nC, string nA,float rec, int p, string l, string c, int d, int m, int a, bool desf):Contrato(t, nC, nA, rec, p, l, c, d, m ,a,desf){

            this->niveisDeExplosoes = exp;
            this->persegueCarro = pC;

            if(niveisDeExplosoes > 3){

                this->setrecompensa(this->getrecompensa()/2);

            }

        }

        void exibirContrato(){

            cout<<"Cliente: " << this->getnomeCliente() <<";" <<endl;
            cout<<"Tipo de execução: "<< this->tipo<< ", Alvo: " << this->getnomeAlvo() << ";"<<endl;
            cout<<"Local: "<< this->getlocal() << ", "<< this->cidade; 
            cout<<"Data: "<< this->dia <<  ", "<< this->mes << ", "<< this->ano << ";"<<endl;
            cout<<"Nível de explosões: "<< this->niveisDeExplosoes;
            cout<<"Preço cobrado ao cliente: "<< this->preco<< ";" <<endl;
            cout<<"Recompensa ao assassino: " << this->getrecompensa() <<";"<<endl;   
        
        }

};