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
	string input;
	ifstream inFile;
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
	cout << sequence << endl;
	return 0;
}

