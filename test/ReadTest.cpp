#include <unittest++/UnitTest++.h>
#include <fastx_utils/read.h>

SUITE(ReadTest)
{
	TEST(TestFields)
	{
		std::string seq = "ACATTTTGATCACCCTAATAGGGAT";
		Read read;
		read.setID("read1");
		read.setSequence(seq);

		CHECK_EQUAL(read.getID(), "read1");
		CHECK_EQUAL(read.getSequence(), seq);

	}
}
