#include <iostream>

class Murtoluku {
    public:
        Murtoluku();
        Murtoluku(int set_osoittaja, int set_nimittaja);
        ~Murtoluku();
        void setOsoittaja(int set_osoittaja);
        void setNimittaja(int set_nimittaja);
        int getOsoittaja() const;
        int getNimittaja() const;

        void kysyTiedot();
        void tulosta() const;

        void sievenna();
        int gcd(int osoittaja, int nimittaja) const;

    private:
        int osoittaja;
        int nimittaja;

};