#pragma once
#include <iostream>

using namespace std;

class Data
{
private:
    int dia, mes, ano;

public:
    Data(int d, int m, int a)
    {
        dia = d;
        mes = m;
        ano = a;
    }
    Data()
    {
        dia = mes = ano = 1;
    }
    int getDia()
    {
        return dia;
    }
    void setDia(int n)
    {
        dia = n;
    }
    int getMes()
    {
        return mes;
    }
    void setMes(int n)
    {
        mes = n;
    }
    int getAno()
    {
        return ano;
    }
    void setAno(int n)
    {
        ano = n;
    }
    string getMesString()
    {
        switch (mes)
        {
        case 1:
            return "Janeiro";
            break;
        case 2:
            return "Fevereiro";
            break;
        case 3:
            return "Março";
            break;
        case 4:
            return "Abril";
            break;
        case 5:
            return "Maio";
            break;
        case 6:
            return "Junho";
            break;
        case 7:
            return "Julho";
            break;
        case 8:
            return "Agosto";
            break;
        case 9:
            return "Setembro";
            break;
        case 10:
            return "Outubro";
            break;
        case 11:
            return "Novembro";
            break;
        case 12:
            return "Dezembro";
            break;
        default:
            return "Indefinido";
            break;
        }
    }
};