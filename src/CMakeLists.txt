# The project's name
project(src)

# Name the source files
set(SOURCE_HEADER_FILES Headers/*)

# Get all the classes source files
AUX_SOURCE_DIRECTORY("./Classes" SOURCE_CLASSES_FILES)
AUX_SOURCE_DIRECTORY("./Classes/Pieces" SOURCE_CLASSES_FILES_1)

# All sources files including main.cpp
set(SOURCE_FILES main.cpp ${SOURCE_CLASSES_FILES} ${SOURCE_CLASSES_FILES_1})

# Header files for our classes
include_directories(${SOURCE_HEADER_FILES})

# The generated executable
add_executable(sdlchesspp ${SOURCE_FILES})

# The libraries we are linking against
target_link_libraries(sdlchesspp ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})

# The installation path
install(TARGETS sdlchesspp RUNTIME DESTINATION ${BIN_DIR})