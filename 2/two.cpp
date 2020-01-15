#include <iostream>
#include <math.h>

void pienempiIsompi(double x);

int main() {
    double luku = 0.0;
    std::cout << "Anna luku: " << std::endl;
    std::cin >> luku;
    pienempiIsompi(luku);
    return 0;
}

void pienempiIsompi(double x) {
    std::cout << "Luku " << x << " sijoittuu lukujen " << floor(x) << " ja " <<  ceil(x) << " välille." << std::endl;
}