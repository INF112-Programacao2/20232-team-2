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
    return carta1.get_Naipe() < carta2.get_Naipe();
}

std::vector<Carta> Mao::getCartas() 
{ 
    return cartas; 
}

void Mao::adicionarCarta(Carta carta) 
{
    cartas.push_back(carta);
    std::sort(cartas.begin(), cartas.end(), compareValorCartas);
}

// Método testado e funcionando
bool Mao::is_DoisPares()
{
    for (int i = 0; i < cartas.size() - 1; i++)
    {
        if (cartas[i].get_Valor_Carta() == cartas[i + 1].get_Valor_Carta())
        {
            for (int j = i + 2; j < cartas.size() - 1; j++)
            {
                if (cartas[j].get_Valor_Carta() == cartas[j + 1].get_Valor_Carta())
                {
                    return true;
                }
            }
        }
    }
    
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
bool Mao::is_Sequencia(int inicio,int n, std::string tipo)
{
    //Temos aqui um uso do conceito de polimorfismo
    //Primeiro motivo: o método is_Sequencia dará um retorno de acordo com seu chamado(tipo), que pode ser sequência por "naipe", "valor" ou "paridade"
    if(tipo.compare("valor") == 0)
    {
        if(cartas.size() >= n)
            for (int i = inicio; i < cartas.size() - n + 1; i++) 
            {
                //A lógica, nesse caso, é que o vetor está organizado segundo o valor das cartas. Então, se eu tenho um vetor de 5 caracteres e eles não formam um par nem um trinca entre si e 
                //o valor da última carta será o mesmo que o da primeira adicionada ao tamanho da sequencia, 5 para o caso (dá para fazer para n, trocando '4' por n e '-5' pelo tamanho da sequência) 
                if (cartas[0].get_Valor_Carta() == cartas[i + n-1].get_Valor_Carta() - n + 1) 
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

}

// Método testado e funcionando
bool Mao::is_Par()
{
    return is_Sequencia(0, 2, "paridade");
} 

// Método testado e funcionando
bool Mao::is_Trinca()
{
    return is_Sequencia(0, 3, "paridade");
}

// Quatro quartas de mesmo valor(Testado e funcionando)
bool Mao::is_Quadra()
{
    return is_Sequencia(0, 4, "paridade");
}

// Caso específico de sequência do tipo valor(Testado e funcionando)
bool Mao::is_Straight()
{
    return is_Sequencia(0, 5, "valor");
}

// Caso específico de sequência do tipo naipe(Testado e funcionando)
bool Mao::is_Flush()
{   
    return is_Sequencia(0 ,5, "naipe");
    
}

// Interseção dos casos de Flush e Straight(Testado e funcionando)
bool Mao::is_StraightFlush()
{
    return is_Straight() && is_Flush();
}

// Um par e uma trinca(Testado e funcionando)
bool Mao::is_FullHouse()
{
    bool dupla = false, trinca = false;
    if(cartas.size() >= 5) // Mínimo para termos um trinca e um dupla com valores diferentes
    {
        for (int i = 0; i < cartas.size() - 5 + 1; i++)
        {
            // Primeiramente verificamos se temos uma trinca
            if (is_Sequencia(i, 3, "paridade") && !trinca)     //Aqui não precisamos de !is_par() porque se tivermos outra trinca, obrigatoriamente teremos outra dupla também
            {
                trinca = true;
                i += 2;
            }
            
            // Depois verificamos se temos uma dupla
            if (is_Sequencia(i, 2, "paridade") && !dupla)   //Temos que, se já encontramos uma dupla, não precisamos buscar outra
            {
                dupla = true;
                i += 1;
            }
        }
    }
    return trinca && dupla;
}

// Identificamos se temos um Straight Flush começado por 10(Testado e funcionando)
bool Mao::is_RoyalFlush()
{
    if (is_StraightFlush())
    {
        std::vector<Carta> copiaCartas = cartas;
        std::sort(cartas.begin(), cartas.end(), compareNaipe);
        for (int i = 0; i < cartas.size() - 5; i++)
        {
            for (int j = i; j < cartas.size() - 5; j++)
            {
                if (copiaCartas[i].get_Valor_Carta() == copiaCartas[j + 5 - 1].get_Valor_Carta() - 5 + 1)
                {
                    if (copiaCartas[i].get_Valor_Carta() == 10)
                    {
                        return true;
                    }
                }
            }
        }
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
    Carta carta1(10, "Ouros");
    Carta carta2(12, "Espada");
    Carta carta3(12, "Ouros");
    Carta carta4(13, "Ouros");
    Carta carta5(14, "Ouros");
    Carta carta6(11, "Ouros");
    mao.adicionarCarta(carta1);
    mao.adicionarCarta(carta2);
    mao.adicionarCarta(carta3);
    mao.adicionarCarta(carta4);
    mao.adicionarCarta(carta5);
    mao.adicionarCarta(carta6);

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
