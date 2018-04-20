It is assumed you have a working development environment including C compiler which will work with CMake.
It is also assumed that you have a working git installation and know how to use it.

For all platforms, you must first clone the repository and create a "build/" directory in the repository:

```
git clone https://github.com/OpenSWE1R/openswe1r.git
cd openswe1r
mkdir build
cd build
```

All of the following instructions should be ran from the newly created "build/" directory, unless noted otherwise.

After following the instructions for your platform below, you can try some of the more advanced [[Build Options]].

---

# Supported platforms:

## Windows (Visual Studio 2017) <img align="right" width="50px" height="50px" src="http://www.unicorn-engine.org/images/windows.png" alt="Windows">

*Only compilation for x86 and x64 are officially supported.*

**Platform requirements**

Make sure you have installed [a full version of Visual Studio 2017](https://www.visualstudio.com/vs/). The Community Edition is available for free, but will require a free registration at Microsoft after a short period of time.
Additionally, you need Microsofts vcpkg, a package manager for Windows. [Please follow the vcpkg quick-start guide on its repository](https://github.com/Microsoft/vcpkg#quick-start) if you don't have it installed already.
Optionally, you can also install an external installation of CMake.

**Install dependencies**

You also need to install the following vcpkg packages. If `vcpkg` is not in your `PATH` variable, you should run the following command from your vcpkg directory:

**x86:**
```
vcpkg install sdl2:x86-windows unicorn:x86-windows glew:x86-windows openal-soft:x86-windows enet:x86-windows
```
**x64:**
```
vcpkg install sdl2:x64-windows unicorn:x64-windows glew:x64-windows openal-soft:x64-windows enet:x64-windows
```

### Option 1: Using Visual Studio CMake support

*You don't need a "build/" folder for this platform*

**Generate build files**

In order to generate build files, you'll first have to create a settings file for CMake.

FIXME

**Building**

FIXME

### Option 2: Using external CMake

**Generate build files**

**x86:**
```
cmake -G "Visual Studio 15 2017" -DCMAKE_TOOLCHAIN_FILE=C:/tools/vcpkg/scripts/buildsystems/vcpkg.cmake ..
```
**x64:**
```
cmake -G "Visual Studio 15 2017 Win64" -DCMAKE_TOOLCHAIN_FILE=C:/tools/vcpkg/scripts/buildsystems/vcpkg.cmake ..
```

**Building**

```
msbuild msvc_build/openswe1r.sln
```

## Windows (MSYS2 / MinGW) <img align="right" width="50px" height="50px" src="http://www.unicorn-engine.org/images/windows.png" alt="Windows">

*Only compilation for x86 and x64 are officially supported.*

**Platform requirements**

Make sure you have [MSYS2 installed as explained on the official website](http://www.msys2.org/). Please make sure to also update your installation using pacman after going through the graphical setup. This is also explained on the website, but often ignored by users.

**Install dependencies**

**x86:**
```
mkdir unicorn
cd unicorn
wget https://raw.githubusercontent.com/Alexpux/MINGW-packages/master/mingw-w64-unicorn/PKGBUILD
MINGW_INSTALLS=mingw32 makepkg-mingw -sLf -i
cd ..
pacman -S mingw-w64-i686-SDL2 mingw-w64-i686-glew mingw-w64-i686-openal mingw-w64-i686-enet
```
**x64:**
```
mkdir unicorn
cd unicorn
wget https://raw.githubusercontent.com/Alexpux/MINGW-packages/master/mingw-w64-unicorn/PKGBUILD
MINGW_INSTALLS=mingw64 makepkg-mingw -sLf -i
cd ..
pacman -S mingw-w64-x86_64-SDL2 mingw-w64-x86_64-glew mingw-w64-x86_64-openal mingw-w64-x86_64-enet
```

**Generate build files**

```
cmake -G 'MSYS Makefiles' ..
```

**Building**

```
mingw32-make
```

## macOS <img align="right" width="50px" height="50px" src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/fa/Apple_logo_black.svg/80px-Apple_logo_black.svg.png" alt="MacOS">

**Install dependencies**

```
brew install cmake
```

**Native:**
```
brew install sdl2 unicorn glew openal-soft enet
```

**Generate build files**

```
cmake ..
```

**Building**

```
make
```

## Ubuntu <img align="right" width="50px" height="50px" src="https://upload.wikimedia.org/wikipedia/commons/thumb/a/ab/Logo-ubuntu_cof-orange-hex.svg/200px-Logo-ubuntu_cof-orange-hex.svg.png" alt="Ubuntu">

**Install dependencies**

```
apt-get install cmake
```

**Native:**
```
apt-get install libopenal-dev libenet-dev libglew-dev libsdl2-dev
```

**Generate build files**

```
mkdir unicorn
cd unicorn
wget https://github.com/unicorn-engine/unicorn/archive/1.0.1.tar.gz
tar xf 1.0.1.tar.gz --strip-components=1
UNICORN_ARCHS="x86" ./make.sh
cd ..
UNICORNDIR="$PWD/unicorn" cmake ..
```

**Building**

```
make
```

## Arch Linux <img align="right" width="50px" height="50px" src="https://upload.wikimedia.org/wikipedia/commons/a/a5/Archlinux-icon-crystal-64.svg" alt="Arch Linux">

**Install dependencies**

```
pacman -S cmake
```

**Native:**
```
pacman -S community/unicorn extra/sdl2 extra/glew extra/openal community/enet
```

**Generate build files**

```
cmake ..
```

**Building**

```
make
```

# Not officially supported (probably working):


## OpenSUSE <img align="right" width="50px" src="https://upload.wikimedia.org/wikipedia/en/thumb/9/98/OpenSUSE_official-logo-color.svg/200px-OpenSUSE_official-logo-color.svg.png" alt="OpenSUSE">


**Install dependencies**

```
zypper in cmake
```

**Native:**
```
zypper in libSDL2-devel glew-devel openal-soft-devel enet-devel
```

**Generate build files**

```
mkdir unicorn
cd unicorn
wget https://github.com/unicorn-engine/unicorn/archive/1.0.1.tar.gz
tar xf 1.0.1.tar.gz --strip-components=1
UNICORN_ARCHS="x86" ./make.sh
cd ..
UNICORNDIR="$PWD/unicorn" cmake ..
```

**Building**

```
make
```


## Fedora <img align="right" width="50px" height="50px" src="https://upload.wikimedia.org/wikipedia/commons/3/3f/Fedora_logo.svg" alt="Fedora">

## Debian <img align="right" width="50px" src="https://upload.wikimedia.org/wikipedia/commons/thumb/6/66/Openlogo-debianV2.svg/194px-Openlogo-debianV2.svg.png" alt="Debian">

## Gentoo <img align="right" width="50px" src="https://upload.wikimedia.org/wikipedia/commons/4/48/Gentoo_Linux_logo_matte.svg" alt="Gentoo">

## FreeBSD <img align="right" width="50px" height="50px" src="http://www.unicorn-engine.org/images/freebsd.png" alt="FreeBSD">

# Not officially supported (probably not working):

## OpenBSD <img align="right" width="50px" src="https://upload.wikimedia.org/wikipedia/commons/4/4c/Puffy_mascot_openbsd.gif" alt="OpenBSD">

## NetBSD <img align="right" width="50px" src="https://upload.wikimedia.org/wikipedia/en/thumb/5/5c/NetBSD.svg/200px-NetBSD.svg.png" alt="NetBSD">

## Raspbian

## Android <img align="right" width="50px" src="https://upload.wikimedia.org/wikipedia/commons/thumb/d/d7/Android_robot.svg/1200px-Android_robot.svg.png" alt="Android">