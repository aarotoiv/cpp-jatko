#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <string>
#include <sstream>
#include <limits>

struct Numerot {
    int numerot[7] = {0,0,0,0,0,0,0};
    int lisaNumero = 0;
    int plusNumero = 0;
};


void pyydaNumerot(int (&pyydetyt)[7]);
Numerot pyydaArvotutNumerot();
void arvoNumerot(int *numerot, int& plus);
void analyysi(int (&omatNumerot)[7], Numerot arvotutNumerot);
bool onJo(int arvotut[], int numero, int len);
void askForEnter();


int main() {
    bool running = true;
    int komento = 0;
    
    srand(time(NULL));
    std::cout << "Tervetuloa lottopeliin!" << std::endl;
    while(running) {
        std::cout << "Ilmoita komento:\n" 
        << "1) Lue ja tulosta lottorivi\n" 
        << "2) Lue käyttäjän ja oikea rivi, tee tulosanalyysi\n" 
        << "3) Lopeta ohjelman ajo\n"
        << std::endl;

        std::cin >> komento;
        std::cin.ignore();
        
        if(komento == 1) {
            int numerot[7] = {0,0,0,0,0,0,0};
            pyydaNumerot(numerot);  
            std::cout << "KÄYTTÄJÄN RIVI ON:";
            for(int i = 0; i<7; i++) {
                std::cout << " " << numerot[i];
            }
            askForEnter();
        } else if(komento == 2) {
            int omatNumerot[7] = {0,0,0,0,0,0,0};
            pyydaNumerot(omatNumerot);
            Numerot arvotutNumerot = pyydaArvotutNumerot();
            
            analyysi(omatNumerot, arvotutNumerot);
    
            askForEnter();
        } else if(komento == 3) {
            std::cout << "Ohjelman ajo loppuu." << std::endl;
            running = false;
            break;
        }
    }
    return 0;
}

void pyydaNumerot(int (&pyydetyt)[7]) {
    std::cout << "ILMOITA NUMEROT: " << std::endl;
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
        else if(quit) 
            std::cout << "Ilmoitit useamman saman numeron, tai numerot eivat ole rajojen sisalla" << std::endl;
    }
}
Numerot pyydaArvotutNumerot() {
    int numerot[7] = {0,0,0,0,0,0,0};
    pyydaNumerot(numerot);  
    int lisaNumero = 0;
    std::cout << "Anna arvottu lisänumero: ";
    while(lisaNumero == 0) {
        int temp = 0;
        std::cin >> temp;
        if(!onJo(numerot, temp, 7) && temp > 0 && temp < 41) 
            lisaNumero = temp;
        else 
            std::cout << "Lisänumero ei sovi." << std::endl;
    }
    int plus = 0; 
    std::cout << "Anna arvottu plusnumero: ";
    while(plus == 0) {
        int temp = 0; 
        std::cin >> temp;
        if(!onJo(numerot, temp, 7) && temp > 0 && temp < 31) 
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

void arvoNumerot(int *numerot, int &plus) {
    for(int i = 0; i<7; i++) {
        numerot[i] = 0;
        while(numerot[i] == 0) {
            int temp = rand() % 40 + 1;
            if(temp > 0 && temp < 41 && !onJo(numerot, temp, 7)) 
                numerot[i] = temp;
        }
    }
    plus = rand() % 30 + 1;
}

bool onJo(int arvotut[], int numero, int len) {
    for(int i = 0; i<len; i++) {
        if(arvotut[i] == numero)
            return true;
    }
    return false;
}
void askForEnter() {
    std::cout << "\nPAINA ENTER jatkaaksesi ...\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << "\n\n" << std::endl;
}