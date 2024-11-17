#include "logging/logging.h"
#include <spdlog/spdlog.h>
#include <SDL2/SDL.h>

int main(int argc, char **argv) {
    spdlog::set_level(spdlog::level::debug);
    duck::engine::logging::info("i luv fini<3");
}
