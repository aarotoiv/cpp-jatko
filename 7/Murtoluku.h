#include <iostream>

class Murtoluku {
    public:
        Murtoluku();
        Murtoluku(int set_osoittaja, int set_nimittaja);
        ~Murtoluku();
        void setOsoittaja(int set_osoittaja);
        void setNimittaja(int set_nimittaja);
        int getOsoittaja();
        int getNimittaja();

        void kysyTiedot();
        void tulosta();

        void sievenna();
        int gcd(int osoittaja, int nimittaja);

    private:
        int osoittaja;
        int nimittaja;

};