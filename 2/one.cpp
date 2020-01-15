#include <iostream>
#include <math.h>

enum Kolmio {
    epaSaannollinen,
    tasaKylkinen,
    tasaSivuinen,
    suoraKulmainen
};

bool onKolmiollinen(int eka, int toka, int kolmas, Kolmio tyyppi);

int main() {
    int eka = 0;
    int toka = 0;
    int kolmas = 0;
    std::cout << "Anna 1. sivun pituus: " << std::endl;
    std::cin >> eka;
    std::cout << "Anna 2. sivun pituus: " << std::endl;
    std::cin >> toka;
    std::cout << "Anna 3. sivun pituus: " << std::endl;
    std::cin >> kolmas;

    if(onKolmiollinen(eka, toka, kolmas, epaSaannollinen)) 
        std::cout << "Kolmio muodostaa epasaannollisen kolmion." << std::endl;
    if(onKolmiollinen(eka, toka, kolmas, tasaKylkinen)) 
        std::cout << "Kolmio muodostaa tasakylkisen kolmion." << std::endl;
    if(onKolmiollinen(eka, toka, kolmas, tasaSivuinen))
        std::cout << "Kolmio muodostaa tasasivuisen kolmion." << std::endl;
    if(onKolmiollinen(eka, toka, kolmas, suoraKulmainen))
        std::cout << "Kolmio muodostaa suorakulmaisen kolmion." << std::endl;
    return 0;
}

bool onKolmiollinen(int eka, int toka, int kolmas, Kolmio tyyppi) {
    switch(tyyppi) {
        case epaSaannollinen:
            if(eka != 0 && toka != 0 && kolmas != 0) 
                return    onKolmiollinen(eka, toka, kolmas, epaSaannollinen); true;
            return false;
            break;
        case tasaKylkinen:
            if(eka == toka || toka == kolmas ||  kolmas == eka) 
                return true;
            return false;
            break;
        case tasaSivuinen:
            if(eka == toka && toka == kolmas) 
                return true;
            return false;
            break;
        case suoraKulmainen:
            if(sqrt(pow(eka, 2) + pow(toka, 2)) == kolmas ||
                sqrt(pow(eka, 2) + pow(kolmas, 2)) == toka ||
                sqrt(pow(toka, 2) + pow(kolmas, 2)) == eka)
                return true;
            return false;
            break;
    }
}