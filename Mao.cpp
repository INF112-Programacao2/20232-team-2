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

int Mao::CartaAlta()
{
    int maior = 0;
    for (int i = 0; i < cartas.size(); i++)
    {
        if(cartas[i].get_Valor_Carta() > maior)
        {
            maior = cartas[i].get_Valor_Carta();
        }
    }
    return maior;
}

//A maioria dos metodos abaixo so funcionarão caso o vetor cartas esteja em ordem crescente pelo valor da carta
//A maioria dos metodos abaixo so funcionarão caso o vetor cartas tenha 5 cartas apenas. A realidade costuma ter 7

std::pair<int,bool> Mao::is_Par()
{
    for (int i = 0; i < cartas.size() - 1; i++) 
    {
        if (cartas[i].get_Valor_Carta() == cartas[i + 1].get_Valor_Carta()) 
        {
            return {cartas[i].get_Valor_Carta(), true};
        }
    }
    return {0, false};
}

bool Mao::is_DoisPares()
{
    //implementar aqui
}

std::pair<int,bool> Mao::is_Trinca()
{
    for (int i = 0; i < cartas.size() - 2; i++) 
    {
        if (cartas[i].get_Valor_Carta() == cartas[i + 1].get_Valor_Carta() && cartas[i].get_Valor_Carta() == cartas[i + 2].get_Valor_Carta()) 
        {
            return {cartas[i].get_Valor_Carta(),true};
        }
    }
    return {0,false};
}

std::pair<int,bool> Mao::is_Straight()
{
    for (int i = 1; i < cartas.size(); i++)
    {
        if(cartas[i].get_Valor_Carta() != cartas[i-1].get_Valor_Carta() + 1)
        {
            return {0, false};
        }
    }
    return {cartas[0].get_Valor_Carta, true};
}

bool Mao::is_Flush()
{
    //Função para descobrir se as cartas do objeto Mao formam um flush
    for (int i = 1; i < cartas.size(); i++)
    {
        if (cartas[0].get_Naipe().compare(cartas[i].get_Naipe()) != 0)
        {
            return false;
        }
    }
    return true;
}

bool Mao::is_FullHouse()
{
    //Função para descobrir se as cartas do objeto Mao formam um FullHouse
    for (int i = 0; i < cartas.size(); i++)
    {
        if (cartas[i].get_Valor_Carta() == 
        cartas[i + 1].get_Valor_Carta() && 
        cartas[i].get_Valor_Carta() == 
        cartas[i + 2].get_Valor_Carta())
        {
            return true;
        }
    }
    return false;
}

std::pair<int,bool> Mao::is_Quadra()
{
    for (int i = 0; i < cartas.size() - 3; i++) 
    {
        if (cartas[i].get_Valor_Carta() == cartas[i + 1].get_Valor_Carta() && cartas[i].get_Valor_Carta() == cartas[i + 2].get_Valor_Carta() && cartas[i].get_Valor_Carta() == cartas[i + 3].get_Valor_Carta()) 
        {
            return {cartas[i].get_Valor_Carta(),true};
        }
    }
    return {0,false};
}

std::pair<int,bool> Mao::is_StraightFlush()
{
    // Parte flush
    for (int i = 1; i < cartas.size(); i++)
    {
        if (cartas[0].get_Naipe().compare(cartas[i].get_Naipe()) != 0)
        {
            return {0, false};
        }
    }
    
    //Parte Straight
    for (int i = 1; i < cartas.size(); i++)
    {
        if(cartas[i].get_Valor_Carta() != cartas[i-1].get_Valor_Carta() + 1)
        {
            return {0, false};
        }
    }
    return {cartas[0].get_Valor_Carta, true};

}

bool Mao::is_RoyalFlush()
{
    if(cartas[0] != 10)
    {
        return false;
    }
    // Parte flush
    for (int i = 1; i < cartas.size(); i++)
    {
        if (cartas[0].get_Naipe().compare(cartas[i].get_Naipe()) != 0)
        {
            return false;
        }
    }
    
    //Parte Straight
    for (int i = 1; i < cartas.size(); i++)
    {
        if(cartas[i].get_Valor_Carta() != cartas[i-1].get_Valor_Carta() + 1)
        {
            return false;
        }
    }

    return true;
}

bool Mao::is_TrincaFlush()
{
    //implementar aqui
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

int Mao::valorMao()
{
    //implementar aqui
}