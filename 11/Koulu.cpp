#include "Koulu.h"        
        
Koulu::Koulu() {
    kouluNimi = "";
}
Koulu::~Koulu() {
    opiskelijat.clear();
    opettajat.clear();
}
void Koulu::lisaaOpiskelija(Opiskelija* opiskelija) {
    opiskelijat.push_back(opiskelija);
}
void Koulu::lisaaOpettaja(Opettaja* opettaja) {
    opettajat.push_back(opettaja);
}
void Koulu::tulostaKaikkiTiedot() const {
    std::cout << "Tulostetaan koulun tiedot: \n"
    << "Koulun Nimi: " << kouluNimi
    << "\nOpettajien määrä: " << opettajat.size()
    << "\nOpiskelijoiden määrä: " << opiskelijat.size()
    << std::endl;
    std::cout << "Tulostetaan opettajien tiedot:\n";
    tulostaOpettajat();
    std::cout << "Tulostetaan opiskelijoiden tiedot:\n";
    tulostaOpiskelijat();
}
void Koulu::tulostaOpettajat() const {
    for(int i = 0; i<opettajat.size(); i++) {
        std::cout << "Opettajan " << i+1 << " tiedot:\n";
        opettajat[i]->tulostaTiedot();
    }
}
void Koulu::tulostaOpiskelijat() const {
    for(int i = 0; i<opiskelijat.size(); i++) {
        std::cout << "Opiskelijan " << i+1 << " tiedot:\n";
        opiskelijat[i]->tulostaTiedot();
    }
}
void Koulu::setKouluNimi(std::string nimi) {
    kouluNimi = nimi;
}
std::string Koulu::getKouluNimi() const {
    return kouluNimi;
}