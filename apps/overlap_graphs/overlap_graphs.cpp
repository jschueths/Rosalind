#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "fasta_read.h"

using namespace std;

void usage(string argv0)
{
    cout << "usage: " << argv0 << " <input file> <overlap>" << endl;
    return;
}

int main(int argc, char * argv[])
{
    if(argc < 3)
    {
        string call = argv[0];
        usage(call);
        exit(1);
    }
    size_t overlap = atoi(argv[2]);
    vector<FastaRead> read;
    string tmp_id;
    string tmp_seq;
    ifstream inFile;
    inFile.open(argv[1]);
    while(!inFile.eof())
    {
        string tmp;
        inFile >> tmp;
        tmp_id = tmp;
        while(!inFile.eof() && inFile.peek() != '>')
        {
            inFile >> tmp;
            tmp_seq += tmp;
        }
        FastaRead tmp_read(tmp_id, tmp_seq);
        read.push_back(tmp_read);
    }
    inFile.close();
    for(size_t i = 0; i < read.size(); i++)
    {
        for(size_t j = 0; j < read.size(); j++)
        {
            if(i != j)
            {
                string begin = read[i].getSequence();
                string end = read[j].getSequence();
                for(size_t k = 0; i < overlap; i++)
                {
                    if(begin[k] != end[end.size() - 1 - k])
                        break;
                }
            }
        }
    }
    return 0;
}

