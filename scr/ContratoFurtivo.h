#pragma once
#include "Contrato.h"
#include <iostream>
#include <string>

using namespace std;

class ContratoFurtivo: public Contrato{
    protected:
        int tempoInf;
        bool persegueCarro;

    public:
    
        ContratoFurtivo(int tempo,bool pC,string t, string nC, string nA,float rec, int p, string l, string c, int d, int m, int a, bool desf):Contrato(t, nC, nA, rec, p, l, c, d, m ,a,desf){
            this->tempoInf = tempo;
            this->persegueCarro = pC;

            if(this->persegueCarro == true && this->tempoInf > 3){

                this->setrecompensa(((1.1+(this->tempoInf-3))*this->getrecompensa()));

            }

            else if(this->persegueCarro == true){

                this->setrecompensa(1.1*(this->getrecompensa()));  

            }
            else if(this->desfecho == false){

                this->setrecompensa(0.0);

            }
            
        };
        void exibirContrato(){
            cout<<"Cliente: " << this->getnomeCliente() <<";" <<endl;
            cout<<"Tipo de execução: "<< this->tipo<< ", Alvo: " << this->getnomeAlvo() << ";"<<endl;
            cout<<"Local: "<< this->getlocal() << ", "<< this->cidade; 
            cout<<"Data: "<< this->dia << ", "<< this->mes << ", "<< this->ano << ";"<<endl;
            cout<<"Preço cobrado ao cliente: "<< this->preco<< ";" <<endl;
            cout<<"Recompensa ao assassino: " << this->getrecompensa()<<";"<<endl;   
        
        }

    ~ContratoFurtivo();

};