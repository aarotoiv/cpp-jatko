#include <iostream>

class Osoite {
    public: 
        Osoite();
        Osoite(std::string setOsoite, std::string setNumero, std::string setKunta);
        ~Osoite();
        void tulostaTiedot() const;
        void setKatuosoite(std::string setOsoite);
        void setPostinumero(std::string setNumero);
        void setKunta(std::string setKunta);
        std::string getKatuosoite() const;
        std::string getPostinumero() const;
        std::string getKunta() const;
    private: 
        std::string katuosoite;
        std::string postinumero;
        std::string kunta;
};