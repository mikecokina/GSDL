 # Ubuntu
 ### Prepare environment

    sudo apt-get install libsdl2-dev

    sudo apt-get install libsdl2-image-dev


### Issues

- in case trailing slashes problem, change

        set(SDL2_LIBRARIES "-L${SDL2_LIBDIR}  -lSDL2 ")
  to

        set(SDL2_LIBRARIES "-L${SDL2_LIBDIR}  -lSDL2")

  in file (or wherever file is located in your case)

        /usr/lib/x86_64-linux-gnu/cmake/SDL2/sdl2-config.cmake
