#include "automat.h"
#include <cctype>
#include <ranges>
#include <ostream>
#include <algorithm>
#include <fstream>

void Automat::check(const std::string &str) {
    for (const auto &ch : str) {
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
        if (!buf_all_atr.empty()) atribytes.try_emplace(buf_name, buf_all_atr);
        else res();
    }
    _fsm.start();
}

void Automat::printGood(const std::string &f) {
    std::ofstream out(f);
    for (auto &str : res_good_string) {
        out << str << std::endl;
    }
    out << "\n" << std::endl;
    for (auto &atr : atribytes) {
            out << atr.first << " | ";
            std::ranges::copy(atr.second, std::ostream_iterator<std::string>(out, ", "));
            out << std::endl;
    }
    out.close();
}

void Automat::printGoods() {
    for (auto &str : res_good_string) {
        std::cout << str << std::endl;
    }
    std::cout << "\n" << std::endl;
    for (auto &atr : atribytes) {
        std::cout << atr.first << " | ";
        std::ranges::copy(atr.second, std::ostream_iterator<std::string>(std::cout, ", "));
        std::cout << std::endl;
    }

}

void Automat::res() {
    if (!atribytes.contains(buf_names_connect1) || !atribytes.contains(buf_names_connect2)) return;
    std::set<std::string>& tmp1 = atribytes[buf_names_connect1];
    std::set<std::string>& tmp2 = atribytes[buf_names_connect2];
    std::set<std::string> res;

    if (tmp1.empty() || tmp2.empty()) return;
    for (const auto& atr : tmp1) {
        if (tmp2.count(atr)) res.insert(buf_names_connect1 + "." + atr);
        else res.insert(atr);
    }

    for (const auto& atr : tmp2) {
        if (tmp1.count(atr)) res.insert(buf_names_connect2 + "." + atr);
        else res.insert(atr);
    }
    atribytes[buf_name] = std::move(res);
}

