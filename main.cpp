#include <iostream>
#include "include/flags.cpp"

int main(const int argv, char** argc) {
    auto flags = flag::parse(argv, argc);
    bool consoleMode = flag::isInConsoleMode(flags);

    std::cout << consoleMode << std::endl;
}


