#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "Dealer.hpp"
#include "Jogador.hpp"
#include "Carta.hpp"

Dealer::Dealer() 
{
    rodada = 1;
    check = 1;
    primeiro_Jogador = -1;
    criarBaralho();
    criarSala();
    darCartas();
    criarMesa();
}

Dealer::~Dealer() {}

int Dealer::getValorMesa()
{
    return valorMesa;
}

int Dealer::get_Primeiro_Jogador()
{
    return primeiro_Jogador;
}

void Dealer::setValorMesa(int valorMesa)
{
    this->valorMesa = valorMesa;
}

void Dealer::criarSala()
{
    std::cout << "Digite a quantidade de jogadores da partida: " << std::endl;
    std::cin >> quantidadeJogadores;
    while (quantidadeJogadores < 2)
    {
        std::cout << "Deve haver no mínimo 2 jogadores para jogar Poker\n";
        std::cout << "\nDigite a quantidade de jogadores da partida: " << std::endl;
        std::cin >> quantidadeJogadores;
    }
    
    for (int i = 1; i <= quantidadeJogadores; i++)
    {
        std::string nick;
        std::cout << "Apelido do jogador " << i << ": ";
        std::cin >> nick;
        bool nick_repetido = false;
        for (int j = 0; j < jogadores.size(); j++)
        {
            if(nick.compare(jogadores[j].get_Nick()) == 0)
            {
                std::cout << "Nick já utilizado por outro jogador, troque o apelido\n";
                nick_repetido = true;
                break;
            }
        }
        if(nick_repetido)
        {
            i--;
            continue;
        }
        Jogador temporario(nick);
        jogadores.push_back(temporario);
    }
    int big = rand()%jogadores.size();
    jogadores[big].set_big_blind(true);
    jogadores[big].set_Vez(true);
    for (int i = 0; i < jogadores.size(); i++)
    {
        if(big == jogadores.size()-1)
        {
            jogadores[0].set_small_blind(true);
        }
        else
        {
            jogadores[big+1].set_small_blind(true);
        }
    }
}

void Dealer::criarBaralho()
{
    for (int i = 2; i <= 14; i++) 
    {
        for (int j = 0; j < 4; j++) 
        {
            baralho.push_back(Carta(i, Carta::naipes_possiveis[j]));
        }
    }
    embaralharCartas();
    embaralharCartas();
    embaralharCartas();
}

void Dealer::embaralharCartas() 
{
    srand(time(NULL));
    std::random_shuffle(baralho.begin(), baralho.end());
}

//Coloquei o while como comentário para fazer os testes em outras funções
void Dealer::darCartas()
{
    for (int i = 0; i < quantidadeJogadores; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            jogadores[i].receberCarta(baralho.back());
            baralho.pop_back();
        }
    }
    for (int i = 0; i < jogadores.size(); i++)
    {
        std::cout << "\nA seguir, irei mostrar as cartas do jogador " << jogadores[i].get_Nick() << "\n\n";
        std::cout << "TODOS OS OUTROS JOGADORES NAO DEVEM OLHAR PARA A TELA NESSE INSTANTE\n";
        std::string confirma = {};
        /*while(!(confirma.compare("CONFIRMA") == 0))
        {
            std::cout << "\nDigite CONFIRMA para mostrar as cartas: ";
            std::cin >> confirma;
        }
        std::cout << "Sua primeira carta: " << jogadores[i].get_Mao().getCartas()[0].get_Valor_Carta() << " de " << jogadores[i].get_Mao().getCartas()[0].get_Naipe() << "\n";
        std::cout << "Sua segunda carta: " << jogadores[i].get_Mao().getCartas()[1].get_Valor_Carta() << " de " << jogadores[i].get_Mao().getCartas()[1].get_Naipe() << "\n";
        confirma = {};
        while(!(confirma.compare("CONFIRMA") == 0))
        {
            std::cout << "\nDigite CONFIRMA para apagar a tela: ";
            std::cin >> confirma;
        }*/
        std::system("clear");
    }
}

void Dealer::verificar_Rodadas()
{
    if(verificar_Check())
    {
        std::cout << "Todos os jogadores cobriram a aposta mais alta da mesa\n";
        std::cout << "Agora iremos para a próxima rodada\n";
        rodada++;

        if(rodada == 2)
        {
            std::cout << "Agora iremos para a próxima rodada\n";
            std::cout << "Agora iremos para a próxima rodada\n";
            std::cout << "Agora iremos para a próxima\n";
            mostrarCartas(3);
        }

        else if(rodada == 3)
        {
            std::cout << "Agora iremos para a próxima rodada\n";
            std::cout << "Agora iremos para a próxima rodada\n";
            mostrarCartas(4);
        }

        else if(rodada == 5)
        {
            std::cout << "Agora iremos para a próxima rodada\n";
            std::cout << "Agora iremos para a próxima rodada\n";
            mostrarCartas(5);
        }
    }
}

void Dealer::finalizar_Partida()
{
    if(jogadores.size() < 2)
    {

    }
}

void Dealer::criarMesa()
{   
    baralho.pop_back();
    for (int i = 0; i < 3; i++)
    {   
        mesa.push_back(baralho.back());
        baralho.pop_back();
    }

    for (int i = 0; i < 2; i++)
    {
        baralho.pop_back();
        mesa.push_back(baralho.back());
        baralho.pop_back();
    }
}

void Dealer::designarSmallBlind()
{
    for (int i = 0; i < jogadores.size(); i++)
    {
        if(jogadores[i].isTrue_Small_Blind())
        {
            jogadores[i].set_small_blind(false);
            if(i == jogadores.size()-1)
            {
                jogadores[0].set_small_blind(true);
            }
            else
            {
                jogadores[i+1].set_small_blind(true);
            }
        }
    }
}

void Dealer::designarBigBlind()
{
    for (int i = 0; i < jogadores.size(); i++)
    {
        if(jogadores[i].isTrue_Big_Blind())
        {
            jogadores[i].set_big_blind(false);
            if(i == jogadores.size()-1)
            {
                jogadores[0].set_big_blind(true);
            }
            else
            {
                jogadores[i+1].set_big_blind(true);
            }
        }
    }
}

void Dealer::designarPrimeiroJogador()
{
    set_Primeiro_Jogador(2);
    jogadores[primeiro_Jogador].set_Ativo(false);
    jogadores[0].set_Ativo(false);
    //std::cout << jogadores[primeiro_Jogador].isTrue_Ativo()<< primeiro_Jogador <<"\n\n";
    for (int i = 0; i < jogadores.size(); i++) {std::cout << jogadores[i].isTrue_Ativo() << "       ";}
    std::cout << "\n\n";
    //No começo da partida o Small Blind sempre será o primeiro
    if(primeiro_Jogador == -1)
    {    
        std::cout << "entrei aqui\n\n";
        for (int i = 0; i < jogadores.size(); i++)
        {
            //encontra o Small Blind
            if(jogadores[i].isTrue_Small_Blind())
            {
                jogadores[i].set_Vez(true);
                primeiro_Jogador = i;
                break;
            }
        }
    }    
    //Verifica se quem era para ser o maior jogador desta rodada ainda está ativo na partida
    
    
    
    else if (!jogadores[primeiro_Jogador].isTrue_Ativo()) //Verificar o problema desse condicional
    {
        std::cout << "entrei aqui\n\n";
        while (true)
        {

            //Se o atual primeiro jogador for o último do vetor, retornamos ao primeiro 
            if(primeiro_Jogador == jogadores.size()-1)
            {
                primeiro_Jogador = 0;
            }
            //Se não veremos o próximo 
            else
            {
                std::cout << "Entrei aqui agora\n\n";
                primeiro_Jogador++;
            }
            //Se o atual jogador avaliado estiver ativo na partida, então ele iniciará as apostas da rodada            
            if(jogadores[primeiro_Jogador].isTrue_Ativo())
            {
                jogadores[primeiro_Jogador].set_Vez(true);
                break;
            }
        }       
    }
}

bool Dealer::verificar_Check()
{
    //verificar se o valor da aposta de todos os jogadores são a mesma que a  atual da mão
    for (int i = 0; i < jogadores.size(); i++)
    {
        if(jogadores[i].isTrue_Vez())
        {
            if(rodada == 2)
            {
                std::cout << "As cartas da mesa são: \n" << mostrarCartas(3);
            }
            if(rodada == 3)
            {
                std::cout << "As cartas da mesa são: \n" << mostrarCartas(4);
            }
            if(rodada == 4)
            {
                std::cout << "As cartas da mesa são: \n" << mostrarCartas(5);
            }
            std::cout << "Digite 1 para ver suas informações\nDigite 2 para apostar algum valor\nDigite 3 para desistir da partida\nDigite 4 para abandonar completamente o jogo\n\n";
            int escolha;
            std::cout << "Digite o numero escolhido: ";
            std::cin >> escolha;
            while(escolha < 1 || escolha > 4)
            {
                std::cout << "Por favor, escolha um numero entre 1 e 4\n\n";
                std::cout << "Digite 1 para ver suas informações\nDigite 2 para apostar algum valor\nDigite 3 para desistir da partida\nDigite 4 para abandonar completamente o jogo\n\n";
                std::cout << "Digite o numero escolhido: ";
                std::cin >> escolha;
            }

            int valorMesaAntigo = valorMesa;   
            if(escolha == 1) jogadores[i].exibirInfo();
            else if(escolha == 2) jogadores[i].apostar(valorMesa);
            else if(escolha == 3) jogadores[i].desistir();
            else if(escolha == 4) jogadores[i].abandonar();

            if(valorMesa == valorMesaAntigo) check++;
            else check = 1;

            jogadores[i].set_vez(false);
            while (true)
            {
                if(primeiro_Jogador == jogadores.size()-1)
                {
                    primeiro_Jogador = 0;
                }

                else
                {
                    primeiro_Jogador++;
                }

                if(jogadores[primeiro_Jogador].isTrue_Ativo())
                {
                    jogadores[primeiro_Jogador].set_Vez(true);
                    break;
                }
            } 

            if( i == jogadores.size() - 1 )
                i = 0;
        }
    } 
}

void Dealer::mostrarCartas(int quantidade_Cartas_Mostradas)
{
    for (int i = 0; i < quantidade_Cartas_Mostradas; i++)
    {
        if(mesa[i].get_Valor_Carta())
        {
            std::cout << mesa[i].get_Valor_Carta() << "   " << mesa[i].get_Naipe() << std::endl;
        }
        else
        {
            if (mesa[i].get_Valor_Carta() == 11)
            {
                std::cout << 'J' << "   " << mesa[i].get_Naipe() << std::endl;
            }
                
            if (mesa[i].get_Valor_Carta() == 12)
            {
                std::cout << 'Q' << "   " << mesa[i].get_Naipe() << std::endl;
            }

            if (mesa[i].get_Valor_Carta() == 13)
            {
                std::cout << 'K' << "   " << mesa[i].get_Naipe() << std::endl;
            }
                
            if (mesa[i].get_Valor_Carta() == 14)
            {
                std::cout << 'A' << "   " << mesa[i].get_Naipe() << std::endl;
            }
        }
    }
}

void Dealer::set_Primeira_Aposta(int primeira_Aposta)
{
    this->primeira_Aposta = primeira_Aposta;
}

void Dealer::set_Valor_Acumulado_Mesa(int valorAtualMesa)
{
    valor_Acumulado_mesa += valorAtualMesa;
}

void Dealer::set_Primeiro_Jogador(int id_Primeiro_Jogador)
{
    primeiro_Jogador = id_Primeiro_Jogador;
}

std::vector<Carta> Dealer::get_baralho()
{
    return baralho;
} 

std::vector<Carta> Dealer::get_mesa()
{
    return mesa;
} 

std::vector<Jogador> Dealer::get_jogadores()
{
    return jogadores;
}

int main()
{
    Dealer dealer;
    dealer.set_Primeiro_Jogador(2);
    dealer.get_jogadores().at(2).set_Ativo(false);
    std::cout << dealer.get_jogadores().at(dealer.get_Primeiro_Jogador()).isTrue_Ativo() << "\n\n";
    
    dealer.designarPrimeiroJogador(); // Call the function to assign the first player
    
    //Entrada 3 jogadores e nome aleatórios
    //Saída esperada: 0     problema: Quando declaramos o primeiro_Jogador manualmente, caso para teste, a função designar_Primeiro_Jogador não está sendo chamada
    //De acordo com os testes que venho fazendo, parece que o bug está no condicional do primeiro "else if"
    std::cout << dealer.get_Primeiro_Jogador()<< "\n\n";
    return 0;
}

//Observação: Nos testes a função designar Primeiro Jogador não está sendo executada