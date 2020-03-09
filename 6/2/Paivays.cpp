#include "Paivays.h"

Paivays::Paivays() {
    paiva = 0;
    kuukausi = 0;
    vuosi = 0;
}
void Paivays::setPaiva(int set_paiva) {
    paiva = set_paiva;
}
void Paivays::setKuukausi(int set_kk) {
    kuukausi = set_kk;
}
void Paivays::setVuosi(int set_vv) {
    vuosi = set_vv;
}
void Paivays::kysyPvm() {
    std::cout << "Kerro paiva: " << std::endl;
    std::cin >> paiva;
    std::cout << "Kerro kuukausi: " << std::endl;
    std::cin >> kuukausi;
    std::cout << "Kerro vuosi: " << std::endl;
    std::cin >> vuosi;
}
void Paivays::lisaaPaiva() {
    paiva++;
    if(paiva > 30) {
        paiva = 1;
        kuukausi++;
    }
    if(kuukausi > 12) {
        kuukausi = 1;
        vuosi++;
    }
}

int Paivays::getPaiva() {
    return paiva;
}
int Paivays::getKuukausi() {
    return kuukausi;
}
int Paivays::getVuosi() {
    return vuosi;
}
void Paivays::tulostaPaivays() {
    std::cout << paiva << "." << kuukausi << "." << vuosi << std::endl;
}