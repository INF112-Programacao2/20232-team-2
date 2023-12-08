#include "Carta.hpp"

//std::string Carta::Naipes_list[4] = ("Ouros", "Espadas", "Copas", "Paus");

Carta::Carta(int valorCarta, std::string naipe)
{
   this->valorCarta = valorCarta;
   this->naipe = naipe;
}

Carta::~Carta()
{

}

int Carta::get_Valor_Carta()
{
   return valorCarta;
}

std::string Carta::get_Naipe()
{
   return naipe;
}
