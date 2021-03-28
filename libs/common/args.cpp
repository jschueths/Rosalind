#include "args.hpp"

bool processArgs(int argc, char* argv[], boost::program_options::options_description &desc)
{
    boost::program_options::variables_map vm;
    try
    {
        boost::program_options::store(boost::program_options::parse_command_line(argc, argv, desc), vm);
        boost::program_options::notify(vm);
    }
    catch(boost::program_options::error &e)
    {
        std::cerr << "ERROR: " << e.what() << std::endl;
        std::cerr << desc << std::endl;
        return false;
    }
    return true;
}
