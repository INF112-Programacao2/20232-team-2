#ifndef USUARIO_HPP
#define USUARIO_HPP
#include "Jogador.hpp"


class Usuario : public Jogador
{
      //Nome do jogador
      const std::string nome; 
      
      //Individualizar  cada jogador
      const std::string CPF;
};

#endif