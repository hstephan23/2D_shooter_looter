add_library(core STATIC
        src/aiming.cpp
        src/bullet_system.cpp
        src/monster.cpp
        src/player.cpp
        src/rendering.cpp
        src/startup.cpp
)

target_include_directories(core PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
)