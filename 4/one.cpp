#include <iostream>

int main() {
    const unsigned int kilo = 1000;
    const long long unsigned int max = 13000;
    //max
    char taulukko[kilo * 8379] = {'a'};
    char * taulukko_p = new char[kilo * max];
    taulukko_p[kilo * max - 1] = 'a';
    
    delete[] taulukko_p;
    return 0;
}