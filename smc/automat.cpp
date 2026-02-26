#include "automat.h"
#include <cctype>

void Automat::check(std::string &str) {
    for (const auto &ch : str) {
        if (isalpha(ch) || ch == '_' || ch == '.') {
            switch(ch) {
                case 'c': _fsm.c(); break;
                case 'r': _fsm.r(); break;
                case 'e': _fsm.e(); break;
                case 'a': _fsm.a(); break;
                case 't': _fsm.t(); break;
                case 's': _fsm.s(); break;
                case 'j': _fsm.j(); break;
                case 'o': _fsm.o(); break;
                case 'i': _fsm.i(); break;
                case 'n': _fsm.n(); break;
                default: _fsm.ch(); break;
            }
        } else if (isdigit(ch)) _fsm.num();
        else if (isspace(ch)) _fsm.sp();
        else if (ch == '(') _fsm.o_b();
        else if (ch == ')') _fsm.c_b();
        else if (ch == ',') _fsm.comma();
        else _fsm.Unknown();
    }
    _fsm.EOS();
}