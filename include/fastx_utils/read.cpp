#include "read.h"

Read::~Read(){};

const std::string& Read::getID() const
{
	return m_id;
}

const std::string& Read::getSequence() const
{
	return m_seq;
}

const Read& Read::operator=(const Read &src)
{
	if(this != &src)
	{
		m_id = src.m_id;
		m_seq = src.m_seq;
	}
	return *this;
}
