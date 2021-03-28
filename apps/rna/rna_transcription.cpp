#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include <boost/program_options.hpp>

#include "args.hpp"

std::string process(const std::string &inputFile) {
    std::string sequence;
    std::ifstream inFile(inputFile);
    inFile >> sequence;
    std::replace(std::begin(sequence), std::end(sequence), 'T', 'U');
    return sequence;
}

int main(int argc, char* argv[]) {
    std::string inputFile;
    boost::program_options::options_description desc;
    desc.add_options()
            (",i", boost::program_options::value<std::string>(&inputFile)->required(), "Input file");
    processArgs(argc, argv, desc);
    std::cout << process(inputFile) << std::endl;
    return 0;
}

