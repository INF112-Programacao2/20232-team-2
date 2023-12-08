#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "Dealer.hpp"

void Dealer::embaralharCartas(std::vector<Carta>& cartas) {
    srand(time(NULL));
    std::random_shuffle(cartas.begin(), cartas.end());
}