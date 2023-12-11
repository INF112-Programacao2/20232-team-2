#ifndef DEALER_H
#define DEALER_H

#include <iostream>
#include <ctime>
#include <vector>
#include <list>
#include <algorithm>
#include "Carta.hpp"
#include "Jogador.hpp"
#include "Usuario.hpp"



class Dealer
{
private:
    std::vector<Carta> baralho; 
    std::vector<Carta> mesa;
    std::vector<Jogador> jogadores;
    int posicao;
    int quantidadeJogadores;
    int valorMesa;

public:
    //Construtor
    Dealer();
    
    //Destrutor
    ~Dealer();

    //get do valor atual da aposta
    int getValorMesa();

    //set para atualizar o valor da aposta
    void setValorMesa(int valor);

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

    std::vector<Carta> get_baralho();

    std::vector<Carta> get_mesa();
};

#endif

