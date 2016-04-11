
cmake command for standalone test with no socket:

 emconfigure cmake .. -DSDL2_INCLUDE_DIR=/usr/local/include/SDL2 -DSDL2_IMAGE_INCLUDE_DIR=/usr/local/include/SDL2 -DSDL2_LIBRARY=$schoolspace/Capstone/project/SDL2_port/lib/libSDL2.a -DSDL2_IMAGE_LIBRARY=$schoolspace/Capstone/project/SDL2_image_port/lib/libSDL2_image.a -DCMAKE_CXX_FLAGS="-Wall -O2 -Oz -s SAFE_HEAP=1 -Werror -g2 -s ASSERTIONS=2 --emrun -s DEMANGLE_SUPPORT=1 -s DISABLE_EXCEPTION_CATCHING=0 --memory-init-file 0  -s STB_IMAGE=1 -s --use-preload-plugins --use-preload-plugins --preload-file ../../res" -DEMSCRIPTEN=1

cmake command for the socket version that will be integrated with the web project:

 emconfigure cmake .. -DSDL2_INCLUDE_DIR=/usr/local/include/SDL2 -DSDL2_IMAGE_INCLUDE_DIR=/usr/local/include/SDL2 -DSDL2_LIBRARY=$schoolspace/Capstone/project/SDL2_port/lib/libSDL2.a -DSDL2_IMAGE_LIBRARY=$schoolspace/Capstone/project/SDL2_image_port/lib/libSDL2_image.a -DCMAKE_CXX_FLAGS="-Wall -O2 -Oz --js-library ../../src/app/helpers/chessgame_javascript_extension.js -s SAFE_HEAP=1 -Werror -g2 -s ASSERTIONS=2 --emrun -s DEMANGLE_SUPPORT=1 -s DISABLE_EXCEPTION_CATCHING=0 --memory-init-file 0  -s STB_IMAGE=1 -s --use-preload-plugins --use-preload-plugins --preload-file ../../res" -DEMSCRIPTEN=1 -DEMSCRIPTEN_SOCKET=1 -DEMSCRIPTEN_WHITE_PLAYER=1 -DEMSCRIPTEN_BLACK_PLAYER=0