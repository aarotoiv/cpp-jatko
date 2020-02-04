#include <iostream>
#include <fstream>

int main() {
    std::string val = "";
    std::ofstream file("index.html");
    if(file.is_open()) {
        file << "<html>\n<head>\n</head>\n<body>\n<center>\n";
        std::cout << "Enter your name: " << std::endl;
        std::getline(std::cin, val);
        file << val << "\n";
        file << "</center>\n<hr />\n";
        std::cout << "Describe yourself: " << std::endl;
        std::getline(std::cin, val);
        file << val << "\n";
        file << "<hr />\n</body>\n</html>";
        file.close();
    } else 
        std::cout << "File can't be opened." << std::endl;

    return 0;
}