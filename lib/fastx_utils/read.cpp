#include "read.h"

Read::Read(){}

Read::Read(const Read &src) : m_id(src.m_id), m_seq(src.m_seq){}

Read::Read(const std::string id, const std::string seq) : m_id(id), m_seq(seq){}

Read::~Read(){}

void Read::setID(const std::string id)
{
	m_id = id;
	return;
}

void Read::setSequence(const std::string seq)
{
	m_seq = seq;
	return;
}

const std::string Read::getID() const
{
	return m_id;
}

const std::string Read::getSequence() const
{
	return m_seq;
}

const Read& Read::operator=(const Read &src)
{
	m_id = src.m_id;
	m_seq = src.m_seq;
	return *this;
}


