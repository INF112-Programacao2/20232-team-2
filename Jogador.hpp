#include "Carta.hpp"
#include <vector>

struct Mao
{
   Carta Carta1;
   Carta Carta2;
};


class Jogador
{
   protected:
      char *Nome; // nome do jogador
      Mao Mao; // mao composta por 2 cartas
      std::vector<std::pair<int,int>> Fichas; // Quantas fichas de qual tipo de ficha; exemplo: 20 fichas de 10, 5 fichas de 100.
      bool Vez; // Verifica se está na vez do jogador x
      bool Ativo; // Verifica se o jogador está na rodada ou se desistiu da rodada
      bool Cobriu; // Verifica se o jogador cobriu o valor proposto por outro jogador
      bool Big_Blind; // Jogador é ou nao é big blind
      bool Small_Blind; // Jogador é ou nao é small blind

   public:
      void Check();
      void Apostar();
      void Igualar();
      void Desistir();
      void Aumentar();
      void ExibirInfo();

};