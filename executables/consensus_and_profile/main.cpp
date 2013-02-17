#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

void usage(string argv0)
{
	cout << "usage: argv0 <input file>" << endl;
	return;
}

char getConsensusBase(unsigned int a, unsigned int c, unsigned int g, unsigned int t)
{
	unsigned int max = a;
	char result = 'A';
	if(c > max)
	{
		result = 'C';
		max = c;
	}
	if(g > max)
	{
		result = 'G';
		max = g;
	}
	if(t > max)
	{
		result = 'T';
	}
	return result;
}

void printVector(vector<unsigned int> v, unsigned int length)
{
	for(unsigned int i = 0; i < length; i++)
	{
		cout << v[i] << " ";
	}
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
	vector<unsigned int> a_profile;
	vector<unsigned int> c_profile;
	vector<unsigned int> g_profile;
	vector<unsigned int> t_profile;
	a_profile.resize(1000, 0);
	c_profile.resize(1000, 0);
	g_profile.resize(1000, 0);
	t_profile.resize(1000, 0);
	unsigned int length = 0;
	string consensus;
	ifstream inFile;
	inFile.open(argv[1]);
	// Profile the strings:
	while(!inFile.eof())
	{
		string seq;
		inFile >> seq;
		if(seq.size())
			length = seq.size();
		for(unsigned int i = 0; i < seq.size(); i++)
		{
			switch(seq[i])
			{
				case 'A':
				case 'a':
					a_profile[i]++;
					break;
				case 'C':
				case 'c':
					c_profile[i]++;
					break;
				case 'G':
				case 'g':
					g_profile[i]++;
					break;
				case 'T':
				case 't':
					t_profile[i]++;
					break;
				default:
					cerr << "Invalid base" << endl;
			}
		}
	}
	// Find the consensus string:
	consensus.resize(length);
	for(unsigned int i = 0; i < length; i++)
		consensus[i] = getConsensusBase(a_profile[i], c_profile[i], g_profile[i], t_profile[i]);
	cout << consensus << endl;
	cout << "A: ";
	printVector(a_profile, length);
	cout << endl;
	cout << "C: ";
	printVector(c_profile, length);
	cout << endl;
	cout << "G: ";
	printVector(g_profile, length);
	cout << endl;
	cout << "T: ";
	printVector(t_profile, length);
	cout << endl;
	inFile.close();
	return 0;
}

