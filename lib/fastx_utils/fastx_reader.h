#include <iostream>
#include <fstream>
#include <string>
#include "read.h"

class FastxReader
{
	public:
		virtual bool next(Read &read) = 0;
};
