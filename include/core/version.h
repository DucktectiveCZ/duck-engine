#ifndef DUCK_ENGINE_CORE_VERSION_H
#define DUCK_ENGINE_CORE_VERSION_H
#include "core/core.h"

namespace DUCK_CORE_NAMESPACE_NAME {

class Version {
public:
    Version(int major, int minor, int patch);
    ~Version();
    int getMajor() const;
    int getMinor() const;
    int getPatch() const;
private:
    int major;
    int minor;
    int patch;
};

}

#endif // DUCK_ENGINE_CORE_VERSION_H