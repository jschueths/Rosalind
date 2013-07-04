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
	int base_a = 0;
	int base_t = 0;
	int base_c = 0;
	int base_g = 0;
	ifstream inFile;
	inFile.open(argv[1]);
	inFile >> sequence;
	unsigned int size = sequence.size();
	for(unsigned int i = 0; i < size; i++)
	{
		switch(sequence[i])
		{
			case 'A':
			case 'a':
				++base_a;
				break;
			case 'C':
			case 'c':
				++base_c;
				break;
			case 'T':
			case 't':
				++base_t;
				break;
			case 'G':
			case 'g':
				++base_g;
		}
	}
	cout << base_a << " " << base_c << " " << base_g << " " << base_t << endl;
	return 0;
}

