#include "Carta.hpp"

//std::string Carta::Naipes_list[4] = ("Ouros", "Espadas", "Copas", "Paus");

Carta::Carta(int valorCarta, char naipe)
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

char Carta::get_Naipe()
{
   return naipe;
}
