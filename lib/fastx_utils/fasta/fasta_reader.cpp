#include "fasta_read.h"
#include "fasta_reader.h"

FastaReader::FastaReader(const std::string &src)
{
	m_in.open(src.c_str());
}

FastaReader::~FastaReader()
{
	m_in.close();
}

bool FastaReader::next(FastaRead &read)
{
	if(m_in.eof())
	{
		return false;
	}
	std::string temp;
	m_in >> temp;
	read.setID(temp);
	m_in >> temp;
	read.setSequence(temp);
	return true;
}
