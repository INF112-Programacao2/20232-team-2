#ifndef DEALER_H
#define DEALER_H

#include <iostream>
#include <ctime>
#include <vector>
#include <list>
#include <algorithm>
#include "Carta.hpp"
#include "Jogador.hpp"

class Dealer
{
private:
    std::list<Carta>; 
    std::vector<Carta> *mesa;
    std::vector<Jogador> *jogadores;
    int posicao;
    int jogadorAtual;
    int jogadorAnterior;
    int jogadorProximo;

public:
    //Construtor
    Dealer();
    
    //Destrutor
    ~Dealer();

    //Criar um baralho
    void criarBaralho();
    
    //Embaralhar as cartas para inicar o jogo
    void embaralharCartas(std::vector<Carta>& cartas);


};
#endif

Dealer::Dealer()
{
}

Dealer::~Dealer()
{
}

