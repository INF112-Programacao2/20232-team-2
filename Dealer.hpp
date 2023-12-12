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
    int valor_Acumulado_mesa;
    int check;
    bool partidaFinalizada;
    int small_blind_apostou;
public:
    //Construtor
    Dealer();
    
    //Destrutor
    ~Dealer();

    //Retorna o baralho
    std::vector<Carta> get_baralho();

    //Retorna a mesa
    std::vector<Carta> get_mesa();

    //Retorna os jogadores
    std::vector<Jogador> get_jogadores();

    //get do valor atual da aposta
    int get_Valor_Mesa();

    //get do primeiro jogador
    int get_Primeiro_Jogador();

    //set para atualizar o valor da aposta
    void set_Valor_Mesa(int valor);

    //set para atualizar o valor acumulado da mesa
    void set_Valor_Acumulado_Mesa(int valorAtualMesa);

    //Alterar o id do primeiro jogador
    void set_Primeiro_Jogador(int id_Jogador);

    //Alterar o valor da primeira aposta(Small Blind) -> Será útil mais a frente para aumentar o valor mínimo da aposta após cada partida
    void set_Primeira_Aposta(int primeira_Aposta);
    
    //Designar o Small blind
    void designar_Small_Blind();

    //Designar o big blind
    void designar_Big_Blind();

    //Designar primeiro jogador
    void designar_Primeiro_Jogador();

    //Iniciar partida
    void iniciar_Partida();

    //Criar a sala da partida
    void criar_Sala();

    //Criar um baralho
    void criar_Baralho();

    //criar as cartas da mesa   
    void criar_Mesa();
    
    //Embaralhar as cartas para inicar o jogo
    void embaralhar_Cartas();

    //Distribuir as cartas aos jogadores da partida
    void dar_Cartas();

    //Passa a vez para o proximo jogador ativo
    void passar_Vez();

    //Verificar se todos os jogadores já cobriram a aposta mais alta da mesa
    bool verificar_Check();
    
    //Verifica cada rodada e garante que tudo corre como deveria
    void verificar_Rodadas();

    //Mostrar cartas de acordo com a rodada
    void mostrar_Cartas(int quantidade_Cartas_Mostradas, std::vector<Carta> vetor);

    //Finaliza a partida atual e reseta alguns dados
    void finalizar_Partida();

};

#endif

