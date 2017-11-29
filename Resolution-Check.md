```C
//----- (00488F50) --------------------------------------------------------
signed int __stdcall sub_488F50(_DWORD *a1, int a2)
{
  int v2; // eax
  _DWORD *v4; // esi
  int v5; // eax
  int v6; // eax
  unsigned int v7; // ebx
  int i; // ecx
  int j; // eax
  unsigned int v10; // ebx
  int k; // ecx
  int l; // eax
  unsigned int v13; // ebx
  int m; // ecx
  int n; // eax
  unsigned int v16; // ecx
  int v18; // eax
  int v19; // ecx

  // We can't handle more than 64 display modes
  if ( dword_52D44C >= 64 ) {
    return 0;
  }
  
  v2 = a1[3];

  if ( dword_52D45C == 1 ) {
      // Check TV resolutions?!
      bool isGood = false;
      isGood |= (v2 == 512 && a1[2] == 384);
      isGood |= (v2 == 640 && a1[2] == 480);
      isGood |= (v2 == 800 && a1[2] == 600);
      if (!isGood) {
        return 1;
      }
    }
  } else {
    // Check PC resolutions?!
      bool isGood = false;
      isGood |= (v2 == 512 && a1[2] == 384);
      isGood |= (v2 == 640 && a1[2] == 480);
      isGood |= (v2 == 800 && a1[2] == 600);
      isGood |= (v2 == 1024 && a1[2] == 768);
      isGood |= (v2 == 1152 && a1[2] == 864);
      isGood |= (v2 == 1280 && a1[2] == 1024);
      isGood |= (v2 == 1600 && a1[2] == 1200);
    if (!isGood) {
      return 1;
    }
  }

  // Get entry in our displaymode array we want to modify
  v4 = &dword_5295F8[20 * dword_52D44C];

  // Copy resolution
  v4[1] = v2;
  v4[2] = a1[2];

  // What is this shit? Some weird aspect ratio stuff?
  // The actual aspect ratio would be different..
  if ( (v4[1] == 320 && v4[2] == 200) || (v4[1] == 640 && v4[2] == 400) ) {
    *v4 = 0x3F400000; // 0.75f [1 / (4:3)]
  } else {
    *v4 = 0x3F800000; // 1.0f [1 / (1:1)]
  }

  v4[4] = a1[4];

  // Check ddpfPixelFormat.dwFlags
  v6 = a1[19];
  if ( v6 & DDPF_PALETTEINDEXED8 ) {
    v4[6] = 0;
    v4[7] = 8;
    v4[8] = 0;
    v4[9] = 0;
    v4[10] = 0;
  } else if ( v6 & DDPF_RGB ) {
    v4[6] = 1;
    v4[7] = a1[21];
    v7 = a1[22];
    for ( i = 0; !(v7 & 1); ++i )
      v7 >>= 1;
    v4[11] = i;
    v4[14] = sub_484880(0xFFu / (a1[22] >> i));
    for ( j = 0; v7 & 1; ++j )
      v7 >>= 1;
    v4[8] = j;
    v10 = a1[23];
    for ( k = 0; !(v10 & 1); ++k )
      v10 >>= 1;
    v4[12] = k;
    v4[15] = sub_484880(0xFFu / (a1[23] >> k));
    for ( l = 0; v10 & 1; ++l )
      v10 >>= 1;
    v4[9] = l;
    v13 = a1[24];
    for ( m = 0; !(v13 & 1); ++m )
      v13 >>= 1;
    v4[13] = m;
    v4[16] = sub_484880(0xFFu / (a1[24] >> m));
    for ( n = 0; v13 & 1; ++n )
      v13 >>= 1;
    v4[10] = n;
  }

  // Get bytes per pixel
  v16 = v4[7];
  switch ( v16 ) {
    case 8:
      v4[5] = v4[4];
      break;
    case 16:
      v4[5] = v4[4] / 2;
      break;
    case 24:
      v4[5] = v4[4] / 3;
      break;
    case 32:
      v4[5] = v4[4] / 4;
      break;
    default:
      break;
  }
  v18 = v4[2] * v4[1];
  v19 = v18 * (v16 / 8);
  v4[3] = v19;
  if ( dword_EC8D80 >= (unsigned int)(2 * (v19 + v18)) )
    ++dword_52D44C;
  return 1;
}
```