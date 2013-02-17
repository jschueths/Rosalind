#include <iostream>
#include <fstream>
#include <string>
#include "fastx_reader.h"
#include "fasta_read.h"

class FastaReader : public FastxReader
{
	public:
		FastaReader(const std::string &src);
		~FastaReader();
		bool next(Read &read);
	
	private:
		std::ifstream m_in;
};
