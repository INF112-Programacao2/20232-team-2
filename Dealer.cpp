#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "Dealer.hpp"

Dealer::Dealer() {}

Dealer::~Dealer() {}

void Dealer::criarBaralho()
{

}

void Dealer::embaralharCartas() 
{
    srand(time(NULL));
    std::random_shuffle(baralho->begin(), baralho->end());
}

void Dealer::set_QuantidaDeJogadores(int quantidade)
{
    this->quantidadeJogadores = quantidade;
}

void Dealer::darCartas()
{

}

void Dealer::criarMesa()
{
    mesa = new std::vector<Carta>;
    for (int i = 0; i < 5; i++)
    {   
        mesa->push_back(baralho->at(i));
    }

}

void Dealer::designarSmallBlind()
{

}

void Dealer::designarBigBlind()
{

}