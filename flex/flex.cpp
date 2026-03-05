#include "flex.hpp"
#include <sstream>

bool Flex::check_str(const std::string& str) {
    set.clear(); name.clear(); buf1.clear(); buf2.clear();
    std::istringstream iss(str);
    lexer.switch_streams(&iss, nullptr);
    if (lexer.yylex() != 1) return false;
    if (lexer.yylex() != 8) return false;
    if (lexer.yylex() != 2) return false;
    name = lexer.YYText();
    if (lexer.yylex() != 8) return false;

    int f = lexer.yylex();
    if (f == 3) {
        if (lexer.yylex() != 8) return false;
        while (true) {
            f = lexer.yylex();
            if (f != 2) return false;
            set.insert(lexer.YYText());
            f = lexer.yylex();
            if (f == 7) continue;
            if (f == 8) {
                f = lexer.yylex();
                if (f == 4)  break;
            } else return false;
        }
        atribytes[name] = set;
    } else if (f == 5) {
        f = lexer.yylex();
        if (f != 8) return false;
        f = lexer.yylex();
        if (f != 2) return false;
        buf1 = lexer.YYText();
        f = lexer.yylex();
        if (f != 8) return false;
        f = lexer.yylex();
        if (f != 6) return false;
        f = lexer.yylex();
        if (f != 8) return false;
        f = lexer.yylex();
        if (f != 2) return false;
        buf2 = lexer.YYText();

        buf_name = name;
        buf_names_connect1 = buf1;
        buf_names_connect2 = buf2;
        res();
    }
    else return false;
    return true;
}