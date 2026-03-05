#include <iostream>
#include <fstream>
#include "smc.h"
#include <vector>
#include "regex/reg_automat.hpp"
#include "flex/flex.hpp"

int main() {
    Smc s;
    Regex r;
    Flex f;
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
                //s.check(l);
                //r.check(l);
                f.check_str(l);
            }
        } catch (const std::exception &e) {
            std::cout << e.what() << "не правильная строчка" << std::endl;
        }

        std::ofstream output("output.txt");
        //s.printGoods();
        //r.printGoods();
        f.printGoods();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}