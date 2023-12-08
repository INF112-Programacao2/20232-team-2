#ifndef JOGADOR_HPP
#define JOGADOR_HPP
#include <iostream>
#include <vector>
#include "Carta.hpp"
#include "Mao.hpp"

class Jogador
{
   private:
      const std::string nome; // nome do jogador
      const std::string CPF;
      Mao mao; // mao composta por 2 cartas
      std::vector<std::pair<int,int>> Fichas; // Quantas fichas de qual tipo de ficha; exemplo: 20 fichas de 10, 5 fichas de 100.
      bool Vez; // Verifica se está na vez do jogador x
      bool Ativo; // Verifica se o jogador está na rodada ou se desistiu da rodada
      bool Cobriu; // Verifica se o jogador cobriu o valor proposto por outro jogador
      bool Big_Blind; // Jogador é ou nao é big blind
      bool Small_Blind; // Jogador é ou nao é small blind

   public:
      //Construtor
      Jogador(std::string nome, Mao mao);
      //Métodos get para acesso aos atributos de Jogador
      const std::string get_Nome();
      Mao get_Mao();
      bool isTrue_Vez();
      bool isTrue_Ativo();
      bool isTrue_Cobriu();
      bool isTrue_Big_Blind();
      bool isTrue_Small_Blind();

      //Métodos de controle da classe 
      void Check();
      void Apostar();
      void Igualar();
      void Desistir();
      void Aumentar();
      void ExibirInfo();
};

#endif