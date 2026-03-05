#ifndef LAB1_REG_AUTOMAT_HPP
#define LAB1_REG_AUTOMAT_HPP
#include "regex"
#include "string"
#include "set"
#include <../automat_class/automat.h>

class Regex final : public Automat{
private:
    std::regex regular1 = std::regex("^create\\s+([a-zA-Z][\\w.]*)\\s+\\(\\s+([a-zA-Z][\\w.]*(?:,[a-zA-Z][\\w.]*)*)\\s+\\)$");
    std::regex regular2 = std::regex("^create\\s+([a-zA-Z][\\w.]*)\\s+\\as\\s+([a-zA-Z][\\w.]*)\\s+join\\s+([a-zA-Z][\\w.]*)$");

public:
    Regex() {}
    void check(const std::string &str) override;
    std::set<std::string> pars_set(const std::string &str);
};

#endif