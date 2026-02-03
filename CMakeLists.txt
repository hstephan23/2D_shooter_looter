cmake_minimum_required(VERSION 4.1)
project(game_engine)

set(CMAKE_CXX_STANDARD 26)

include_directories(/opt/homebrew/include)
link_directories(/opt/homebrew/lib)

find_library(RAYLIB raylib HINTS /opt/homebrew/lib)

#add_subdirectory(EngineRoot/Engine/Audio)
add_subdirectory(EngineRoot/Engine/core)
#add_subdirectory(EngineRoot/Engine/ECS)
#add_subdirectory(EngineRoot/Engine/Physics)
#add_subdirectory(EngineRoot/Engine/Platform)
#add_subdirectory(EngineRoot/Engine/Resources)
#add_subdirectory(EngineRoot/Engine/Scene)
#add_subdirectory(EngineRoot/Engine/Scripting)
#add_subdirectory(EngineRoot/Engine/Tools)
#add_subdirectory(EngineRoot/Engine/UI)

add_executable(game_engine main.cpp)

target_link_libraries(game_engine
    PRIVATE
        core
        ${RAYLIB}
            "-framework Cocoa"
            "-framework IOKit"
            "-framework CoreVideo"
)