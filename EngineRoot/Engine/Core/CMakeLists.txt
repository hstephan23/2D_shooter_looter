add_library(core STATIC
        src/startup.cpp
        src/aiming.cpp
        src/player.cpp
        src/bullet_system.cpp
        src/rendering.cpp
)

target_include_directories(core PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
)