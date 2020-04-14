#include "Opettaja.h"

Opettaja::Opettaja() {
    koulutusala = "";
    setNimi("");
    setIka(0);
    std::cout << "Opettaja default" << std::endl;
}
Opettaja::Opettaja(const Opettaja &o) {
    koulutusala = o.getKoulutusala();
    kurssit = o.kurssit;
    setNimi(o.getNimi());
    setIka(o.getIka());
    std::cout << "Opettaja copy" << std::endl;
}
Opettaja::Opettaja(const std::string nimi, const int ika, const std::string set_koulutusala, const std::vector<std::string> &set_kurssit) {
    setNimi(nimi);
    setIka(ika);
    koulutusala = set_koulutusala;
    kurssit = kurssit;
    std::cout << "Opettaja param" << std::endl;
}
Opettaja::~Opettaja() {
    kurssit.clear();
}
void Opettaja::tulostaTiedot() const {
    std::cout << "Koulutusala: " << koulutusala << std::endl;
    for(int i = 0; i<kurssit.size(); i++) {
        std::cout << "Kurssi" << i+1 << ": " << kurssit.at(i);
    }
}
void Opettaja::poistaKurssi(std::string kurssi) {
    for(int i = 0; i<kurssit.size(); i++) {
        if(kurssit.at(i) == kurssi)
            kurssit.erase(kurssit.begin() + i);
    }
}
void Opettaja::lisaaKurssi(std::string kurssi) {
    kurssit.push_back(kurssi);
}
void Opettaja::setKoulutusala(std::string set_koulutusala) {
    koulutusala = set_koulutusala;
}
std::string Opettaja::getKoulutusala() const {
    return koulutusala;
}