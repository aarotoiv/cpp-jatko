#ifndef HENKILO
#define HENKILO

#include <iostream>
#include "Osoite.h"

class Henkilo {
    public:
        Henkilo();
        Henkilo(const Henkilo &henkilo);
        Henkilo(const int set_ika, const std::string set_nimi, const Osoite set_osoite);
        ~Henkilo();
        void tulostaTiedot() const;
        void setNimi(std::string set_nimi);
        void setIka(int set_ika);
        std::string getNimi() const;
        int getIka() const;
        void setOsoite(Osoite set_osoite);
        Osoite getOsoite() const;
    private:
        int ika;
        std::string nimi;
        Osoite osoite;
};

#endif