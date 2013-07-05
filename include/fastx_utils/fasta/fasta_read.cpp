#include "fasta_read.h"

FastaRead::FastaRead(){}

FastaRead::FastaRead(const Read &src)
{
	FastaRead::setID(src.getID());
	m_seq = src.getSequence();
}

FastaRead::FastaRead(const std::string& id, const std::string& seq)
{
	FastaRead::setID(id);
	m_seq = seq;
}

FastaRead::~FastaRead(){}

void FastaRead::setID(const std::string& id)
{
	m_id = id;
	if(m_id[0] == '>')
		m_id.erase(m_id.begin());
	return;
}

void FastaRead::setSequence(const std::string &seq)
{
	m_seq = seq;
}

const Read& FastaRead::operator=(const Read& src)
{
	FastaRead::setID(src.getID());
	m_seq = src.getSequence();
	return *this;
}
