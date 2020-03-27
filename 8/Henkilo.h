#include <iostream>
#include "Osoite.h"

class Henkilo {
    public:
        Henkilo();
        Henkilo(std::string set_nimi, int set_ika);
        Henkilo(std::string set_nimi, int set_ika, std::string setOsoite, std::string setNumero, std::string setKunta);
        ~Henkilo();
        void setNimi(std::string set_nimi);
        void setIka(int set_ika);
        void tulostaHenkilonTiedot() const;     
        void setOsoite(std::string setOsoite, std::string setNumero, std::string setKunta);
        Osoite getOsoite() const;

    private:
        std::string getNimi() const;
        int getIka() const;

        std::string nimi;
        int ika;

        Osoite osoite;
};