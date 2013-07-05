#ifndef __READ_H__
#define __READ_H__

#include <string>

class Read
{
	public:
		virtual ~Read();
		virtual void setID(const std::string &id) = 0;
		virtual void setSequence(const std::string& seq) = 0;
		virtual const std::string& getID() const;
		virtual const std::string& getSequence() const;
		virtual const Read& operator=(const Read &src);
	protected:
		std::string m_id;
		std::string m_seq;
};

#endif

