#include "Henkilo.h"

Henkilo::Henkilo() {
    nimi = "";
    osoite = "";
    ika = 0;
}

Henkilo::Henkilo(std::string set_nimi, std::string set_osoite, int set_ika) {
    nimi = set_nimi;
    osoite = set_osoite;
    ika = set_ika;
    std::cout << "CONSTRUCTOR CALLED" << std::endl;
}

Henkilo::Henkilo(const Henkilo &h) {
    nimi = h.nimi;
    osoite = h.osoite;
    ika = h.ika;
    
    std::cout << "COPIER CALLED" << std::endl;
}

Henkilo::~Henkilo() {
    std::cout << "DESTRUCTOR CALLED" << std::endl;
}

std::string Henkilo::getNimi() const {
    return nimi;
}

std::string Henkilo::getOsoite() const {
    return osoite;
}

int Henkilo::getIka() const {
    return ika;
}