#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ranges>
#include <span>
#include <string>
#include <vector>

void usage(std::string_view argv0)
{
    std::cout << "usage: " << argv0 << " <input file>" << std::endl;
}

int main(int argc, char * argv[]) {
    auto args = std::span<char*>(argv, size_t(argc));
    if(argc < 2) {
        usage(args[0]);
        exit(1);
    }

    std::string sequence;
    std::string input;
    std::ifstream inFile(args[1]);
    inFile >> input;

    auto complement = [](char c) {
        switch (c) {
            case 'A':
            case 'a':
                return 'T';
            case 'C':
            case 'c':
                return 'G';
            case 'T':
            case 't':
                return 'A';
            case 'G':
            case 'g':
                return 'C';
            default:
                return c;
        }
    };

    for (auto c : input | std::views::transform(complement) | std::views::reverse) {
        std::cout << c;
    }
    std::cout << std::endl;
    return 0;
}

