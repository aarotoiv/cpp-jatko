#include <iostream>

class Henkilo {
    public:
        Henkilo();
        Henkilo(const Henkilo &h);
        Henkilo(std::string set_nimi, std::string set_osoite, int set_ika);
        ~Henkilo();

        std::string getNimi() const;
        std::string getOsoite() const;
        int getIka() const;

    private:
        std::string nimi;
        std::string osoite;
        int ika;
};