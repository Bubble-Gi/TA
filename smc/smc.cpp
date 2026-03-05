#include "smc.h"
#include <cctype>
#include <algorithm>
#include <fstream>

void Smc::check(const std::string &str) {
    for (const auto &ch : str) {
        if (isalpha(ch) || ch == '_' || ch == '.') {_fsm.ch(ch);}
        else if (isdigit(ch)) { _fsm.num(ch);}
        else if (isspace(ch)) {_fsm.sp();}
        else if (ch == '(') {_fsm.o_b();}
        else if (ch == ')') {_fsm.c_b();}
        else if (ch == ',') {_fsm.comma(); }
        else {_fsm.Unknown();  }
    }
    _fsm.EOS();
    if (good) {
        res_good_string.push_back(str);
        if (!buf_all_atr.empty()) atribytes.try_emplace(buf_name, buf_all_atr);
        else res();
    }
    _fsm.start();
}

