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
    int rodada;
    int quantidadeJogadores;
    int valorMesa;
    int primeiro_Jogador;
    int primeira_Aposta;
    int check;

public:
    //Construtor
    Dealer();
    
    //Destrutor
    ~Dealer();

    //get do valor atual da aposta
    int getValorMesa();

    //get do primeiro jogador
    int get_Primeiro_Jogador();

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

    //Designar primeiro jogador
    void designarPrimeiroJogador();

    //Verificar se todos os jogadores já cobriram a aposta mais alta da mesa
    bool verificar_Check();

    //
    void verificar_Rodadas();

    //Mostrar cartas de acordo com a rodada
    void mostrarCartas(int quantidade_Cartas_Mostradas);

    //Alterar o id do primeiro jogador
    void set_Primeiro_Jogador(int id_Jogador);

    //Alterar o valor da primeira aposta(Small Blind) -> Será útil mais a frente para aumentar o valor mínimo da aposta após cada partida
    void set_Primeira_Aposta(int primeira_Aposta);

    //Retorna o baralho
    std::vector<Carta> get_baralho();

    //Retorna a mesa
    std::vector<Carta> get_mesa();

    //Retorna os jogadores
    std::vector<Jogador> get_jogadores();
};

#endif

