There seems to be a sprite renderer which is used for the HUD (and probably other things).

# Sprite struct

```C
// Array starting at 0xE9BA60
typedef struct {
  int16_t x; // Position x
  int16_t y; // Position y
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

# Query sprite texture (Wrapper)

```C
//----- (00446FB0) --------------------------------------------------------
// a1 = sprite texture index
SpriteTexture* __cdecl sub_446FB0(int a1) {
  return sub_446CA0(a1);
}
```

# Query sprite texture

```C
static inline uint32_t swap32(uint32_t v) {
  return ((v & 0xFF0000 | (v >> 16)) >> 8) | (((v << 16) | v & 0xFF00) << 8);
}
```

```C
//----- (00446CA0) --------------------------------------------------------
// a1 = sprite texture index
signed __int16 *__cdecl sub_446CA0(int a1) {
  int *v4; // ecx
  signed int v5; // edx
  unsigned int v6; // eax
  unsigned int v12; // ecx
  int v13; // edi
  int v14; // eax
  int v15; // eax
  unsigned int v16; // edi
  int v17; // eax
  int v18; // edi
  unsigned int v19; // ecx
  int v20; // edx
  unsigned int v21; // ebp
  int v23; // ebp
  signed int v24; // ecx
  bool v25; // zf
  bool v26; // sf
  __int16 v27; // dx
  unsigned int *v28; // edx
  int v33; // eax
  int v34; // ecx


  size_t v36; // [esp+10h] [ebp-1Ch]
  int v37; // [esp+10h] [ebp-1Ch]
  signed __int16 *v38; // [esp+14h] [ebp-18h]
  uint32_t v39; // [esp+18h] [ebp-14h]

  struct {
    uint32_t v42_begin;
    uint32_t v42_end;
  } v42u;

  // Open "out_spriteblock.bin"
  sub_42D680(1);

  // Get pointer to buffer
  //FIXME: Change to uint8_t* and use another index to navigate through this buffer
  uint16_t* i = sub_445B40();

  // Read 32 bit BE from out_spriteblock.bin and convert the to LE
  // This is the number of sprites in the file
  sub_42D640(1, 0, &v39, 4u);
  v39 = swap32(v39);

  // Check if the index is out of bounds
  if ( a1 < 0 || a1 >= v39 ) {
    return 0;
  }

  // Get offset into address table and find the offset of our index and the one after it
  sub_42D640(1, 4 * a1 + 4, &v42u, 8u);

  v42u.begin = swap32(v42u.begin);
  v42u.end = swap32(v42u.end);

  struct {
    uint16_t width; // 0x0
    uint16_t height; // 0x2 
    uint16_t format; // 0x4
    uint16_t unk3; // 0x6 always zero?
    uint32_t unk4; // 0x8 palette offset
    uint16_t unk5; // 0xC page count?
    uint16_t unk6; // 0xE always 32 [bits per pixel?]
    uint32_t unk7; // 0x10 data offset / header size? [unused?]
    // 0x14 bytes total
  }* d = i;
  //FIXME: Replace all uses of "d." with "d->"

  // Read 0x14 bytes from offset v42u.begin to buffer d / i
  sub_42D640(1, v42u.begin, d, 0x14u);

  d.width = swap16(d.width);
  d.height = swap16(d.height);
  d.unk3 = swap16(d.unk3);
  d.unk4 = swap32(d.unk4);
  d.unk5 = swap16(d.unk5);
  d.unk6 = swap16(d.unk6);
  d.unk7 = swap32(d.unk7);

  // Keep pointer to the buffer
  v38 = i;

  v18 = &d.unk7; // data pointer [points at pagetable]

  //FIXME: Verify this check in the future. Might have messed up
  if ((d->format & 0xFF) != 2 || d.unk4 ) {

    // Read page data (8 byte per page)
    uint8_t* v22 = &d[1]; // Pointer to after d
    v36 = 8 * d.unk5; //FIXME: Signed multiplication
    sub_42D640(1, v42u.begin + 20, v22, v36);

    struct {
      uint16_t width;
      uint16_t height;
      uint32_t offset;
    }* p = v22;

    // Update the data pointer
    d->unk7 = p;

    // Endianess swap pages
    for(int v24 = 0; v24 < d->unk5; v24++) {
      p[v24].width = swap16(p[v24].width);
      p[v24].height = swap16(p[v24].height);
      p[v24].offset = swap32(p[v24].offset);
    }

    // Get buffer pointer after pagetable and align it to next 16 bytes
    v22 = ((uintptr_t)v22 + v36 + 15) & 0xFFFFFFF0);

    // Read palette if there is one
    if ( d.unk4 ) {
      // Calculate palette size (it's from palette begin until the first page)
      v23 = p[0].offset - d.unk4;

      // Read palette
      sub_42D640(1, v42u.begin + d.unk4, v22, v23);

      // Update palette pointer
      d.unk4 = (int)v22;

      // Get pointer to next free bytes in buffer    
      v22 = ((uintptr_t)v22 + v23 + 15) & 0xFFFFFFF0;
    }

    i = v22;

    // Loop over all pages and read their data
    for (int32_t v32 = 0; v32 < d->unk5; ++v32 ) {

      // Get pointer to offset which is used for other things (end offset for us)
      // The last one must be handled slightly differently
      if ( v32 == d->unk5 - 1 ) {
        v33 = v42u.end - v42u.begin;
      } else {
        v33 = p[v32 + 1].offset;
      }

      // Calculate size from offset to end offset and read data
      v37 = v33 - p[v32].offset;
      sub_42D640(1, v42u.begin + p[v32].offset, i, v37);

      // Update pointer to data
      p[v32].offset = i;

      // Update buffer and page table pointer for this sprite
      //FIXME: Sprite 99 must be special?!
      if ( a1 != 99 ) {
        sub_446B60(v38, &p[v32]);
      }

      // Get next free bytes in buffer again
      i = ((uintptr_t)i + v37 + 15) & 0xFFFFFFF0;
    }

    // Update buffer pointer for special sprite
    //FIXME: Sprite 99 must be special?!
    if ( a1 == 99 ) {
      sub_446A20(v38);
    }

  }

  // Close spriteblock again
  sub_42D6F0(1);

  //FIXME: Mark the end of the buffer?
  sub_445B20((int)i);

  // Return buffer pointer
  return v38;
}
```