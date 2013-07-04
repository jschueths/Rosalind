#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
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
	
	string sequence;
	ifstream inFile;
	inFile.open(argv[1]);
	inFile >> sequence;
	unsigned int size = sequence.size();
	for(unsigned int i = 0; i < size; i++)
	{
		if(sequence[i] == 'T')
			sequence[i] = 'U';
	}
	cout << sequence << endl;
	return 0;
}

