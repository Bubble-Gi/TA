#ifndef LAB1_AUTOMAT_H
#define LAB1_AUTOMAT_H
#include "automat_sm.h"
#include <vector>
#include <set>
#include <unordered_map>
#include <sstream>

class Automat {
private:
    automatContext _fsm;
    std::vector<std::string> res_good_string;
    std::unordered_map<std::string, std::set<std::string>> atribytes;

public:
    bool good;
    Automat() : good(true), _fsm(*this) {}
    void check(const std::string &str);
    void setGood() { good = true; }
    void setBad() { good = false; }

    std::string buf_name;
    std::string buf_one_atr;
    std::set<std::string> buf_all_atr;
    std::string buf_names_connect1;
    std::string buf_names_connect2;
    template <typename B>
    void add_char(B& buf, char c) { buf.push_back(c); }
    void add_all_atr() { buf_all_atr.insert(buf_one_atr); }
    void reset() { buf_name.clear(); buf_all_atr.clear(); buf_names_connect2.clear(); buf_names_connect1.clear(); }
    void reset_buf_atr() { buf_one_atr.clear(); }
    void printGood(const std::string &f);
    void printGoods();

    void res();



};
#endif