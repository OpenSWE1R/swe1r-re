# This article is WIP

It is assumed you have a working environment including C compiler which will work with CMake.
It is also assumed that you have a working git installation and know how to use it.

For all platforms, you must first clone the repository:

```
git clone https://github.com/OpenSWE1R/openswe1r.git
cd openswe1r
```

---

## Windows (Visual Studio)

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

## Windows (msys2)

**FIXME?!**

## macOS

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

## Arch Linux

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

## Ubuntu

**FIXME?!**

---

FIXME: Create package guidelines which autoinstalls the demo?