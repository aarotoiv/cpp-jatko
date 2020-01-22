#include <iostream>

struct aika_ty {
    int tunnit;
    int minuutit;
    int sekunnit;
};

aika_ty kysyTunnit();
aika_ty aikojenErotus(aika_ty eka, aika_ty toka);

int main() {
    aika_ty erotus = aikojenErotus(kysyTunnit(), kysyTunnit());
    std::cout << "Aika on: " << (erotus.tunnit > 9 ? "" : "0") << erotus.tunnit << ":" << (erotus.minuutit > 9 ? "" : "0") << erotus.minuutit << ":" << (erotus.sekunnit > 9 ? "" : "0") << erotus.sekunnit << std::endl;
    return 0;
}

aika_ty kysyTunnit() {
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
    aika.tunnit = tunnit;
    aika.minuutit = minuutit;
    aika.sekunnit = sekunnit;
    return aika;
}

aika_ty aikojenErotus(aika_ty toka, aika_ty eka) {
    aika_ty ret;
    ret.tunnit = eka.tunnit - toka.tunnit;
    ret.minuutit = eka.minuutit - toka.minuutit;
    ret.sekunnit = eka.sekunnit - toka.sekunnit;

    if(ret.sekunnit < 0) {
        ret.sekunnit = 60 + ret.sekunnit;
        ret.minuutit--;
    }
    if(ret.minuutit < 0) {
        std::cout << ret.minuutit << "WTF" << std::endl;
        ret.minuutit = 60 + ret.minuutit;
        ret.tunnit--;
    }
    if(ret.tunnit < 0) 
        std::cout << "hold up.." << std::endl;

    return ret;
}