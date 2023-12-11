#include <vector>
#include "Mao.hpp"
#include "Carta.hpp"
#include <algorithm>

Mao::Mao() {}

Mao::~Mao() {}

bool Mao::compareValorCartas(Carta &carta1, Carta &carta2)
{
    return carta1.get_Valor_Carta() < carta2.get_Valor_Carta();
}

bool Mao::compareNaipe(Carta &carta1, Carta &carta2)
{
    if(carta1.get_Naipe() == carta2.get_Naipe())
        return carta1.get_Valor_Carta() < carta2.get_Valor_Carta();
    return carta1.get_Naipe() < carta2.get_Naipe();
}

std::vector<Carta> Mao::getCartas() 
{ 
    return cartas; 
}

void Mao::adicionarCarta(Carta carta) 
{
    cartas.push_back(carta);
}

// Método testado e funcionando
bool Mao::is_DoisPares()
{
    std::vector<Carta> copiaCartas = cartas;
    std::sort(copiaCartas.begin(), copiaCartas.end(), compareValorCartas);
    bool um_Par = false, dois_Pares = false;
    for (int i = 0; i < copiaCartas.size()-1; i++)
    {
        if((copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[1+i]).get_Valor_Carta()))
        {
            um_Par = true;
            copiaCartas.erase(copiaCartas.begin() +1+i);
            copiaCartas.erase(copiaCartas.begin() +0+i);
            break;
        }
    }
    
    for (int i = 0; i < copiaCartas.size()-1; i++)
    {
        if((copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[1+i]).get_Valor_Carta()))
        {
            dois_Pares = true;
        }
    }
    return dois_Pares && um_Par;

    
}

// Ainda incompleto(por conta da ordenação)
bool Mao::is_Dobro()
{
    //Método para verificar se as duas primeiras cartas adicionadas é um dobro
    if (cartas[0].get_Valor_Carta() == cartas[1].get_Valor_Carta())
    {
        return true;
    }
    return false;
}

// Método testado e funcionando para valores de n acima de 3
/*bool Mao::is_Sequencia(int inicio,int n, std::string tipo)
{
    //Temos aqui um uso do conceito de polimorfismo
    //Primeiro motivo: o método is_Sequencia dará um retorno de acordo com seu chamado(tipo), que pode ser sequência por "naipe", "valor" ou "paridade"
    if(tipo.compare("valor") == 0)
    {
        if(cartas.size() >= n)
            for (int i = 0; i < cartas.size() - n + 1; i++) 
            {
                //A lógica, nesse caso, é que o vetor está organizado segundo o valor das cartas. Então, se eu tenho um vetor de 5 caracteres e eles não formam um par nem um trinca entre si e 
                //o valor da última carta será o mesmo que o da primeira adicionada ao tamanho da sequencia, 5 para o caso (dá para fazer para n, trocando '4' por n e '-5' pelo tamanho da sequência) 
                if (cartas[0].get_Valor_Carta() == cartas[i + n - 1].get_Valor_Carta() - n + 1) 
                {
                    return true;
                }
            }
        return false;
    }
    else if (tipo.compare("naipe") == 0)
    {
        std::vector<Carta> copiaCartas = cartas;
        sort(copiaCartas.begin(), copiaCartas.end(), compareNaipe);
        //imprimir copiaCartas
        for (int i = 0; i < copiaCartas.size(); i++)
        {
            //std::cout << copiaCartas[i].get_Valor_Carta() << "              " << copiaCartas[i].get_Naipe() << std::endl;
        }
        if(cartas.size() >= n)
            for (int i = inicio; i < copiaCartas.size() - n + 1; i++) 
            {
                //A lógica, nesse caso, é que o vetor está organizado segundo o naipe, portanto teremos primeiramente todas as cartas do naipe de copas, depois todas de espadas... Portanto, se em alguma parte do vetor tivermos que se a carta[i] for igual à carta [i+n-1], então n é a quantidade de cartas que temos daquele naipe
                //Dado isso, aqui estamos perguntando se a sequência de cartas(tamanho n) ordenadas pelo naipe existe ou não
                if (copiaCartas[i].get_Naipe() == copiaCartas[i + n-1].get_Naipe() ) 
                {
                    return true;
                }
            }
        return false;
    }
    else if (tipo.compare("paridade") == 0) // não achei esse nome tão interessante, mas foi o melhor que encontrei por hora rs
    {
        if(cartas.size() >= n)
        for (int i = inicio; i < cartas.size() - n + 1; i++) 
            {
                //A lógica, nesse caso, é que o vetor está organizado segundo o valor das cartas 
                //Portanto, para verificar se temos n cartas com o mesmo valor, basta que o elemento
                //cartas[i] == cartas[i+n-1], primeiro e último termos avaliados, respectivamente.
                if (cartas[i].get_Valor_Carta() == cartas[i + n-1].get_Valor_Carta()) return true;
            }
        return false;
    }
    else return false;
}*/

// Método testado e funcionando
bool Mao::is_Par()
{
    std::vector<Carta> copiaCartas = cartas;
    std::sort(copiaCartas.begin(), copiaCartas.end(), compareValorCartas);
    for (int i = 0; i < copiaCartas.size()-1; i++)
    {
        if((copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[1+i]).get_Valor_Carta()))
            return true;
    }
    return false;
} 

// Método testado e funcionando
bool Mao::is_Trinca()
{
    std::vector<Carta> copiaCartas = cartas;
    std::sort(copiaCartas.begin(), copiaCartas.end(), compareValorCartas);
    for (int i = 0; i < copiaCartas.size()-2; i++)
    {
        if((copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[1+i]).get_Valor_Carta()) && (copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[2+i]).get_Valor_Carta()))
            return true;
    }
    return false;
}

// Quatro quartas de mesmo valor(Testado e funcionando)
bool Mao::is_Quadra()
{
    std::vector<Carta> copiaCartas = cartas;
    std::sort(copiaCartas.begin(), copiaCartas.end(), compareValorCartas);
    for (int i = 0; i < copiaCartas.size()-3; i++)
    {
        if((copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[1+i]).get_Valor_Carta()) && (copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[2+i]).get_Valor_Carta()) && (copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[3+i]).get_Valor_Carta()))
            return true;
    }
    return false;
    
}

// Caso específico de sequência do tipo valor(Testado e funcionando)
bool Mao::is_Straight()
{
    std::vector<Carta> copiaCartas = cartas;
    std::sort(copiaCartas.begin(), copiaCartas.end(), compareValorCartas);

    for (int i = 0; i < copiaCartas.size(); i++)
    {
        for (int j = i+1; j < copiaCartas.size(); j++)
        {
            if(copiaCartas[i].get_Valor_Carta() == copiaCartas[j].get_Valor_Carta())
            {
                copiaCartas.erase(copiaCartas.begin() + j);
            }
        }
    }

    for (int i = 0; i < copiaCartas.size() - 4; i++)
    {
        if((copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[1+i]).get_Valor_Carta() - 1) && (copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[2+i]).get_Valor_Carta() - 2) && (copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[3+i]).get_Valor_Carta() - 3) && (copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[4+i]).get_Valor_Carta() - 4))
            return true;
    }
    return false;
}

// Caso específico de sequência do tipo naipe(Testado e funcionando)
bool Mao::is_Flush()
{   
    std::vector<Carta> copiaCartas = cartas;
    std::sort(copiaCartas.begin(), copiaCartas.end(), compareNaipe);
    for (int i = 0; i < copiaCartas.size() - 4; i++)
    {
        if((copiaCartas[0+i].get_Naipe()) == (copiaCartas[1+i].get_Naipe()) && (copiaCartas[0+i].get_Naipe()) == (copiaCartas[2+i].get_Naipe()) && (copiaCartas[0+i].get_Naipe()) == (copiaCartas[3+i].get_Naipe()) && (copiaCartas[0+i].get_Naipe()) == (copiaCartas[4+i].get_Naipe()))
            return true;
    }
    return false;
}

// Interseção dos casos de Flush e Straight(Testado e funcionando)
bool Mao::is_StraightFlush()
{
    std::vector<Carta> copiaCartas = cartas;
    std::sort(copiaCartas.begin(), copiaCartas.end(), compareNaipe);

    for (int i = 0; i < copiaCartas.size() - 4; i++)
    {
        if((copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[1+i]).get_Valor_Carta() - 1) && (copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[2+i]).get_Valor_Carta() - 2) && (copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[3+i]).get_Valor_Carta() - 3) && (copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[4+i]).get_Valor_Carta() - 4))
            if((copiaCartas[0+i].get_Naipe()) == (copiaCartas[1+i].get_Naipe()) && (copiaCartas[0+i].get_Naipe()) == (copiaCartas[2+i].get_Naipe()) && (copiaCartas[0+i].get_Naipe()) == (copiaCartas[3+i].get_Naipe()) && (copiaCartas[0+i].get_Naipe()) == (copiaCartas[4+i].get_Naipe()))
                return true;
    }
    return false;
}

// Um par e uma trinca(Testado e funcionando)
bool Mao::is_FullHouse()
{
    bool trinca = false;
    bool dupla = false;
    std::vector<Carta> copiaCartas = cartas;
    std::sort(copiaCartas.begin(), copiaCartas.end(), compareValorCartas);
    for (int i = 0; i < copiaCartas.size()-2; i++)
    {
        if((copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[1+i]).get_Valor_Carta()) && 
        (copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[2+i]).get_Valor_Carta()))
        {
            copiaCartas.erase(copiaCartas.begin() + i);
            copiaCartas.erase(copiaCartas.begin() + 1+i);
            copiaCartas.erase(copiaCartas.begin() + 2+i);
            trinca = true;
            //Testando mudança push
        }
    }
    for (int i = 0; i < copiaCartas.size()-1; i++)
    {
        if((copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[1+i]).get_Valor_Carta()))
            dupla = true;
    }
    return trinca && dupla;
}

// Identificamos se temos um Straight Flush começado por 10(Testado e funcionando)
bool Mao::is_RoyalFlush()
{   
    std::vector<Carta> copiaCartas = cartas;
    std::sort(copiaCartas.begin(), copiaCartas.end(), compareNaipe);
    for (int i = 0; i < copiaCartas.size() - 4; i++)
    {
        if((copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[1+i]).get_Valor_Carta() - 1) && 
        (copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[2+i]).get_Valor_Carta() - 2) && 
        (copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[3+i]).get_Valor_Carta() - 3) && 
        (copiaCartas[0+i].get_Valor_Carta()) == ((copiaCartas[4+i]).get_Valor_Carta() - 4))
            if((copiaCartas[0+i].get_Naipe()) == (copiaCartas[1+i].get_Naipe()) && 
            (copiaCartas[0+i].get_Naipe()) == (copiaCartas[2+i].get_Naipe()) && 
            (copiaCartas[0+i].get_Naipe()) == (copiaCartas[3+i].get_Naipe()) && 
            (copiaCartas[0+i].get_Naipe()) == (copiaCartas[4+i].get_Naipe()))
                if((copiaCartas[0+i].get_Valor_Carta() == 10))
                    return true;
    }
    return false;
    
}

void Mao::valorMao()
{
    // Atribuir o valor à mão
    if(is_RoyalFlush())           valor_Da_Mao= 100;
    else if(is_StraightFlush())   valor_Da_Mao= 90;
    else if (is_Quadra())         valor_Da_Mao= 80;
    else if (is_FullHouse())      valor_Da_Mao= 70;
    else if (is_Flush())          valor_Da_Mao= 60;
    else if (is_Straight())       valor_Da_Mao= 50;
    else if (is_Trinca())         valor_Da_Mao= 40;        
    else if (is_DoisPares())      valor_Da_Mao= 30;
    else if (is_Par())            valor_Da_Mao= 20;
    else                          valor_Da_Mao= cartas.back().get_Valor_Carta(); 
}

void Mao::printCartas()
{
    for (int i = 0; i < cartas.size(); i++)
    {
        std::cout << cartas[i].get_Valor_Carta() << " " << cartas[i].get_Naipe() << "\n";
    }

    this->valorMao();

    std::cout << valor_Da_Mao;
}

//main para testar esse código

int main()
{ 
    Mao mao;
    Carta carta1(12, "Ouros");
    Carta carta2(12, "Espadas");
    Carta carta3(12, "Espadas");
    Carta carta4(15, "Ouros");
    Carta carta5(13, "Ouros");
    Carta carta6(7, "Espadas");
    Carta carta7(7, "Ouros");
    mao.adicionarCarta(carta1);
    mao.adicionarCarta(carta2);
    mao.adicionarCarta(carta3);
    mao.adicionarCarta(carta4);
    mao.adicionarCarta(carta5);
    mao.adicionarCarta(carta6);
    mao.adicionarCarta(carta7);

    //mao.valor_Mao;
    std::cout << mao.getCartas().size() << std::endl;
    mao.printCartas();

    while (true)
    {        
        int entrada;
        std::cin >>entrada;
        if (entrada == 1)std::cout << mao.is_Flush() << "\n";
        if (entrada == 2)std::cout << mao.is_Par() << "\n";            //
        if (entrada == 3)std::cout << mao.is_StraightFlush() << "\n";
        if (entrada == 4)std::cout << mao.is_Trinca() << "\n";          //
        if (entrada == 5)std::cout << mao.is_FullHouse() << "\n";
        if (entrada == 6)std::cout << mao.is_Dobro() << "\n";
        if (entrada == 8)std::cout << mao.is_Quadra() << "\n";          //
        if (entrada == 9)std::cout << mao.is_Straight() << "\n";
        if (entrada == 10)std::cout << mao.is_DoisPares() << "\n";
        if (entrada == 11)std::cout << mao.is_RoyalFlush() << "\n";
        if (entrada ==0) break;
    }
    return 0;
}
