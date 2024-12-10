#include <boost/stacktrace/frame.hpp>
#include <boost/stacktrace/safe_dump_to.hpp>
#include <boost/stacktrace/stacktrace.hpp>
#include <spdlog/common.h>
#include <spdlog/spdlog.h>
#include <SDL2/SDL.h>
#include "core/scene.h"
#include "exceptions/exception.h"
#include <boost/stacktrace.hpp>

int main_(int argc, char **argv) {
  spdlog::set_level(spdlog::level::debug);
  spdlog::debug("Loading scene");
  auto scene = duck::engine::core::Scene::loadFromFile("/home/ducktectivecz/cpp/duck-engine/examples/Scene1.xml");
  spdlog::debug("Scene loaded");
  for (auto it : scene.getChildren()) {
    spdlog::debug("Found child: ", it->toString());
  }
  return 0;
}

int main(int argc, char **argv) {
  try {
    return main_(argc, argv);
  } catch (duck::engine::exceptions::Exception ex) {
    spdlog::critical(
      "Exception caught: '{}' Stacktrace:\n{}", 
      ex.getMessage(), 
      boost::stacktrace::to_string(ex.getStacktrace()) );
  }
}

