### WIP
Provided that the project is pretty old, I still have not made the time to polish it in the manner that would make it
a reference for learning.
In the future, expect to find:

    * A throughout wiki
    * A Dockerfile! so you would not have to lose your brain with emscripten
    * git submodules to fetch the dependencies (probably)
    * The react/nodejs app where the forum of chess is taking place
    * A chess engine to be able to play against the server (for now, there is only multiplayer)
    
# chejsspp
A chess game written in C++, transcompiled to JS  to run in the browser.

### General 
This project is intended to be used when reading through the wiki, as a thorought documentation of my experience with emscripten, so I get to remember what I did, and help others at the same time.

### Description

Although different from the original one, this version will have an Express server that'll host chess battles between players, whereas the chess game is thoroughly written in C++, using SDL for graphics.

C++ is most suitable for bitboards logic, as of that, this project aims to introduce you to how to write C++ and have it work for Javascript when Javascript would not serve as C++ would. (e.g: bitboards)