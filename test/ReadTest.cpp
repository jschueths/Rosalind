#include <unittest++/UnitTest++.h>
#include <fastx_utils/fasta/fasta_read.h>

SUITE(ReadTest)
{
	TEST(Fields)
	{
		std::string seq = "ACATTTTGATCACCCTAATAGGGAT";
		FastaRead read;
		read.setID("read1");
		read.setSequence(seq);

		CHECK_EQUAL("read1", read.getID());
		CHECK_EQUAL(seq, read.getSequence());
	}
}
