#include <iostream>
#include <vector>
#include "Carta.hpp"
#include "Mao.hpp"
#include "Jogador.hpp"
#include "Dealer.hpp"


int main()
{
   Dealer ricardo;
   ricardo.iniciar_Partida();




//main Dealer
/*
int main()
{
    Dealer dealer;
    dealer.set_Primeiro_Jogador(2);
    dealer.get_jogadores().at(2).set_Ativo(false);
    std::cout << dealer.get_jogadores().at(dealer.get_Primeiro_Jogador()).is_True_Ativo() << "\n\n";
    
    dealer.designar_Primeiro_Jogador(); // Call the function to assign the first player
    
    //Entrada 3 jogadores e nome aleatórios
    //Saída esperada: 0     problema: Quando declaramos o primeiro_Jogador manualmente, caso para teste, a função designar_Primeiro_Jogador não está sendo chamada
    //De acordo com os testes que venho fazendo, parece que o bug está no condicional do primeiro "else if"
    std::cout << dealer.get_Primeiro_Jogador()<< "\n\n";
    return 0;
}
*/
//Observação: Nos testes a função designar Primeiro Jogador não está sendo executada



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