#include <iostream>
#include <fstream>
#include <string>
#include "read.hpp"

namespace fastx {

class FastxReader
{
    public:
        virtual ~FastxReader(){};
        virtual bool next(Read &read) = 0;
};

}
