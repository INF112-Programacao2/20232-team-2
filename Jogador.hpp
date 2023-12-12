#ifndef JOGADOR_HPP
#define JOGADOR_HPP
#include <iostream>
#include <vector>
#include "Carta.hpp"
#include "Mao.hpp"

class Jogador
{
   private:
      //Apelido do jogador
      std::string nickname;

      //Mão composta por 2 cartas
      Mao mao; 
      
      //Vetor de pairs relativos ao valor da ficha bem como suas quantidades
      //Valores já pré estabelecidos {1, 5, 10, 20, 50, 100, 500} -> Limitaremos o valor em mil para evitar vícios
      std::vector<std::pair<int,int>> fichas; 

      //Saldo total em fichas
      int saldo;

      //Valor que o jogador já tem apostado
      int apostado;

      //Verifica se está na vez do jogador x
      bool vez; 

      //Verifica se o jogador está na rodada ou se desistiu da rodada
      bool ativo; 

      //Verifica se o jogador cobriu o valor proposto por outro jogador
      bool cobriu; 

      //Verificar se o tipo do jogador é Big Blind
      bool big_Blind; 

      //Verificar se o tipo do jogador é Small Blind
      bool small_Blind; 

      //Indica se o jogador está no modo All in
      bool all_in;

   public:
      //Construtor
      Jogador(std::string nick);
      
      //Destrutor
      ~Jogador();

      //Métodos get e isTrue para acesso aos atributos de Jogador

      //Nome do jogador
      std::string get_Nick();
      
      //Só poderá ser chamado pelo Dealer na última rodada
      Mao get_Mao();

      //Retorna a mao do jogador
      int get_Valor_Mao();

      //Retorna o valor apostado em cada rodada do jogador
      int get_Apostado();

      //Retorna o saldo do jogador
      int get_Saldo();

      //Verifica se é a vez do jogador
      bool is_True_Vez();
      
      //Retornar o status do jogador(ativo ou inativo -> PS: Acredito que melhoraremos a qualidade do código se Criarmos os jogadores como objetos dinâmicos e sempre removê-los da memória após desistirem, mantendo seus dados em um arquivo)
      bool is_True_Ativo();
     
      //Identificar se o jogador deu check com a aposta atual
      bool is_True_Cobriu();

      //Definir se esse jogador será ou não um big blind
      bool is_True_Big_Blind();

      //Definir se esse jogador será ou não um small blind
      bool is_True_Small_Blind();

      //Retornar true caso o jogador esteja no modo all_in
      bool is_True_All_In();


      //Métodos set

      //settar o status do jogador na partida
      void set_Ativo(bool);

      //settar o valor apostado
      void set_Apostado(int);

      //Alterar a posição do Small Blind
      void set_Small_Blind(bool);

      //Alterar a posição do Big Blind
      void set_Big_Blind(bool);

      //Alterar a vez do jogador
      void set_Vez(bool);

      //setta o all_in do jogador
      void set_All_In(bool);

      //Reseta a mao do jogador
      void set_Mao(Mao);


      //Métodos de controle da classe

      //Receber cartas
      void receber_Carta(Carta carta);
      
      //Verificar se o jogador desiste da rodada
      void desistir();
      
      //Verificar se o jogador quer apostar
      bool apostar(int &valorMesa);

      //Exibe as informações do jogador
      void exibir_Info(int ValorMesa);
      
      //Aumenta o saldo do jogador caso ele ganhe
      void aumenta_Saldo(int saldo);

      //Converte fichas de um tipo em fichas de outro tipo
      void converte();

      //Converte valor extra da aposta em outras fichas menores
      void converte_Sobressalente(int valor_sobressalente);
};

#endif