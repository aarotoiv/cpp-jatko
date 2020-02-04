#include <iostream>
#include <fstream>

int main() {
    std::string nimi = "";
    std::string merkkijono = "";
    std::cout << "Ilmoita tiedoston nimi: " << std::endl;
    std::cin >> nimi;
    std::cout << "Ilmoita haettava merkkijono: " << std::endl;
    std::cin >> merkkijono;

    std::ifstream file(nimi);
    std::string line;
    int count = 0;
    if(file.is_open()) {
        while(getline(file, line)) {
            if(line.find(merkkijono) != std::string::npos) {
                count++;
                std::cout << line << std::endl;
            }
        }
        file.close();
        std::cout << "Time of occurrences: " << count << ", String to find: " << merkkijono << std::endl;
    }
    else 
        std::cout << "Can't open file: " << nimi << "." << std::endl;

    return 0;
}