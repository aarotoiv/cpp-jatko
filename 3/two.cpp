#include <iostream>
#include <ctime>

void sekunnitAjaksi(int kaikki_sekunnit, int &tunnit, int &minuutit, int &sekunnit);
int aikaSekunneiksi(int tunnit, int minuutit, int sekunnit);

int main() {
    time_t aika;
    struct tm *paikallinenAika;
    time(&aika);
    paikallinenAika = localtime(&aika);
    int tunnit = paikallinenAika->tm_hour;
    int minuutit = paikallinenAika->tm_min;
    int sekunnit = paikallinenAika->tm_sec;
    std::cout << tunnit << " " << minuutit << " " << sekunnit << std::endl;
    int kaikki_sekunnit = aikaSekunneiksi(tunnit, minuutit, sekunnit);
    std::cout << kaikki_sekunnit << " sekuntia vuorokauden alusta." << std::endl;
}

void sekunnitAjaksi(int kaikki_sekunnit, int &tunnit, int &minuutit, int &sekunnit) {
    sekunnit = kaikki_sekunnit % 60;
    minuutit = kaikki_sekunnit / 60 % 60;
    tunnit = kaikki_sekunnit / 60 / 60;
}
int aikaSekunneiksi(int tunnit, int minuutit, int sekunnit) {
    return tunnit * 60 * 60 + minuutit * 60 + sekunnit;
}
