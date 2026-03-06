#include <iostream>
#include <fstream>
#include "smc.h"
#include <vector>
#include "regex/reg_automat.hpp"
#include "flex/flex.hpp"
#include <chrono>
#include <numeric>

int main() {
    try {
        Smc s;
        Regex r;
        Flex f;
        std::string fileName;
        std::vector<std::chrono::duration<double>> time;
        std::cout << "enter the file name from where to read the data: " << std::endl;
        std::cin >> fileName;

        std::string line;
        std::vector<std::string> lines;
        std::ifstream input(fileName);
        if (input.is_open()) {
            while (std::getline(input, line)) {
                lines.push_back(line);
            }
        } else {
            throw std::runtime_error("Can't open file");
        }
        input.close();

        std::cout << "_____MENU_____" << std::endl
        << "1. SMC" << std::endl
        << "2. REGEX" << std::endl
        << "3. FLEX" << std::endl
        << "4. EXIT" << std::endl;

        int ch;
        std::cin >> ch;
        std::cin.ignore();
        switch (ch) {
            case 1:
                try {
                    for (size_t i = 1; i <= 10; i++) {
                        auto start = std::chrono::steady_clock::now();
                        for (auto &l : lines) {
                            s.check(l);
                        }
                        auto end = std::chrono::steady_clock::now();
                        std::chrono::duration<double> diff = end - start;
                        time.push_back(diff);
                    }
                    s.printGood("output.txt");
                    break;
                } catch (const std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
            case 2:
                try {
                    for (size_t i = 1; i <= 10; i++) {
                        auto start = std::chrono::steady_clock::now();
                        for (auto &l : lines) {
                            r.check(l);
                        }
                        auto end = std::chrono::steady_clock::now();
                        std::chrono::duration<double> diff = end - start;
                        time.push_back(diff);
                        std::cout << i << std::endl;
                    }
                    r.printGood("output.txt");
                    break;
                } catch (const std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
            case 3:
                try {
                    for (size_t i = 1; i <= 10; i++) {
                        auto start = std::chrono::steady_clock::now();
                        for (auto &l : lines) {
                            f.check_str(l);
                        }
                        auto end = std::chrono::steady_clock::now();
                        std::chrono::duration<double> diff = end - start;
                    }
                    f.printGood("output.txt");
                    break;
                } catch (const std::exception &e) {
                    std::cout << e.what() << std::endl;
                }
            case 4: break;
            default: std::cout << "Not the right choice, try again)" << std::endl;
        }
        auto time1 = std::accumulate(time.begin(), time.end(), std::chrono::duration<double>(0));
        auto res_time = time1 / time.size();
        std::cout << res_time << std::endl;

    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
