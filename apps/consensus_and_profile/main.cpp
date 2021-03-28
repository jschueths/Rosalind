#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <span>

void usage(const std::string& argv0) {
    std::cout << "usage: " << argv0 << "<input file>" << std::endl;
}

char getConsensusBase(unsigned int a, unsigned int c, unsigned int g, unsigned int t) {
    unsigned int max = a;
    char result = 'A';
    if(c > max)
    {
        result = 'C';
        max = c;
    }
    if(g > max)
    {
        result = 'G';
        max = g;
    }
    if(t > max)
    {
        result = 'T';
    }
    return result;
}

void printVector(std::vector<unsigned int> v, unsigned int length) {
    for(unsigned int i = 0; i < length; i++) {
        std::cout << v[i] << " ";
    }
}

int main(int argc, char * argv[]) {
    auto args = std::span<char*>(argv, size_t(argc));
    if(argc < 2) {
        usage(args[0]);
        exit(1);
    }
    std::vector<unsigned int> a_profile;
    std::vector<unsigned int> c_profile;
    std::vector<unsigned int> g_profile;
    std::vector<unsigned int> t_profile;
    a_profile.resize(1000, 0);
    c_profile.resize(1000, 0);
    g_profile.resize(1000, 0);
    t_profile.resize(1000, 0);
    unsigned int length = 0;
    std::string consensus;
    std::ifstream inFile;
    inFile.open(args[1]);
    // Profile the strings:
    while(!inFile.eof()) {
        std::string seq;
        inFile >> seq;
        if(seq.size()){
            length = seq.size();
        }
        for(unsigned int i = 0; i < seq.size(); i++) {
            switch(seq[i]) {
                case 'A':
                case 'a':
                    a_profile[i]++;
                    break;
                case 'C':
                case 'c':
                    c_profile[i]++;
                    break;
                case 'G':
                case 'g':
                    g_profile[i]++;
                    break;
                case 'T':
                case 't':
                    t_profile[i]++;
                    break;
                default:
                    std::cerr << "Invalid base" << std::endl;
            }
        }
    }
    // Find the consensus string:
    consensus.resize(length);
    for(unsigned int i = 0; i < length; i++) {
        consensus[i] = getConsensusBase(a_profile[i], c_profile[i], g_profile[i], t_profile[i]);
    }
    std::cout << consensus << std::endl;
    std::cout << "A: ";
    printVector(a_profile, length);
    std::cout << std::endl;
    std::cout << "C: ";
    printVector(c_profile, length);
    std::cout << std::endl;
    std::cout << "G: ";
    printVector(g_profile, length);
    std::cout << std::endl;
    std::cout << "T: ";
    printVector(t_profile, length);
    std::cout << std::endl;
    inFile.close();
    return 0;
}

