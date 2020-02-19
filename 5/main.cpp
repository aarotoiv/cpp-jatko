#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <string>
#include <sstream>
#include <limits>
#include <vector>
#include <array>
#include <algorithm>
#include <fstream>

//numerot structi
struct Numerot {
    int numerot[7] = {0,0,0,0,0,0,0};
    int lisaNumero = 0;
    int plusNumero = 0;
};


void pyydaNumerot(int (&pyydetyt)[7], bool canForceQuit);
void pyydaMonta(std::vector<std::array<int, 7>> &kaikkiNumerot);
void lueTiedostosta(std::vector<std::array<int, 7>> &kaikkiNumerot);
Numerot pyydaArvotutNumerot();
Numerot arvoNumerot();
void analyysi(int (&omatNumerot)[7], Numerot arvotutNumerot);
void analysoiMonta(std::vector<std::array<int, 7>> &kaikkiNumerot, Numerot arvotutNumerot);
bool onJo(int arvotut[], int numero, int len);
void askForEnter();



int main() {
    //running muuttuja jolloin tietää koska ohjelma lopetetaan.
    bool running = true;
    int komento = 0;
    
    //seedi randille jota käytetään arvonnoissa
    srand(time(NULL));

    std::cout << "Tervetuloa lottopeliin!" << std::endl;
    //mainloop
    while(running) {
        std::cout << "Ilmoita komento:\n" 
        << "1) Lue ja tulosta lottorivi\n" 
        << "2) Lue käyttäjän ja oikea rivi, tee tulosanalyysi\n" 
        << "3) Lue käyttäjän rivi, arvo oikea rivi, tee tulosanalyysi\n"
        << "4) Lue monta käyttäjän riviä, arvo oikea rivi, tee tuloasanalyysi\n"
        << "5) Lue pelitiedot tiedostosta, tee tuloanalyysi\n"
        << "6) Lopeta ohjelman ajo\n"
        << std::endl;

        std::cin >> komento;
        std::cin.ignore();
        
        //pyydetään käyttäjän numerot ja tulostetaan ne
        if(komento == 1) {
            int numerot[7] = {0,0,0,0,0,0,0};
            std::cout << "ILMOITA NUMEROT: ";
            pyydaNumerot(numerot, false);  
            std::cout << "KÄYTTÄJÄN RIVI ON:";
            for(int i = 0; i<7; i++) {
                std::cout << " " << numerot[i];
            }
            askForEnter();
        } 
        //pyydetään käyttäjän numerot ja pyydetään arvotut numerot
        //tehdään analyysi
        else if(komento == 2) {
            int omatNumerot[7] = {0,0,0,0,0,0,0};
            std::cout << "ILMOITA KÄYTTÄJÄN NUMEROT: ";
            pyydaNumerot(omatNumerot, false);
            Numerot arvotutNumerot = pyydaArvotutNumerot();
            
            analyysi(omatNumerot, arvotutNumerot);
    
            askForEnter();
        }
        //pyydetään käyttäjän numerot ja arvotaan numerot
        //tehdään analyysi 
        else if(komento == 3) {
            int omatNumerot[7] = {0,0,0,0,0,0,0};
            std::cout << "ILMOITA KÄYTTÄJÄN NUMEROT: ";
            pyydaNumerot(omatNumerot, false);
            Numerot arvotutNumerot = arvoNumerot();
            
            analyysi(omatNumerot, arvotutNumerot);

            askForEnter();
        }
        //pyydetään numeroita kunnes käyttäjä syöttää tyhjän rivin
        //tehdään analyysit mikäli käyttäjä syötti vähintään yhden rivin 
        else if(komento == 4) {
            std::vector<std::array<int, 7>> kaikkiNumerot;
            pyydaMonta(kaikkiNumerot);
            if(kaikkiNumerot.size() > 0) {
                Numerot arvotutNumerot = arvoNumerot();
                analysoiMonta(kaikkiNumerot, arvotutNumerot);
            } else {
                std::cout << "Et syöttänyt yhtäkään täyttä riviä." << std::endl;
            }
            askForEnter();
        }
        //luetaan numerot tiedostosta, vain rivit joissa on kaikki 7 numeroa huomioidaan
        //tehdään analyysit 
        else if(komento == 5) {
            std::vector<std::array<int, 7>> kaikkiNumerot;
            lueTiedostosta(kaikkiNumerot);
            if(kaikkiNumerot.size() > 0) {
                Numerot arvotutNumerot = arvoNumerot();
                analysoiMonta(kaikkiNumerot, arvotutNumerot);
            } else {
                std::cout << "Yhtäkään täyttä riviä ei luettu." << std::endl;
            }
            askForEnter();
        }
        //lopetetaan ohjelma 
        else if(komento == 6) {
            std::cout << "Ohjelman ajo loppuu." << std::endl;
            running = false;
            break;
        }
    }
    return 0;
}

//käyttäjältä pyydetään perus 7 numeron rivi.
//en huomannut tekstiä: "virhekäsittelyä ei tarvitse tehdä syöttötiedoille", joten tästä löytyy varsin tarkat "checkerit"
void pyydaNumerot(int (&pyydetyt)[7], bool canForceQuit) {
    int i = 0;
    while(i < 7) {
        std::fill_n(pyydetyt, 7, 0);
        bool quit = false;
        i = 0;
        std::string input;
        std::getline(std::cin, input);
        std::stringstream ssin(input);
        while(ssin.good() && i < 7) {
            int temp = 0;
            ssin >> temp; 
            if(!onJo(pyydetyt, temp, i+1) && temp > 0 && temp < 41) {
                pyydetyt[i] = temp;
                ++i;
            } else {
                quit = true;
                break;
            }
        }
        if(i < 7 && !quit) 
            std::cout << "ET SYÖTTÄNYT TARPEEKSI NUMEROITA" << std::endl;
        else if(i < 7 && canForceQuit) 
            i = 7;
        else if(quit) 
            std::cout << "Ilmoitit useamman saman numeron, tai numerot eivat ole rajojen sisalla" << std::endl;
    }
}
//käyttäjältä pyydetään rivejä, kunnes vajaavainen rivi palautetaan, jolloin tiedetään että käyttäjä ei tahdo enää syöttää rivejä.
void pyydaMonta(std::vector<std::array<int, 7>> &kaikkiNumerot) {
    bool asking = true;
    int i = 0;
    while(asking) {
        i++;
        int numerot[7] = {0,0,0,0,0,0,0};
        std::cout << "ILMOITA käyttäjän " << i << " numerot:";
        pyydaNumerot(numerot, true);
        if(numerot[0] == 0 || numerot[1] == 0 || numerot[2] == 0 || numerot[3] == 0 || numerot[4] == 0 || numerot[5] == 0 || numerot[6] == 0) {
            asking = false;
            break;
        }   
        else {
            std::array<int, 7> temp;
            std::copy(std::begin(numerot), std::end(numerot), std::begin(temp));
            kaikkiNumerot.push_back(temp);
        }
        std::cout << std::endl;
    }
}
//luetaan tiedostosta rivit
//vain rivit joilla on 7 numeroa huomioidaan
void lueTiedostosta(std::vector<std::array<int, 7>> &kaikkiNumerot) {
    std::string nimi;
    std::cout << "Ilmoita tiedoston nimi: " << std::endl;
    std::cin >> nimi;
    std::cin.ignore();
    std::ifstream file(nimi);
    std::string line;
    int rivit = 0;
    if(file.is_open()) {
        while(getline(file, line)) {std::cout << "ILMOITA NUMEROT: ";
            std::array<int, 7> rivi;

            std::stringstream ssin(line);
            int i = 0;
            while(ssin.good() && i < 7) {
                int temp = 0;
                ssin >> rivi[i];
                ++i;
            }
            if(i == 7) {
                kaikkiNumerot.push_back(rivi);
                rivit++;
            }
            
        }
        file.close();
        std::cout << "Syötit " << rivit << " täyttä riviä.\n" << std::endl;
    } else 
        std::cout << "TIEDOSTOA EI VOIDA AVATA\n" << std::endl;

}
//pyydä arvotut numerot
//palauttaa structin, koska lisanumero ja plusnumero vaaditaan myös
Numerot pyydaArvotutNumerot() {
    std::cout << "ILMOITA ARVOTUT NUMEROT: ";
    int numerot[7] = {0,0,0,0,0,0,0};
    pyydaNumerot(numerot, false);  
    int lisaNumero = 0;
    std::cout << "Anna arvottu lisänumero: ";
    while(lisaNumero == 0) {
        int temp = 0;
        std::cin >> temp;
        if(temp > 0 && temp < 41) 
            lisaNumero = temp;
        else 
            std::cout << "Lisänumero ei sovi." << std::endl;
    }
    int plus = 0; 
    std::cout << "Anna arvottu plusnumero: ";
    while(plus == 0) {
        int temp = 0; 
        std::cin >> temp;
        if(temp > 0 && temp < 31) 
            plus = temp;
        else 
            std::cout << "Plusnumero ei sovi." << std::endl;
    }
    
    Numerot neNumerot;

    for(int i = 0; i<7; i++) {
        neNumerot.numerot[i] = numerot[i];
    }
    neNumerot.lisaNumero = lisaNumero;
    neNumerot.plusNumero = plus;
    return neNumerot;
}
//analyysi
void analyysi(int (&omatNumerot)[7], Numerot arvotutNumerot) {
    int oikein = 0;
    bool lisaOikein = false;
    bool plusOikein = false;

    for(int i = 0; i<7; i++) {
        for(int j = 0; j<7; j++) {
            if(omatNumerot[i] == arvotutNumerot.numerot[j]) 
                oikein++;
        }
        if(omatNumerot[i] == arvotutNumerot.lisaNumero) 
            lisaOikein = true;

        if(omatNumerot[i] == arvotutNumerot.plusNumero)
            plusOikein = true;
    }

    std::cout << "Tulos: " 
    << oikein 
    << (lisaOikein ? "+1" : "") 
    << " oikein"
    << (plusOikein ? ", plusnumero oikein" : ", plusnumero väärin") 
    << std::endl;    
}
//analysoi monta riviä
//analysoidaan niin monta riviä kuin "kaikkinumerot" vectorista löytyy
void analysoiMonta(std::vector<std::array<int, 7>> &kaikkiNumerot, Numerot arvotutNumerot) {
    std::cout << "TULOS:" << std::endl;
    for(int i = 0; i<kaikkiNumerot.size(); i++) {
        std::cout << "Käyttäjän " << i+1 << " rivi: ";
        int temp[7] = {0,0,0,0,0,0,0};
        std::copy(kaikkiNumerot[i].begin(), kaikkiNumerot[i].end(), std::begin(temp));
        analyysi(temp, arvotutNumerot);
    }
}

//arvotaan numerot
Numerot arvoNumerot() {
    Numerot arvotutNumerot;
    for(int i = 0; i<7; i++) {
        arvotutNumerot.numerot[i] = 0;
        while(arvotutNumerot.numerot[i] == 0) {
            int temp = rand() % 40 + 1;
            if(!onJo(arvotutNumerot.numerot, temp, 7)) 
                arvotutNumerot.numerot[i] = temp;
        }
    }
    while(arvotutNumerot.lisaNumero == 0) {
        int lisa = rand() % 40 + 1;
        if(!onJo(arvotutNumerot.numerot, lisa, 7)) 
            arvotutNumerot.lisaNumero = lisa;
    }
    while(arvotutNumerot.plusNumero == 0) {
        int plus = rand() % 30 + 1;
        if(!onJo(arvotutNumerot.numerot, plus, 7)) 
            arvotutNumerot.plusNumero = plus;
    }
    std::cout << "Numerot arvottiin" << std::endl;
    return arvotutNumerot;
}

//apufunktio jolla voi katsoa, onko arvottu tai syötetty numero jo taulukossa
bool onJo(int arvotut[], int numero, int len) {
    for(int i = 0; i<len; i++) {
        if(arvotut[i] == numero)
            return true;
    }
    return false;
}
//pyydä käyttäjää painamaan enteriä, jotta ohjelma jatkuu
void askForEnter() {
    std::cout << "\nPAINA ENTER jatkaaksesi ...\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << "\n\n" << std::endl;
}