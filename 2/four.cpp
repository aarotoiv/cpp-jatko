#include <iostream>
#include <math.h>

bool prime(int luku);
bool primeDiv(int luku);
bool primeSqrt(int luku);

int main() {
    const int KOKO = 10000;
    int primes = 0;
    for(int i = 2; i<KOKO; i++) {
        if(primeSqrt(i))
            primes++;
    }
    double percentage = (double)primes / (double)KOKO * 100.0;
    std::cout << percentage << std::endl;
    return 0;
}

bool prime(int luku) {
    bool isPrime = true;
    for(int i = 2; i<luku; i++) {
        if(luku % i == 0 && luku != i) 
            isPrime = false;
    }
    return isPrime;
}
bool primeDiv(int luku) {
    bool isPrime = true;
    int uusiLuku = luku / 2.0 + 1;
    for(int i = 2; i<uusiLuku; i++) {
        if(luku % i == 0 && luku != i && luku > 2) 
            isPrime = false;
    }
    return isPrime;
}
bool primeSqrt(int luku) {
    bool isPrime = true;
    int uusiLuku = sqrt(luku) + 1;
    for (int i = 2; i<uusiLuku; i++) {
        if(luku % i == 0 && luku != i && luku > 2) 
            isPrime = false;
    }
    return isPrime;
}