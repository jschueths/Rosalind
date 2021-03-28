#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <map>

std::map<std::string, std::string> codonTable;

void usage(std::string argv0)
{
    std::cout << "usage: " << argv0 << " <input file>" << std::endl;
    return;
}

void initTable()
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
    codonTable["UUU"] = "F";
    codonTable["CUU"] = "L";
    codonTable["AUU"] = "I";
    codonTable["GUU"] = "V";
    codonTable["UUC"] = "F";
    codonTable["CUC"] = "L";
    codonTable["AUC"] = "I";
    codonTable["GUC"] = "V";
    codonTable["UUA"] = "L";
    codonTable["CUA"] = "L";
    codonTable["AUA"] = "I";
    codonTable["GUA"] = "V";
    codonTable["UUG"] = "L";
    codonTable["CUG"] = "L";
    codonTable["AUG"] = "M";
    codonTable["GUG"] = "V";
    codonTable["UCU"] = "S";
    codonTable["CCU"] = "P";
    codonTable["ACU"] = "T";
    codonTable["GCU"] = "A";
    codonTable["UCC"] = "S";
    codonTable["CCC"] = "P";
    codonTable["ACC"] = "T";
    codonTable["GCC"] = "A";
    codonTable["UCA"] = "S";
    codonTable["CCA"] = "P";
    codonTable["ACA"] = "T";
    codonTable["GCA"] = "A";
    codonTable["UCG"] = "S";
    codonTable["CCG"] = "P";
    codonTable["ACG"] = "T";
    codonTable["GCG"] = "A";
    codonTable["UAU"] = "Y";
    codonTable["CAU"] = "H";
    codonTable["AAU"] = "N";
    codonTable["GAU"] = "D";
    codonTable["UAC"] = "Y";
    codonTable["CAC"] = "H";
    codonTable["AAC"] = "N";
    codonTable["GAC"] = "D";
    codonTable["UAA"] = "Stop";
    codonTable["CAA"] = "Q";
    codonTable["AAA"] = "K";
    codonTable["GAA"] = "E";
    codonTable["UAG"] = "Stop";
    codonTable["CAG"] = "Q";
    codonTable["AAG"] = "K";
    codonTable["GAG"] = "E";
    codonTable["UGU"] = "C";
    codonTable["CGU"] = "R";
    codonTable["AGU"] = "S";
    codonTable["GGU"] = "G";
    codonTable["UGC"] = "C";
    codonTable["CGC"] = "R";
    codonTable["AGC"] = "S";
    codonTable["GGC"] = "G";
    codonTable["UGA"] = "Stop";
    codonTable["CGA"] = "R";
    codonTable["AGA"] = "R";
    codonTable["GGA"] = "G";
    codonTable["UGG"] = "W";
    codonTable["CGG"] = "R";
    codonTable["AGG"] = "R";
    codonTable["GGG"] = "G";
    codonTable["GGG"] = "G";
    return;
}

std::string codonToAcid(std::string codon)
{
    return codonTable[codon];
}

int main(int argc, char * argv[])
{
    if(argc < 2)
    {
        std::string call = argv[0];
        usage(call);
        exit(1);
    }
    initTable();
    std::string sequence;
    std::string protein = "";
    std::ifstream inFile;
    inFile.open(argv[1]);
    inFile >> sequence;
    inFile.close();

    unsigned int size = sequence.size();
    for(unsigned int i = 0; i * 3 < size; i++)
    {
        std::string tran = codonToAcid(sequence.substr(i*3, 3));
        if(tran == "Stop")
            break;
        protein += tran;
    }
    std::cout << protein << std::endl;
    return 0;
}

