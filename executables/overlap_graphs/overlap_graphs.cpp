#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <fastx_utils/fasta/fasta_read.h>

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
	int overlap = atoi(argv[2]);
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
	for(unsigned int i = 0; i < read.size(); i++)
	{
		for(unsigned int j = 0; j < read.size(); j++)
		{
			if(i != j)
			{
				string begin = read[i].getSequence();
				string end = read[j].getSequence();
				for(unsigned int i = 0; i < overlap; i++)
				{
					if(begin[i] != end[end.size() - 1 - i])
						break;
				}
			}
		}
	}
	return 0;
}

