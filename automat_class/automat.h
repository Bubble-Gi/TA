#ifndef LAB1_AUTOMAT_H
#define LAB1_AUTOMAT_H
#include <string>
#include <vector>
#include <unordered_map>
#include <set>

class Automat {
public:
    std::vector<std::string> res_good_string;
    std::unordered_map<std::string, std::set<std::string>> atribytes;
    std::string buf_name;
    std::string buf_names_connect1;
    std::string buf_names_connect2;
    Automat() {}
    virtual void check(const std::string &str) = 0;
    void printGood(const std::string& s) const;
    void printGoods() const;
    void res();
};

#endif