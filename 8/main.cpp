#include <iostream>
#include "Henkilo.h"
#include "Kalenterimerkinta.h"

int main() {
    Henkilo henkilo("juu", 10, "Katukatu 183", "23432", "Kyllkyll");
    Henkilo henkiloKaksi("onon", 200);
    henkiloKaksi.setOsoite("JokuKatu 182", "23923", "Juuuu");
    henkilo.tulostaHenkilonTiedot();
    henkiloKaksi.tulostaHenkilonTiedot();

    Kalenterimerkinta merkinta;
    merkinta.kysyTiedot();
    Kalenterimerkinta toinenMerkinta(10, 10, 1999, "Asia on se.", true);
    
    merkinta.tulostaTiedot();
    toinenMerkinta.tulostaTiedot();
    
    return 0;
}