#include <iostream>
#include <stdlib.h>
#include <time.h> 

bool onJo(int arvotut[], int numero, int len);

int main() {
    bool running = true;
    int komento = 0;
    
    srand(time(NULL));

    while(running) {
        std::cout << "Tervetuloa lottopeliin!\nIlmoita komento:\n1) Lue ja tulosta lottorivi\n2) Lopeta ohjelman ajo" << std::endl;
        std::cin >> komento;
        if(komento == 1) {
            int numerot[7] = {0, 0, 0, 0, 0, 0, 0};
            int plus = 0;
            for(int i = 0; i < 7; i++) {
                std::cout << "Syötä numero " << i+1 << ":" << std::endl;
                while(numerot[i] == 0) {
                    int temp = 0;
                    std::cin >> temp;
                    if(temp > 0 && temp < 41 && !onJo(numerot, temp, 7)) 
                        numerot[i] = temp;
                    else 
                        std::cout << "Numero ei sovi. Yritä uudelleen." << std::endl;
                }
            }
            std::cout << "Syötä plusnumero: " << std::endl;
            std::cin >> plus;
            
            std::cout << "Käyttäjän rivi on: " << std::endl;
            std::cout << "Numerot: ";
            for(int i = 0; i < 7; i++) {
                std::cout << numerot[i] << " ";
            }
            std::cout << " ja plusnumero: " << plus << std::endl;
    
        }
        if(komento == 2) {
            std::cout << "Ohjelman ajo loppuu." << std::endl;
            running = false;
            break;
        }
    }
    return 0;
}

bool onJo(int arvotut[], int numero, int len) {
    for(int i = 0; i<len; i++) {
        if(arvotut[i] == numero)
            return true;
    }
    return false;
}