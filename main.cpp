#include <iostream>
#include <fstream>
#include "automat.h"
#include <vector>
#include "regex/reg_automat.hpp"

int main() {
    Automat a;
    Regex r;
    try {
        std::string line;
        std::vector<std::string> lines;
        std::ifstream input("data.txt");
        if (input.is_open()) {
            while (std::getline(input, line)) {
                lines.push_back(line);
            }
        } else {
            throw std::runtime_error("Can't open file");
        }
        input.close();

        try {
            for (auto &l : lines) {
                //a.check(l);
                r.check_rgx(l);
            }
        } catch (const std::exception &e) {
            std::cout << e.what() << "не правильная строчка" << std::endl;
        }

        std::ofstream output("output.txt");
        if (output.is_open()) {
            a.printGood("output.txt");
        }
        r.printGoods();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}