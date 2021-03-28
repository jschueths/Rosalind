#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

void usage(string argv0)
{
	cout << "usage: " << argv0 << " <input file>" << endl;
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
	
    string seq;
    string motif;
    vector<unsigned int> pos;
    ifstream inFile;
	inFile.open(argv[1]);
    inFile >> seq;
    inFile >> motif;

    unsigned int limit = seq.size() - motif.size();
    unsigned int motif_size = motif.size();
    for(unsigned int i = 0; i < limit; i++)
    {
        string tmp = seq.substr(i, motif_size);
        if(tmp == motif)
            pos.push_back(i + 1);
    }
	inFile.close();

    for(unsigned int i = 0; i < pos.size(); i++)
        cout << pos[i] << " ";
    cout << endl;
	return 0;
}

