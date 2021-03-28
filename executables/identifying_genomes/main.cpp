#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <fastx_utils/fasta/fasta_read.h>
using namespace std;

void usage(string argv0)
{
    cout << "usage: " << argv0 << " <input file>" << endl;
    return;
}

double getGC(const string seq)
{
    double result;
    unsigned int count = 0;
    for(unsigned int i = 0; i < seq.size(); i++)
    {
        if(seq[i] == 'C' || seq[i] == 'G' || seq[i] == 'c' || seq[i] == 'g')
            count++;
    }
    result = (static_cast<double>(count) * 100.0) / static_cast<double>(seq.size());
    return result;
}

int main(int argc, char * argv[])
{
    if(argc < 2)
    {
        string call = argv[0];
        usage(call);
        exit(1);
    }

    vector<FastaRead> read;
    double max = 0.0;
    unsigned int max_index = 0;
    ifstream inFile;
    inFile.open(argv[1]);
    while(!inFile.eof())
    {
        std::string tmp_id, tmp_seq;
        inFile >> tmp_id;
        inFile >> tmp_seq;
        read.emplace_back(tmp_id, tmp_seq);
    }
    inFile.close();
    for(unsigned int i = 0; i < read.size(); i++)
    {
        double gc = getGC(read[i].getSequence());
        if(gc > max)
        {
            max = gc;
            max_index = i;
        }
    }
    cout << read[max_index].getID() << endl;
    cout << setprecision(8) << max << "%" << endl;

    return 0;
}

