#include "read.hpp"

namespace fastx {

const std::string& Read::getID() const {
    return m_id;
}

const std::string& Read::getSequence() const {
    return m_seq;
}

}
