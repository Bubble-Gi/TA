#ifndef LAB1_SMC_H
#define LAB1_SMC_H
#include "smc_sm.h"
#include <vector>
#include <set>
#include "../automat_class/automat.h"

class Smc final : public Automat {
private:
    smcContext _fsm;
public:
    bool good;
    std::string buf_one_atr;
    std::set<std::string> buf_all_atr;
    Smc() : good(true), _fsm(*this) {}
    void check(const std::string &str) override;
    void setGood() { good = true; }
    void setBad() { good = false; }

    template <typename B>
    void add_char(B& buf, char c) { buf.push_back(c); }
    void add_all_atr() { buf_all_atr.insert(buf_one_atr); }
    void reset() { buf_name.clear(); buf_all_atr.clear(); buf_names_connect2.clear(); buf_names_connect1.clear(); }
    void reset_buf_atr() { buf_one_atr.clear(); }
};
#endif