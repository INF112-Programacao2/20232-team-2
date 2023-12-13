#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>
#include<string>
#include "../include/Carta.hpp"
#include "../include/Mao.hpp"
#include "../include/Jogador.hpp"

Jogador::Jogador(std::string nick)
{
   //Construtor do jogador, setta variáveis da forma que elas devem estar ao criar um jogador
   nickname = nick;
   ativo = true;
   vez  = small_Blind = big_Blind = all_in = false;
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
   //destrutor vazio, pois nao possui nenhuma alocação dinâmica
}

std::string Jogador::get_Nick()
{
   return nickname;
}

Mao Jogador::get_Mao()
{ 
   return mao;
}

std::vector<std::pair<int,int>> Jogador::get_Fichas()
{
   return fichas;
}

int Jogador::get_Valor_Mao()
{
   return mao.get_Valor_Mao();
}

int Jogador::get_Apostado()
{
   return apostado;
}

int Jogador::get_Saldo()
{
   return saldo;
}

bool Jogador::is_True_Vez()
{
   return vez;
}
      
bool Jogador::is_True_Ativo()
{
   return ativo;
}

bool Jogador::is_True_Big_Blind()
{
   return big_Blind;
}

bool Jogador::is_True_Small_Blind()
{
   return small_Blind;
}

bool Jogador::is_True_All_In()
{
   return all_in;
}

void Jogador::set_Ativo(bool _ativo)
{
   ativo = _ativo;
}

void Jogador::set_Apostado(int valor)
{
   apostado = valor;
}

void Jogador::set_Small_Blind(bool small)
{
   small_Blind = small;
}

void Jogador::set_Big_Blind(bool big)
{
   big_Blind = big;
}

void Jogador::set_Vez(bool _vez)
{
   vez = _vez;
}

void Jogador::set_All_In(bool _all_in)
{
   all_in = _all_in;
}

void Jogador::reset_Mao()
{
   Mao _mao;
   mao = _mao;
}

void Jogador::receber_Carta(Carta carta)
{
   mao.adicionar_Carta(carta);
}

bool Jogador::desistir()
{
   std::cout << "Realmente deseja desistir? digite SIM para confirmar\n";
   std::string confirmacao;
   try
   {
      std::getline(std::cin, confirmacao);
      if (confirmacao == "SIM")
      {
         ativo = false;
         std::cout << "Desistência confirmada\n\n\n";
      }
      else
      {
         throw std::invalid_argument("Entrada inválida, digite 'SIM' para confirmar\n");
      }
   }
   catch (std::invalid_argument &e)
   {
      std::cerr << e.what() << "\n";
   }
   return !ativo;
}

bool Jogador::apostar(int &valorMesa)
{
   //Caso o jogador nao tenha o valor necessário para aposta, ele entra "automaticamente" no modo all in
   if (saldo <= valorMesa)
   {
      std::cout << "Você não possui saldo suficiente para cobrir o valor da mesa. Com essa aposta, você entrará em modo all in. Deseja prosseguir? Digite SIM para confirmar\n";
      std::string confirmacao;
      
      //Garante que confirmação seja string, e caso nao seja, limpa a entrada cin para nao prejudicar as proximas entradas
      try
      {
         std::getline(std::cin, confirmacao);
         if (confirmacao == "SIM")
         {
            all_in = true;
            apostado += saldo;
            saldo = 0;
            for (size_t i = 0; i < fichas.size(); i++)
            {
               fichas[i].second = 0;
            }
            return true;
         }
         return false;
      }
      catch (std::invalid_argument &e)
      {
         std::cerr << e.what() << "\n";
      }
   }
   //Enquanto o jogador nao fizer uma aposta válida, tenta apostar novamente
   while(true)
   {
      
      int aposta;

      //Garantia de que aposta será um inteiro maior que 0
      while (true)
      {
         std::cout << "\nSeu saldo é: " << saldo  << "\nO valor da mesa é: " << valorMesa << "\nVocê já apostou essa rodada: " << apostado; 
         std::cout << "\nDigite o valor que deseja apostar (aposte tudo para entrar em all in): ";
         try
         {
            std::cin >> aposta;
            if (std::cin.fail())
            {
               std::cin.clear();
               std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
               throw std::invalid_argument("Entrada inválida, insira um número inteiro\n");
            }
            if (aposta < 0)
            {
               throw std::invalid_argument("Entrada inválida, a aposta deve ser maior ou igual a 0\n");
            }

            std::cin.ignore();
            break;
         }
         catch (std::invalid_argument &e)
         {
            std::cerr << e.what() << "\n";
         }
      }

      //Se o valor já apostado mais o valor que ira apostar suprir o valor da mesa, ele aposta de fato
      if(aposta + apostado >= valorMesa)
      {

         //se a aposta for zero, ele so quer passar a vez
         if(aposta == 0)   return true;

         // se a aposta for menor que o saldo disponivel, ele aposta normalmente
         if(aposta < saldo)
         {
            std::cout << "Suas fichas atuais sao:\n\n";
            for (size_t i = 0; i < fichas.size(); i++)
            {
               std::cout << "Fichas de " << fichas[i].first << " : " << fichas[i].second << "\n";
            }
            std::cout << "\n";

            int aposta_em_fichas = 0, ficha, quantidadeFicha;
            while(true)
            {
               //Garantia de que ficha e quantidadeFicha serão inteiros maior que 0
               while (true)
               {
                  std::cout << "OBSERVAÇÂO : quantidades sobressalentes serão convertidas em outras fichas e guardadas novamente em sua carteira\n";
                  std::cout << "Insira o tipo de ficha que quer apostar, e a quantidade de fichas desse tipo que deseja apostar (ex: '3 10', equivalem a 3 fichas de 10): ";
                  try
                  {
                     std::cin >> quantidadeFicha >> ficha;
                     if (std::cin.fail())
                     {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        throw std::invalid_argument("Entrada inválida, insira dois numeros inteiros separados por espaço\n");
                     }
                     if (quantidadeFicha < 0 || ficha < 0)
                     {
                        throw std::invalid_argument("Entrada inválida, as quantias devem ser maior ou iguais a 0\n");
                     }
                     std::cin.ignore();
                     break;
                  }
                  catch (std::invalid_argument &e)
                  {
                     std::cerr << e.what() << "\n";
                  }
               }
               
               if(ficha != 5 && ficha != 10 && ficha != 20 && ficha != 50 && ficha != 100 && ficha != 500) // verifica em loop se a ficha que deseja apostar é uma ficha válida
               {
                  std::cout << "Insira uma ficha de valor valido para apostar (5, 10, 20, 50, 100 ou 500)\n";
               }
               else
               {
                  for (size_t i = 0; i < fichas.size(); i++)
                  {
                     if (fichas[i].first == ficha)
                     {

                        // se a quantidade de fichas apostadas for maior que a quantidade de fichas na carteira do jogador, ele aposta
                        if(fichas[i].second >= quantidadeFicha)
                        {
                           aposta_em_fichas += ficha * quantidadeFicha;
                           fichas[i].second -= quantidadeFicha;
                           std::cout << "\nVocê apostou " << quantidadeFicha << " fichas de " << ficha << "\n";

                           // se a quantidade apostada em fichas ate então suprir o valor da aposta proposta, ele finaliza com um goto endloop
                           if(aposta_em_fichas >= aposta)
                           {
                              aposta_em_fichas -= aposta;
                              goto endloop;
                           }

                           //se a quantidade apostada nao suprir o valor, ele pede para apostar mais fichas
                           else
                           {
                              std::cout << "É necessário apostar mais " << aposta - aposta_em_fichas << " para atingir a aposta proposta\n\n";
                           }
                        }

                        //caso a quantidade de fichas apostadas for menor que a quantidade armazenada na carteira, ele pede outro tipo de ficha, ou uma quantidade menor da mesma ficha
                        else
                        {
                           std::cout << "\nVoce nao possui fichas do tipo " << ficha << " suficientes\n\n";
                        }
                     }
                  }               
               }
            }

            //no endloop é convertido o valor sobressalentes da aposta em outros valores da carteira
            endloop:
            converte_Sobressalente(aposta_em_fichas);
            std::cout << "Foram convertidas " << aposta_em_fichas << " fichas para a sua carteira\n\n";
            apostado += aposta;
            saldo -= aposta;
            valorMesa = apostado;
            return true;
         }

         //Se a aposta for igual ao saldo do jogador, isso quer dizer que o jogador entrará em modo all in
         else if(aposta == saldo)
         {
            std::cout << "Seu saldo se esgotou, com essa aposta voce entrará em modo all in. Deseja prosseguir? digite SIM para confirmar\n";
            std::string confirmacao;

            //Garante que confirmação seja string, e caso nao seja, limpa a entrada cin para nao prejudicar as proximas entradas
            try
            {
               std::getline(std::cin, confirmacao);
               if (confirmacao == "SIM")
               {
                  all_in = true;
                  saldo  = 0;
                  apostado += aposta;
                  //Consertado o bug para o caso de o valor da mesa ser superior ao da aposta do jogador em All In. Sem esse condicional, teríamos uma atualização do valor da mesa para o valor do All in do jogador, ou seja, uma redução do seu valor, caso impossível
                  if(valorMesa > apostado)   valorMesa = apostado;   //Se o valor do All In for superior ao valo da mesa(caso em que o próprio jogador oferece All In), então a aposta é atualizada. Caso o valor da mesa já chegue mais alto para ele, então o valor atual se mantém
                  for (size_t i = 0; i < fichas.size(); i++)
                  {
                     fichas[i].second = 0;
                  }
                  return true;
               }
               return false;
            }
            catch (std::invalid_argument &e)
            {
               std::cerr << e.what() << "\n";
            }
         }

         // se a aposta for maior que o saldo, o jogador nao possui saldo para apostar o valor desejado
         else
         {
            std::cout << "Saldo insuficiente, aposte um valor mais baixo\n";
         }
      }

      //se o valor já apostado mais o valor que ira apostar nao suprir o valor da mesa, o jogador deve apostar um valor mais alto
      else
      {
         std::cout << "Valor da mesa não atingido, aposte um valor maior\n\n";
      }
   }
}

void Jogador::exibir_Info(int ValorMesa)
{
   std::cout << "\nNickname: " << nickname << "\n";
   for (size_t i = 0; i < fichas.size(); i++)
   {
      std::cout << "Fichas de " << fichas[i].first << " : " << fichas[i].second << "\n";
   }
   std::cout << "Saldo total: " << saldo << "\n";
   if(small_Blind)
   {
      std::cout << "Você é o small blind nessa partida\n";
   }
   else if(big_Blind)
   {
      std::cout << "Você é o big blind nessa partida\n";
   }
   else
   {
      std::cout << "Você é um jogador regular nessa partida\n";
   }

   std::cout << "\n\n";
}

void Jogador::aumenta_Saldo(int _saldo)
{
   saldo += _saldo;
   converte_Sobressalente(_saldo);
}

void Jogador::converte()
{
   std::cout << "Suas fichas atuais sao:\n\n";
   for (size_t i = 0; i < fichas.size(); i++)
   {
      std::cout << "Fichas de " << fichas[i].first << " : " << fichas[i].second << "\n";
   }
   std::cout << "\n";

   int a_converter, convertido;
   int quantidade_a_converter, quantidade_convertida;

   // Precisa converter um tipo de ficha válido
   while (true) 
   {
      try 
      {
         std::cout << "Deseja converter fichas de qual valor?: ";
         std::cin >> a_converter;

         if (std::cin.fail() || (a_converter != 5 && a_converter != 10 && a_converter != 20 && a_converter != 50 && a_converter != 100 && a_converter != 500)) 
         {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::invalid_argument("Insira uma ficha de valor válido para converter (5, 10, 20, 50, 100 ou 500)\n");
         }
         std::cin.ignore();
         break;
      }
      catch (std::invalid_argument &e) 
      {
         std::cerr << e.what() << "\n";
      }
   }
   
   while (true)
   {
      std::cout << "Quantas fichas do tipo "<< a_converter << " serão convertidas?: ";
      try
      {
         std::cin >> quantidade_a_converter;
         if (std::cin.fail())
         {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::invalid_argument("Entrada inválida, insira um número inteiro");
         }
         if (quantidade_a_converter < 0)
         {
            throw std::invalid_argument("Entrada inválida, a quantia deve ser maior ou igual a 0");
         }
         std::cin.ignore();
         break;
      }
      catch (std::invalid_argument &e)
      {
         std::cerr << e.what() << "\n";
      }
   }

   //Verifica se ele possui fichas suficientes do tipo que deseja converter, caso nao possua, finaliza o método sem converter
   for (size_t i = 0; i < fichas.size(); i++)
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
   
   //Verifica em qual tipo de ficha ele deseja converter, deve ser uma ficha válida
   while (true) 
   {
      try 
      {
         std::cout << "\nEssas fichas do tipo " << a_converter << " serão convertidas em fichas de qual valor?: ";
         if (!(std::cin >> convertido)) 
         {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::invalid_argument("Entrada inválida, insira um número inteiro\n");
         }
         if (convertido == a_converter) 
         {
            throw std::invalid_argument("O tipo de ficha a converter deve ser diferente do tipo de ficha resultante!\n");
         }
         if (convertido != 5 && convertido != 10 && convertido != 20 && convertido != 50 && convertido != 100 && convertido != 500) 
         {
            throw std::invalid_argument("Insira uma ficha de valor válido para converter (5, 10, 20, 50, 100 ou 500)\n");
         }
         std::cin.ignore();
         break;
      }
      catch (std::invalid_argument &e) 
      {
         std::cerr << e.what() << "\n";
      }
   }

   // caso o valor a converter nao supra o valor de 1(uma) ficha convertida, o método é finalizado e nao converte nada 
   for (size_t i = 0; i < fichas.size(); i++)
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
            for (size_t i = 0; i < fichas.size(); i++)
            {
               if(fichas[i].first == convertido)
               {
                 fichas[i].second += quantidade_convertida;
                 break;
               }
            }
            for (size_t i = 0; i < fichas.size(); i++)
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

void Jogador::converte_Sobressalente(int aposta_em_fichas)
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