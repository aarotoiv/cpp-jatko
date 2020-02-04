#include <iostream>

int main() {
    const unsigned int kilo = 1000;
    //max
    char taulukko[kilo * 8379] = {'a'};
    char * taulukko_p = new char[kilo * 1000000000];
    
    delete[] taulukko_p;
    std::cout << "ayy" << std::endl;
    while(true) {

    }
    return 0;
}