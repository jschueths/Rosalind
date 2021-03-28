#ifndef __READ_H__
#define __READ_H__

#include <string>

namespace fastx {

class Read
{
    public:
      virtual ~Read() = default;
      virtual void setID(std::string id) = 0;
      virtual void setSequence(std::string seq) = 0;
        virtual const std::string& getID() const;
        virtual const std::string& getSequence() const;
      Read& operator=(const Read&) = default;
    protected:
        std::string m_id;
        std::string m_seq;
};

}

#endif

