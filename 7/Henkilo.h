#include <iostream>

class Henkilo {
    public:
        Henkilo();
        Henkilo(std::string set_nimi, int set_ika);
        ~Henkilo();
        void setNimi(std::string set_nimi);
        void setIka(int set_ika);
        void tulostaHenkilonTiedot();     
    private:
        std::string getNimi();
        int getIka();

        std::string nimi;
        int ika;
};