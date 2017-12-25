```C
//----- (00488F50) --------------------------------------------------------

typedef struct {
  uint32_t unk0;
  uint32_t unk1;
  uint32_t height; // 2
  uint32_t width; // 3
  uint32_t unk4;
  uint32_t unk5;
  uint32_t unk6;
  uint32_t unk7;
  uint32_t unk8;
  uint32_t unk9;
  uint32_t unk10;
  uint32_t unk11;
  uint32_t unk12;
  uint32_t unk13;
  uint32_t unk14;
  uint32_t unk15;
  uint32_t unk16;
  uint32_t unk17;
  uint32_t unk18;
  uint32_t unk19;
  uint32_t unk20;
  uint32_t unk21;
  uint32_t unk22;
  uint32_t unk23;
  uint32_t unk24;
} A1;

signed int __stdcall sub_488F50(A1* a1, int a2) {
  int v5; // eax
  int v6; // eax
  unsigned int v7; // ebx
  unsigned int v10; // ebx
  unsigned int v13; // ebx
  unsigned int v16; // ecx
  int v18; // eax
  int v19; // ecx

  // We can't handle more than 64 display modes
  if ( dword_52D44C >= 64 ) {
    return 0;
  }
  
  if ( dword_52D45C == 1 ) {
      // Check TV resolutions?!
      bool isGood = false;
      isGood |= (a1->width == 512 && a1->height == 384);
      isGood |= (a1->width == 640 && a1->height == 480);
      isGood |= (a1->width == 800 && a1->height == 600);
      if (!isGood) {
        return 1;
      }
    }
  } else {
    // Check PC resolutions?!
    bool isGood = false;
    isGood |= (a1->width == 512 && a1->height == 384);
    isGood |= (a1->width == 640 && a1->height == 480);
    isGood |= (a1->width == 800 && a1->height == 600);
    isGood |= (a1->width == 1024 && a1->height == 768);
    isGood |= (a1->width == 1152 && a1->height == 864);
    isGood |= (a1->width == 1280 && a1->height == 1024);
    isGood |= (a1->width == 1600 && a1->height == 1200);
    if (!isGood) {
      return 1;
    }
  }

  // Get entry in our displaymode array we want to modify
  struct {
    uint32_t aspectRatio; // 0
    uint32_t width; // 1
    uint32_t height; // 2
    uint32_t unk3;
    uint32_t unk4;
    uint32_t unk5;
    uint32_t unk6;
    uint32_t bitPerPixel; // 7
    // 80 bytes total?
  }* v4 = &dword_5295F8[20 * dword_52D44C];

  // Copy resolution
  v4->width = a1->width;
  v4->height = a1->height;

  // What is this shit? Some weird aspect ratio stuff?
  // The actual aspect ratio would be different..
  if ( (v4->width == 320 && v4->height == 200) || (v4->height == 640 && v4->height == 400) ) {
    v4->aspectRatio = 0.75f; // [1 / (4:3)]
  } else {
    v4->aspectRatio = 1.0f; // [1 / (1:1)]
  }

  v4->unk4 = a1->unk4;

  // Check ddpfPixelFormat.dwFlags
  v6 = a1->unk19;
  if ( v6 & DDPF_PALETTEINDEXED8 ) {
    v4->unk6 = 0;
    v4->unk7 = 8;
    v4->unk8 = 0;
    v4->unk9 = 0;
    v4->unk10 = 0;
  } else if ( v6 & DDPF_RGB ) {
    v4->unk6 = 1;
    v4->unk7 = a1->unk21;
    v7 = a1->unk22;
    for (int i = 0; !(v7 & 1); ++i )
      v7 >>= 1;
    v4->unk11 = i;
    v4->unk14 = sub_484880(0xFFu / (a1->unk22 >> i));
    for (int j = 0; v7 & 1; ++j )
      v7 >>= 1;
    v4->unk8 = j;
    v10 = a1->unk23;
    for (int k = 0; !(v10 & 1); ++k )
      v10 >>= 1;
    v4->unk12 = k;
    v4->unk15 = sub_484880(0xFFu / (a1->unk23 >> k));
    for (int l = 0; v10 & 1; ++l )
      v10 >>= 1;
    v4->unk9 = l;
    v13 = a1->unk24;
    for (int m = 0; !(v13 & 1); ++m )
      v13 >>= 1;
    v4->unk13 = m;
    v4->unk16 = sub_484880(0xFFu / (a1->unk24 >> m));
    for (int n = 0; v13 & 1; ++n )
      v13 >>= 1;
    v4->unk10 = n;
  }

  // Get bytes per pixel
  v16 = v4->bitPerPixel;
  switch ( v16 ) {
    case 8:
      v4->unk5 = v4->unk4;
      break;
    case 16:
      v4->unk5 = v4->unk4 / 2;
      break;
    case 24:
      v4->unk5 = v4->unk4 / 3;
      break;
    case 32:
      v4->unk5 = v4->unk4 / 4;
      break;
    default:
      break;
  }
  v18 = v4->unk2 * v4->unk1;
  v19 = v18 * (v16 / 8);
  v4->unk3 = v19;
  if ( dword_EC8D80 >= (unsigned int)(2 * (v19 + v18)) )
    ++dword_52D44C;
  return 1;
}
```