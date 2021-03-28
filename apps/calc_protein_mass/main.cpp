#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "monoisotopic_mass.hpp"

int main(int argc, char *argv[]) {
    if(argc != 2) {
        std::cout << "Improper usage." << std::endl;
        return 1;
    }
    std::string fileName = argv[1];
    std::string proteinString;

    std::ifstream in;
    in.open(fileName.c_str());
    in >> proteinString;
    in.close();

    MonoisotopicMass massTable;
    double weight = 0.0;
    for(size_t i = 0; i < proteinString.size(); i++)
    {
        weight += massTable.getMass(proteinString[i]);
    }
    std::cout << std::setprecision(15) << "Weight: " << weight << std::endl;
    return 0;
}
