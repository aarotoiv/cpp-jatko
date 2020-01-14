#include <iostream>

int main() {
    int kok = 5;

    int *kokp = &kok;   
    
    *kokp = 7;

    std::cout << "Eka: " << kok << " " << &kok << std::endl;
    std::cout << "Toka: " << *kokp << " " << kokp << std::endl;

    //todetaan
    std::cout << "* ja & kumoavat toisensa " << *&kokp << std::endl;

    std::cout << "Koko eka: " << sizeof(kok) << " bittiä" << std::endl;
    std::cout << "Koko toka: " << sizeof(kokp) << " bittiä" << std::endl;

    //Onnistuu, mutta vastassa on roskaluku
    int* kolmas;
    std::cout << "Alustamaton osoitinmuuttuja: " << *kolmas << std::endl;

    kolmas = nullptr;
    std::cout << "Nullptr osoitinmuuttuja: " << kolmas << std::endl;

    return 0;
}