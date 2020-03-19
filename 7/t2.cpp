#include <iostream>
#include "Henkilo.h"
#include "Paivays.h"

void luo();

int main() {
    //purkaja kutsutaan kun main functio loppuu
    Henkilo henkilo;

    if(true) {
        //purkaja kutsutaan kun if lause loppuu
        Henkilo toinenHenkilo;
    }

    for(int i = 0; i<10; i++) {
        //purkaja kutsutaan aina kun if lauseen kierros loppuu
        Henkilo kolmasHenkilo;
    }

    luo();

    Henkilo * ptrHenkilo = new Henkilo();
    //purkaja kutsutaan delete komennon ohessa
    delete ptrHenkilo;

    return 0;
}

void luo() {
    //purkaja kutsutaan kun aliohjelma loppuu
    Henkilo neljasHenkilo;
}