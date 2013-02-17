#ifndef MONOISOTOPIC_MASS_H
#define MONOISOTOPIC_MASS_H

#include <map>

class MonoisotopicMass{

	public:
		MonoisotopicMass();
		MonoisotopicMass(const MonoisotopicMass &src);
		~MonoisotopicMass();
		double getMass(const char protein);

	private:
		std::map<char, double> m_table;
};

#include "monoisotopic_mass.hpp"

#endif

