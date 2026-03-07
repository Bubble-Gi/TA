#ifndef LAB1_GENERAT_H
#define LAB1_GENERAT_H
#include <iostream>
#include <vector>
#include <random>

class Generator {
    const std::string alpha = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    const std::string digits = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM0123456789_";
    size_t lenfile;
    std::vector<std::string> name_connects;
    std::string namefile;
    std::mt19937 rng;
public:
    Generator(const size_t n, std::string name) : lenfile(n), name_connects(), rng(std::random_device{}()), namefile(std::move(name)) {};
    void generate();
    std::string generate_string();
    std::string generate_connects();
    std::string mutable_generate(std::string str);
    std::string generate_alpha(size_t n);
};

#endif