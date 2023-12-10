#ifndef MAO_H
#define MAO_H
#include <vector>
#include "Carta.hpp"

class Mao 
{
    private:
        std::vector<Carta> cartas; // Armazena as cartas da mão
        static bool compare(Carta &a, Carta &b);
    public:
        // Construtor
        Mao();

        // Destrutor
        ~Mao();

        
        // Getters
        std::vector<Carta> getCartas();

        // Adiciona uma carta à mão
        void adicionarCarta(Carta carta);

        // Verifica se a mão é uma carta menor (ace a 2)
        bool is_CartaMenor(int index); 

        //Menor pontuação, verifica qual a maior carta do jogador
        int CartaAlta();
        
        // Verifica se a mão é um par (duas cartas iguais)
        bool is_Par();

        // Verifica se a mão é um dois pares (dois pares de cartas iguais)
        bool is_DoisPares();

        // Verifica se a mão é um trinca (três cartas iguais)
        bool is_Trinca();

        // Verifica se a mão é um straigth (sequência de cinco cartas)
        bool is_Straight();

        // Verifica se a mão é um flush (cinco cartas no mesmo naipe)
        bool is_Flush();

        // Verifica se a mão é um full house (três cartas iguais e um par)
        bool is_FullHouse();

        // Verifica se a mão é uma quadra (quatro cartas iguais)
        bool is_Quadra();

        // Verifica se a mão é uma straight flush (sequência de cinco cartas no mesmo naipe)
        bool is_StraightFlush();

        // Verifica se a mao é um royal flush (Sequência de 10 a Ás do mesmo naipe)
        bool is_RoyalFlush();

        // Verifica se a mão é um dobro (duas cartas iguais, em sequência)
        bool is_Dobro();
           
        // Verifica se a mão é uma sequência (três ou mais cartas em sequência)
        bool is_Sequencia();

        // Verifica se a mão é um trinca flush (três cartas iguais no mesmo naipe)
        bool is_TrincaFlush();

        // Retorna o valor da mão, em termos de pontuação
        int valorMao();

        // Imprimir cartas
        void printCartas();
};

#endif
