#include "Osoite.h"

Osoite::Osoite() {
    katuosoite = "";
    postinumero = "";
    kunta = "";
}

Osoite::Osoite(std::string setOsoite, std::string setNumero, std::string setKunta) {
    katuosoite = setOsoite;
    postinumero = setNumero;
    kunta = setKunta;
}

Osoite::~Osoite() {

}

void Osoite::tulostaTiedot() const {
    std::cout
    << "Osoite: \t" << katuosoite 
    << "\nPostinumero: \t" << postinumero
    << "\nKunta: \t" << kunta 
    << std::endl;
}

void Osoite::setKatuosoite(std::string setOsoite) {
    katuosoite = setOsoite;
}

void Osoite::setPostinumero(std::string setNumero) {
    postinumero = setNumero;
}

void Osoite::setKunta(std::string setKunta) {
    kunta = setKunta;
}

std::string Osoite::getKatuosoite() const {
    return katuosoite;
}   

std::string Osoite::getPostinumero() const {
    return postinumero;
}

std::string Osoite::getKunta() const {
    return kunta;
}