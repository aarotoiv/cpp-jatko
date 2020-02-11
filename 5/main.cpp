#include <iostream>
#include <stdlib.h>
#include <time.h> 
#include <string>
#include <sstream>

void pyydaNumerot();
void arvoNumerot(int *numerot, int& plus);
void analyysi(int *numerot, int plus, int *arvotut, int aPlus);
bool onJo(int arvotut[], int numero, int len);

struct Numerot {
    int numerot[7];
    int lisaNumero;
    int plusNumero;
};

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
            pyydaNumerot();  

        } else if(komento == 2) {
            

        } else if(komento == 3) {
            std::cout << "Ohjelman ajo loppuu." << std::endl;
            running = false;
            break;
        }
    }
    return 0;
}

void pyydaNumerot() {
    std::cout << "ILMOITA NUMEROT: " << std::endl;
    int pyydetyt[7] = {0,0,0,0,0,0,0};
    

    int i = 0;
    while(i < 7) {
        i = 0;
        std::string input;
        std::getline(std::cin, input);
        std::stringstream ssin(input);
        while(ssin.good() && i < 7) {
            ssin >> pyydetyt[i]; 
            ++i;
        }
        if(i < 7) 
            std::cout << "ET SYÖTTÄNYT TARPEEKSI NUMEROITA" << std::endl;
    }
    std::cout << "KÄYTTÄJÄN RIVI ON:";
    for(int j = 0; j<i; j++) {
        std::cout << " " << pyydetyt[j];
    }
    //TODO NEEDS ASK FOR ENTER

    std::cout << "\n\n" << std::endl;
    
}

void analyysi(int *numerot, int plus, int *arvotut, int aPlus) {
    int oikein = 0;
    for(int i = 0; i<7; i++) {
        for(int j = 0; j<7; j++) {
            if(numerot[i] == arvotut[j]) 
                oikein++;
        }
    }

    std::cout << "Tulos: " 
    << oikein 
    << (plus == aPlus ? "+1" : "") 
    << " oikein"
    << (plus == aPlus ? ", plusnumero oikein" : ", plusnumero väärin") 
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