#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <boost/program_options.hpp>
#include <span>

struct Args {
    std::string inputFile;
};

bool processArgs(std::span<char*> argv, Args &args) {
    namespace po = boost::program_options;
    po::options_description desc("Options");
    desc.add_options()
            (",i", po::value<std::string>(&args.inputFile)->required(), "Input file");
    po::variables_map vm;
    try {
        po::store(po::parse_command_line(static_cast<int>(argv.size()), argv.data(), desc), vm);
        po::notify(vm);
    }
    catch(po::error &e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        std::cerr << desc << std::endl;
        return false;
    }
    return true;
}

void processFile(const std::string &input) {
    std::string sequence;
    int base_a = 0;
    int base_t = 0;
    int base_c = 0;
    int base_g = 0;
    std::ifstream inFile;
    inFile.open(input);
    inFile >> sequence;
    for(char i : sequence) {
        switch(i) {
            case 'A': case 'a': ++base_a; break;
            case 'C': case 'c':	++base_c; break;
            case 'T': case 't': ++base_t; break;
            case 'G': case 'g': ++base_g;
        }
    }
    std::cout << base_a << " " << base_c << " " << base_g << " " << base_t << std::endl;
}

int main(int argc, char * argv[]) {
    Args args;
    auto argvs = std::span<char*>(argv, size_t(argc));
    processArgs(argvs, args);
    processFile(args.inputFile);

    return 0;
}

