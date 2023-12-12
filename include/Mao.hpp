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
        static bool compare_Valor_Cartas(Carta &a, Carta &b);
        
        // Função compare para organizar o vetor de acordo com os naipes
        static bool compare_Naipe(Carta &carta1, Carta &carta2);

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

        // Retornar as cartas da mão
        std::vector<Carta> get_Cartas();

        // Retornar o valor da mão
        int get_Valor_Mao();

        // Verifica se a mão é um par (duas cartas iguais)
        std::pair<int, bool> is_Par();

        // Verifica se a mão é um dois pares (dois pares de cartas iguais)
        std::pair<std::pair<int, int>, bool> is_Dois_Pares();

        // Verifica se a mão é um trinca (três cartas iguais)
        std::pair<int, bool> is_Trinca();

        // Verifica se a mão é um straigth (sequência de cinco cartas)
        std::pair<int, bool> is_Straight();

        // Verifica se a mão é um flush (cinco cartas no mesmo naipe)
        bool is_Flush();

        // Verifica se a mão é um full house (três cartas iguais e um par)
        std::pair<std::pair<int, int>, bool> is_Full_House();

        // Verifica se a mão é uma quadra (quatro cartas iguais)
        std::pair<int, bool> is_Quadra();

        // Verifica se a mão é uma straight flush (sequência de cinco cartas no mesmo naipe)
        std::pair<int, bool> is_Straight_Flush();

        // Verifica se a mao é um royal flush (Sequência de 10 a Ás do mesmo naipe)
        bool is_Royal_Flush();

        // Adiciona uma carta à mão
        void adicionar_Carta(Carta carta);   
};

#endif
