#include "Kalenterimerkinta.h"
#include "Henkilo.h"
#include <vector>

void doSomethingArvo(Kalenterimerkinta aKalenterimerkinta);
void doSomethingRef(Kalenterimerkinta &rKalenterimerkinta);

int main() {
    //OSOITTIMET ON NOPEAMPIA
    //ilman osoittimia olio luodaan -> 
    //olio annetaan push_back metodille -> 
    //metodi luo kopion oliosta -> 
    //vanha tuhotaan ->
    //ei hyvä.
    //Osoittimilla riittää kun tehdään vain yksi olio, jonka osoite talletetaan vectoriin
    std::vector <Henkilo*> pHenkilot;
    pHenkilot.push_back(new Henkilo("juuuu u", "on on", 10));
    pHenkilot.push_back(new Henkilo("juuuu uu", "on onn", 20));
    pHenkilot.push_back(new Henkilo("juuuu uuu", "on onnn", 30));
    pHenkilot.push_back(new Henkilo("juuuu uuuu", "on onnnn", 40));
    pHenkilot.push_back(new Henkilo("juuuu uuuuu", "on onnnnn", 50));

    std::vector<Henkilo> henkilot;
    bool running = true;

    while(running) {
        std::cout << "\n\n\n\nILMOITA TOIMINTO:\n1. LISÄÄ UUSI HENKILÖ\n2. POISTA HENKILÖ\n3. TULOSTA HENKILÖT\n4. LOPETA" << std::endl;
        int komento = 0;
        std::cin >> komento;
        std::cin.ignore();
        std::cin.sync();
        switch(komento) {
            case 1: {
                std::string nimi = "";
                std::string osoite = "";
                int ika = 0;
                std::cout << "ILMOITA NIMI: " << std::endl;
                std::getline(std::cin, nimi);
                std::cout << "ILMOITA IKA: " << std::endl;
                std::cin >> ika;
                std::cin.ignore();
                std::cin.sync();
                std::cout << "ILMOITA OSOITE: " << std::endl;
                std::getline(std::cin, osoite);
                
                henkilot.push_back(Henkilo(nimi, osoite, ika));
                break;
            }
            case 2: {
                std::string nimi;
                std::cout << "ILMOITA HENKILON NIMI: " << std::endl;
                std::getline(std::cin, nimi);
                for(int i = 0; i<henkilot.size(); i++) {
                    if(henkilot.at(i).getNimi() == nimi) 
                        henkilot.erase(henkilot.begin() + i);
                }
                break;
            }
            case 3:
                for(int i = 0; i<henkilot.size(); i++) {
                    std::cout << henkilot.at(i).getNimi() << " " << henkilot.at(i).getIka() << " " << henkilot.at(i).getOsoite() << std::endl;
                }
                break;
            case 4:
                running = false;
                break;
        }
    }

    return 0;
}

// ei kuuluisi käyttää, koska uusi olio muodaan aina kun funktio kutsutaan
void doSomethingArvo(Kalenterimerkinta aKalenterimerkinta) {}

//voidaan kutsua nyt vain const merkittyjä funktioita, koska muuttuja on const jolloin sen arvojakaan ei voi muuttaa.
//kuuluisi laittaa parametriviitteen yhteyteen, mikäli halutaan esim. tarkastella olion dataa muuttamatta sitä.
void doSomethingRef(const Kalenterimerkinta &rKalenterimerkinta) {}
