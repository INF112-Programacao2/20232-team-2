#include <vector>
#include "Mao.hpp"
#include "Carta.hpp"
#include <algorithm>

Mao::Mao() {}

Mao::~Mao() {}

bool Mao::compare_Valor_Cartas(Carta &carta1, Carta &carta2)
{
    return carta1.get_Valor_Carta() < carta2.get_Valor_Carta();
}

bool Mao::compare_Naipe(Carta &carta1, Carta &carta2)
{
    if(carta1.get_Naipe() == carta2.get_Naipe())
        return carta1.get_Valor_Carta() < carta2.get_Valor_Carta();
    return carta1.get_Naipe() < carta2.get_Naipe();
}

std::vector<Carta> Mao::get_Cartas() 
{ 
    return cartas; 
}

int Mao::get_Valor_Mao()
{
    
    // Atribuir o valor à mão
    if(is_Royal_Flush().second)  {      return 100;}
    else if(is_Straight_Flush().second) return 90;
    else if (is_Quadra().second)        return 80;
    else if (is_Full_House().second)    return 70;
    else if (is_Flush())                return 60;
    else if (is_Straight().second)      return 50;
    else if (is_Trinca().second)        return 40;      
    else if (is_Dois_Pares().second)    return 30;
    else if (is_Par().second)           return 20;
    else                               std::sort(cartas.begin(), cartas.end(), compare_Valor_Cartas); return cartas.back().get_Valor_Carta();
}

std::pair<int,bool> Mao::is_Par()
{
    std::vector<Carta> copiaCartas = cartas;
    std::sort(copiaCartas.begin(), copiaCartas.end(), compare_Valor_Cartas);
    for (int i = 0; i < copiaCartas.size()-1; i++)
    {
        if((copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[1+i]).get_Valor_Carta()))
            return {(copiaCartas[0+i].get_Valor_Carta()), true};
    }
    return {0, false};
}

// Método testado e funcionando
std::pair<std::pair<int, int>, bool> Mao::is_Dois_Pares()
{
    std::vector<Carta> copiaCartas = cartas;
    std::sort(copiaCartas.begin(), copiaCartas.end(), compare_Valor_Cartas);
    bool um_Par = false, dois_Pares = false;
    int valor_par_um, valor_par_dois;
    for (int i = 0; i < copiaCartas.size()-1; i++)
    {
        if((copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[1+i]).get_Valor_Carta()))
        {
            um_Par = true;
            valor_par_um = (copiaCartas[0+i].get_Valor_Carta());
            copiaCartas.erase(copiaCartas.begin() +1+i);
            copiaCartas.erase(copiaCartas.begin() +0+i);
            break;
        }
    }
    
    for (int i = 0; i < copiaCartas.size()-1; i++)
    {
        if((copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[1+i]).get_Valor_Carta()))
        {
            dois_Pares = true;
            valor_par_dois = (copiaCartas[0+i].get_Valor_Carta());
        }
    }
    if(dois_Pares && um_Par)
        return {{valor_par_um, valor_par_dois}, true};
    return {{0,0}, false};
}

std::pair<int, bool> Mao::is_Trinca()
{
    std::vector<Carta> copiaCartas = cartas;
    std::sort(copiaCartas.begin(), copiaCartas.end(), compare_Valor_Cartas);
    for (int i = 0; i < copiaCartas.size()-2; i++)
    {
        if((copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[1+i]).get_Valor_Carta()) && (copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[2+i]).get_Valor_Carta()))
            return {(copiaCartas[0+i].get_Valor_Carta()), true};
    }
    return {0, false};
}

std::pair<int, bool> Mao::is_Straight()
{
    std::vector<Carta> copiaCartas = cartas;
    std::sort(copiaCartas.begin(), copiaCartas.end(), compare_Valor_Cartas);

    for (int i = 0; i < copiaCartas.size(); i++)
    {
        for (int j = i+1; j < copiaCartas.size(); j++)
        {
            if(copiaCartas[i].get_Valor_Carta() == copiaCartas[j].get_Valor_Carta())
            {
                copiaCartas.erase(copiaCartas.begin() + j);
            }
        }
    }

    for (int i = 0; i < copiaCartas.size() - 4; i++)
    {
        if((copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[1+i]).get_Valor_Carta() - 1) && (copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[2+i]).get_Valor_Carta() - 2) && (copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[3+i]).get_Valor_Carta() - 3) && (copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[4+i]).get_Valor_Carta() - 4))
            return {(copiaCartas[0+i].get_Valor_Carta()), true};
    }
    return {0, false};
}

bool Mao::is_Flush()
{   
    std::vector<Carta> copiaCartas = cartas;
    std::sort(copiaCartas.begin(), copiaCartas.end(), compare_Naipe);
    for (int i = 0; i < copiaCartas.size() - 4; i++)
    {
        if((copiaCartas[0+i].get_Naipe()) == (copiaCartas[1+i].get_Naipe()) && (copiaCartas[0+i].get_Naipe()) == (copiaCartas[2+i].get_Naipe()) && (copiaCartas[0+i].get_Naipe()) == (copiaCartas[3+i].get_Naipe()) && (copiaCartas[0+i].get_Naipe()) == (copiaCartas[4+i].get_Naipe()))
            return true;
    }
    return false;
}

std::pair<std::pair<int, int>, bool> Mao::is_Full_House()
{
    bool trinca = false, dupla = false;
    int valor_trinca, valor_dupla;
    std::vector<Carta> copiaCartas = cartas;
    std::sort(copiaCartas.begin(), copiaCartas.end(), compare_Valor_Cartas);
    for (int i = 0; i < copiaCartas.size()-2; i++)
    {
        if((copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[1+i]).get_Valor_Carta()) && 
        (copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[2+i]).get_Valor_Carta()))
        {
            valor_trinca = (copiaCartas[0+i].get_Valor_Carta());
            copiaCartas.erase(copiaCartas.begin() + 2+i);
            copiaCartas.erase(copiaCartas.begin() + 1+i);
            copiaCartas.erase(copiaCartas.begin() + i);
            trinca = true;
            break;
        }
    }
    for (int i = 0; i < copiaCartas.size()-1; i++)
    {
        if((copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[1+i]).get_Valor_Carta()))
        {
            valor_dupla = (copiaCartas[0+i].get_Valor_Carta());
            dupla = true;
            break;
        }
    }
    if(trinca && dupla)
        return {{valor_trinca, valor_dupla}, true};
    return {{0,0}, false};
}

std::pair<int, bool> Mao::is_Quadra()
{
    std::vector<Carta> copiaCartas = cartas;
    std::sort(copiaCartas.begin(), copiaCartas.end(), compare_Valor_Cartas);
    for (int i = 0; i < copiaCartas.size()-3; i++)
    {
        if((copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[1+i]).get_Valor_Carta()) && (copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[2+i]).get_Valor_Carta()) && (copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[3+i]).get_Valor_Carta()))
            return {(copiaCartas[0+i].get_Valor_Carta()), true};
    }
    return {0, false};
}

std::pair<int, bool> Mao::is_Straight_Flush()
{
    std::vector<Carta> copiaCartas = cartas;
    std::sort(copiaCartas.begin(), copiaCartas.end(), compare_Naipe);

    for (int i = 0; i < copiaCartas.size() - 4; i++)
    {
        if((copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[1+i]).get_Valor_Carta() - 1) && (copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[2+i]).get_Valor_Carta() - 2) && (copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[3+i]).get_Valor_Carta() - 3) && (copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[4+i]).get_Valor_Carta() - 4))
            if((copiaCartas[0+i].get_Naipe()) == (copiaCartas[1+i].get_Naipe()) && (copiaCartas[0+i].get_Naipe()) == (copiaCartas[2+i].get_Naipe()) && (copiaCartas[0+i].get_Naipe()) == (copiaCartas[3+i].get_Naipe()) && (copiaCartas[0+i].get_Naipe()) == (copiaCartas[4+i].get_Naipe()))
                return {(copiaCartas[0+i].get_Valor_Carta()), true};
    }
    return {0, false};
}

std::pair<int, bool> Mao::is_Royal_Flush()
{   

    std::vector<Carta> copiaCartas = cartas;
    std::sort(copiaCartas.begin(), copiaCartas.end(), compare_Naipe);
    for (int i = 0; i < copiaCartas.size() - 4; i++)
    {
        if((copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[1+i]).get_Valor_Carta() - 1) && 
        (copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[2+i]).get_Valor_Carta() - 2) && 
        (copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[3+i]).get_Valor_Carta() - 3) && 
        (copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[4+i]).get_Valor_Carta() - 4))
            if((copiaCartas[0+i].get_Naipe()) == (copiaCartas[1+i].get_Naipe()) && 
            (copiaCartas[0+i].get_Naipe()) == (copiaCartas[2+i].get_Naipe()) && 
            (copiaCartas[0+i].get_Naipe()) == (copiaCartas[3+i].get_Naipe()) && 
            (copiaCartas[0+i].get_Naipe()) == (copiaCartas[4+i].get_Naipe()))
                if((copiaCartas[0+i].get_Valor_Carta() == 10))
                {
                    return {(copiaCartas[0+i].get_Valor_Carta()), true};
                }
    }
    return {0, false};
    
}

void Mao::adicionar_Carta(Carta carta) 
{
    cartas.push_back(carta);
}

