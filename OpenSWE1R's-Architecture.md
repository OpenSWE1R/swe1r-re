OpenSWE1R consists of 4 major parts:

- swep1rcr.exe-loader and interface code
- API reimplementations
- Game code reimplementation
- CPU Emulation

# swep1rcr.exe-loader and interface code

FIXME

# API reimplementations

Star Wars Episode 1: Racer was originally written for a handful of platforms.
For OpenSWE1R, most research is performed on the Windows versions of the game.
To be able to run this version of the game on non-Windows Operating Systems, all of the functions provided by the Operating System must be reimplemented.

As we know how the game works, we only implement those functions which are used by the game.
As we also know how they are used, we can often simplify them to reduce the amount of work.
This also means that the reimplemented APIs used in OpenSWE1R can probably not be used for other games.
This is a major difference to WINE which aims to reimplement those functions more accurately for greated compatibility.

All implemented API function signatures are currently constructed through a macro.
This macro will create a so called constructor-function (also known as "initializer") for each function, which is ran before `main()`. This constructor will register the function by name so the function can later be found during runtime.

There are different methods of symbol importing: COM instances, GetProcAddress and the PE import table.

There are 2 important calling conventions: stdcall and cdecl.


The important APIs are:

* Windows API (File access, timing, window creation, some input)
* DirectX6
  * DirectDraw (2D graphics)
  * Direct3D (3D graphics)
  * DirectInput (Input)
  * DirectPlay (Network)
* A3D (Audio playback and effects)
* Smush (Video playback)
* I-Force 2 (Force Feedback)

# Game code reimplementation

Game code reimplementations are similar to the API reimplementations. The main difference is that there are additional interfaces to communicate with the game. The game functions are also injected differently into the games memory space. See the first section for more details.

# CPU Emulation

The Windows version of Star Wars Episode 1: Racer was originally compiled only for x86 CPUs.
To be able to run the game on non-x86 CPUs, a CPU emulation layer is required.
As the emulation layer also provides greater flexibility in manipulating and observing the games state, this emulation layer is also used when compiling OpenSWE1R for x86.
This is also easier than loading the game natively as the emulation code already exists.
While this protects us from CPU incompatibilities, it also adds a hefty performance penalty.

Whenever the code switches between the emulation host or the guest, it should be considered an expensive operation.
Therefore it makes sense to rewrite those game functions which call a lot of API functions first.

The CPU emulation is mainly provided by Unicorn-Engine. Unicorn-Engine is an API with the QEMU JIT (TCG) as the primary emulation backend. Alternative backends can exist in OpenSWE1R by implementing a subset of the Unicorn-Engine API.

The CPU is directly booted into protected mode with a flat memory model.

The games code is ran until a `HLT` (Opcode 0xF4) is encountered or something fails (like invalid memory access).

Star Wars Episode 1: Racer was written at a time, when multiple threads could not run in parallel.
As multi-core CPUs were not commonly used, each thread had to wait to get a timeslice on the CPU.
This behaviour is emulated in OpenSWE1R too: Each thread is run for a time quantum on the same host emulation thread.
The end of timeslice is checked when the virtual CPU gives control back to the host (because of a HLT instruction or some error condition). If the guest does not return quick enough, it is caused to leave emulation from a second host thread.