#ifndef MAO_H
#define MAO_H
#include <vector>
#include "Carta.hpp"

class Mao 
{
    private:
        // Armazena as cartas da mão
        std::vector<Carta> cartas; 
        
        // Função compare para organizar o vetor de acordo com os valores
        static bool compareValorCartas(Carta &a, Carta &b);
        
        // Função compare para organizar o vetor de acordo com os naipes
        static bool compareNaipe(Carta &carta1, Carta &carta2);

        // Verifica se a mão é uma sequência (três ou mais cartas em sequência)
        bool is_Sequencia(int inicio, int n, std::string tipo);

        // Variável que indica o valor da mão do jogador
        int valor_Da_Mao;
    public:
        // Construtor
        Mao();

        // Destrutor
        ~Mao();

        // Getters
        std::vector<Carta> getCartas();
        int get_Valor_Mao();

        // Adiciona uma carta à mão
        void adicionarCarta(Carta carta);
        
        // Verifica se a mão é um par (duas cartas iguais)
        std::pair<int, bool> is_Par();

        // Verifica se a mão é um dois pares (dois pares de cartas iguais)
        std::pair<std::pair<int, int>, bool> is_DoisPares();

        // Verifica se a mão é um trinca (três cartas iguais)
        std::pair<int, bool> is_Trinca();

        // Verifica se a mão é um straigth (sequência de cinco cartas)
        std::pair<int, bool> is_Straight();

        // Verifica se a mão é um flush (cinco cartas no mesmo naipe)
        bool is_Flush();

        // Verifica se a mão é um full house (três cartas iguais e um par)
        std::pair<std::pair<int, int>, bool> is_FullHouse();

        // Verifica se a mão é uma quadra (quatro cartas iguais)
        std::pair<int, bool> is_Quadra();

        // Verifica se a mão é uma straight flush (sequência de cinco cartas no mesmo naipe)
        std::pair<int, bool> is_StraightFlush();

        // Verifica se a mao é um royal flush (Sequência de 10 a Ás do mesmo naipe)
        std::pair<int, bool> is_RoyalFlush();

        // Verifica se a mão é um dobro (duas cartas iguais, em sequência)
        std::pair<int, bool> is_Dobro();

        // Retorna o valor da mão, em termos de pontuação
        int valorMao();

        // Imprimir cartas
        void printCartas();
};

#endif
