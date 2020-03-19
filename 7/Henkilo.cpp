#include "Henkilo.h"

Henkilo::Henkilo() {
    nimi = "";
    ika = 0;
}
Henkilo::Henkilo(std::string set_nimi, int set_ika) {
    nimi = set_nimi;
    ika = set_ika;
}
Henkilo::~Henkilo() {
    nimi = "";
    ika = 0;
}
int Henkilo::getIka() {
    return ika;
}
std::string Henkilo::getNimi() {
    return nimi;
}
void Henkilo::setIka(int set_ika) {
    ika = set_ika;
}
void Henkilo::setNimi(std::string set_nimi) {
    nimi = set_nimi;
}
void Henkilo::tulostaHenkilonTiedot() {
    std::cout << "Nimi: " << getNimi() << std::endl;
    std::cout << "Ika: " << getIka() << std::endl;
}
