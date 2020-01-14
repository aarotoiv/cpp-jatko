#include <iostream>

void swap(int &uno, int &dos);
void ptrSwap(int* uno, int* dos);

int main() {
    int eka = 5;
    int toka = 8;
    std::cout << "Eka: " << eka << " Toka: " << toka << std::endl;
    std::cout << "VIITTAUS SWAP" << std::endl;
    swap(eka, toka);
    std::cout << "Eka: " << eka << " Toka: " << toka << std::endl;

    std::cout << "OSOITIN SWAP" << std::endl;
    ptrSwap(&eka, &toka);
    std::cout << "Eka: " << eka << " Toka: " << toka << std::endl;

    return 0;
}

void swap(int &uno, int &dos) {
    int temp = uno;
    uno = dos;
    dos = temp;
}

void ptrSwap(int* uno, int* dos) {
    int temp = *uno;
    *uno = *dos;
    *dos = temp;
}