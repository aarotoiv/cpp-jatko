#include "Opiskelija.h"

Opiskelija::Opiskelija() {
    opNro = "";
    opintopisteet = 0;
    setNimi("");
    setIka(0);
    setOsoite(Osoite());
    std::cout << "Opiskelija default" << std::endl;
}
Opiskelija::Opiskelija(const Opiskelija &o) {
    opNro = o.getOpNro();
    opintopisteet = o.getOpintopisteet();
    setNimi(o.getNimi());
    setIka(o.getIka());
    setOsoite(o.getOsoite());
    std::cout << "Opiskelija copy" << std::endl;
}
Opiskelija::Opiskelija(const std::string set_nimi, const int set_ika, const std::string set_opnro, const int set_op, const Osoite set_osoite) {
    setNimi(set_nimi);
    setIka(set_ika);
    opNro = set_opnro;
    opintopisteet = set_op;
    setOsoite(set_osoite);
    std::cout << "Opiskelija param" << std::endl;
}
Opiskelija::~Opiskelija() {
    suoritetutKurssit.clear();
}
void Opiskelija::lisaaKurssi(std::string kurssi) {
    suoritetutKurssit.push_back(kurssi);
}
void Opiskelija::poistaKurssi(std::string kurssi) {
    for(int i = 0; i<suoritetutKurssit.size(); i++) {
        if(suoritetutKurssit.at(i) == kurssi)
            suoritetutKurssit.erase(suoritetutKurssit.begin() + i);
    }
}
void Opiskelija::tulostaTiedot() const {
    std::cout << "Opnro: " << opNro << "\nOpintopisteet: " << opintopisteet << std::endl;
    for(int i = 0; i<suoritetutKurssit.size(); i++) {
        std::cout << "Kurssi" << i+1 << ": " << suoritetutKurssit.at(i) << "\n";
    }
}
int Opiskelija::getOpintopisteet() const {
    return opintopisteet;
}
int Opiskelija::lisaaOpintopisteita(int op) {
    opintopisteet += op;
}
std::string Opiskelija::getOpNro() const {
    return opNro;
}
void Opiskelija::setOpNro(std::string nro) {
    opNro = nro;
}