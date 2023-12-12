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
    valor_Acumulado_mesa = 0;
    valorMesa = 0;
    primeira_Aposta = 10;
    criarBaralho();
    criarSala();
    darCartas();
    criarMesa();
}

Dealer::~Dealer() {}

void Dealer::passar_Vez()
{
    for (int i = 0; i < jogadores.size(); i++)
    {
        if(jogadores[i].isTrue_Vez() && jogadores[i].isTrue_Ativo())
        {
            while (true)
            {
                jogadores[i].set_Vez(false);


                if(i == jogadores.size()-1 && jogadores[0].isTrue_Ativo())
                {
                    i=0;
                    jogadores[0].set_Vez(true);
                    return;
                }
                else if (jogadores[i+1].isTrue_Ativo())
                {
                    jogadores[i+1].set_Vez(true);
                    return;
                }
                if (i == jogadores.size() - 1) i=0;
            }
        }
    }
}

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
        //resetar o valor das apostas da mesa
        valorMesa = 0;
        //resetar o valor que cada jogador tem apostado
        for (int i = 0; i < jogadores.size(); i++) {jogadores[i].set_Apostado(0);}
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

        else if(rodada == 4)
        {
            std::cout << "Agora iremos para a próxima rodada\n";
            std::cout << "Agora iremos para a próxima rodada\n";
            mostrarCartas(5);
        }
    }
}

void Dealer::finalizar_Partida()
{

    int jogadoresAtivos = 0;

    for (int i = 0; i < jogadores.size(); i++)
    {
        if(jogadores[i].isTrue_Ativo())
        jogadoresAtivos++;
    }
    
    // Quem ganhou se tiver apenas um jogador
    if(jogadoresAtivos == 1)
    {
        std::cout << "A partida acabou\n";
        for (int i = 0; i < jogadores.size(); i++)
        {
            if(jogadores[i].isTrue_Ativo())
            {
                std::cout << "O jogador " << jogadores[i].get_Nick() << " ganhou a partida\n";
                std::cout << "Obrigado por jogar\n";
                jogadores[i].aumenta_Saldo(valor_Acumulado_mesa);
                return;
            }
        }
    }

    // Quem ganhou se tiver mais de um jogador
    if(rodada == 4 && verificar_Check())
    {
        std::pair<int,int> maior_Valor;
        maior_Valor.first = 0;  //maior valor da mão (second é a posição do jogador)
        for (int i = 0; i < jogadores.size(); i++)
        {
            if(jogadores[i].get_Valor_Mao() > maior_Valor.first)
                maior_Valor.first = jogadores[i].get_Valor_Mao();
                maior_Valor.second = i;
        }
        std::cout << "O jogador " << jogadores[maior_Valor.second].get_Nick() 
        <<" ganhou a partida com uma pontuação de: " << maior_Valor.first << std::endl;
        std::cout << "A partida acabou\n";
        std::cout << "Obrigado por jogar\n";
        jogadores[maior_Valor.second].aumenta_Saldo(valor_Acumulado_mesa);
        return;
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
    //No começo da partida o Small Blind sempre será o primeiro
    if(primeiro_Jogador == -1)
    {    
        for (int i = 0; i < jogadores.size(); i++)
        {
            //encontra o Small Blind
            if(jogadores[i].isTrue_Small_Blind())
            {
                jogadores[i].set_Vez(true);
                primeiro_Jogador = i;
                for (int  j = 0; j < jogadores.size(); j++)
                {
                    if(j != i)
                    {
                        jogadores[j].set_Vez(false);
                    }
                }
                break;
            }
        }
    }    
    //Verifica se quem era para ser o maior jogador desta rodada ainda está ativo na partida
    else if (!jogadores[primeiro_Jogador].isTrue_Ativo()) //Verificar o problema desse condicional
    {
        while (true)
        {

            //Se o atual primeiro jogador for o último do vetor, retornamos ao primeiro 
            if(primeiro_Jogador == jogadores.size()-1)
            {
                primeiro_Jogador = 0;
            }
            //Se não, veremos o próximo 
            else
            {
                primeiro_Jogador++;
            }
            //Se o atual jogador avaliado estiver ativo na partida, então ele iniciará as apostas da rodada            
            if(jogadores[primeiro_Jogador].isTrue_Ativo())
            {
                jogadores[primeiro_Jogador].set_Vez(true);
                for (int j = 0; j < jogadores.size(); j++)
                {
                    if(j != primeiro_Jogador)
                    {
                        jogadores[j].set_Vez(false);
                    }
                }
                break;
            }
        }       
    }
}

bool Dealer::verificar_Check()
{
    //verificar se o valor da aposta de todos os jogadores são a mesma que a  atual da mão
    for (int i = 0;; i++)
    {
        if(jogadores[i].isTrue_Vez() && !jogadores[i].isTrue_All_In())
        {
            if (rodada == 2)
            {
                std::cout << "As cartas da mesa são: \n";
                mostrarCartas(3);
            }
            if (rodada == 3)
            {
                std::cout << "As cartas da mesa são: \n"; 
                mostrarCartas(4);
            }
            if (rodada == 4)
            {
                std::cout << "As cartas da mesa são: \n";
                mostrarCartas(5);
            }

            again:
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
            if(escolha == 1)
            { 
                jogadores[i].exibirInfo(valorMesa);
                goto again;
            }
            else if(escolha == 2)
            {
                if (jogadores[i].apostar(valorMesa);)
                {
                    if(valorMesa == valorMesaAntigo) check++;
                    else check = 1;
                }
                
                passar_Vez();
            }
            else if(escolha == 3)
            {
                passar_Vez();
                jogadores[i].desistir();
            } 
            else if(escolha == 4)
            {
                passar_Vez();
                jogadores[i].abandonar();
            } 

            int jogadoresAtivos = 0;
            for (int i = 0; i < jogadores.size(); i++)
            {
                if(jogadores[i].isTrue_Ativo())
                    jogadoresAtivos++;
            }
            if(jogadoresAtivos == check)
                return true;
            
        }
        if(jogadores[i].isTrue_All_In())
        {
            check++;
            passar_Vez();
        }
        if( i == jogadores.size() - 1 )
            i = 0;
    } 
}

void Dealer::mostrarCartas(int quantidade_Cartas_Mostradas)
{
    for (int i = 0; i < quantidade_Cartas_Mostradas; i++)
    {
        if(mesa[i].get_Valor_Carta() <= 10)
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