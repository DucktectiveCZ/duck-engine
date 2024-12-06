#ifndef DUCK_ENGINE_SCRIPT_C_SCRIPT_H
#define DUCK_ENGINE_SCRIPT_C_SCRIPT_H

#include "core/core.h"
#include "boost/dll/import.hpp"
#include <cstdint>

namespace DUCK_ENGINE_SCRIPTS_NAMESPACE_NAME::c {

// Basic types

struct CVector2 {
    int x;
    int y;
};

struct CDimension2 {
    int width;
    int height;
};

using CString = const char*;
using CBool = uint8_t;

// Constants

const CBool CTrue = 1;
const CBool CFalse = 0;

// Game objects

struct CGameObject { };
struct CComponent { };
struct CEnity { };

// C-engine communication

struct CLogInterf {
    void (*info)(CString);
    void (*error)(CString);
    void (*warning)(CString);
    void (*debug)(CString);
    void (*trace)(CString);
    void (*fatal)(CString);
};

// Event args

struct CEventArgs {
    CGameObject* sender;
};
struct CLoadEventArgs {
    CGameObject* sender;
    CLogInterf logInterf;
};
struct CUnloadEventArgs {
    CGameObject* sender;
};
struct CCollissionEventArgs {
    CGameObject* sender;
};
struct CUpdateEventArgs {
    CGameObject* sender;
};

// Event results

struct CEventResult {
    CBool success;
};
struct CCollissionEventResult {
    CBool success;
};
struct CUpdateEventResult {
    CBool success;
};

}

#endif // DUCK_ENGINE_SCRIPT_C_SCRIPT_H
