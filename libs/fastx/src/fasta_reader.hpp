#ifndef __FASTA_READER_H__
#define __FASTA_READER_H__

#include <iostream>
#include <fstream>
#include <string>
#include "fastx_reader.hpp"
#include "fasta_read.hpp"

class FastaReader : public FastxReader
{
    public:
        FastaReader(const std::string &src);
        ~FastaReader();
        bool next(FastaRead &read);

    private:
        std::ifstream m_in;
};

#endif
