#ifndef CARTA_H
#define CARTA_H
#include <vector>
#include <iostream>

class Carta
{
   private:
      int valorCarta; // Varia de 2 a 14; 11 é valete, 12 é dama, 13 é rei, e 14 é ás
      std::string naipe; // Ouros, Espadas, Copas ou Paus
   public:
      static std::string naipes_possiveis[4];
      Carta(int valorCarta, std::string naipe);
      ~Carta();

      //Retornar o valor das cartas
      int get_Valor_Carta();

      //Retornar o naipe das cartas
      std::string get_Naipe();
};



#endif