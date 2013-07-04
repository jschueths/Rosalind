#ifndef __READ_H__
#define __READ_H__

#include <string>

class Read
{
	public:
		Read();
		Read(const Read &src);
		Read(const std::string id, const std::string seq);
		~Read();
		void setID(const std::string id);
		void setSequence(const std::string seq);
		const std::string getID() const;
		const std::string getSequence() const;
		const Read& operator=(const Read &src);
	protected:
		std::string m_id;
		std::string m_seq;
};

#endif

