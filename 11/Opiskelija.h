#ifndef OPISKELIJA
#define OPISKELIJA

#include <iostream>
#include "Henkilo.h"
#include <vector>

class Opiskelija : public Henkilo {
    public:
        Opiskelija();
        Opiskelija(const Opiskelija &o);
        Opiskelija(const std::string set_nimi, const int set_ika, const std::string set_opnro, const int set_op, const Osoite set_osoite);
        ~Opiskelija();
        void lisaaKurssi();
        void lisaaKurssi(std::string kurssi);
        void poistaKurssi(std::string kurssi);
        void tulostaTiedot() const;
        int getOpintopisteet() const;
        int lisaaOpintopisteita(int op);
        std::string getOpNro() const;
        void setOpNro(std::string nro);
        void kysyTiedot();

    private:
        std::string opNro;
        std::vector<std::string> suoritetutKurssit;
        int opintopisteet;
};

#endif