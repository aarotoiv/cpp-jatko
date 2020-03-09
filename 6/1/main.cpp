#include "Henkilo.h"

int main() {
    Henkilo *eka = new Henkilo();
    Henkilo *toka = new Henkilo();
    eka->setNimi("Pena");
    eka->setIka(43);

    toka->setNimi("nojuu");
    toka->setIka(20);

    eka->tulostaHenkilonTiedot();
    toka->tulostaHenkilonTiedot();

    return 0;
}