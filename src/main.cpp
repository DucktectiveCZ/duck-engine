#include <spdlog/spdlog.h>
#include <SDL2/SDL.h>
#include "core/scene.h"

int main(int argc, char **argv) {
  auto scene = duck::engine::core::Scene::loadFromFile("/home/ducktectivecz/cpp/duck-engine/examples/Scene1.xml");
  for (auto it : scene.
}
