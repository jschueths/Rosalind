#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

void usage(string argv0)
{
	cout << "usage: " << argv0 << "<input file>" << endl;
	return;
}

int main(int argc, char * argv[])
{
	if(argc < 2)
	{
		string call = argv[0];
		usage(call);
		exit(1);
	}
	
    string seq1, seq2;
    unsigned int count = 0;
	ifstream inFile;
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

    cout << count << endl;
	return 0;
}

