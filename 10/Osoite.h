#ifndef OSOITE
#define OSOITE

#include <iostream>

class Osoite {
    public:
        Osoite();
        Osoite(const Osoite &o);
        Osoite(const std::string katu, const std::string posti, const std::string set_kunta);
        ~Osoite();
        void tulostaTiedot() const;
        void setKatuosoite(std::string osoite);
        void setPostinumero(std::string numero);
        void setKunta(std::string set_kunta);
        std::string getKatuosoite() const;
        std::string getPostinumero() const;
        std::string getKunta() const;

    private:
        std::string katuosoite;
        std::string postinumero;
        std::string kunta;

};

#endif