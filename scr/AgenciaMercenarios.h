#pragma once
#include <iostream>
#include <string>
#include "Contrato.h"

using namespace std;

class AgenciaMercenarios {
protected:
    string nome;
    vector<Contrato> contratos;

public:
    AgenciaMercenarios(string n) : nome(n) {}

    void adicionarContrato(Contrato contrato) {
        contratos.push_back(contrato);
    }

    void removerContrato(string n) {
        int index = Pesquisar(n);
        if (index != -1) {
            contratos.erase(contratos.begin() + index);
            cout << "Contrato removido com sucesso!" << endl;
        } else {
            cout << "Contrato nao encontrado!" << endl;
        }
    }

    void alterarContrato(string n, Contrato novoC) {
        int index = Pesquisar(n);
        if (index != -1) {
            contratos[index] = novoC;
            cout << "Contrato alterado com sucesso!" << endl;
        } else {
            cout << "Contrato nao encontrado!" << endl;
        }
    }

    void exibirContratos() {
        cout << "Contratos da agencia " << nome << ":" << endl;
        for (int i = 0; i < contratos.size(); i++) {
            cout << "Contrato " << i + 1 << ": " << contratos[i].getNome() << endl;
        }
    }

    int Pesquisar(string n){ 
        for (int i = 0; i < contratos.size(); i++) {
            if (contratos[i].getNome() == n) {
                return i;
            }
        }
        return -1;
    }