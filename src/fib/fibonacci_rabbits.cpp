#include <iostream>
#include <fstream>
#include <boost/cstdint.hpp>
#include <boost/program_options.hpp>

struct Args
{
		boost::uint32_t n;
		boost::uint32_t k;
};

bool parseArgs(int argc, char* argv[], Args &args)
{
	namespace po = boost::program_options;
	po::options_description desc("Options");
	desc.add_options()
			(",n", po::value<boost::uint32_t>(&args.n)->required(), "Number of months")
			(",k", po::value<boost::uint32_t>(&args.k)->required(), "Pairs per generation");
	po::variables_map vm;
	try
	{
		po::store(po::parse_command_line(argc, argv, desc), vm);
		po::notify(vm);
	}
	catch(po::error &e)
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
		std::cerr << desc << std::endl;
		return false;
	}
	return true;
}

boost::uint64_t processRabbits(boost::uint32_t months, boost::uint32_t rate)
{
	boost::uint64_t mature = 0;
	boost::uint64_t young = 1;
	boost::uint64_t result;
	boost::uint64_t nextMature;
	boost::uint64_t nextYoung;
	for(size_t i = 0; i < months; i++)
	{
		result = mature + young;
		nextMature = mature + young;
		nextYoung = mature * rate;
		mature = nextMature;
		young = nextYoung;
	}
	return result;
}

int main(int argc, char* argv[])
{
	Args args;
	parseArgs(argc, argv, args);
	boost::uint32_t numPairs = processRabbits(args.n, args.k);
	std::cout << numPairs << std::endl;
	return 0;
}
