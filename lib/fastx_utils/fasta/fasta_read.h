#ifndef __FASTA_READ_H__
#define __FASTA_READ_H__

#include <string>
#include "../read.h"

class FastaRead : public Read
{
	public:
		FastaRead();
		FastaRead(const Read &src);
		FastaRead(const std::string id, const std::string seq);
		~FastaRead();
		void setID(const std::string id);
		const FastaRead& operator=(const Read &src);
};

#include "fasta_read.hpp"
#endif

