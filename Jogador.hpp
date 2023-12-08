#ifndef JOGADOR_HPP
#define JOGADOR_HPP
#include <iostream>
#include <vector>
#include "Carta.hpp"
#include "Mao.hpp"

class Jogador
{
   private:
      //Nome do jogador
      const std::string nome; 
      
      //Individualizar  cada jogador
      const std::string CPF;  
      
      //Mão composta por 2 cartas
      Mao mao; 
      
      //Vetor de pairs relativos ao valor da ficha bem como suas quantidades
      //Valores já pré estabelecidos {1, 5, 10, 20, 50, 100, 1000} -> Limitaremos o valor em mil para evitar vícios
      std::vector<std::pair<int,int>> Fichas; 

      // Verifica se está na vez do jogador x
      bool Vez; 

      // Verifica se o jogador está na rodada ou se desistiu da rodada
      bool Ativo; 

      // Verifica se o jogador cobriu o valor proposto por outro jogador
      bool Cobriu; 

      // Verificar se o tipo do jogador é Big Blind
      bool Big_Blind; 

      // Verificar se o tipo do jogador é Small Blind
      bool Small_Blind; 

   public:
      //Construtor
      Jogador(std::string nome, Mao mao);
      
      //Destrutor
      ~Jogador();

      //Métodos get e isTrue para acesso aos atributos de Jogador

      //Nome do jogador
      const std::string get_Nome();

      //Receber cartas
      void receberCarta(Carta carta);
      
      //Só poderá ser chamado pelo Dealer na última rodada
      Mao get_Mao();

      //Verifica se é a vez do jogador
      bool isTrue_Vez();
      
      //Retornar o status do jogador(ativo ou inativo -> PS: Acredito que melhoraremos a qualidade do código se Criarmos os jogadores como objetos dinâmicos e sempre removê-los da memória após desistirem, mantendo seus dados em um arquivo)
      bool isTrue_Ativo();
     
      //Identificar se o jogador deu check com a aposta atual
      bool isTrue_Cobriu();

      //Definir se esse jogador será ou não um big blind
      bool isTrue_Big_Blind();

      //Definir se esse jogador será ou não um small blind
      bool isTrue_Small_Blind();

      //Métodos de controle da classe
      
      //Verificar se o jogador concorda em aceitar o atual valor da aposta
      void Check();
      
      //Verificar se o jogador desiste da rodada
      void Desistir();
      
      //Verificar se o jogador quer apostar
      void Apostar();

      //Igualar a aposta ao valor da mesa
      void Igualar();
      
      //Aumentar o valor da aposta atual
      void Aumentar();

      //Essa eu não entendi muito bem
      void ExibirInfo();
};

#endif