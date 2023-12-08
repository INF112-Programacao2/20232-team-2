#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "Dealer.hpp"
#include "Jogador.hpp"
#include "Carta.hpp"

Dealer::Dealer() 
{
    criarBaralho();
    criarSala();
    darCartas();
    criarMesa();
}

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
    int big = rand()%jogadores.size();
    jogadores[big].set_big_blind(true);
    for (int i = 0; i < jogadores.size(); i++)
    {
        if(big == jogadores.size()-1)
        {
            jogadores[0].set_small_blind(true);
        }
        else
        {
            jogadores[big+1].set_small_blind(true);
        }
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
    embaralharCartas();
    for (int i = 0; i < 5; i++)
    {   
        mesa.push_back(baralho.back());
        baralho.pop_back();
    }
    for (int i = 0; i < 2; i++)
    {
        baralho.pop_back();
        mesa.push_back(baralho.back());
    }
}

void Dealer::designarSmallBlind()
{
    for (int i = 0; i < jogadores.size(); i++)
    {
        if(jogadores[i].isTrue_Small_Blind())
        {
            jogadores[i].set_small_blind(false);
            if(i == jogadores.size()-1)
            {
                jogadores[0].set_small_blind(true);
            }
            else
            {
                jogadores[i].set_small_blind(true);
            }
        }
    }
}

void Dealer::designarBigBlind()
{
    for (int i = 0; i < jogadores.size(); i++)
    {
        if(jogadores[i].isTrue_Big_Blind())
        {
            jogadores[i].set_big_blind(false);
            if(i == jogadores.size()-1)
            {
                jogadores[0].set_big_blind(true);
            }
            else
            {
                jogadores[i].set_big_blind(true);
            }
        }
    }
}