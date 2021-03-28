#ifndef __FASTA_READ_H__
#define __FASTA_READ_H__

#include <string>
#include "read.h"

class FastaRead : public Read
{
    public:
        FastaRead() = default;
        FastaRead(const Read& src);
        FastaRead(const FastaRead&) = default;
        FastaRead(FastaRead&& src) = default;
        FastaRead(std::string id, std::string seq);
        FastaRead& operator=(const FastaRead&) = default;
        FastaRead& operator=(FastaRead&&) = default;
        ~FastaRead() = default;

        void setID(std::string id) override;
        void setSequence(std::string seq) override;
        FastaRead& operator=(const Read &src);
};

#endif

