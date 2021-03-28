#include <iostream>
#include <fstream>
#include <boost/cstdint.hpp>
#include <boost/program_options.hpp>

struct Args {
    int n;
    int k;
};

Args parseArgs(int argc, char* argv[]) {
    Args args = {0, 0};
    namespace po = boost::program_options;
    po::options_description desc("Options");
    desc.add_options()
            (",n", po::value<int>(&args.n)->required(), "Number of months")
            (",k", po::value<int>(&args.k)->required(), "Pairs per generation");
    po::variables_map vm;
    try {
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);
    }
    catch(po::error &e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
        std::cerr << desc << std::endl;
    }
    return args;
}

int processRabbits(int months, int rate) {
    int mature = 0;
    int young = 1;
    int result = 0;
    int nextMature = 0;
    int nextYoung = 0;
    for(int i = 0; i < months; i++)
    {
        result = mature + young;
        nextMature = mature + young;
        nextYoung = mature * rate;
        mature = nextMature;
        young = nextYoung;
    }
    return result;
}

int main(int argc, char* argv[]) {
    Args args = parseArgs(argc, argv);
    int numPairs = processRabbits(args.n, args.k);
    std::cout << numPairs << std::endl;
    return 0;
}
