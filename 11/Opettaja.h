#ifndef OPETTAJA
#define OPETTAJA

#include <iostream>
#include <vector>
#include "Henkilo.h"

class Opettaja : public Henkilo {
    public:
        Opettaja();
        Opettaja(const Opettaja &o);
        Opettaja(const std::string nimi, const int ika, const std::string set_koulutusala, const std::vector<std::string> &set_kurssit);
        ~Opettaja();
        void tulostaTiedot() const;
        void poistaKurssi(std::string kurssi);
        void lisaaKurssi();
        void lisaaKurssi(std::string kurssi);
        void setKoulutusala(std::string set_koulutusala);
        std::string getKoulutusala() const;
        void muutaPrivate();
        void kysyTiedot();

    private:
        std::string koulutusala;
        std::vector<std::string> kurssit;
};

#endif