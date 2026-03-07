#include "generator/generat.h"

int main() {
    Generator g(150000, "test.txt");
    g.generate();
    return 0;
}