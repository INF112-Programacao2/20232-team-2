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
   vez  = cobriu = ativo = small_Blind = big_Blind = all_in = false;
   //mao = new Mao(cartas);
   fichas.push_back({5, 10});// 10 de 5, 5 de 10, 5 de 20, 2 de 50, 2 de 100, 1 de 500
   fichas.push_back({10, 5});
   fichas.push_back({20, 5});
   fichas.push_back({50, 2});
   fichas.push_back({100, 2});
   fichas.push_back({500, 1});
   saldo  = 1000;
   apostado = 0;
}

Jogador::~Jogador()
{

}

void Jogador::receberCarta(Carta carta)
{
   mao.adicionarCarta(carta);
}

void Jogador::check(int &valorMesa)
{
   if (valorMesa <= apostado)
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
   //Falta implementar tratamento de exceçoes
   if(saldo + apostado <= valorMesa)
   {
      std::cout << "Você nao possui saldo suficiente para cobrir o valor da mesa, com essa aposta voce entrará em modo all in. Deseja prosseguir? digite SIM para confirmar\n";
      std::string confirmacao;
      std::cin >> confirmacao;
      if(confirmacao.compare("SIM") == 0)
      {
         all_in = true;
         apostado += saldo;
         saldo  = 0;
         for (int i = 0; i < fichas.size(); i++)
         {
            fichas[i].second = 0;
         }
      }
      return;
   }
   while(true)
   {
      std::cout << "\nSeu saldo é: " << saldo  << "\nO valor da mesa é: " << valorMesa << "\nVocê já apostou essa rodada: " << apostado; 
      std::cout << "\nDigite o valor que deseja apostar (aposte tudo para entrar em all in):";
      int aposta;
      std::cin >> aposta;
      if((aposta + apostado) >= valorMesa)
      {
         if(aposta < saldo)
         {
            std::cout << "Suas fichas atuais sao:\n\n";
            for (int i = 0; i < fichas.size(); i++)
            {
               std::cout << "Fichas de " << fichas[i].first << " : " << fichas[i].second << "\n";
            }
            std::cout << "\n";

            int aposta_em_fichas = 0, ficha, quantidadeFicha;
            while(true)
            {
               std::cout << "OBSERVAÇÂO : quantidades sobressalentes serão convertidas em outras fichas e guardadas novamente em sua carteira\n";
               std::cout << "Insira o tipo de ficha que quer apostar, e a quantidade de fichas desse tipo que deseja apostar (ex: '3 10', equivalem a 3 fichas de 10): ";
               std::cin >> quantidadeFicha >> ficha;
               if(ficha != 5 && ficha != 10 && ficha != 20 && ficha != 50 && ficha != 100 && ficha != 500)
               {
                  std::cout << "Insira uma ficha de valor valido para apostar (5, 10, 20, 50, 100 ou 500)\n";
               }
               else
               {
                  for (int i = 0; i < fichas.size(); i++)
                  {
                     if (fichas[i].first == ficha)
                     {
                        if(fichas[i].second >= quantidadeFicha)
                        {
                           aposta_em_fichas += ficha * quantidadeFicha;
                           fichas[i].second -= quantidadeFicha;
                           std::cout << "\nVocê apostou " << quantidadeFicha << " fichas de " << ficha << "\n";
                           if(aposta_em_fichas >= aposta)
                           {
                              aposta_em_fichas -= aposta;
                              goto endloop;
                           }
                           else
                           {
                              std::cout << "É necessário apostar mais " << aposta - aposta_em_fichas << " para atingir a aposta proposta\n\n";
                           }
                        }
                        else
                        {
                           std::cout << "\nVoce nao possui fichas do tipo " << ficha << " suficientes\n\n";
                        }
                     }
                  }               
               }
            }
            endloop:
            converte_sobressalente(aposta_em_fichas);
            std::cout << "Foram convertidas " << aposta_em_fichas << " fichas para a sua carteira\n\n";
            cobriu = true;
            apostado += aposta;
            saldo -= aposta;
            valorMesa = apostado;
            break;
         }
         else if(aposta == saldo)
         {
            std::cout << "Seu saldo se esgotou, com essa aposta voce entrará em modo all in. Deseja prosseguir? digite SIM para confirmar\n";
            std::string confirmacao;
            std::cin >> confirmacao;
            if(confirmacao.compare("SIM") == 0)
            {
               all_in = cobriu = true;
               saldo  = 0;
               apostado += aposta;
               valorMesa = apostado;
               for (int i = 0; i < fichas.size(); i++)
               {
                  fichas[i].second = 0;
               }
               break;
            }
         }
         else
         {
            std::cout << "Saldo insuficiente, aposte um valor mais baixo\n";
         }
      }
      else
      {
         std::cout << "Valor da mesa não atingido, aposte um valor maior\n\n";
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
   for (int i = 0; i < fichas.size(); i++)
   {
      std::cout << "Fichas de " << fichas[i].first << " : " << fichas[i].second << "\n";
   }
   std::cout << "Saldo total: " << saldo << "\n";
   std::cout << "\n";
   if(cobriu)
   {
      std::cout << "Você já cobriu o valor da aposta (" << ValorMesa << ") mais alta da mesa\n";
   }
   else
   {
      std::cout << "Você ainda não cobriu o valor da aposta (" << ValorMesa << ") mais alta da mesa\n";
      std::cout << "Voce já apostou " << apostado << " nessa rodada\n";
   }
   if(small_Blind)
   {
      std::cout << "Você é o small blind nessa rodada\n";
   }
   if(big_Blind)
   {
      std::cout << "Você é o big blind nessa rodada\n";
   }
   std::cout << "\n";
}

Mao Jogador::get_Mao()
{ 
   return mao;
}

std::string Jogador::get_Nick()
{
   return nickname;
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

void Jogador::converte()
{
   std::cout << "Suas fichas atuais sao:\n\n";
   for (int i = 0; i < fichas.size(); i++)
   {
      std::cout << "Fichas de " << fichas[i].first << " : " << fichas[i].second << "\n";
   }
   std::cout << "\n";

   int a_converter, convertido;
   int quantidade_a_converter, quantidade_convertida;
   while (true)
   {
      std::cout << "Deseja converter fichas de qual valor?: ";
      std::cin >> a_converter;
      if(a_converter != 5 && a_converter != 10 && a_converter != 20 && a_converter != 50 && a_converter != 100 && a_converter != 500)
      {
         std::cout << "Insira uma ficha de valor valido para converter (5, 10, 20, 50, 100 ou 500)\n";
      }
      else
      {
         break;
      }
   }

   std::cout << "Quantas fichas do tipo "<< a_converter << " serão convertidas?: ";
   std::cin >> quantidade_a_converter;
   for (int i = 0; i < fichas.size(); i++)
   {
      if(fichas[i].first == a_converter)
      {
         if(quantidade_a_converter > fichas[i].second)
         {
            std::cout << "Você nao possui fichas do tipo "<< a_converter << " suficientes\n";
            return;
         }
      }
   }
   
   while (true)
   {
      std::cout << "\nEssas fichas do tipo " << a_converter << " serao convertidas em fichas de qual valor?: ";
      std::cin >> convertido;
      if(convertido == a_converter)
      {
         std::cout << "O tipo de ficha a converter deve ser diferente do tipo de ficha resultante!\n";
      }
      else if(convertido != 5 && convertido != 10 && convertido != 20 && convertido != 50 && convertido != 100 && convertido != 500)
      {
         std::cout << "Insira uma ficha de valor valido para converter (5, 10, 20, 50, 100 ou 500)\n";
      }
      else
      {
         break;
      }
   }

   for (int i = 0; i < fichas.size(); i++)
   {
      if(fichas[i].first == convertido)
      {
         if(quantidade_a_converter * a_converter < convertido)
         {
            std::cout << quantidade_a_converter << " fichas de " << a_converter << " não são fichas o suficiente para converter em fichas de " << convertido << "\n";
            return;
         }
         else
         {
            quantidade_convertida = ((quantidade_a_converter * a_converter) / convertido);
            for (int i = 0; i < fichas.size(); i++)
            {
               if(fichas[i].first == convertido)
               {
                 fichas[i].second += quantidade_convertida;
                 break;
               }
            }
            for (int i = 0; i < fichas.size(); i++)
            {
               if(fichas[i].first == a_converter)
               {
                 fichas[i].second -= (quantidade_convertida * convertido) / a_converter ;
                 break;
               }
            }
         }
      }
   }
}

void Jogador::converte_sobressalente(int aposta_em_fichas)
{
   while (aposta_em_fichas >= 500)
   {
      fichas[5].second++;
      aposta_em_fichas -= 500;
   }
   while (aposta_em_fichas >= 100)
   {
      fichas[4].second++;
      aposta_em_fichas -= 100;
   }
   while (aposta_em_fichas >= 50)
   {
      fichas[3].second++;
      aposta_em_fichas -= 50;
   }
   while (aposta_em_fichas >= 20)
   {
      fichas[2].second++;
      aposta_em_fichas -= 20;
   }
   while (aposta_em_fichas >= 10)
   {
      fichas[1].second++;
      aposta_em_fichas -= 10;
   }
   while (aposta_em_fichas >= 5)
   {
      fichas[0].second++;
      aposta_em_fichas -= 5;
   }

}