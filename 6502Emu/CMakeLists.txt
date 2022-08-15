cmake_minimum_required(VERSION 3.0.0)
project(6502Emu VERSION 0.1.0)
cmake_policy(SET CMP0079 NEW)

enable_testing()

find_package(X11 REQUIRED)
find_library(curses NAMES ncurses curses
REQUIRED)
link_libraries(${X11_LIBRARIES} curses)
include_directories(${X11_INCLUDE_DIR})

include_directories(PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/Source"
)

add_subdirectory(${PROJECT_SOURCE_DIR}/Source/Common)

add_subdirectory(${PROJECT_SOURCE_DIR}/Source/InputHandler)

add_subdirectory(${PROJECT_SOURCE_DIR}/Source/Debugger)
target_link_libraries(Debugger PUBLIC Common InputHandler)

add_subdirectory(${PROJECT_SOURCE_DIR}/Source/FileHandler)
target_link_libraries(FileHandler PUBLIC Common Debugger)

add_subdirectory(${PROJECT_SOURCE_DIR}/Source/Assembler)
target_link_libraries(Assembler PUBLIC InputHandler)

add_subdirectory(${PROJECT_SOURCE_DIR}/Source/Core)
target_link_libraries(Core PUBLIC Common Debugger InputHandler FileHandler)

add_subdirectory(${PROJECT_SOURCE_DIR}/Source/EmuWrapper)
target_link_libraries(6502Emu PUBLIC Assembler FileHandler Core)


#[[target_include_directories(6502Emu PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/Source"
                          )
]]

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
