**THIS IS FROM THE DEMO VERSION!**

This article is a bit of a misnomer. It's actually about Z-buffer readbacks in general

```C
//----- (00433CD0) --------------------------------------------------------
// a1 = &pixelsize_in_bytes
// a2 = &pitch
// a3 = &surface_data_ptr
// a4 = probably some width?
// a5 = probably some height?
// Locks the Z-Buffer
// Probably returns void
uint32_t* __cdecl sub_433CD0(uint32_t* a1, _DWORD *a2, _DWORD *a3, uint32_t* a4, uint32_t* a5) {

  // Get depth buffer surface
  DirectDrawSurface4* v5 = sub_48DB40();

  // Lock the surface
  DDSURFACEDESC2 v8; //FIXME: static assert that this is sizeof() == 124 and use this below
  memset(&v8, 0, 124);
  v8.dwSize = 124;
  v5->Lock(NULL, &v8, 1, 0);

  *a2 = desc->lPitch; // + 0x10
  *a1 = desc->ddpfPixelFormat.dwZBufferBitDepth / 8; // +0x54 ; FIXME: Confirm that this is the correct field
  *a3 = desc->lpSurface; // +0x24

  *a4 = *(_DWORD *)(*(_DWORD *)(dword_E03204 + 72) + 4);
  *a5 = *(_DWORD *)(*(_DWORD *)(dword_E03204 + 72) + 8);

  return a5;
}
```

```C
// Does various tests against the Z-Buffer
//----- (0042D440) --------------------------------------------------------
int sub_42D440() {
  int v31; // [esp+10h] [ebp-30h]
  uint8_t* v32; // [esp+14h] [ebp-2Ch] // buffer base?
  int32_t v33; // [esp+18h] [ebp-28h] // pitch
  int32_t v35; // [esp+20h] [ebp-20h] // pixel size in bytes
  int v36; // [esp+24h] [ebp-1Ch]
  int v37; // [esp+28h] [ebp-18h]
  int v38; // [esp+2Ch] [ebp-14h]
  int v39; // [esp+30h] [ebp-10h]
  uint8_t* v40; // [esp+34h] [ebp-Ch]
  uint32_t v41; // [esp+38h] [ebp-8h]
  uint32_t v42; // [esp+3Ch] [ebp-4h]

  // Lock the Z-Buffer
  sub_433CD0(&v35, &v33, &v32, &v42, &v41);

  v40 = v32 + dword_ED38C8 * v33; // buffer end?
  
  // Presumably handle up to 2 suns
  for(unsigned int v3 = 0; v3 < 2; v3++) {
    if (dword_4BEE60[v3] >= 0) {
      int32_t v4 = dword_EA5760[v3];
      int32_t v5 = dword_EA5768[v3];
      if ( v4 >= -500 ) {
        v36 = 12 - v4;
        v38 = 12 - v5;

        v37 = dword_ED39A4 - v4 - 8;
        v39 = dword_ED38C8 - v5 - 8;

        // Get pixel (v4 - 4, v5 - 4)
        uint8_t* v6 = v32 + v33 * (v5 - 4) + v35 * (v4 - 4);

        // This seems to scan a 8x8 pixel block and counts pixels which were not in depth buffer [= farplane]
        v31 = 0;
        for(int v7 = 0; v7 < 8; v7++) {
          for(int v8 = 0; v8 < 8; v8++) {
            if ( v8 < v36 || v8 >= v37 ||
                 v7 < v38 || v7 >= v39 ||
                 v6 >= v32 && v6 < v40
              && (v35 == 1 && *(uint8_t*)v6 != 0xFF || v35 == 2 && *(uint16_t*)v6 != 0xFFFF) ) {
              v31++;
            }
            v6 += v35;
          }

          v6 += v33 - 8 * v35;
        }

        dword_EA56A0[v3] = v31;
      } else {
        dword_EA56A0[v3] = 50;
      }
    }
  }

  // Get factor to bring depth values into [0.0, 1.0] range
  float v9;
  switch ( v35 ) {
    case 1: v9 = flt_4BEE48; break; // 0x3b808081 ~ 1.0 / 0xFF
    case 2: v9 = flt_4BEE4C; break; // 0x37800080 ~ 1.0 / 0xFFFF
    case 3: v9 = flt_4BEE54; break; // 0x33800001 ~ 1.0 / 0xFFFFFE
    case 4: v9 = flt_4BEE50; break; // 0x2f800000 ~ 1.0 / 0xFFFFFFFF
    default:
      v9 = v42;
      break;
  }

  // 20 coordinates:
  //   X at dword_EA5A00[v10] (int)
  //   Y at dword_EA5A60[v10] (int)
  //   Z will be at dword_EA5AC0[v10] (float)
  for(int v10 = 0; v10 < 20; v10++) {
    int v11 = dword_EA5A00[v10];
    dword_EA5AC0[v10] = -1000.0f;
    if ( v11 >= 0 ) {

      // Get depth pointer for pixel (v11, dword_EA5A60[v10])
      uint8_t* v13 = v32 + v33 * dword_EA5A60[v10] + v11 * v35 + v35;

      // Read depth bytes
      float v12 = 0.0;
      int v14 = 8 * v35;
      for(int v15 = 0; v15 < v35; v15++) {
        v14 -= 8;
        v40 = *--v13;
        v40 <<= v14;
        v12 += (int32_t)v40;
      }

      // Normalize depth
      dword_EA5AC0[v10] = v12 * v9;
    }
  }


  // 40 coordinates:
  //   byte_EA59C0[v17] must be != 0 or coord is ignored
  //   X at dword_EA4FC0[v17] (int)
  //   Y at dword_EA4F20[v17] (int)
  //   Z will be at dword_EA5060[v17] (float)
  for(int v17 = 0; v17 < 40; v17++) {
    if ( byte_EA59C0[v17] == 0) {
      continue;
    }

    int v18 = dword_EA4FC0[v17];
    dword_EA5060[v17] = -1000.0;
    if ( v18 >= 0 ) {

      uint8_t* v20 = v32 + v33 * dword_EA4F20[v17] + v18 * v35 + v35;

      float v19 = 0.0;
      int v21 = 8 * v35;
      for(int v22 = 0; v22 < v35; v22++) {
        v21 -= 8;
        v40 = *--v20;
        v40 <<= v21;
        v19 += (int32_t)v40;
      }

      dword_EA5060[v17] = v19 * v9;
    }
  }

  // dword_517348 coordinates
  //   X at dword_EA5B80[v23] (int)
  //   Y at dword_EA5C00[v23] (int)
  //   Z as output at EA5BC0 (float)
  for(int v23 = 0; v23 < dword_517348; v23++) {
    int32_t v25 = dword_EA5B80[v23];
    dword_EA5BC0[v23] = -1000.0;
    if ( v25 >= 0 ) {

      uint8_t* v27 = v32 + v33 * dword_EA5C00[v23] + v25 * v35 + v35;

      float v26 = 0.0;
      int v28 = 8 * v35;
      for(int v29 = 0; v29 < v35; v29++) {
        v28 -= 8;
        v40 = *--v27;
        v40 <<= v28;
        v26 += (int32_t)v40;
      }

      dword_EA5BC0[v23] = v26 * v9;
    }
  }

  // Unlock zbuffer
  return sub_433D60();
}
```