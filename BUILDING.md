### Building on Linux for switch
#### Install dependencies

    wget https://github.com/devkitPro/pacman/releases/download/devkitpro-pacman-1.0.1/devkitpro-pacman.deb  
    sudo dpkg -i devkitpro-pacman.deb
    sudo dkp-pacman -S switch-dev switch-bzip2 switch-freetype switch-glad switch-glm switch-libdrm_nouveau switch-libpng switch-mesa switch-pkg-config switch-sdl2 switch-zlib switch-portlibs

#### Then

    git clone --recursive https://github.com/minkcv/pinballnx.git
    cd pinballnx
    mkdir cmake-build && cd cmake-build
    export DEVKITPRO=/opt/devkitpro  
    cmake -DPLATFORM_SWITCH=ON -DCMAKE_BUILD_TYPE=Release ../
    make pinball.nro


#### Finally
Copy the pinball.nro and data folder in cmake-build/games/pinball to the switch folder on your sd card.

### Building on Linux for Linux
#### Install dependencies

    sudo apt-get install build-essential cmake git libsdl2-dev libfreetype6-dev libglm-dev libconfig-dev

#### Then

    git clone --recursive https://github.com/minkcv/pinballnx.git
    cd pinballnx
    mkdir cmake-build && cd cmake-build
    cmake -DPLATFORM_LINUX=ON -DCMAKE_BUILD_TYPE=Release ../
    make pinball
    cd games/pinball
    ./pinball.elf

### Building on Windows for Windows
#### Install devitPro

    https://devkitpro.org/wiki/Getting_Started

#### Install dependencies
From an MSYS2 shell

    echo -e "[mingw64]\nInclude = /etc/pacman.d/mirrorlist.mingw64" >> /etc/pacman.conf
    pacman -Syyu
    pacman -Sy bash git mingw-w64-x86_64-toolchain mingw-w64-x86_64-cmake mingw-w64-x86_64-SDL2 mingw-w64-x86_64-freetype mingw-w64-x86_64-glm mingw-w64-x86_64-glew mingw-w64-x86_64-mesa

#### Then
From git bash

    git clone --recursive https://github.com/minkcv/pinballnx.git

From Command Prompt

    cd C:\devkitPro\msys2
    .\msys2_shell.bat -mingw64

Which opens an MSYS2 shell. From that new shell

    cd pinballnx
    mkdir cmake-build && cd cmake-build
    cmake -G "MSYS Makefiles" -DPLATFORM_WINDOWS=ON -DCMAKE_BUILD_TYPE=Release ../
    make pinball.elf
    cd games/pinball
    ./pinball.elf.exe
