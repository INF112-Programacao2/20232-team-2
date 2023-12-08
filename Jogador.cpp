#include "Jogador.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>
#include "Carta.hpp"
#include "Mao.hpp"

Carta *carta1 = new Carta(3,'O');
Carta *carta2 = new Carta(4,'P');
std::vector<Carta> cartas = {carta1, carta2};


Jogador::Jogador(std::string nome) : nome(nome)
{

   ativo = true;
   vez  = cobriu = small_Blind = big_Blind = false;
   mao = new Mao(cartas);
   /*Fichas.push_back({8, 25}); // 8 de 25, 8 de 100, 4 de 500, 2 de 1000, 1 de 5000
   Fichas.push_back({8, 100});
   Fichas.push_back({4, 500});
   Fichas.push_back({2, 1000});
   Fichas.push_back({1, 5000});*/
}

Jogador::~Jogador()
{

}

/*void Jogador::receberCarta(Carta carta)
{
   mao.adicionarCarta(carta);
}*/

void Jogador::check(int &valorMesa)
{
   if (valorMesa == apostado && vez)
   {
      cobriu = true;
   }

   else 
   {
      std::cout << "Você não pode selecionar essa opção até que o valor da sua aposta seja maior ou igual ao atual valor da mesa\n";
   }
}

void Jogador::apostar(int &valorMesa)
{

   //Ainda falta implementar a forma com que o usuário escolherá as fichas que serão apostadas
   try
   {
      std::cout << "Digite o valor que deseja apostar";
      int aposta;
      std::cin >> aposta;
      if (aposta < valorMesa && saldo > valorMesa) throw std::invalid_argument("Aposta insuficiente, por favor, aumente ela");   
      else if (aposta >= valorMesa && saldo <= valorMesa) 
      {
         bool confirma = false;
         std::cout << "Seu saldo é menor ou igual ao valor da mesa, deseja entrar no modo all in?\n";
         std::cin >> confirma;
         //criar a classe de exceção All_in
         //if(confirma)   throw all_in("Agora você está no modo All in");
      }

      saldo -= aposta;
   }
   catch(const std::invalid_argument& e)
   {
      std::cerr << e.what() << '\n';
   }
   /*catch(const All_inn& e)
   {
      all_in = true;
      std::cerr << e.what() << '\n';
   }*/


}

void Jogador::igualar()
{

}

void Jogador::desistir()
{
   std::cout << "Realmente deseja desistir? digite SIM para confirma\n";
   std::string confirmacao;
   std::cin >> confirmacao;
   if(confirmacao.compare("SIM") == 0) ativo = false;
}

//Acredito que não valha a pena separar os métodos apostar, aumentar e igualar
void Jogador::aumentar()
{

}

void Jogador::exibirInfo()
{
   std::cout << "\nNome: " << nome << "\n";
   std::cout << "\nFichas:\n";
   for (int i = 0; i < 5; i++)
   {
      
      std::cout << "De " << Fichas[i].first << " : " << Fichas[i].second << "\n";
   }
}

void Jogador::comprarFichas()
{
   std::cout << "\nConversão Real-Fichas: 1 Real -> 250 fichas\n";
   std::cout << "Quantos reais (numero inteiro) deseja inserir?: ";
   unsigned int adicionar;
   std::cin >> adicionar;
   Injetar *= 250;
   while (Injetar >= 5000) Fichas[4].second ++;
   while (Injetar >= 1000) Fichas[3].second ++;
   while (Injetar >= 500) Fichas[2].second ++;
   while (Injetar >= 100) Fichas[1].second ++;
   while (Injetar >= 25) Fichas[0].second ++;
}


int main()
{
   Jogador *jogador1 = new Jogador("Carlos");
}