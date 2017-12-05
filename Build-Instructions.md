# This article is WIP: nothing of this works, images are poorly hotlinked

It is assumed you have a working environment including C compiler which will work with CMake.
It is also assumed that you have a working git installation and know how to use it.

For all platforms, you must first clone the repository:

```
git clone https://github.com/OpenSWE1R/openswe1r.git
cd openswe1r
```

---

# Supported platforms:

## Windows (Visual Studio) <img align="right" width="50px" height="50px" src="http://www.unicorn-engine.org/images/windows.png" alt="Windows">

**FIXME: Manually install vcpkg and cmake?!**

* Unicorn-Engine: **FIXME: missing!!!**
* SDL2: sdl2
* GLEW: glew
* DevIL: devil
* OpenAL: openal-soft
* ENet: enet

```
vcpkg <FIXME!!!>
```

### Using Visual Studio CMake support

### Using external CMake

## Windows (msys2) <img align="right" width="50px" height="50px" src="http://www.unicorn-engine.org/images/windows.png" alt="Windows">

**FIXME?!**

## macOS <img align="right" width="50px" height="50px" src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/fa/Apple_logo_black.svg/80px-Apple_logo_black.svg.png" alt="MacOS">

* Unicorn-Engine: unicorn
* SDL2: sdl2
* GLEW: glew
* DevIL: devil
* OpenAL: openal-soft
* ENet: **FIXME: not looked for yet**

```
brew install cmake
```

```
brew install sdl2 unicorn glew devil openal-soft
```

## Arch Linux <img align="right" width="50px" height="50px" src="https://upload.wikimedia.org/wikipedia/commons/a/a5/Archlinux-icon-crystal-64.svg" alt="Arch Linux">

* Unicorn-Engine: community/unicorn
* SDL2: extra/sdl2
* GLEW: extra/glew
* DevIL: community/devil
* OpenAL: extra/openal
* ENet: community/enet

```
pacman -S cmake
```

```
pacman -S community/unicorn extra/sdl2 extra/glew community/devil extra/openal community/enet
```

# Not currently supported:

## Ubuntu <img align="right" width="50px" height="50px" src="https://assets.ubuntu.com/v1/29985a98-ubuntu-logo32.png" alt="Ubuntu">

## FreeBSD <img align="right" width="50px" height="50px" src="http://www.unicorn-engine.org/images/freebsd.png" alt="FreeBSD">

## OpenBSD <img align="right" width="50px" height="50px" src="http://www.unicorn-engine.org/images/openbsd.png" alt="OpenBSD">

## NetBSD <img align="right" width="50px" height="50px" src="http://www.unicorn-engine.org/images/netbsd.png" alt="NetBSD">

## Raspbian <img align="right" height="50px" src="https://www.raspberrypi.org/app/uploads/2011/10/Raspi-PGB001.png" alt="Raspbian">

## Android <img align="right" width="50px" height="50px" src="https://upload.wikimedia.org/wikipedia/commons/thumb/d/d7/Android_robot.svg/1200px-Android_robot.svg.png" alt="Android">