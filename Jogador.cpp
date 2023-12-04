#include "Jogador.hpp"
#include <iostream>
#include <string>
#include <vector>


Jogador::Jogador(std::string nome)
{
   Nome = nome;
   Vez = Ativo = Cobriu = Small_Blind = Big_Blind = false;
   /*Fichas.push_back({8, 25}); // 8 de 25, 8 de 100, 4 de 500, 2 de 1000, 1 de 5000
   Fichas.push_back({8, 100});
   Fichas.push_back({4, 500});
   Fichas.push_back({2, 1000});
   Fichas.push_back({1, 5000});*/
}

Jogador::~Jogador()
{

}

void Jogador::Check()
{

}

void Jogador::Apostar()
{

}

void Jogador::Igualar()
{

}

void Jogador::Desistir()
{

}

void Jogador::Aumentar()
{

}

void Jogador::ExibirInfo()
{
   std::cout << "\nNome: " << Nome << "\n";
   std::cout << "\nFichas:\n";
   for (int i = 0; i < 5; i++)
   {
      
      std::cout << "De " << Fichas[i].first << " : " << Fichas[i].second << "\n";
   }
}

void Jogador::InjetarFichas()
{
   std::cout << "\nConversão Real-Fichas: 1 Real -> 250 fichas\n";
   std::cout << "Quantos reais (numero inteiro) deseja inserir?: ";
   unsigned int Injetar;
   std::cin >> Injetar;
   Injetar *= 250;
   while (Injetar >= 5000) Fichas[4].second ++;
   while (Injetar >= 1000) Fichas[3].second ++;
   while (Injetar >= 500) Fichas[2].second ++;
   while (Injetar >= 100) Fichas[1].second ++;
   while (Injetar >= 25) Fichas[0].second ++;
}

void Jogador::SetCartas()
{
   
}