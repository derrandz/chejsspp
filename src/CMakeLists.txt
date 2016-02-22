# Executable's path
set(BIN_DIR "./../bin")

# Name the source files
set(HEADER_APP_FILES ./../include/app)

# Get all the classes source files
AUX_SOURCE_DIRECTORY("app/controllers" SOURCE_CONTROLLERS_FILES)
AUX_SOURCE_DIRECTORY("app/helpers" SOURCE_HELPERS_FILES)
AUX_SOURCE_DIRECTORY("app/views" SOURCE_VIEWS_FILES)
AUX_SOURCE_DIRECTORY("app/entities" SOURCE_ENTITIES_FILES)

# Source files for the app directory.
set(APP_SOURCE_FILES ${SOURCE_CONTROLLERS_FILES} ${SOURCE_HELPERS_FILES} ${SOURCE_VIEWS_FILES} ${SOURCE_ENTITIES_FILES})

# All sources files including main.cpp
set(SOURCE_FILES main.cpp ${APP_SOURCE_FILES})

# Header files for our classes
include_directories(${HEADER_APP_FILES})

# The generated executable
add_executable(chessgame ${SOURCE_FILES})

# The libraries we are linking against
target_link_libraries(chessgame ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})

# The installation path
install(TARGETS chessgame RUNTIME DESTINATION ${BIN_DIR})