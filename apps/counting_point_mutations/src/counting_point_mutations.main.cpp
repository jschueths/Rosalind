#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <span>

void usage(const std::string& argv0) {
    std::cout << "usage: " << argv0 << "<input file>" << std::endl;
}

int main(int argc, char* argv[]) {
    auto args = std::span<char*>(argv, size_t(argc));
    if(argc < 2) {
        usage(args[0]);
        exit(1);
    }

    std::string seq1, seq2;
    unsigned int count = 0;
    std::ifstream inFile(args[1]);
    inFile >> seq1;
    inFile >> seq2;
    for(unsigned int i = 0; i < seq1.size(); i++) {
        if(seq1[i] != seq2[i]) {
            count++;
        }
    }

    std::cout << count << std::endl;
    return 0;
}
