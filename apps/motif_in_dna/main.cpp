#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>

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

    std::string seq;
    std::string motif;
    std::vector<unsigned int> pos;
    std::ifstream inFile;
    inFile.open(argv[1]);
    inFile >> seq;
    inFile >> motif;

    unsigned int limit = seq.size() - motif.size();
    unsigned int motif_size = motif.size();
    for(unsigned int i = 0; i < limit; i++)
    {
        std::string tmp = seq.substr(i, motif_size);
        if(tmp == motif)
            pos.push_back(i + 1);
    }
    inFile.close();

    for(unsigned int i = 0; i < pos.size(); i++)
        std::cout << pos[i] << " ";
    std::cout << std::endl;
    return 0;
}

