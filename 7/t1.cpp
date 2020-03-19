#include <iostream>
#include "Henkilo.h"
#include "Paivays.h"

int main() {
    Henkilo hNoParam;
    Henkilo hParam("juu", 10);

    Paivays pNoParam;
    Paivays pParam(10, 10, 10);

    std::cout << "Paivays ilman parametreja: " << std::endl;
    hNoParam.tulostaHenkilonTiedot();

    std::cout << "Paivays parametrien kanssa: " << std::endl;
    hParam.tulostaHenkilonTiedot();

    std::cout << "Henkilo ilman parametreja: " << std::endl;
    pNoParam.tulostaPaivays();

    std::cout << "Henkilo parametrien kanssa: " << std::endl;
    pParam.tulostaPaivays();

    //kutsuu rakentajaa joka ei ota vastaan parametreja
    Henkilo henkilot[10];

    return 0;
}