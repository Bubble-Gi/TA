#ifndef LAB1_AUTOMAT_H
#define LAB1_AUTOMAT_H
#include "automat_sm.h"

class Automat {
private:
    automatContext _fsm;
public:
    Automat();
    ~Automat();
    void check(std::string &str);

};
#endif