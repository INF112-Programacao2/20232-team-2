#include "Carta.hpp"

std::string Carta::Naipes_list[4] = ("Ouros", "Espadas", "Copas", "Paus");

Carta::Carta(int caractere, std::string naipe, bool comunitaria)
{
   Caractere = caractere;
   Naipe = naipe;
   Comunitaria = comunitaria;
}

Carta::~Carta()
{

}

int Carta::GetCaractere()
{
   return Caractere;
}

std::string Carta::GetNaipe()
{
   return Naipe;
}

bool Carta::GetComunitaria()
{
   return Comunitaria;
}
