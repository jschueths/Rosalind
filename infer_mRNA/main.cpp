#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <map>

using namespace std;

void usage(string argv0)
{
	cout << "usage: argv0 <input file>" << endl;
	return;
}

map<char, size_t> init_map()
{
    /*
    UUU F      CUU L      AUU I      GUU V
    UUC F      CUC L      AUC I      GUC V
    UUA L      CUA L      AUA I      GUA V
    UUG L      CUG L      AUG M      GUG V
    UCU S      CCU P      ACU T      GCU A
    UCC S      CCC P      ACC T      GCC A
    UCA S      CCA P      ACA T      GCA A
    UCG S      CCG P      ACG T      GCG A
    UAU Y      CAU H      AAU N      GAU D
    UAC Y      CAC H      AAC N      GAC D
    UAA Stop   CAA Q      AAA K      GAA E
    UAG Stop   CAG Q      AAG K      GAG E
    UGU C      CGU R      AGU S      GGU G
    UGC C      CGC R      AGC S      GGC G
    UGA Stop   CGA R      AGA R      GGA G
    UGG W      CGG R      AGG R      GGG G
    */
    map<char, unsigned int> result;
    result['F'] = 2;
    result['L'] = 4;
    result['S'] = 6;
    result['Y'] = 2;
    result['C'] = 2;
    result['W'] = 1;
    result['L'] = 6;
    result['P'] = 4;
    result['H'] = 2;
    result['Q'] = 2;
    result['R'] = 6;
    result['I'] = 3;
    result['M'] = 1;
    result['T'] = 4;
    result['N'] = 2;
    result['V'] = 4;
    result['A'] = 4;
    result['D'] = 2;
    result['E'] = 2;
    result['G'] = 4;
    result['K'] = 2;
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
	
    string seq;
    ifstream inFile;
    map<char, unsigned int> val = init_map();
    unsigned long long int product = 1;
    inFile.open(argv[1]);
    inFile >> seq;
    for(unsigned int i = 0; i < seq.size(); i++)
        product *= val[seq[i]];
    product *= 3;
    cout << product << endl;
	inFile.close();
	return 0;
}

