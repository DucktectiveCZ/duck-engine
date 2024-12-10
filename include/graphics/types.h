#ifndef DUCK_ENGINE_GRAPHICS_TYPES_H
#define DUCK_ENGINE_GRAPHICS_TYPES_H

#include "core/core.h"

namespace DUCK_ENGINE_GRAPHICS_NAMESPACE_NAME {

using Size = long;

class Point : public duck::engine::core::Object {
public:
  Point(Size x, Size y);
  Point();

  void setX(Size x);
  void setY(Size y);
  Size getX() const;
  Size getY() const;

  Point& operator+(const Point& other);
  Point& operator-(const Point& other);
  Point& operator*(const Point& other);
  Point& operator/(const Point& other);
  
  Point& operator+=(const Point& other);
  Point& operator-=(const Point& other);
  Point& operator*=(const Point& other);
  Point& operator/=(const Point& other);
};

class Dimension : public duck::engine::core::Object {
  Dimension(Size w, Size h);
  Dimension();

  void setW(Size w);
  void setH(Size h);
  Size getW() const;
  Size getH() const;

  Dimension& operator+(const Dimension& other);
  Dimension& operator-(const Dimension& other);
  Dimension& operator*(const Dimension other);
  Dimension& operator/(const Dimension& other);
  
  Dimension& operator+=(const Dimension other);
  Dimension& operator-=(const Dimension& other);
  Dimension& operator*=(const Dimension& other);
  Dimension& operator/=(const Dimension& other); 
};

class Rectangle : public duck::engine::core::Object {
public:
  Rectangle(Size x, Size y, Size w, Size h);
  Rectangle(const Point& position, const Dimension& dimensions);
  Rectangle();

  void setX(Size x);
  void setY(Size y);
  void setWidth(Size w);
  void setHeight(Size h);
  void setPosition(const Point& p);
  void setDimensions(const Dimension& d);

  Size getX() const;
  Size getY() const;
  Size getWidth() const;
  Size getHeight() const;

private:
  Size m_x;
  Size m_y;
  Size m_width;
  Size m_height;
};

}
#endif // !DUCK_ENGINE_GRAPHICS_TYPES_H

