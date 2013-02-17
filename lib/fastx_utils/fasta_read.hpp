#ifndef __FASTA_READ_HPP__
#define __FASTA_READ_HPP__

FastaRead::FastaRead(){}

FastaRead::FastaRead(const Read &src)
{
	setID(src.getID());
	m_seq = src.getSequence();
}

FastaRead::FastaRead(const std::string id, const std::string seq)
{
	setID(id);
	m_seq = seq;
}

FastaRead::~FastaRead(){}

void FastaRead::setID(const std::string id)
{
	m_id = id;
	if(m_id[0] == '>')
		m_id.erase(m_id.begin());
	return;
}

const FastaRead& FastaRead::operator=(const Read &src)
{
	setID(src.getID());
	m_seq = src.getSequence();
	return *this;
}

#endif

