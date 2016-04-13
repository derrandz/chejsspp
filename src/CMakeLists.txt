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
if(${EMSCRIPTEN})
	if(${EMSCRIPTEN_SOCKET})
		if(${EMSCRIPTEN_WHITE_PLAYER})
			add_executable(chessgame_white ${SOURCE_FILES})
			target_link_libraries(chessgame_white ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})
			install(TARGETS chessgame_white RUNTIME DESTINATION ${BIN_DIR})
		else()
			if(${EMSCRIPTEN_BLACK_PLAYER})
			add_executable(chessgame_black ${SOURCE_FILES})
			target_link_libraries(chessgame_black ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})
			install(TARGETS chessgame_black RUNTIME DESTINATION ${BIN_DIR})
			else()
				add_executable(chessgame ${SOURCE_FILES})
				target_link_libraries(chessgame ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})
				install(TARGETS chessgame RUNTIME DESTINATION ${BIN_DIR})
			endif()
		endif()
	else()
		add_executable(chessgame ${SOURCE_FILES})
		target_link_libraries(chessgame ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})
		install(TARGETS chessgame RUNTIME DESTINATION ${BIN_DIR})
	endif()
else()
	add_executable(chessgame ${SOURCE_FILES})
	target_link_libraries(chessgame ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})
	install(TARGETS chessgame RUNTIME DESTINATION ${BIN_DIR})
endif()

# The libraries we are linking against

# The installation path
