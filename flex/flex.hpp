#ifndef LAB1_FLEX_HPP
#define LAB1_FLEX_HPP
#include "../automat_class/automat.h"
#include <FlexLexer.h>
#include <string>
#include <vector>

class Flex final : public Automat {
private:
    yyFlexLexer lexer;
    std::string name;
    std::set<std::string> set;
    std::string buf1;
    std::string buf2;
public:
    bool check_str(const std::string& str);
    void check(const std::string &str) override {}
};

#endif