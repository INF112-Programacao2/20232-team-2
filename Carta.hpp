#ifndef CARTA_H
#define CARTA_H
#include <vector>

class Carta
{
   private:
      //Ordenação do valor de cada carta no jogo, variando de 2 a 13 => "Ás" pode se comportar como 1 ou 14
      int valorCarta; 

      //Ouros(O), Espadas(E), Copas(C) ou Paus(P)
      char naipe;

   public:
      //Construtor das cartas 
      Carta(int valorCarta, char Naipe);

      //Destrutor das cartas
      ~Carta();

      //Retornar o valor das cartas
      int get_Valor_Carta();

      //Retornar o naipe 
      char get_Naipe();
};

#endif