#include <iostream>
#include <fstream>
#include "automat.h"
#include <vector>

int main() {
    Automat a;
    std::string line;
    std::vector<std::string> lines;
    std::ifstream input("data.txt");
    if (input.is_open()) {
        while (std::getline(input, line)) {
            lines.push_back(line);
        }
    }
    input.close();

    for (const auto &l : lines) {
        a.check(l);
    }

    std::ofstream output("output.txt");
    if (output.is_open()) {
        a.printGood("output.txt");
    }
    a.printGoods();
    return 0;
}