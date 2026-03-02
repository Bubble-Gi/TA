#include "reg_automat.hpp"
#include <set>
#include <ranges>
#include <algorithm>
#include <iostream>

void Regex::check_rgx(std::string &str) {
    std::cmatch res;
    if (std::regex_match(str.c_str(), res, regular1)) {
        atribytes.try_emplace(res[1], pars_set(res[2]));
        std::cout << str << std::endl;
    } else if (std::regex_match(str.c_str(), res, regular2)) {
        buf_name = res[1];
        buf_names_connect1 = res[2];
        buf_names_connect2 = res[3];
        std::cout << str << std::endl;
        res_reg();
    } else std::cout << "bad" << std::endl;
}

std::set<std::string> Regex::pars_set(const std::string &str) {
    std::stringstream ss(str);
    std::set<std::string> set;
    std::string w;
    while ( std::getline(ss, w,',')) set.insert(w);
    return set;
}

void Regex::res_reg() {
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

void Regex::printGoods() const {
    std::cout << "\n" << std::endl;
    for (auto &atr : atribytes) {
        std::cout << atr.first << " | ";
        std::ranges::copy(atr.second, std::ostream_iterator<std::string>(std::cout, ", "));
        std::cout << std::endl;
    }

}



