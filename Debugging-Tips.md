## Tracing

From GDB you can enable tracing at any time.
Here is an example to isolate an issue shortly after `IA3dSource__7`:

```
(gdb) break Hook_IA3dSource__7
(gdb) r
```

Program runs until the breakpoint is reached, so we enable tracing now:
```
Thread 1 "openswe1r" hit Breakpoint 1, Hook_IA3dSource__7 (uc=0x5555557b97e0, _address=224853248, _size=0, _user_data=0x555556ab0470) at /home/fox/Data/Projects/OpenSWE1R/main.c:3246
3246	HACKY_COM_BEGIN(IA3dSource, 7)
(gdb) call SetTracing(1)
(gdb) c
Continuing.
```

The program continues and outputs:

```
SetWaveFormat
p 0xD66E800
a 0xD68BB74
Stack at 0xC07FFB6C; returning EAX: 0x00000000
  46847 Emulation at 423494 ('IA3dSource__7') from 423494

      0 TRACE Emulation at 0x423494 (ESP: 0xC07FFB78); eax = 0x00000000 esi = 0x0002B110 (TS: 465105553)
      1 TRACE Emulation at 0x423496 (ESP: 0xC07FFB78); eax = 0x00000000 esi = 0x0002B110 (TS: 465105553)
      2 TRACE Emulation at 0x4234AD (ESP: 0xC07FFB78); eax = 0x00000000 esi = 0x0002B110 (TS: 465105553)
      3 TRACE Emulation at 0x4234AF (ESP: 0xC07FFB78); eax = 0x00000000 esi = 0x0002B110 (TS: 465105554)
      4 TRACE Emulation at 0x4234B0 (ESP: 0xC07FFB7C); eax = 0x00000000 esi = 0x0002B110 (TS: 465105554)
      5 TRACE Emulation at 0x4234B2 (ESP: 0xC07FFB7C); eax = 0x00000000 esi = 0x0002B110 (TS: 465105554)
      6 TRACE Emulation at 0x4234B5 (ESP: 0xC07FFB7C); eax = 0x00000000 esi = 0x0002B110 (TS: 465105554)
      7 TRACE Emulation at 0x4234B6 (ESP: 0xC07FFB7C); eax = 0x00000000 esi = 0x0002B110 (TS: 465105554)
      8 TRACE Emulation at 0x4234B7 (ESP: 0xC07FFB80); eax = 0x00000000 esi = 0x00000000 (TS: 465105554)
      9 TRACE Emulation at 0x4234B9 (ESP: 0xC07FFB80); eax = 0x00000000 esi = 0x00000000 (TS: 465105554)
     10 TRACE Emulation at 0x4234BA (ESP: 0xC07FFB84); eax = 0x00000000 esi = 0x00000000 (TS: 465105554)
     11 TRACE Emulation at 0x4234BC (ESP: 0xC07FFB84); eax = 0x0002B110 esi = 0x00000000 (TS: 465105554)
     12 TRACE Emulation at 0x4234BD (ESP: 0xC07FFB88); eax = 0x0002B110 esi = 0x00000000 (TS: 465105554)
     13 TRACE Emulation at 0xC07FFBB8 (ESP: 0xC07FFB8C); eax = 0x0002B110 esi = 0x00000000 (TS: 465105554)
     14 TRACE Emulation at 0xC07FFBBE (ESP: 0xC07FFB8C); eax = 0x0002B110 esi = 0x00000000 (TS: 465105554)
Unicorn-Engine error of type 19 at 0x2b110, size = 0x1
EIP: 0xC07FFBBE
ESP: 0xC07FFB8C
EBP: 0x00000000
EAX: 0x0002B110
EBX: 0x0002B110
ECX: 0x0D68BB74
EDX: 0x0002B110
ESI: 0x00000000
EDI: 0x004D4658
EFLAGS: 0x00000084
FPSW: 0x4000
FPCW: 0x0200
FPTAG: 0xFFFF
FP0: 0x80000000000000000000
FP1: 0x40079380000000000000
FP2: 0x4005E800000000000000
FP3: 0x4005C800000000000000
FP4: 0x4005C800000000000000
FP5: 0x4005C800000000000000
FP6: 0x4005C800000000000000
FP7: 0x00000000000000000000
Emulation returned C07FFBBE
Stack [0] = C07FFBB4
Stack [1] = 0
Stack [2] = 0
Stack [3] = 0
...
```