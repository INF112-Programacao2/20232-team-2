#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "Dealer.hpp"
#include "Jogador.hpp"
#include "Carta.hpp"

Dealer::Dealer() {}

Dealer::~Dealer() {}

void Dealer::criarSala()
{
    std::cout << "Digite a quantidade de jogadores da partida: " << std::endl;
    std::cin >> quantidadeJogadores;
    for (int i = 1; i <= quantidadeJogadores; i++)
    {
        std::string nick;
        std::cout << "Apelido do jogador " << i << ": ";
        std::cin >> nick;
        Jogador temporario(nick);
        jogadores.push_back(temporario);
    }
}

void Dealer::criarBaralho()
{
    for (int i = 2; i <= 14; i++) {
        for (int j = 0; j < 4; j++) {
            baralho.push_back(Carta(i, Carta::naipes_possiveis[j]));
        }
    }
    embaralharCartas();
}

void Dealer::embaralharCartas() 
{
    srand(time(NULL));
    std::random_shuffle(baralho.begin(), baralho.end());
}

void Dealer::darCartas()
{
    for (int i = 0; i < quantidadeJogadores; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            jogadores[i].receberCarta(baralho.back());
            baralho.pop_back();
        }
    }
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