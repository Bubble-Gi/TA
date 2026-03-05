#include "automat.h"
#include <fstream>
#include <algorithm>
#include <ranges>
#include <iostream>

void Automat::printGood(const std::string &f) const {
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

void Automat::printGoods() const {
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