#ifndef JOGADOR_BOT_H
#define JOGADOR_BOT_H
#include<iostream>
#include"Jogador.hpp"
#include "Carta.hpp"
#include "Mao.hpp"

class Jogador_Bot : public Jogador
{
    private:

    public:
        Jogador_Bot(std::string);
        ~Jogador_Bot();
        virtual bool apostar(int &valorMesa) override;
        void funcao_teste() ;
};

#endif


