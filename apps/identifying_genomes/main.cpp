#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <span>

#include "fastx/fasta_read.hpp"

void usage(const std::string& argv0) {
    std::cout << "usage: " << argv0 << " <input file>" << std::endl;
}

double getGC(const std::string& seq) {
    unsigned int count = 0;
    for(char i : seq)
    {
        if(i == 'C' || i == 'G' || i == 'c' || i == 'g') {
            count++;
        }
    }
    double result = (static_cast<double>(count) * 100.0) / static_cast<double>(seq.size());
    return result;
}

int main(int argc, char * argv[]) {
    auto args = std::span<char*>(argv, size_t(argc));
    if(argc < 2) {
        usage(args[0]);
        exit(1);
    }

    std::vector<fastx::FastaRead> read;
    double max = 0.0;
    unsigned int max_index = 0;
    std::ifstream inFile;
    inFile.open(args[1]);
    while(!inFile.eof()) {
        std::string tmp_id, tmp_seq;
        inFile >> tmp_id;
        inFile >> tmp_seq;
        read.emplace_back(tmp_id, tmp_seq);
    }
    inFile.close();
    for(unsigned int i = 0; i < read.size(); i++) {
        double gc = getGC(read[i].getSequence());
        if(gc > max) {
            max = gc;
            max_index = i;
        }
    }
    std::cout << read[max_index].getID() << std::endl;
    std::cout << std::setprecision(8) << max << "%" << std::endl;

    return 0;
}

