#include <vector>
#include "Mao.hpp"
#include "Carta.hpp"

Mao::Mao() {}

Mao::~Mao() {}

std::vector<Carta> Mao::getCartas() 
{ 
    return cartas; 
}

void Mao::adicionarCarta(Carta carta) 
{
    cartas.push_back(carta);
}

bool Mao::is_CartaMenor(int index) 
{
    if (index >= cartas.size()) 
    {
        return true;
    }

    if (cartas[index].get_Valor_Carta() < 2 || cartas[index].get_Valor_Carta() > 14) 
    {
        return false;
    }

    return is_CartaMenor(index + 1);
}

bool Mao::is_Pair()
{
    for (int i = 0; i < cartas.size() - 1; i++) {
    if (cartas[i].get_Valor_Carta() != cartas[i + 1].get_Valor_Carta()) 
    {
        return false;
    }
    }
    return true;
} 

bool Mao::is_Dobro()
{
    for (int i = 0; i < cartas.size() - 1; i++) {
        if (cartas[i].get_Valor_Carta() != cartas[i + 1].get_Valor_Carta() - 1) 
        {
            return false;
        }
    }
    return true;    
}

bool Mao::is_Sequencia()
{
    for (int i = 0; i < cartas.size() - 2; i++) 
    {
        if (cartas[i].get_Valor_Carta() != cartas[i + 1].get_Valor_Carta() - 1 || cartas[i].get_Valor_Carta() != cartas[i + 2].get_Valor_Carta() - 2) 
        {
            return false;
        }
    }
    return true;
}

bool Mao::is_Trinca()
{
    for (int i = 0; i < cartas.size() - 2; i++) {
        if (cartas[i].get_Valor_Carta() == cartas[i + 1].get_Valor_Carta() && cartas[i].get_Valor_Carta() == cartas[i + 2].get_Valor_Carta()) 
        {
            return true;
        }
    }
    return false;
}

bool Mao::is_StraightFlush()
{
    //implementar aqui
}

bool Mao::is_Flush()
{
    //implementar aqui
}

bool Mao::is_FullHouse()
{
    //implementar aqui
}

bool Mao::is_Quatro()
{
    //implementar aqui
}

bool Mao::is_Straight()
{
    //implementar aqui
}

bool Mao::is_TrincaFlush()
{
    //implementar aqui
}

bool Mao::is_DoisPares()
{
    //implementar aqui
}

int Mao::valorMao()
{
    //implementar aqui
}