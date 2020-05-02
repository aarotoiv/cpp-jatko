#include "Opettaja.h"
#include "Opiskelija.h"
#include <vector>
#include <iostream>

class Koulu {
    public:
        Koulu();
        ~Koulu();
        void lisaaOpiskelija(Opiskelija* opiskelija);
        void lisaaOpettaja(Opettaja* opettaja);
        void tulostaKaikkiTiedot() const;
        void tulostaOpettajat() const;
        void tulostaOpiskelijat() const;
        void setKouluNimi(std::string nimi);
        std::string getKouluNimi() const;

    private:
        std::string kouluNimi;
        std::vector<Opettaja*> opettajat;
        std::vector<Opiskelija*> opiskelijat;

};