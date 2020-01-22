//Palautin tän jo viime viikolla. Ilmeisesti ei kuulunut niihin tehtäviin
#include <iostream>
#include <ctime>

void sekunnitAjaksi(int kaikki_sekunnit, int &tunnit, int &minuutit, int &sekunnit);

int main() {
    int sekunnit = 0;
    int minuutit = 0;
    int tunnit = 0;
    std::time_t kaikki_sekunnit = std::time(nullptr) % (24 * 60 * 60);
    sekunnitAjaksi(kaikki_sekunnit, tunnit, minuutit, sekunnit);
    std::cout << tunnit << ":" << minuutit << ":" << sekunnit << std::endl;
    
    return 0;
}

void sekunnitAjaksi(int kaikki_sekunnit, int &tunnit, int &minuutit, int &sekunnit) {
    sekunnit = kaikki_sekunnit % 60;
    minuutit = kaikki_sekunnit / 60 % 60;
    tunnit = kaikki_sekunnit / 60 / 60;
}