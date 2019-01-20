### Building on linux for switch
#### Install dependencies

    wget https://github.com/devkitPro/pacman/releases/download/devkitpro-pacman-1.0.1/devkitpro-pacman.deb  
    sudo dpkg -i devkitpro-pacman.deb
    sudo dkp-pacman -S switch-dev switch-bzip2 switch-freetype switch-glad switch-glm switch-libdrm_nouveau switch-libpng switch-mesa switch-pkg-config switch-sdl2 switch-zlib  
#### Then
Clone this repo.
Clone the (box2d repo)[https://github.com/erincatto/Box2D] and place the Box2D foler in the examples/pinball/source/ folder
Make a cmake-build folder in the root of the pinballnx repo. Change directory into the cmake-build folder.

    export DEVKITPRO=/opt/devkitpro  

    cmake -DBUILD_SWITCH=1 ../  

    make pinball.nro

### Building on linux for linux
#### Install dependencies

    sudo apt-get install build-essential cmake git libsdl2-dev libfreetype6-dev libglm-dev  

#### Then
Clone this repo.
Clone the (box2d repo)[https://github.com/erincatto/Box2D] and place the Box2D foler in the examples/pinball/source/ folder
Make a cmake-build folder in the root of the pinballnx repo. Change directory into the cmake-build folder.

    cmake -DBUILD_LINUX=1 ../

    make pinball.elf

