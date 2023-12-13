#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <limits>
#include <string>
#include "Dealer.hpp"
#include "Jogador.hpp"
#include "Jogador_Bot.hpp"
#include "Carta.hpp"
//#include "Dealer.hpp"


TEST_CASE ("Deve retornar o saldo subtraido do atual valor da mesa")
{
    //Arrange
    int valorMesa = 100;
    Jogador_Bot bot1("bot1");
    
    //act
    bool apostou = bot1.apostar(valorMesa);

    //Assert
    REQUIRE(900 == bot1.get_Saldo());
}

TEST_CASE ("Retorna o valor apostado")
{
    int valorMesa = 100;
    Jogador_Bot bot2("bot2");
    
    bool apostou = bot2.apostar(valorMesa);

    REQUIRE(100 == bot2.get_Apostado());
}


TEST_CASE ("Verifica se ocorreu tudo bem com as apostas")
{
    //Arrange
    int valorMesa = 100;
    Jogador_Bot bot3("bot3");
    
    //act
    bool apostou = bot3.apostar(valorMesa);

    //Assert
    REQUIRE(true == apostou);
}

TEST_CASE ("Verificar o saldo do bot caso ele aposte toda a sua carteira")
{
    //Arrange
    int valorMesa = 1000;
    Jogador_Bot bot4("bot4");
    
    //act
    bool apostou = bot4.apostar(valorMesa);

    //Assert
    REQUIRE(0 == bot4.get_Saldo());
}

TEST_CASE ("Verificar o saldo do bot caso o valor da mesa seja maior do que seu saldo")
{
    //Arrange
    int valorMesa = 1100;
    Jogador_Bot bot5("bot1");
    
    //act
    bool apostou = bot5.apostar(valorMesa);

    //Assert
    REQUIRE(0 == bot5.get_Saldo());
}

TEST_CASE ("Verifica se o jogador está em modo all in")
{
    //Arrange
    int valorMesa = 1000;
    Jogador_Bot bot6("bot4");
    
    //act
    bool apostou = bot6.apostar(valorMesa);

    //Assert
    REQUIRE(true == bot6.is_True_All_In());
}




