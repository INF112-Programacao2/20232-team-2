#include <string>
#include <vector>

class Carta
{
   private:
      int Caractere; // Varia de 2 a 14; 11 é valete, 12 é dama, 13 é rei, e 14 é ás
      std::string Naipe; // Ouros, Espadas, Copas ou Paus
      static std::string Naipes_list[4];
      bool Comunitaria;
   public:
      Carta(int, std::string, bool);
      ~Carta();
      int GetCaractere();
      std::string GetNaipe();
      bool GetComunitaria();
};