#include <iostream>
#include <fstream>
#include <string>
#include "monoisotopic_mass.h"
#include <iomanip>

using namespace std;

int main(int argc, char *argv[]) {
	if(argc != 2) {
		cout << "Improper usage." << endl;
		return 1;
	}
	string fileName = argv[1];
	string proteinString;

	ifstream in;
	in.open(fileName.c_str());
	in >> proteinString;
	in.close();
	
	MonoisotopicMass massTable;
	double weight = 0.0;
	for(size_t i = 0; i < proteinString.size(); i++)
	{
		weight += massTable.getMass(proteinString[i]);
	}
	cout << setprecision(15) << "Weight: " << weight << endl;
	return 0;
}
