#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

void usage(std::string argv0)
{
    std::cout << "usage: " << argv0 << "<input file>" << std::endl;
    return;
}

int main(int argc, char * argv[])
{
    if(argc < 2)
    {
        std::string call = argv[0];
        usage(call);
        exit(1);
    }

    std::string seq1, seq2;
    unsigned int count = 0;
    std::ifstream inFile;
    inFile.open(argv[1]);
    inFile >> seq1;
    inFile >> seq2;
    inFile.close();
    unsigned int size = seq1.size();
    for(unsigned int i = 0; i < size; i++)
    {
        if(seq1[i] != seq2[i])
            count++;
    }

    std::cout << count << std::endl;
    return 0;
}

