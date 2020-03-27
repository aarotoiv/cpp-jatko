#include "Kalenterimerkinta.h"

Kalenterimerkinta::Kalenterimerkinta() {
    paivays = Paivays();
    asia = "";
    muistutus = false;
}

Kalenterimerkinta::Kalenterimerkinta(int paiva, int kuukausi, int vuosi, std::string setAsia, bool setMuistutus) {
    paivays = Paivays(paiva, kuukausi, vuosi);
    asia = setAsia;
    muistutus = setMuistutus;
}

Kalenterimerkinta::~Kalenterimerkinta() {

}

Paivays Kalenterimerkinta::getPaivays() const {
    return paivays;
}

std::string Kalenterimerkinta::getAsia() const {
    return asia;
}

bool Kalenterimerkinta::getMuistutus() const {
    return muistutus;
}

void Kalenterimerkinta::setPaivays(int paiva, int kuukausi, int vuosi) {
    paivays = Paivays(paiva, kuukausi, vuosi);
}

void Kalenterimerkinta::setAsia(std::string setAsia) {
    asia = setAsia;
}

void Kalenterimerkinta::setMuistutus(bool setMuistutus) {
    muistutus = setMuistutus;
}

void Kalenterimerkinta::tulostaTiedot() const {
    std::cout << "Asia:\t" << asia
    << "\nMuistutus\t" << (muistutus ? "Paalla" : "Pois")
    << "\nPaivays:\t";
    paivays.tulostaPaivays();
}

void Kalenterimerkinta::kysyTiedot() {
    std::cout << "Kerro asia: " << std::endl;
    std::cin >> asia;
    std::cout << "Muistutus?(y/n)" << std::endl;
    std::string muistutusMuuttuja;
    std::cin >> muistutusMuuttuja;
    muistutus = muistutusMuuttuja == "y" ? true : false;
    int setPaiva;
    int setKK;
    int setVuosi;
    std::cout << "Kerro paiva: " << std::endl;
    std::cin >> setPaiva;
    std::cout << "Kerro kuukausi: " << std::endl;
    std::cin >> setKK;
    std::cout << "Kerro vuosi: " << std::endl;
    std::cin >> setVuosi;
    paivays = Paivays(setPaiva, setKK, setVuosi);
}