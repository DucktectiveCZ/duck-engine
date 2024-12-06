#ifndef DUCK_ENGINE_EXCEPTIONS_NOTIMPLEMENTEDEXCEPTION_H
#define DUCK_ENGINE_EXCEPTIONS_NOTIMPLEMENTEDEXCEPTION_H

#include "core/core.h"
#include "exceptions/exception.h"

namespace DUCK_ENGINE_EXCEPTIONS_NAMESPACE_NAME {

class NotImplementedException : public Exception {
public:
    NotImplementedException(const std::string& message);
    NotImplementedException();
};

}

#endif // DUCK_ENGINE_EXCEPTIONS_NOTIMPLEMENTEDEXCEPTION_H
