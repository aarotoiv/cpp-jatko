#include "Koulu.h"

int main() {
    /* TEHTÄVÄ 1
    Opettaja.cpp:48:5: error: ‘std::__cxx11::string Henkilo::nimi’ is private within this context
        nimi = "asdfasdf";
        ^~~~
    In file included from Opettaja.h:6:0,
                    from Opettaja.cpp:1:
    Henkilo.h:22:21: note: declared private here
            std::string nimi;
    
    EI MAHDOLLINEN 
    nimi on henkilo-luokan private atribuutti,
    joten sitä ei voida muuttaa perityistä luokista
    
    MAHDOLLINEN
    kun nimen ja iän muuttaa private --> protected
    */
    //Opettaja *opettaja = new Opettaja();
    //opettaja->muutaPrivate();

    /*TEHTÄVÄ 2
    Mikäli henkilö-luokan tulostaTiedot() metodiin lisätään "virtual"-sana,
    se kutsutaan vain silloin kun "aliluokalla" ei ole samannimistä metodia.
    Dynaaminen sidonta tarkoittaa sitä, että ohjelman runtimessa päätellään,
    mitä metodeja käytetään. 
    */
    //Henkilo *oppilas = new Opiskelija();
    //Henkilo *ope = new Opettaja();
    //oppilas->tulostaTiedot();
    //ope->tulostaTiedot();
    
    //TEHTÄVÄT 3-5
    Koulu *koulu = new Koulu();
    koulu->setKouluNimi("no se on joo");

    Opettaja *kouluOpettaja = new Opettaja();
    kouluOpettaja->kysyTiedot();
    koulu->lisaaOpettaja(kouluOpettaja);

    kouluOpettaja->lisaaKurssi();

    Opiskelija *kouluOpiskelija = new Opiskelija();
    kouluOpiskelija->kysyTiedot();
    koulu->lisaaOpiskelija(kouluOpiskelija);

    kouluOpiskelija->lisaaKurssi();


    koulu->tulostaOpettajat();
    koulu->tulostaOpiskelijat();
    koulu->tulostaKaikkiTiedot();

    return 0;
}