#ifndef DUCK_ENGINE_EXCEPTIONS_XML_PARSE_EXCEPTION_H
#define DUCK_ENGINE_EXCEPTIONS_XML_PARSE_EXCEPTION_H

#include "core/core.h"
#include "exceptions/exception.h"
namespace DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME {

class XmlParseException : public Exception {
public:
    XmlParseException(const std::string& message);
    virtual ~XmlParseException();
};

}

#endif // DUCK_ENGINE_EXCEPTIONS_XML_PARSE_EXCEPTION_H
