### Building on linux for switch
#### Install dependencies

    wget https://github.com/devkitPro/pacman/releases/download/devkitpro-pacman-1.0.1/devkitpro-pacman.deb  
    sudo dpkg -i devkitpro-pacman.deb
    sudo dkp-pacman -S switch-dev switch-bzip2 switch-freetype switch-glad switch-glm switch-libdrm_nouveau switch-libpng switch-mesa switch-pkg-config switch-sdl2 switch-zlib  
#### Then
Clone this repo.
Make a cmake-build folder in the root of the pinballnx repo. Change directory into the cmake-build folder.

    export DEVKITPRO=/opt/devkitpro  

    cmake -DBUILD_SWITCH=1 ../  

    make pinball.nro

### Building on linux for linux
#### Install dependencies

    sudo apt-get install build-essential cmake git libsdl2-dev libfreetype6-dev libglm-dev  

#### Then
Clone this repo.
Make a cmake-build folder in the root of the pinballnx repo. Change directory into the cmake-build folder.

    cmake -DBUILD_LINUX=1 ../

    make pinball.elf

    ./examples/pinball/pinball.elf

### Building on windows for windows
#### Install devitPro

	https://devkitpro.org/wiki/Getting_Started

#### Install dependencies
From an MSYS2 shell

	echo -e "[mingw64]\nInclude = /etc/pacman.d/mirrorlist.mingw64" >> /etc/pacman.conf
	pacman -Syyu
	pacman -Sy bash git mingw-w64-x86_64-toolchain mingw-w64-x86_64-cmake mingw-w64-x86_64-SDL2 mingw-w64-x86_64-freetype mingw-w64-x86_64-glm mingw-w64-x86_64-glew mingw-w64-x86_64-mesa


From Command Prompt

	cd C:\devkitPro\msys2
	.\msys2_shell.bat -mingw64

Which opens an MSYS2 shell. From that new shell

    cd pinballnx
    mkdir cmake-build && cd cmake-build
    cmake -G "MSYS Makefiles" -DBUILD_WINDOWS=1 ../
    make pinball.elf
    ./examples/pinball/pinball.elf.exe
