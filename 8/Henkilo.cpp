#include "Henkilo.h"

Henkilo::Henkilo() {
    nimi = "";
    ika = 0;
}
Henkilo::Henkilo(std::string set_nimi, int set_ika) {
    nimi = set_nimi;
    ika = set_ika;
    osoite = Osoite();
}
Henkilo::Henkilo(std::string set_nimi, int set_ika, std::string setOsoite, std::string setNumero, std::string setKunta) {
    nimi = set_nimi;
    ika = set_ika;
    osoite = Osoite(setOsoite, setNumero, setKunta);
}
Henkilo::~Henkilo() {
    nimi = "";
    ika = 0;
}
int Henkilo::getIka() const {
    return ika;
}
std::string Henkilo::getNimi() const {
    return nimi;
}
void Henkilo::setIka(int set_ika) {
    ika = set_ika;
}
void Henkilo::setNimi(std::string set_nimi) {
    nimi = set_nimi;
}
void Henkilo::tulostaHenkilonTiedot() const {
    std::cout << "Nimi: " << getNimi() << std::endl;
    std::cout << "Ika: " << getIka() << std::endl;
    osoite.tulostaTiedot();
    std::cout << std::endl;
}

void Henkilo::setOsoite(std::string setOsoite, std::string setNumero, std::string setKunta) {
    osoite = Osoite(setOsoite, setNumero, setKunta);
}

Osoite Henkilo::getOsoite() const {
    return osoite;
}