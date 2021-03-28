#include "fasta_read.hpp"

namespace fastx {

FastaRead::FastaRead(const Read& src)
{
    FastaRead::setID(src.getID());
    m_seq = src.getSequence();
}

FastaRead::FastaRead(std::string id, std::string seq)
{
    FastaRead::setID(std::move(id));
    m_seq = std::move(seq);
}

void FastaRead::setID(std::string id)
{
    m_id = std::move(id);
    if(m_id[0] == '>') {
        m_id.erase(m_id.begin());
    }
}

void FastaRead::setSequence(std::string seq)
{
    m_seq = std::move(seq);
}

FastaRead& FastaRead::operator=(const Read& src)
{
    FastaRead::setID(src.getID());
    m_seq = src.getSequence();
    return *this;
}

}
