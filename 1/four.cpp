#include <iostream>

void turn(int* arr);
void ptrSwap(int* uno, int* dos);

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    turn(arr);

    for(int i = 0; i<10; i++) {
        std::cout << arr[i] << std::endl;
    }

    return 0;
}

void turn(int* arr) {
    for(int i = 0; i<10/2; i++) {
        ptrSwap(arr+i, arr+(9-i));
    }
}

void ptrSwap(int* uno, int* dos) {
    int temp = *uno;
    *uno = *dos;
    *dos = temp;
}