#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <boost/program_options.hpp>
#include "args.h"

std::string process(const std::string &inputFile)
{
    std::string sequence;
    std::ifstream inFile;
    inFile.open(inputFile.c_str());
    inFile >> sequence;
    std::replace(std::begin(sequence), std::end(sequence), 'T', 'U');
    return sequence;
}

int main(int argc, char * argv[])
{
    std::string inputFile;
    boost::program_options::options_description desc;
    desc.add_options()
            (",i", boost::program_options::value<std::string>(&inputFile)->required(), "Input file");
    processArgs(argc, argv, desc);
    std::cout << process(inputFile) << std::endl;
    return 0;
}

