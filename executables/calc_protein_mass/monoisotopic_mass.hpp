
MonoisotopicMass::MonoisotopicMass()
{
	m_table['A'] = 71.03711;
	m_table['C'] = 103.00919;
	m_table['D'] = 115.02694;
	m_table['E'] = 129.04259;
	m_table['F'] = 147.06841;
	m_table['G'] = 57.02146;
	m_table['H'] = 137.05891;
	m_table['I'] = 113.08406;
	m_table['K'] = 128.09496;
	m_table['L'] = 113.08406;
	m_table['M'] = 131.04049;
	m_table['N'] = 114.04293;
	m_table['P'] = 97.05276;
	m_table['Q'] = 128.05858;
	m_table['R'] = 156.10111;
	m_table['S'] = 87.03203;
	m_table['T'] = 101.04768;
	m_table['V'] = 99.06841;
	m_table['W'] = 186.07931;
	m_table['Y'] = 163.06333;
}

MonoisotopicMass::MonoisotopicMass(const MonoisotopicMass &src)
{
	m_table = src.m_table;
}

MonoisotopicMass::~MonoisotopicMass(){}

double MonoisotopicMass::getMass(const char protein)
{
	return m_table[protein];
}

