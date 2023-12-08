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

void Dealer::darCartas()
{

}

void Dealer::criarMesa()
{
    mesa = new std::vector<Carta>;
}

void Dealer::designarSmallBlind()
{

}

void Dealer::designarBigBlind()
{

}