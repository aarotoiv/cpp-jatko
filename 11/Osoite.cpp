#include "Osoite.h"
 
Osoite::Osoite() {
    katuosoite = "";
    postinumero = "";
    kunta = "";
    std::cout << "Osoite default" << std::endl;
}
Osoite::Osoite(const Osoite &o) {
    katuosoite = o.getKatuosoite();
    postinumero = o.getPostinumero();
    kunta = o.getKunta();
    std::cout << "Osoite copy" << std::endl;
}
Osoite::Osoite(const std::string katu, const std::string posti, const std::string set_kunta) {
    katuosoite = katu;
    postinumero = posti;
    kunta = set_kunta;
    std::cout << "Osoite param" << std::endl;
}
Osoite::~Osoite() {

}
void Osoite::tulostaTiedot() const {
    std::cout << "\nKatu: " << katuosoite << "\nPostinumero: " << postinumero << "\nKunta: " << kunta << std::endl;
}
void Osoite::setKatuosoite(std::string osoite) {
    katuosoite = osoite;
}
void Osoite::setPostinumero(std::string numero) {
    postinumero = numero;
}
void Osoite::setKunta(std::string set_kunta) {
    kunta = set_kunta;
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
void Osoite::kysyTiedot() {
    
}