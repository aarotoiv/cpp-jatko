#include <iostream>

class Paivays {
    public:
        Paivays();
        Paivays(int set_paiva, int set_kk, int set_vuosi);
        ~Paivays();
        void setPaiva(int set_paiva);
        void setKuukausi(int set_kk);
        void setVuosi(int set_vuosi);

        int getPaiva();
        int getKuukausi();
        int getVuosi();
        void tulostaPaivays();

        void lisaaPaiva();
        void kysyPvm();

    private:
        int paiva;
        int kuukausi;
        int vuosi;
};