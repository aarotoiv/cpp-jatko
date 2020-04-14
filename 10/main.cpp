#include "Opettaja.h"
#include "Opiskelija.h"

int main() {
    Henkilo henkilo();
    Henkilo hhenkilo(100, "aaaa", Osoite("aaa", "aaa", "aaaa"));
    Henkilo hhhenkilo(hhenkilo);

    Opettaja opettaja();
    std::vector <std::string> vec;
    Opettaja oopettaja("aaa", 1000, "aaaaaaaa", vec);
    Opettaja ooopettaja(oopettaja);

    Opiskelija opiskelija();
    Opiskelija oopiskelija("aaaaaaaa", 1010101001, "aaaaaaaaaaaaaaaaaa", 1010101, Osoite("aaaaaaa", "aaaaa", "aaaa"));
    Opiskelija ooopiskelija(oopiskelija);

    std::vector<Henkilo*> henkilot;
    henkilot.push_back(new Henkilo(100, "aaaa", Osoite("aaa", "aaa", "aaaa")));
    henkilot.push_back(new Opettaja("aaa", 1000, "aaaaaaaa", vec));
    henkilot.push_back(new Opiskelija("aaaaaaaa", 1010101001, "aaaaaaaaaaaaaaaaaa", 1010101, Osoite("aaaaaaa", "aaaaa", "aaaa")));

    //voidaan kutsua vain henkilö luokalle annettuja metodeja, sillä kaikilla vectorissa pitää olla käytetty kutsuttu metodi.
    //esim. lisaaOpintopisteita() metodia ei voida kutsua, sillä vain opiskelijat omaavat sen.
    for(int i = 0; i<henkilot.size(); i++) {
        henkilot.at(i)->tulostaTiedot();
    }

    return 0;
}