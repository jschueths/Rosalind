#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

void usage(std::string argv0)
{
    std::cout << "usage: " << argv0 << " <input file>" << std::endl;
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

    std::string sequence;
    std::string input;
    std::ifstream inFile;
    inFile.open(argv[1]);
    inFile >> input;
    unsigned int size = input.size();
    sequence.resize(size);
    for(unsigned int i = 0; i < size; i++)
    {
        unsigned int index = size - 1 - i;
        switch(input[i])
        {
            case 'A':
            case 'a':
                sequence[index] = 'T';
                break;
            case 'C':
            case 'c':
                sequence[index] = 'G';
                break;
            case 'T':
            case 't':
                sequence[index] = 'A';
                break;
            case 'G':
            case 'g':
                sequence[index] = 'C';
        }
    }
    std::cout << sequence << std::endl;
    return 0;
}

