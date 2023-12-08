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
    std::vector<Carta> *baralho; 
    std::vector<Carta> *mesa;
    std::vector<Jogador> *jogadores;
    int posicao;
    int quantidadeJogadores;

public:
    //Construtor
    Dealer();
    
    //Destrutor
    ~Dealer();

    //Criar a sala da partida
    void criarSala();

    //Criar um baralho
    void criarBaralho();
    
    //Embaralhar as cartas para inicar o jogo
    void embaralharCartas();

    //Distribuir as cartas aos jogadores da partida
    void darCartas();     

    //criar as cartas da mesa   
    void criarMesa();

    //Designar o Small blind
    void designarSmallBlind();

    //Designar o big blind
    void designarBigBlind();
};

#endif

