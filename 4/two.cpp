#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    std::string line;
    long long int sum = 0;
    int count = 0;
    std::ifstream file;
    file.open("random.txt");
    if(file.is_open()) {
        while(getline(file, line)) {
            std::stringstream theString(line);
            int val = 0;
            theString >> val;
            sum += val;
            count++;
        }
        std::cout << "Sum: " << sum << " Count: " << count << " AVG: " << (double)sum / (double)count << std::endl;
        file.close();
    }
    else 
        std::cout << "File can't be opened." << std::endl;

}