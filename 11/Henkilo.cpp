#include "Henkilo.h"

Henkilo::Henkilo() {
    ika = 0;
    nimi = "";
    osoite = Osoite();
    std::cout << "Henkilo default" << std::endl;
}
Henkilo::Henkilo(const Henkilo &henkilo) {
    ika = henkilo.ika;
    nimi = henkilo.getNimi();
    osoite = henkilo.getOsoite();
    std::cout << "Henkilo copy" << std::endl;
}
Henkilo::Henkilo(const int set_ika, const std::string set_nimi, const Osoite set_osoite) {
    ika = set_ika;
    nimi = set_nimi;
    osoite = set_osoite;
    std::cout << "Henkilo param" << std::endl;
}
Henkilo::~Henkilo() {

}
void Henkilo::tulostaTiedot() const {
    std::cout << "TULOSTETAAN HENKILON TIEDOT: \n";
    std::cout << "HENKILON TIEDOT:\nNimi: " << nimi << "\nIka: " << ika;
    osoite.tulostaTiedot();
}
void Henkilo::setNimi(std::string set_nimi) {
    nimi = set_nimi;
}
void Henkilo::setIka(int set_ika) {
    ika = set_ika;
}
std::string Henkilo::getNimi() const {
    return nimi;
}
int Henkilo::getIka() const {
    return ika;
}
void Henkilo::setOsoite(Osoite set_osoite) {
    osoite = set_osoite;
}
Osoite Henkilo::getOsoite() const {
    return osoite;
}