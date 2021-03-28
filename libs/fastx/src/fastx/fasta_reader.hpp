#ifndef __FASTA_READER_H__
#define __FASTA_READER_H__

#include <iostream>
#include <fstream>
#include <string>
#include "fastx/fastx_reader.hpp"
#include "fastx/fasta_read.hpp"

namespace fastx {

class FastaReader : public FastxReader
{
    public:
        FastaReader(const std::string &src);
        ~FastaReader();
        bool next(FastaRead &read);

    private:
        std::ifstream m_in;
};

}

#endif
