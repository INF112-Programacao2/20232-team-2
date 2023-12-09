#include "Jogador.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>
#include "Carta.hpp"
#include "Mao.hpp"

Jogador::Jogador(std::string nick)
{
   nickname = nick;
   ativo = true;
   vez  = cobriu = ativo = small_Blind = big_Blind = false;
   //mao = new Mao(cartas);
   fichas.push_back({5, 10});// 8 de 25, 8 de 100, 4 de 500, 2 de 1000, 1 de 5000
   fichas.push_back({10, 5});
   fichas.push_back({20, 5});
   fichas.push_back({50, 2});
   fichas.push_back({100, 2});
   fichas.push_back({500, 1});
}

Jogador::~Jogador()
{

}

void Jogador::receberCarta(Carta carta)
{
   mao->adicionarCarta(carta);
}

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
   //Falta implementar tratamento de exceçoes
   while(true)
   {
      std::cout << "Seu saldo é: " << saldo  << "\nO valor da mesa é: " << valorMesa << "\nDigite o valor que deseja apostar (aposte tudo para entrar em all in):";
      int aposta;
      std::cin >> aposta;
      if(aposta > saldo)
      {
         apostado += aposta;
         saldo -= aposta;
      }
      else if(aposta == saldo)
      {
         std::cout << "Seu saldo se esgotou, com essa aposta voce entrará em modo all in. Deseja prosseguir? digite SIM para confirmar\n";
         std::string confirmacao;
         std::cin >> confirmacao;
         if(confirmacao.compare("SIM") == 0)
         {
            all_in = true;
            saldo  = 0;
         }
      }
      else
      {
         std::cout << "Saldo insuficiente, aposte um valor mais baixo\n";
      }

      if (apostado < valorMesa && !all_in)
      {
         std::cout << "Aposta insuficiente, por favor, aumente ela\n"; //throw std::invalid_argument("Aposta insuficiente, por favor, aumente ela");
      }
      else
      {
           break;
      }
   }

   /*catch(const std::invalid_argument& e)
   {
      std::cerr << e.what() << '\n';
   }
   catch(const All_inn& e)
   {
      all_in = true;
      std::cerr << e.what() << '\n';
   }*/
}

void Jogador::desistir()
{
   std::cout << "Realmente deseja desistir? digite SIM para confirmar\n";
   std::string confirmacao;
   std::cin >> confirmacao;
   if(confirmacao.compare("SIM") == 0) ativo = false;
}

void Jogador::exibirInfo(int ValorMesa)
{
   std::cout << "\nNickname: " << nickname << "\n";
   for (int i = 0; i < 5; i++)
   {
      
      std::cout << "Fichas de " << fichas[i].first << " : " << fichas[i].second << "\n";
   }
   std::cout << "\n";
   if(cobriu)
   {
      std::cout << "Você já cobriu o valor da aposta (" << ValorMesa << ") mais alta da mesa\n";
   }
   else
   {
      std::cout << "Você ainda não cobriu o valor da aposta (" << ValorMesa << ") mais alta da mesa\n";
      std::cout << "Voce já apostou " << apostado << "nessa rodada\n";
   }
   if(small_Blind)
   {
      std::cout << "Você é o small blind nessa rodada\n";
   }
   if(big_Blind)
   {
      std::cout << "Você é o big blind nessa rodada\n";
   }
}

Mao Jogador::get_Mao()
{ 
   return *mao;
}

bool Jogador::isTrue_Vez()
{
   return vez;
}
      
bool Jogador::isTrue_Ativo()
{
   return ativo;
}
     
bool Jogador::isTrue_Cobriu()
{
   return cobriu;
}

bool Jogador::isTrue_Big_Blind()
{
   return big_Blind;
}

bool Jogador::isTrue_Small_Blind()
{
   return small_Blind;
}

void Jogador::set_small_blind(bool small)
{
   small_Blind = small;
}

void Jogador::set_big_blind(bool big)
{
   big_Blind = big;
}

/*void Jogador::comprarFichas()
{
   std::cout << "\nConversão Real-Fichas: 1 Real -> 250  fichas\n";
   std::cout << "Quantos reais (numero inteiro) deseja inserir?: ";
   unsigned int adicionar;
   std::cin >> adicionar;
   Injetar *= 250;
   while (Injetar >= 5000) Fichas[4].second ++;
   while (Injetar >= 1000) Fichas[3].second ++;
   while (Injetar >= 500) Fichas[2].second ++;
   while (Injetar >= 100) Fichas[1].second ++;
   while (Injetar >= 25) Fichas[0].second ++;
}*/

