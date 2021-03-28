#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <span>

#include "monoisotopic_mass.hpp"

int main(int argc, char* argv[]) {
    auto args = std::span<char*>(argv, size_t(argc));
    if(argc != 2) {
        std::cout << "Improper usage." << std::endl;
        return 1;
    }
    std::string fileName = args[1];
    std::string proteinString;

    std::ifstream in(fileName);
    in >> proteinString;

    MonoisotopicMass massTable;
    double weight = 0.0;
    for(char i : proteinString)
    {
        weight += massTable.getMass(i);
    }
    std::cout << std::setprecision(15) << "Weight: " << weight << std::endl;
    return 0;
}
