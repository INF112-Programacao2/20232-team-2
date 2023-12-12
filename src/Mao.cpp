#include <vector>
#include "Mao.hpp"
#include "Carta.hpp"
#include <algorithm>

Mao::Mao() {}

Mao::~Mao() {}

bool Mao::compare_Valor_Cartas(Carta &carta1, Carta &carta2)
{

    //método que acompanha a função sort da biblioteca algorithm. Organiza o vetor cartas pelo valor 
    return carta1.get_Valor_Carta() < carta2.get_Valor_Carta();
}

bool Mao::compare_Naipe(Carta &carta1, Carta &carta2)
{

    //método que acompanha a função sort da biblioteca algorithm. Organiza o vetor cartas pelo naipe, e se o naipe for igual, ordena por valor da carta
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
    
    // Atribui um valor à mão, de cima pra baixo
    // Caso nenhuma pontuação especial aconteça, a maior carta [2,14] é a pontuação
    if(is_Royal_Flush())         return 100;
    else if(is_Straight_Flush().second) return 90;
    else if (is_Quadra().second)        return 80;
    else if (is_Full_House().second)    return 70;
    else if (is_Flush())                return 60;
    else if (is_Straight().second)      return 50;
    else if (is_Trinca().second)        return 40;      
    else if (is_Dois_Pares().second)    return 30;
    else if (is_Par().second)           return 20;
    else 
    {
        std::sort(cartas.begin(), cartas.end(), compare_Valor_Cartas); 
        return cartas.back().get_Valor_Carta();
    }
}

std::pair<int,bool> Mao::is_Par()
{
    //Método que verifica se as cartas da mao do jogador + as da mesa formam um par
    //É utilizado uma copia de um vector para nao "desorganizar" o vector original
    //Retorna um pair contendo o valor do par e caso possua par
    std::vector<Carta> copiaCartas = cartas;
    std::sort(copiaCartas.begin(), copiaCartas.end(), compare_Valor_Cartas);
    for (int i = 0; i < copiaCartas.size()-1; i++)
    {
        if((copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[1+i]).get_Valor_Carta()))
            return {(copiaCartas[0+i].get_Valor_Carta()), true};
    }
    return {0, false};
}

std::pair<std::pair<int, int>, bool> Mao::is_Dois_Pares()
{
    //Método que verifica se as cartas da mao do jogador + as da mesa formam dois pares distintos
    //É utilizado uma copia de um vector para nao "desorganizar" o vector original
    //Retorna um pair contendo outro pair. O pair interno contem os valores de cada par, e .second do pair externo um bool caso existam 2 pares distintos
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
    //Método que verifica se as cartas da mao do jogador + as da mesa formam uma trinca
    //É utilizado uma copia de um vector para nao "desorganizar" o vector original
    //Retorna um pair contendo o valor da trinca e caso possua uma trinca
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
    //Método que verifica se as cartas da mao do jogador + as da mesa formam um straight
    //É utilizado uma copia de um vector para nao "desorganizar" o vector original
    //Retorna um pair contendo o valor da posição incial do straight e caso possua de fato um straight
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
    //Método que verifica se as cartas da mao do jogador + as da mesa formar um flush
    //É utilizado uma copia de um vector para nao "desorganizar" o vector original
    //Retorna um bool que contém o resultado da verificação
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
    //Método que verifica se as cartas da mao do jogador + as da mesa formar um par e uma trinca distintos
    //É utilizado uma copia de um vector para nao "desorganizar" o vector original
    //Retorna um pair contendo outro pair. O pair interno contem os valores do par e da trinca, e .second do pair externo um bool caso existam um par e uma trinca distintos
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
    //Método que verifica se as cartas da mao do jogador + as da mesa formam uma quadra
    //É utilizado uma copia de um vector para nao "desorganizar" o vector original
    //Retorna um pair contendo o valor da quadra e caso possua uma quadra
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
    //Método que verifica se as cartas da mao do jogador + as da mesa formam um straight flush
    //É utilizado uma copia de um vector para nao "desorganizar" o vector original
    //Retorna um pair contendo o valor do straight flush, e um bool que indica se ha de fato um straight flush
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

bool Mao::is_Royal_Flush()
{   
    //Método que verifica se as cartas da mao do jogador + as da mesa formam um royal flush
    //É utilizado uma copia de um vector para nao "desorganizar" o vector original
    //Retorna um bool que contém o resultado da verificação
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
                    return true;
                }
    }
    return false;
    
}

void Mao::adicionar_Carta(Carta carta) 
{
    cartas.push_back(carta);
}

