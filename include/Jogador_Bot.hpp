#ifndef JOGADOR_BOT_H
#define JOGADOR_BOT_H
#include<iostream>
#include"Jogador.hpp"
#include "Carta.hpp"
#include "Mao.hpp"

class Jogador_Bot : Jogador
{
private:

public:
    Jogador_Bot();
    ~Jogador_Bot();
    virtual bool apostar(int &valorMesa) override;
};

#endif


