There seems to be a sprite renderer which is used for the HUD (and probably other things).

# Sprite struct

```C
// Array starting at 0xE9BA60
typedef struct {
  int16_t x; // Position x?
  int16_t y; // Position y?
  int16_t unk0x4; // 0x4, written in sub_4286C0
  int16_t unk0x6; // 0x6, written in sub_4286C0
  float width; //0x8 Size X
  float height; //0xC Size Y
  uint32_t unk0x10; // written in sub_428720
  uint32_t flags; // Flags:
                 // 0x10000 = position is again different + size is different
                 // 0x8000 = colors are weird? might be unrelated?!
                 // 0x4000 = can't find the image on screen?!
                 // 0x2000 = ???
                 // 0x1000 = offsets the image
                 // 0x800 = ???
                 // 0x400 = ???
                 // 0x200 = ???
                 // 0x100 = tiles differently
                 // 0x80 = tiles the image somewhat?
                 // 0x40 = ???
                 // 0x20 = stay in memory?
                 // 0x10 = ???
                 // 0x8 = mirror vertically
                 // 0x4 = mirror horizontally
                 // 0x2 = ???
                 // 0x1 = used/displayed?
  uint8_t r; // 0x18 R
  uint8_t g; // 0x19 G
  uint8_t b; // 0x1A B
  uint8_t a; // 0x1B A
  SpriteTexture* texture; //0x1C, written in sub_4282F0
  // 32 bytes
} Sprite;

typedef struct {
  // At most 0x2460/2 bytes
} SpriteTexture;
```

# Activate sprite?

```C
//----- (004285D0) --------------------------------------------------------
// a1 = sprite slot
// a2 = enabled? boolean
// Probably returns nothing
__int16 __cdecl sub_4285D0(__int16 a1, int a2) {
  int *v2; // eax
  int v3; // eax
  int v4; // ecx

  LOWORD(v2) = a1;
  if ( a1 == -201) {
    LOWORD(v2) = a2 != 0;
    dword_50B700 = a2 != 0;
  } else if (a1 == -103) {
    HIBYTE(dword_50B704) = -(a2 != 0);
  } else if (a1 == -104) {
    HIBYTE(dword_50B708) = -(a2 != 0);
  } else if ( a1 >= 0 ) {
    if ( a2 ) {
      dword_E9BA74[8 * a1] |= 0x20;
    } else {
      dword_E9BA74[8 * a1] &= ~0x20;
    }
  }
  return (signed __int16)v2;
}
```

# Set sprite position

```C
//----- (00428660) --------------------------------------------------------
// a1 = sprite slot
// a2 = x position?
// a3 = y position?
// Probably returns nothing
__int16 __cdecl sub_428660(__int16 a1, int16_t a2, int16_t a3) {
  unsigned int v3; // eax

  LOWORD(v3) = a1;
  if ( a1 == -201 ) {
    LOWORD(v3) = a2;
    flt_4B91BC = (double)a2;
    flt_4B91C0 = (double)a3;
  } else if ( a1 >= 0 ) {
    v3 = 32 * a1;
    word_E9BA60[v3 / 2] = a2;
    word_E9BA62[v3 / 2] = a3;
  }
  return v3;
}
```

# Set sprite size?

```C
//----- (004286F0) --------------------------------------------------------
// a1 = sprite slot
// a2 = x size?
// a3 = y size?
// Probably returns nothing
__int16 __cdecl sub_4286F0(__int16 a1, float a2, float a3) {
  unsigned int v3; // eax

  LOWORD(v3) = a1;

  if ( a1 >= 0 ) {
    v3 = 32 * a1;
    dword_E9BA68[v3 / 4] = a2;
    dword_E9BA6C[v3 / 4] = a3;
  }
  return v3;
}
```

# Set sprite color?

```C
//----- (00428740) --------------------------------------------------------
// a1 = sprite slot
// a2 = red?
// a3 = green?
// a4 = blue?
// a5 = alpha?
// Probably returns nothing
char __cdecl sub_428740(__int16 a1, uint8_t a2, uint8_t a3, uint8_t a4, uint8_t a5) {
  if ( a1 == -103 ) {
    LOBYTE(dword_50B704) = a2;
    BYTE1(dword_50B704) = a3;
    BYTE2(dword_50B704) = a4;
    HIBYTE(dword_50B704) = a5;
  } else if ( a1 == -104 ) {
    LOBYTE(dword_50B708) = a2;
    BYTE1(dword_50B708) = a3;
    BYTE2(dword_50B708) = a4;
    HIBYTE(dword_50B708) = a5;
  } else if ( a1 >= 0 ) {
    v5 = 32 * a1;
    byte_E9BA78[v5] = a2;
    byte_E9BA79[v5] = a3;
    byte_E9BA7A[v5] = a4;
    byte_E9BA7B[v5] = a5;
  }
  return;
}
```

# Unknown 1

```C
//----- (00428720) --------------------------------------------------------
// a1 = sprite slot
// a2 = unknown
// Probably returns nothing
__int16 __cdecl sub_428720(__int16 a1, int32_t a2) {
  unsigned int v2; // eax

  LOWORD(v2) = a1;
  if ( a1 >= 0 ) {
    v2 = 32 * a1;
    dword_E9BA70[v2 / 4] = a2;
  }
  return v2;
}
```

# Unknown 2

```
//----- (004286C0) --------------------------------------------------------
// a1 = sprite slot
// a2 = unknown
// a3 = unknown
__int16 __cdecl sub_4286C0(__int16 a1, __int16 a2, __int16 a3) {
  unsigned int v3; // eax

  LOWORD(v3) = a1;
  if ( a1 >= 0 ) {
    v3 = 32 * a1;
    word_E9BA64[v3 / 2] = a2;
    word_E9BA66[v3 / 2] = a3;
  }
  return v3;
}
```

# Something related to slot -201

```C
//----- (00454920) --------------------------------------------------------
__int16 sub_454920() {
  sub_4831D0(0, 8, 8, 312, 232);
  sub_4831D0(1, 8, 8, 312, 232);
  sub_483230(1, 7);
  sub_483590(1, 85.0, -1.0, -1.0, -1.0, -1.0);
  return sub_4285D0(-201, 0);
}
```