#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "Dealer.hpp"
#include "Jogador.hpp"

Dealer::Dealer() 
{

}

Dealer::~Dealer() {}

void Dealer::criarSala()
{
    std::cout << "Digite a quantidade de jogadores da partida: " << std::endl;
    std::cin >> quantidadeJogadores;
    jogadores = new Jogador*[quantidadeJogadores];
}

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
    for (int i = 0; i < quantidadeJogadores; i++) 
    {
        std::cout << "Digite o nome do jogador " << i+1 << std::endl;
        std::string nome;
        std::cin >> nome;
        Jogador *jogador = new Jogador(nome);
        //baralho->back();
        jogadores.push_back(jogador);
    }
    for (int i = 0; i < quantidadeJogadores; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            jogadores[i].receberCarta(baralho->back());
            baralho->pop_back();
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