#include "automat.h"
#include <cctype>
#include <ranges>
#include <ostream>
#include <algorithm>

void Automat::check(const std::string &str) {
    for (const auto &ch : str) {
        if (!good) { good = true; _fsm.start(); return; }
        if (isalpha(ch) || ch == '_' || ch == '.') {_fsm.ch(ch); std::cout << "ch" << std::endl;}
        else if (isdigit(ch)) { _fsm.num(ch); std::cout << "num" << std::endl; }
        else if (isspace(ch)) {_fsm.sp(); std::cout << "space" << std::endl; }
        else if (ch == '(') {_fsm.o_b(); std::cout << "(" << std::endl; }
        else if (ch == ')') {_fsm.c_b(); std::cout << ")" << std::endl; }
        else if (ch == ',') {_fsm.comma(); std::cout << "comma" << std::endl; }
        else {_fsm.Unknown(); std::cout << "unknown" << std::endl; }
    }
    _fsm.EOS();
    if (good) {
        res_good_string.push_back(str);
        atribytes.try_emplace(buf_name, buf_all_atr);
    }
    _fsm.start();
}

void Automat::printGood() {
    for (auto &str : res_good_string) {
        std::cout << str << std::endl;
    }
    for (auto &atr : atribytes) {
        std::cout << "| " << atr.first << " | ";
        std::ranges::copy(atr.second, std::ostream_iterator<std::string>(std::cout, " "));
        std::cout << std::endl;
    }
}