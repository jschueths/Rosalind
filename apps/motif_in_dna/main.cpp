#include <cstdlib>
#include <fstream>
#include <iostream>
#include <span>
#include <string>
#include <vector>

void usage(std::string_view argv0) {
    std::cout << "usage: " << argv0 << " <input file>" << std::endl;
}

int main(int argc, char * argv[]) {
    auto args = std::span<char*>(argv, size_t(argc));
    if(argc < 2) {
        usage(args[0]);
        exit(1);
    }

    std::string seq;
    std::string motif;
    std::vector<unsigned int> pos;
    std::ifstream inFile(args[1]);
    inFile >> seq;
    inFile >> motif;

    auto limit = std::ssize(seq) - std::ssize(motif);
    auto motif_size = motif.size();
    for(ssize_t i = 0; i < limit; i++) {
        std::string tmp = seq.substr(i, motif_size);
        if(tmp == motif) {
            pos.push_back(i + 1);
        }
    }

    for(unsigned int po : pos) {
        std::cout << po << " ";
    }
    std::cout << std::endl;
    return 0;
}

