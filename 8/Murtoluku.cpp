#include "Murtoluku.h"

Murtoluku::Murtoluku() {
    osoittaja = 0;
    nimittaja = 0;
}

Murtoluku::Murtoluku(int set_osoittaja, int set_nimittaja) {
    osoittaja = set_osoittaja;
    nimittaja = set_nimittaja;
}

Murtoluku::~Murtoluku() {
    osoittaja = 0;
    nimittaja = 0;
}

void Murtoluku::setOsoittaja(int set_osoittaja) {
    osoittaja = set_osoittaja;
}

void Murtoluku::setNimittaja(int set_nimittaja) {
    nimittaja = set_nimittaja;
}

int Murtoluku::getOsoittaja() const {
    return osoittaja;
}

int Murtoluku::getNimittaja() const {
    return nimittaja;
}

void Murtoluku::kysyTiedot() {
    std::cout << "Ilmoita osoittaja: " << std::endl;
    std::cin >> osoittaja;
    std::cout << "Ilmoita nimittaja: " << std::endl;
    std::cin >> nimittaja;
}

void Murtoluku::tulosta() const {
    std::cout << osoittaja << "/" << nimittaja << std::endl;
}

void Murtoluku::sievenna() {
    int jako = gcd(osoittaja, nimittaja);
    osoittaja /= jako;
    nimittaja /= jako;
    std::cout << jako << std::endl;
}

int Murtoluku::gcd(int osoittaja, int nimittaja) const {
    if(nimittaja == 0)
        return osoittaja;
    else
        return gcd(nimittaja, (osoittaja % nimittaja));
}