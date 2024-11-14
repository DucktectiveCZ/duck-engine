#ifndef DUCK_ENGINE_GRAPHICS_DIMENSION_H
#define DUCK_ENGINE_GRAPHICS_DIMENSION_H

#include "core/core.h"

namespace DUCK_GRAPHICS_NAMESPACE_NAME {

class Dimension {
public:
    Dimension() = default;
    Dimension(int width, int height);
    ~Dimension() = default;

    int getWidth() const;
    int getHeight() const;
    
    void setWidth(int width);
    void setHeight(int height);
    
    bool operator==(const Dimension& other) const;
    bool operator!=(const Dimension& other) const;

    Dimension& operator+=(const Dimension& other);
    Dimension& operator-=(const Dimension& other);
    Dimension& operator*=(const Dimension& other);
    Dimension& operator/=(const Dimension& other);
    
    Dimension& operator++();
    Dimension operator++(int);
    Dimension& operator--();
    Dimension operator--(int);
    
    Dimension operator+(const Dimension& other) const;
    Dimension operator-(const Dimension& other) const;
    Dimension operator*(const Dimension& other) const;
    Dimension operator/(const Dimension& other) const;

};

}

#endif // DUCK_ENGINE_GRAPHICS_DIMENSION_H