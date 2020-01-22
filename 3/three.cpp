#include <iostream>

struct aika_ty {
    int tunnit;
    int minuutit;
    int sekunnit;
};

int main() {
    bool kunnossa = false;
    int tunnit = 0;
    int minuutit = 0;
    int sekunnit = 0;
    aika_ty aika;
    while(!kunnossa) {
        std::cout << "Anna tunnit: " << std::endl;
        std::cin >> tunnit;
        if(tunnit > 23 || tunnit < 0) {
            std::cout << "Syötit sopimattoman tuntinumeron, kokeile uudestaan." << std::endl;
            continue;
        }
        std::cout << "Anna minuutit: " << std::endl;
        std::cin >> minuutit;
        if(minuutit > 59 || minuutit < 0) {
            std::cout << "Syötit sopimattoman minuuttinumeron, kokeile uudestaan." << std::endl;
            continue;
        } 
        std::cout << "Anna sekunnit: " << std::endl;
        std::cin >> sekunnit;
        if(sekunnit > 59 || sekunnit < 0) { 
            std::cout << "Syötit sopimattoman sekuntinumeron, kokeile uudestaan." << std::endl;
            continue;
        }

        kunnossa = true;
    }
    std::cout << "Aika on: " << (tunnit > 9 ? "" : "0") << tunnit << ":" << (minuutit > 9 ? "" : "0") << minuutit << ":" << (sekunnit > 9 ? "" : "0") << sekunnit << std::endl;
    aika.tunnit = tunnit;
    aika.minuutit = minuutit;
    aika.sekunnit = sekunnit;
    
    aika_ty *aikaPtr = &aika;
    std::cout << "Aika on: " << (aikaPtr->tunnit > 9 ? "" : "0") << aikaPtr->tunnit << ":" << (aikaPtr->minuutit > 9 ? "" : "0") << aikaPtr->minuutit << ":" << (aikaPtr->sekunnit > 9 ? "" : "0") << aikaPtr->sekunnit << std::endl;

    aika_ty eka;
    aika_ty toka = {tunnit: 12, minuutit: 12, sekunnit: 12}; 

    eka = toka;

    if (eka.tunnit == toka.tunnit && eka.minuutit == toka.minuutit && eka.sekunnit == toka.sekunnit) 
        std::cout << "Sisällöt ovat samat" << std::endl;
    return 0;
}