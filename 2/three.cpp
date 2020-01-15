#include <iostream>

int min(int x, int y);
int min(int x, int y, int z);
int min(int x, int y, int z, int w);

int main() {
    int x = 0, y = 0, z = 0, w = 0;
    std::cout << "Ilmoita luku 1: " << std::endl;
    std::cin >> x;
    std::cout << "Ilmoita luku 2: " << std::endl;
    std::cin >> y;
    std::cout << "Ilmoita luku 3: " << std::endl;
    std::cin >> z;
    std::cout << "Ilmoita luku 4: " << std::endl;
    std::cin >> w;

    std::cout << "Pienin luku on: " << min(x, y, z, w) << std::endl;
    return 0;
}

int min(int x, int y) {
    return x < y ? x : y;
}
int min(int x, int y, int z) {
    return min(x, y) < z ? min(x, y) : z;
}
int min(int x, int y, int z, int w) {
    return min(x, y, z) < w ? min(x, y, z) : w;
}