#include <iostream>
#include <fstream>
#include <string>
#include "read.h"

class FastxReader
{
	public:
		virtual ~FastxReader(){};
		virtual bool next(Read &read) = 0;
};
