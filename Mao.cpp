#include <vector>
#include "Mao.hpp"
#include "Carta.hpp"
#include <algorithm>

Mao::Mao() {}

Mao::~Mao() {}

bool Mao::compare(Carta &carta1, Carta &carta2)
{
    return carta1.get_Valor_Carta() < carta2.get_Valor_Carta();
}

std::vector<Carta> Mao::getCartas() 
{ 
    return cartas; 
}

void Mao::adicionarCarta(Carta carta) 
{
    cartas.push_back(carta);
    std::sort(cartas.begin(), cartas.end(), compare);
}

bool Mao::is_CartaMenor(int index) 
{
    if (index >= cartas.size()) 
    {
        return true;
    }

    if (cartas[index].get_Valor_Carta() < 2 || cartas[index].get_Valor_Carta() > 14) 
    {
        return false;
    }

    return is_CartaMenor(index + 1);
}

// Método testado e funcionando
bool Mao::is_Pair()
{
    for (int i = 0; i < cartas.size() - 1; i++) {
        if (cartas[i].get_Valor_Carta() == cartas[i + 1].get_Valor_Carta()) 
        {
            return true;
        }
    }
    return false;
} 


bool Mao::is_Dobro()
{
    //Método para verificar se as duas primeiras cartas adicionadas é um dobro
    if (cartas[0].get_Valor_Carta() == cartas[1].get_Valor_Carta())
    {
        return true;
    }
    return false;
}

//Método testado e funcionando
bool Mao::is_Sequencia()
{
    for (int i = 0; i < cartas.size() - 2; i++) 
    {
        if (cartas[i].get_Valor_Carta() != cartas[i + 1].get_Valor_Carta() - 1 || cartas[i].get_Valor_Carta() != cartas[i + 2].get_Valor_Carta() - 2) 
        {
            return false;
        }
    }
    return true;
}

//Método testado e funcionando
bool Mao::is_Trinca()
{
    for (int i = 0; i < cartas.size() - 2; i++) {
        if (cartas[i].get_Valor_Carta() == cartas[i + 1].get_Valor_Carta() && cartas[i].get_Valor_Carta() == cartas[i + 2].get_Valor_Carta()) 
        {
            return {cartas[i].get_Valor_Carta(),true};
        }
    }
    return {0,false};
}

std::pair<int,bool> Mao::is_Straight()
{
    for (int i = 1; i < cartas.size(); i++)
    {
        if(cartas[i].get_Valor_Carta() != cartas[i-1].get_Valor_Carta() + 1)
        {
            return {0, false};
        }
    }
    return {cartas[0].get_Valor_Carta, true};
}

bool Mao::is_Flush()
{
    for (int i = 0; i < cartas.size(); i++)
    {
        if (cartas[i].get_Naipe().compare(cartas[i + 1].get_Naipe()) != 02
        )
            {
                return false;
            }
    }
    return true;
}

bool Mao::is_FullHouse()
{
    //Função para descobrir se as cartas do objeto Mao formam um FullHouse
    for (int i = 0; i < cartas.size(); i++)
    {
        if (cartas[i].get_Valor_Carta() == 
        cartas[i + 1].get_Valor_Carta() && 
        cartas[i].get_Valor_Carta() == 
        cartas[i + 2].get_Valor_Carta())
        {
            return true;
        }
    }
    return false;
}

//Método implementado, testado e funcionando
bool Mao::is_Quatro()
{
    for (int i = 0; i < cartas.size(); i++)
    {
        if (cartas[i].get_Valor_Carta() == cartas[i + 1].get_Valor_Carta() && cartas[i].get_Valor_Carta() == cartas[i + 2].get_Valor_Carta() && cartas[i].get_Valor_Carta() == cartas[i + 3].get_Valor_Carta())
        {
            return true;
        }
    }
    return false;
}

bool Mao::is_Straight()
{
    // Parte flush
    for (int i = 1; i < cartas.size(); i++)
    {
        if (cartas[0].get_Naipe().compare(cartas[i].get_Naipe()) != 0)
        {
            return {0, false};
        }
    }
    
    //Parte Straight
    for (int i = 1; i < cartas.size(); i++)
    {
        if(cartas[i].get_Valor_Carta() != cartas[i-1].get_Valor_Carta() + 1)
        {
            return {0, false};
        }
    }
    return {cartas[0].get_Valor_Carta, true};

}

bool Mao::is_RoyalFlush()
{
    if(cartas[0] != 10)
    {
        return false;
    }
    // Parte flush
    for (int i = 1; i < cartas.size(); i++)
    {
        if (cartas[0].get_Naipe().compare(cartas[i].get_Naipe()) != 0)
        {
            return false;
        }
    }
    
    //Parte Straight
    for (int i = 1; i < cartas.size(); i++)
    {
        if(cartas[i].get_Valor_Carta() != cartas[i-1].get_Valor_Carta() + 1)
        {
            return false;
        }
    }

    return true;
}

bool Mao::is_TrincaFlush()
{
    //implementar aqui
}

bool Mao::is_Dobro()
{
    for (int i = 0; i < cartas.size() - 1; i++) {
        if (cartas[i].get_Valor_Carta() != cartas[i + 1].get_Valor_Carta() - 1) 
        {
            return false;
        }
    }
    return true;    
}

bool Mao::is_Sequencia()
{
    for (int i = 0; i < cartas.size() - 2; i++) 
    {
        if (cartas[i].get_Valor_Carta() != cartas[i + 1].get_Valor_Carta() - 1 || cartas[i].get_Valor_Carta() != cartas[i + 2].get_Valor_Carta() - 2) 
        {
            return false;
        }
    }
    return true;
}

int Mao::valorMao()
{
    //implementar aqui
}

void Mao::printCartas()
{
    for (int i = 0; i < cartas.size(); i++)
    {
        std::cout << cartas[i].get_Valor_Carta() << " " << cartas[i].get_Naipe() << "\n";
    }
}

//main para testar esse código

/*int main()
{ 
    Mao mao;
    Carta carta1(10, "Ouros");
    Carta carta2(10, "Espada");
    Carta carta3(11, "Paus");
    Carta carta4(11, "Copas");
    Carta carta5(15, "Ouros");
    mao.adicionarCarta(carta1);
    mao.adicionarCarta(carta2);
    mao.adicionarCarta(carta3);
    mao.adicionarCarta(carta4);
    mao.adicionarCarta(carta5);

    std::cout << mao.getCartas()->size() << std::endl;

    mao.printCartas();

    while (true)
    {        
        int entrada;
        std::cin >>entrada;
        if (entrada == 1)std::cout << mao.is_Flush() << "\n";
        if (entrada == 2)std::cout << mao.is_Pair() << "\n";            //
        if (entrada == 3)std::cout << mao.is_StraightFlush() << "\n";
        if (entrada == 4)std::cout << mao.is_Trinca() << "\n";          //
        if (entrada == 5)std::cout << mao.is_FullHouse() << "\n";
        if (entrada == 6)std::cout << mao.is_Dobro() << "\n";
        if (entrada == 7)std::cout << mao.is_Sequencia() << "\n";       //
        if (entrada == 8)std::cout << mao.is_Quatro() << "\n";          //
        if (entrada == 9)std::cout << mao.is_Straight() << "\n";
        if (entrada == 10)std::cout << mao.is_TrincaFlush() << "\n";
        if (entrada == 11)std::cout << mao.is_DoisPares() << "\n";
        if (entrada ==0) break;
    }
    
    
    return 0;
}
*/