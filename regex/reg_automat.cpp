#include "reg_automat.hpp"
#include <set>
#include <ranges>
#include <algorithm>
#include <iostream>

void Regex::check(const std::string &str) {
    std::cmatch ress;
    if (std::regex_match(str.c_str(), ress, regular1)) {
        atribytes.try_emplace(ress[1], pars_set(ress[2]));
    } else if (std::regex_match(str.c_str(), ress, regular2)) {
        buf_name = ress[1];
        buf_names_connect1 = ress[2];
        buf_names_connect2 = ress[3];
        res();
    } else return;
}

std::set<std::string> Regex::pars_set(const std::string &str) {
    std::stringstream ss(str);
    std::set<std::string> set;
    std::string w;
    while ( std::getline(ss, w,',')) set.insert(w);
    return set;
}



