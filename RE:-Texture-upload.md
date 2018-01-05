# Getting texture dimensions

```C
// a1 = in_width
// a2 = in_height
// a3 = &out_width
// a4 = &out_height
//----- (0048A9E0) --------------------------------------------------------
void sub_48A9E0(unsigned int a1, unsigned int a2, unsigned int *a3, unsigned int *a4) {
  unsigned int min_width = *(_DWORD *)(dword_52E618 + 32);
  unsigned int max_width = *(_DWORD *)(dword_52E618 + 40);

  unsigned int width;
  if (a1 < min_width) {
    width = min_width;
  } else if (a1 > max_width) {
    width = max_width;
  } else {
    width = a1;
  }

  unsigned int min_height = *(_DWORD *)(dword_52E618 + 36);
  unsigned int max_height = *(_DWORD *)(dword_52E618 + 44);

  unsigned int height;
  if (a2 < min_height) {
    height = min_height;
  } else if (a2 > max_height) {
    height = max_height
  } else {
    height = a2;
  }

  // Check for square textures
  unsigned int must_be_square = *(_DWORD *)(dword_52E618 + 28);
  if (must_be_square) {
    // Make sure that `width` is the maximum, either `width` or `height`
    if (height > width ) {
      width = height;
    }
    *a3 = width;
    *a4 = width;
  } else {
    *a3 = width;
    *a4 = height;
  }
}
```

# Loading texture

```C
//----- (0048A5E0) --------------------------------------------------------
// a1 = ?
// a2 = texture object
// a3 = number of mipmaps
// a4 = number of bytes per pixel?
int __cdecl sub_48A5E0(_DWORD *a1, _DWORD *a2, unsigned int a3, int a4)
{
  int result; // eax
  _DWORD **v5; // ebx
  unsigned int *v6; // ebp
  unsigned int v7; // edx
  int v8; // eax
  unsigned int v10; // ebp
  unsigned int v11; // esi
  signed int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // esi
  int v15; // [esp+8Ch] [ebp-1C4h]
  int v16; // [esp+90h] [ebp-1C0h]
  int v17; // [esp+94h] [ebp-1BCh]
  int v18; // [esp+98h] [ebp-1B8h]
  int v19; // [esp+9Ch] [ebp-1B4h]
  signed int (__cdecl *v20)(_DWORD *, unsigned int, int); // [esp+A0h] [ebp-1B0h]
  int v21; // [esp+A4h] [ebp-1ACh]
  int v22; // [esp+A8h] [ebp-1A8h]
  int v23; // [esp+ACh] [ebp-1A4h]
  int v24; // [esp+B0h] [ebp-1A0h]
  unsigned int v25; // [esp+B4h] [ebp-19Ch]
  unsigned int *v26; // [esp+B8h] [ebp-198h]
  char v27; // [esp+BCh] [ebp-194h]
  unsigned int v32; // [esp+F4h] [ebp-15Ch]
  char v33; // [esp+124h] [ebp-12Ch]
  int (*v34)(); // [esp+144h] [ebp-10Ch]
  int v35; // [esp+158h] [ebp-F8h]
  unsigned int v36; // [esp+160h] [ebp-F0h]
  int v37; // [esp+164h] [ebp-ECh]
  int v38; // [esp+168h] [ebp-E8h]
  int v39; // [esp+17Ch] [ebp-D4h]

  memset(a1, 0, 0x94u);
  result = dword_52E61C;
  v15 = 0;
  v16 = 0;
  if ( !dword_52E61C )
    return result;

  v5 = (_DWORD **)a2;
  v6 = (unsigned int *)*a2;
  v26 = v6;

  // Get texture dimensions
  sub_48A9E0(v6[3], v6[4], (unsigned int *)&v19, (unsigned int *)&v18);

  //  width * height * bits_per_pixel / 8
  v25 = v19 * v18 * v6[9] >> 3;

  if ( dword_52E614 ) {
    v7 = a3;
  } else {
    v7 = 1;
    a3 = 1;
  }

  // Get proper format for number of bytes per pixel?!
  if ( a4 == 1 )
  {
    v8 = dword_52D568;
  }
  else if ( a4 == 2 )
  {
    v8 = dword_52D560;
  }
  else
  {
    v8 = dword_52D564;
  }
  qmemcpy(&v27, (char *)&unk_52D5B0 + 96 * v8, 0x20u);

  DDSURFACEDESC2 v28;
  // int v28; // [esp+DCh] [ebp-174h] + 0
  // int v29; // [esp+E0h] [ebp-170h] + 4
  // int v30; // [esp+E4h] [ebp-16Ch] + 8
  // unsigned int v31; // [esp+E8h] [ebp-168h] + 12
  memset(&v28, 0, 0x7Cu);
  v28.size = 124;
  v28.dwFlags = 0x1007 // v29 = 4103;
  v28.dwWidth = v6[3]; // v31 = v6[3];
  v28.dwHeight = v6[4]; // v30 = v6[4];
  v10 = 0;
  v15 = 0;

  v34 = 0x1800; // this will be ddsCaps.dwCaps
  qmemcpy(&v33, &v27, 0x20u);

  if ( v7 > 1 )
  {
    v29 = 135175;
    v34 = sub_401808;
    v32 = v7;
  }
  if ( dword_52E638->CreateSurface(&v28, &v15, 0) || v15->QueryInterface(&unk_4AF328, &v17) )
  {
    goto LABEL_43;
  }
  v11 = a3;
  if ( a3 )
  {
    do
    {
      memset(&v35, 0, 0x7Cu);
      v35 = 124;
      if (v15->Lock(0, &v35, 1, 0))
        goto LABEL_43;
      v12 = (*v5)[8];
      if ( v12 && v12 > 0 && v12 <= 2 )
      {
        sub_488370(*v5);
        v13 = 0;
        // Check if height is != 0
        if ( v36 )
        {
          // Copy line `v13`
          do {
            qmemcpy((void *)(v39 + v13 * v38), (const void *)((*v5)[22] + v13 * (*v5)[6]), 2 * v37);
            ++v13;
          } while ( v13 < v36 );
          v11 = a3;
        }
        sub_4883C0(*v5);
      }
      if (v15->Unlock(0))
        goto LABEL_43;
      if ( v10 < v11 - 1 )
      {
        v21 = 0;
        v22 = 0;
        v23 = 0;
        v20 = sub_401000;
        if (v15->GetAttachedSurface(&v20, &v15))
        {
          goto LABEL_43;
        }
      }
      ++v10;
      ++v5;
    }
    while ( v10 < v11 );
  }

  // Do some size checking
  if ( v19 == v26[3] && v18 == v26[4] )
    goto LABEL_39;

  DDSURFACEDESC2 v40;
  //char v40; // [esp+1D4h] [ebp-7Ch] // + 0
  //int v41; // [esp+1DCh] [ebp-74h] // + 8
  //int v42; // [esp+1E0h] [ebp-70h] // + 12
  qmemcpy(&v40, &v28, 0x7Cu);

  v40.dwWidth = v19; // v42 = v19;
  v40.dwHeight = v18; // v41 = v18;

  if ( !dword_52E638->CreateSurface(&v40, &v16, 0) && !(v16->QueryInterface((&unk_4AF328, &v24) )
  {
    v14 = 0;
    if ( a3 )
    {
      while ( !v16->Blt(0, v15, 0, 0x1000000, 0) )
      {
        if ( v14 < a3 - 1 )
        {
          v20 = sub_401000;
          v21 = 0;
          v22 = 0;
          v23 = 0;
          if (v16->GetAttachedSurface(&v20, &v16) )
          {
            break;
          }
        }
        if ( ++v14 >= a3 )
          goto LABEL_36;
      }
      goto LABEL_43;
    }
LABEL_36:
    if ( v16 )
      v16->Release();
      v17->Release();
    qmemcpy(&v28, &v40, 0x7Cu);
    v17 = v24;
LABEL_39:
    if ( v15 )
      v15->Release();
    result = (int)a1;
    a1[31] = v17;
    qmemcpy(a1, &v28, 0x7Cu);
    a1[33] = v25;
    return result;
  }
LABEL_43:
  result = v15;
  if ( v15 )
    result = v15->Release();
  return result;
}
```

# Color inversion?

```C
//----- (00431DF0) --------------------------------------------------------
// (not actually a function)
// a3 = must be "invcol"
// Probably returns void
int __usercall sub_431DF0@<eax>(int a1@<ebx>, int a2@<ebp>, char *a3)
{
  int result; // eax
  int v6; // eax
  int v7; // ebp
  int v8; // edi
  int v10; // [esp+20h] [ebp-80h]
  int v11; // [esp+28h] [ebp-78h]

  v10 = 0;
  result = strncmp(a3, aInvcol, 5u);
  if (result) {
    sprintf(a3, aInvcol);
    something = *(_DWORD *)(*((_DWORD *)a3 + 36) + 124); // or something like this..
    unk_4AF208->QueryInterface(..., &v11); //FIXME: Used to say `.., &v10, a, b); ?!

    DDSURFACEDESC2 v12;
    //  int v12; // [esp+2Ch] [ebp-74h]    0 dwSize
    //  char v13; // [esp+30h] [ebp-70h]   4 dwFlags
    //  int v14; // [esp+34h] [ebp-6Ch]    8 dwHeight
    //  int v15; // [esp+38h] [ebp-68h]   12 dwWidth
    //  int v16; // [esp+3Ch] [ebp-64h]   16 lPitch or dwLinearSize
    //  __int16 *v17; // [esp+50h] [ebp-50h] 36 lpSurface

    memset(&v12, 0, 0x7Cu);
    v12.dwSize = 124;
    v11->Lock(0, &v12, 1, 0);

    uint16_t* v4 = v12.lpSurface;

    // Calculate pitch if it doesn't exist
    if ( v12.dwFlags & DDSD_PITCH ) {
      v6 = v12.lPitch / 2;
    } else {
      v6 = v11; //FIXME: This is probably bad?!
    }

    // Loop over rows in image
    for(v7 = 0; v7 < v12.dwHeight; v7++) {
      // Loop over pixels in row
      for(v8 = 0; v8 < v12.dwWidth; v8++) {
        // Sample pixel
        uint16_t pixel = *v4;
        // Invert color but keep alpha
        //FIXME: this is a bug? inverting 0x0FFF will also overwrite alpha. Figure out if this is a bug in RE or the game.
        *v4++ = (pixel & 0xF000) | ~(pixel & 0xFFF);
      }
      // Advance to next row (v6 = pitch?, v5 = rowlength)
      v4 += v6 - v12.dwWidth;
    }
    result = v11->Unlock(0);
  }
  return result;
}
```


# Load texture from textureblock

```C
//----- (00448780) --------------------------------------------------------
int *__cdecl sub_448780(size_t a1) {
  int v1; // ebx
  unsigned int v2; // edx
  int v3; // eax
  int *v4; // ecx
  signed int v5; // edx
  unsigned int v6; // eax
  int v7; // esi
  signed int v8; // ebp
  int *v9; // ecx
  int v10; // edx
  unsigned int v11; // eax
  int v12; // eax
  int *v13; // edi
  int v14; // ebx
  int *result; // eax
  char *v16; // esi
  int v17; // ebp
  unsigned int *v18; // esi
  unsigned int v19; // eax
  int v20; // eax
  unsigned int v21; // [esp+10h] [ebp-14h]
  int v22; // [esp+14h] [ebp-10h]
  int v23; // [esp+18h] [ebp-Ch]
  int v24; // [esp+1Ch] [ebp-8h]
  int v25; // [esp+20h] [ebp-4h]
  int v26; // [esp+28h] [ebp+4h]

  // Load textureblock
  sub_42D680(3);

  v1 = 0;
  sub_42D680(0);
  dword_50C600 = 1;
  dword_50C628 = 0;
  dword_50C62C = 0;
  dword_50C630 = 0;
  dword_E981E0 = 0;
  dword_E98240 = 0;
  dword_E98248 = 0;

  // Read texture count
  sub_42D640(0, 0, &v21, 4u);
  v2 = ((v21 >> 16) | v21 & 0xFF0000) >> 8;
  v3 = v2 | (((v21 << 16) | v21 & 0xFF00) << 8);
  v21 = v2 | (((v21 << 16) | v21 & 0xFF00) << 8);
  if ( (a1 & 0x80000000) != 0 )
    goto LABEL_43;
  if ( (signed int)a1 >= v3 )
    goto LABEL_43;

  // Read entry from offset table
  sub_42D640(0, 8 * a1 + 4, &v23, 0xCu);
  v4 = &v23;
  v5 = 3;
  do {
    v6 = *v4;
    ++v4;
    --v5;
    *(v4 - 1) = ((v6 & 0xFF0000 | (v6 >> 16)) >> 8) | (((v6 << 16) | v6 & 0xFF00) << 8);
  } while ( v5 );

  v7 = v24 - v23;
  v8 = v25 - v24;
  if ( v24 - v23 > 153600 ) {
LABEL_43:
    sub_42D6F0(3);
    sub_42D6F0(0);
    result = 0;
  }
  else
  {
    sub_42D640(0, v23, dword_E6B180, v24 - v23);
    if ( v7 / 4 > 0 )
    {
      v9 = dword_E6B180;
      v10 = v7 / 4;
      do
      {
        v11 = *v9;
        ++v9;
        --v10;
        *(v9 - 1) = (((v11 >> 16) | v11 & 0xFF0000) >> 8) | (((v11 << 16) | v11 & 0xFF00) << 8);
      }
      while ( v10 );
    }
    v12 = sub_445B40();
    v13 = (int *)((v12 + 7) & 0xFFFFFFF8);
    v22 = v12;
    sub_42D640(0, v24, v13, 0xCu);
    if ( (((*v13 & 0xFF0000 | ((unsigned int)*v13 >> 16)) >> 8) | (((*v13 << 16) | *v13 & 0xFF00) << 8)) == 1131375984 )
    {
      v14 = v8 - 12;
      v26 = v8 - 12;
      v8 = ((((unsigned int)v13[2] >> 16) | v13[2] & 0xFF0000) >> 8) | (((v13[2] << 16) | v13[2] & 0xFF00) << 8);
      if ( v8 + 8 > sub_445BF0() )
      {
        dword_50C610 = 1;
        sub_42D6F0(3);
        sub_42D6F0(0);
        return 0;
      }
      v16 = (char *)((dword_E981E4 - v14) & 0xFFFFFFF8);
      if ( v16 < (char *)v13 + v8 )
      {
        sub_42D6F0(3);
        sub_42D6F0(0);
LABEL_17:
        dword_50C610 = 1;
        return 0;
      }
      sub_42D640(0, v24 + 12, v16, v26);
      sub_42D520(v16, v13);
      sub_445B20((int)v13 + v8);
      v1 = 0;
    }
    else
    {
      if ( v8 + 8 > sub_445BF0() )
      {
        sub_42D6F0(3);
        sub_42D6F0(0);
        goto LABEL_17;
      }
      sub_42D640(0, v24, v13, v8);
      sub_445B20((int)v13 + v8);
    }
    dword_E9822C = v22;
    dword_E6B164 = sub_445B40();
    v22 = sub_445B40();
    if ( dword_50C604 )
    {
      sub_445B40();
      sub_445B40();
      sub_445B40();
      sub_445B40();
    }
    v17 = v8 >> 2;
    v18 = (unsigned int *)v13;
    if ( v17 > 0 )
    {
      do
      {
        if ( (1 << (31 - (v1 & 0x1F))) & dword_E6B180[v1 >> 5] )
        {
          v19 = (((*v18 >> 16) | *v18 & 0xFF0000) >> 8) | (((*v18 << 16) | *v18 & 0xFF00) << 8);
          *v18 = v19;
          if ( (v19 & 0xFF000000) == 167772160 )
          {
            sub_447490(v17, v19 & 0xFFFFFF, (char **)v18, (int *)v18 + 1);
          }
          else if ( v19 )
          {
            *v18 = (unsigned int)v13 + v19;
          }
        }
        ++v18;
        ++v1;
      }
      while ( v1 < v17 );
    }
    sub_4485D0((unsigned int *)v13);
    v20 = *v13;
    if ( *v13 == 1299145836
      || v20 == 1416782187
      || v20 == 1349477476
      || v20 == 1348563572
      || v20 == 1399022958
      || v20 == 1296133236
      || v20 == 1349873776 )
    {
      ++v13;
    }
    else
    {
      nullsub_3();
    }

    if ( dword_50C604 ) {
      sub_445B40();
      sub_445B40();
      sub_445B40();
      sub_445B40();
    }

    dword_E98240 = sub_445B40() - v22;
    dword_E981E0 = dword_E6B164 - dword_E9822C;
    sub_42D6F0(3);
    sub_42D6F0(0);
    result = v13;
  }

  return result;
}
```