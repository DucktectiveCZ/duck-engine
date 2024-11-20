cmake_minimum_required(VERSION 3.20)
project(duck-engine VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find packages
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)
find_package(TinyXML2 REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(Boost REQUIRED COMPONENTS filesystem system)
# Create executable from main.cpp
add_executable(${PROJECT_NAME})




file(GLOB_RECURSE SOURCES 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

target_sources(duck-engine PRIVATE ${SOURCES})
# Link libraries
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        SDL2::SDL2
        SDL2_image::SDL2_image
        SDL2_mixer::SDL2_mixer
        fmt::fmt
        spdlog::spdlog
        tinyxml2::tinyxml2
        nlohmann_json::nlohmann_json
        Boost::system
        Boost::filesystem
)

# Set include directories
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
        ${Boost_INCLUDE_DIRS}
)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

# leon je debil
