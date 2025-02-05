#include <iostream>

void increment(int arr[10]);
void incrementPtr(int* arr);

int main() {
    int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    increment(arr);
    incrementPtr(arr);
    for(int i = 0; i<10; i++) {
        std::cout << arr[i] << std::endl;
    }
    return 0;
}

void increment(int arr[10]) {
    for(int i = 0; i<10; i++) {
        arr[i]++;
    }
}

void incrementPtr(int *arr) {
    for(int i = 0; i<10; i++) {
        *(arr+i) += 1;
    }
}