#ifndef __FASTA_READER_H__
#define __FASTA_READER_H__

#include <iostream>
#include <fstream>
#include <string>
#include "../fastx_reader.h"
#include "fasta_read.h"

class FastaReader : public FastxReader
{
	public:
		FastaReader(const std::string &src);
		~FastaReader();
		bool next(FastaRead &read);
	
	private:
		std::ifstream m_in;
};

#include "fasta_reader.hpp"

#endif
