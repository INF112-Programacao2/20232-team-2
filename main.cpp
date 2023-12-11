#include <iostream>
#include <vector>
#include "Dealer.hpp"
#include "Jogador.hpp"
#include "Carta.hpp"
#include "Mao.hpp"


int main()
{
   Dealer ricardo;

   std::system("clear");

   



   //mostrar big bling e small blind
   /*
   for (int i = 0; i < ricardo.get_jogadores().size(); i++)
   {
      if(ricardo.get_jogadores()[i].isTrue_Big_Blind())
         std::cout << ricardo.get_jogadores()[i].get_Nick() << "\n";
   }
   for (int i = 0; i < ricardo.get_jogadores().size(); i++)
   {
      if(ricardo.get_jogadores()[i].isTrue_Small_Blind())
         std::cout << ricardo.get_jogadores()[i].get_Nick() << "\n";
   }*/

   //teste dealer

   /*for (int i = 0; i < ricardo.get_baralho().size(); i++)
   {
      std::cout << ricardo.get_baralho()[i].get_Valor_Carta() << ' ' << ricardo.get_baralho()[i].get_Naipe() << "\n";
   }

   std::cout << "\n";

   for (int i = 0; i < ricardo.get_mesa().size(); i++)
   {
      std::cout << ricardo.get_mesa()[i].get_Valor_Carta() << ' ' << ricardo.get_mesa()[i].get_Naipe() << "\n";
   }*/
   
   //teste jogador

   /*int a = 100;
   Jogador C("Coshe");
   C.exibirInfo(a);
   C.apostar(a);
   C.exibirInfo(a);
   */

   return 0;
}