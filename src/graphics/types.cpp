#include "graphics/types.h"

void duck::engine::graphics::Rectangle::setX(Size x) {
  m_x = x;
}
void duck::engine::graphics::Rectangle::setY(Size y) {
  m_y = y;
}
void duck::engine::graphics::Rectangle::setWidth(Size width) {
  m_width = width;
}
void duck::engine::graphics::Rectangle::setHeight(Size height) {
  m_height = height;
}

duck::engine::graphics::Size duck::engine::graphics::Rectangle::getX() const {
  return m_x;
}
duck::engine::graphics::Size duck::engine::graphics::Rectangle::getY() const {
  return m_y;
}
duck::engine::graphics::Size duck::engine::graphics::Rectangle::getWidth() const {
  return m_width;
}
duck::engine::graphics::Size duck::engine::graphics::Rectangle::getHeight() const {
  return m_height;
}
