#include <iostream>
#include <string>
#include "Paivays.h"

class Kalenterimerkinta {
    public:
        Kalenterimerkinta();
        Kalenterimerkinta(const Kalenterimerkinta &km);
        Kalenterimerkinta(int paiva, int kuukausi, int vuosi, std::string setAsia, bool setMuistutus);
        ~Kalenterimerkinta();
        Paivays getPaivays() const;
        std::string getAsia() const;
        bool getMuistutus() const;
        void setPaivays(int paiva, int kuukausi, int vuosi);
        void setAsia(std::string setAsia);
        void setMuistutus(bool setMuistutus);
        void tulostaTiedot() const;
        void kysyTiedot();

    private:
        Paivays paivays;
        std::string asia;
        bool muistutus;
};