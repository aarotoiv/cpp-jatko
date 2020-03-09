#include "Paivays.h"

int main() {
    Paivays *tanaan = new Paivays();
    Paivays *huomenna = new Paivays();

    tanaan->setPaiva(9);
    tanaan->setKuukausi(3);
    tanaan->setVuosi(2020);

    huomenna->setPaiva(10);
    huomenna->setKuukausi(3);
    huomenna->setVuosi(2020);

    tanaan->tulostaPaivays();
    huomenna->tulostaPaivays(); 

    return 0;
}