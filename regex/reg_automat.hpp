#ifndef LAB1_REG_AUTOMAT_HPP
#define LAB1_REG_AUTOMAT_HPP
#include "regex"
#include "vector"
#include "string"
#include "unordered_map"
#include "set"

class Regex {
private:
    std::regex regular1 = std::regex("^create\\s+([a-zA-Z][\\w.]*)\\s+\\(\\s+([a-zA-Z][\\w.]*(?:,[a-zA-Z][\\w.]*)*)\\s+\\)$");
    std::regex regular2 = std::regex("^create\\s+([a-zA-Z][\\w.]*)\\s+\\as\\s+([a-zA-Z][\\w.]*)\\s+join\\s+([a-zA-Z][\\w.]*)$");
    std::vector<std::string> good_res;
    std::unordered_map<std::string, std::set<std::string>> atribytes;

public:
    std::string buf_name;
    std::string buf_names_connect1;
    std::string buf_names_connect2;
    Regex() {}
    void check_rgx(std::string &str);
    std::set<std::string> pars_set(const std::string &str);
    void printGoods() const;

    void res_reg();
};

#endif