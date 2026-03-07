#include "generat.h"

#include <algorithm>
#include <set>
#include <fstream>

std::string Generator::generate_string() {
    std::string res;
    std::string buf_name;
    res = "create ";
    std::uniform_int_distribution<>len(3, 10);
    //std::uniform_int_distribution<>len_atr(2, 5);
    buf_name.append(generate_alpha(len(rng)));
    res.append(buf_name);
    name_connects.push_back(buf_name);
    res.append(" ( ");
    std::uniform_int_distribution<>atr(2, 5);
    size_t n = atr(rng);
    for (size_t i = 1; i < n; i++) {
        res.append(generate_alpha(atr(rng)));
        if (i == n - 1) continue;
        else res.append(",");
    }
    res.append(" )");
    return res;
}

std::string Generator::generate_alpha(size_t n) {
    std::uniform_int_distribution<>count1(0, static_cast<int>(alpha.size() - 1));
    std::uniform_int_distribution<>count2(0, static_cast<int>(digits.size() - 1));
    std::string res;
    res.reserve(n);
    res.push_back(alpha[count1(rng)]);
    for (size_t i = 1; i < n-1; i++) res.push_back(digits[count2(rng)]);
    return res;
}

std::string Generator::generate_connects() {
    std::string res;
    std::string buf1, buf2;
    res = "create ";
    std::uniform_int_distribution<>len(3, 10);
    res.append(generate_alpha(len(rng)));
    res.append(" as ");
    std::uniform_int_distribution<>connect(0, static_cast<int>(name_connects.size() - 1));
    buf1.append(name_connects[connect(rng)]);
    res.append(buf1);
    buf2.append(name_connects[connect(rng)]);
    if (buf1 != buf2) res.append(" join "); res.append(buf2);
    return res;
}

std::string Generator::mutable_generate(std::string str) {
    std::shuffle(str.begin(), str.end(), rng);
    return str;
}

void Generator::generate() {
    std::ofstream output(namefile);
    if (!output.is_open()) throw std::runtime_error("Could not open file");
    std::uniform_int_distribution<>chance(1, 100);
    output << generate_string() << std::endl;
    output << generate_string() << std::endl;
    for (size_t i = 0; i < lenfile - 2;i++) {
        int ch = chance(rng);
        if (ch <= 60) output << generate_string() << std::endl;
        else if (ch <= 90) output << generate_connects() << std::endl;
        else output << mutable_generate(generate_string()) << std::endl;
    }
}
