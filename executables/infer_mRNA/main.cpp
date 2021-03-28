#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <map>

void usage(const std::string& argv) {
    std::cout << "usage: " << argv << " <input file>" << std::endl;
}

std::map<char, int> init_map() {
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
    std::map<char, int> result;
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

int main(int argc, char* argv[]) {
    if(argc < 2) {
        std::string call = argv[0];
        usage(call);
        exit(1);
    }

    std::string seq;
    std::ifstream inFile;
    auto val = init_map();
    long long int product = 1;
    inFile.open(argv[1]);
    inFile >> seq;
    for (char& i : seq) {
       product *= val[i];
    }

    product *= 3;
    std::cout << product << std::endl;
    inFile.close();
    return 0;
}

