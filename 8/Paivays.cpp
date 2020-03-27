#include "Paivays.h"

Paivays::Paivays() {
    paiva = 0;
    kuukausi = 0;
    vuosi = 0;
}
Paivays::Paivays(int set_paiva, int set_kk, int set_vuosi) {
    paiva = set_paiva; 
    kuukausi = set_kk;
    vuosi = set_vuosi;
}
Paivays::~Paivays() {
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

int Paivays::getPaiva() const {
    return paiva;
}
int Paivays::getKuukausi() const {
    return kuukausi;
}
int Paivays::getVuosi() const {
    return vuosi;
}
void Paivays::tulostaPaivays() const {
    std::cout << paiva << "." << kuukausi << "." << vuosi << std::endl;
}