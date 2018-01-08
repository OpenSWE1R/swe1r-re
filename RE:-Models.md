# Load model

```C
//----- (00448780) --------------------------------------------------------
// a1 = index of model to load
int *__cdecl sub_448780(int32_t a1) {
  int v1; // ebx
  unsigned int v2; // edx
  int v3; // eax
  int *v4; // ecx
  unsigned int v6; // eax
  int v7; // esi
  signed int v8; // ebp
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

  // Load modelblock
  sub_42D680(0);

  dword_50C600 = 1;
  dword_50C628 = 0;
  dword_50C62C = 0;
  dword_50C630 = 0;
  dword_E981E0 = 0;
  dword_E98240 = 0;
  dword_E98248 = 0;

  // Read model count
  sub_42D640(0, 0, &v21, 4u);
  v21 = = swap32(v21);

  // Check if model index is in valid range
  if ((a1 < 0) || (a1 >= v3)) {
    sub_42D6F0(3);
    sub_42D6F0(0);
    return 0;
  }

  // Read model entry from offset table
  v4 = &v23;
  sub_42D640(0, 8 * a1 + 4, v4, 3 * 4);
  for(int32_t v5 = 0; v5 < 3; v5++) {
    v4[v5] = swap32(v4[v5]);
  }

  v7 = v24 - v23;
  v8 = v25 - v24;
  if ( v7 > 153600 ) {
    sub_42D6F0(3);
    sub_42D6F0(0);
    return 0;
  }

  int32_t* v9 = dword_E6B180;
  sub_42D640(0, v23, v9, v7);
  for(int32_t v10 = 0; v10 < v7 / 4; v10++) {
    v9[v10] = swap32(v9[v10]);
  }


  // Get buffer and align to 8 byte
  typdef struct {
    uint32_t magic;
    uint32_t unk1;
    uint32_t unk2;
  } V13;
  v12 = sub_445B40();
  v13 = (int *)((v12 + 7) & 0xFFFFFFF8);

  //FIXME: Read 12 byte.. what for?
  v22 = v12;
  sub_42D640(0, v24, v13, 0xCu);

  if (swap32(v13[0]) == MAGIC('C','o','m','p')) {

    // If this chunk is compressed, decompress it

    // Get and validate length of compressed chunk
    v26 = v8 - 12;
    v8 = swap32(v13[2]);
    if ( v8 + 8 > sub_445BF0() ) {
      dword_50C610 = 1;
      sub_42D6F0(3);
      sub_42D6F0(0);
      return 0;
    }

    v16 = (char *)((dword_E981E4 - (v8 - 12)) & 0xFFFFFFF8);
    if ( v16 < (char *)v13 + v8 ) {
      sub_42D6F0(3);
      sub_42D6F0(0);
      dword_50C610 = 1;
      return 0;
    }

    // Load compressed data
    sub_42D640(0, v24 + 12, v16, v26);

    // Uncompress
    sub_42D520(v16, v13);

    // Parse model??
    sub_445B20((int)v13 + v8);
  } else {
    
    // Chunk is not compressed, just load it

    // Validate length of chunk
    if ( v8 + 8 > sub_445BF0() ) {
      sub_42D6F0(3);
      sub_42D6F0(0);
      dword_50C610 = 1;
      return 0;
    }

    // Load data
    sub_42D640(0, v24, v13, v8);

    // Parse model??
    sub_445B20((int)v13 + v8);
  }

  dword_E9822C = v22;
  dword_E6B164 = sub_445B40();
  v22 = sub_445B40();

  if ( dword_50C604 ) {
    sub_445B40();
    sub_445B40();
    sub_445B40();
    sub_445B40();
  }

  v17 = v8 / 4;
  v18 = (unsigned int *)v13;

  for (int32_t v1 = 0; v1 < v17; v1++) {
    if ( (1 << (31 - (v1 & 0x1F))) & dword_E6B180[v1 >> 5] ) {
      v18[v1] = swap32(v18[v1]);
      if ( (v18[v1] & 0xFF000000) == 0x0A000000 ) {
        sub_447490(v17, v18[v1] & 0x00FFFFFF, &v18[v1], &v18[v1 + 1]);
      } else if ( v18[v1] != 0x00000000) {
        v18[v1] = (unsigned int)v13 + v18[v1];
      }
    }
  }

  sub_4485D0(v13);

  // For certain types, the header seems to be skipped?!
  v20 = v13[0];
  if ((v20 == MAGIC('M','o','d','l')) || // 0x4D6F646C 
      (v20 == MAGIC('T','r','a','k')) || // 0x5472616B
      (v20 == MAGIC('P','o','d','d')) || // 0x506F6464
      (v20 == MAGIC('P','a','r','t')) || // 0x50617274
      (v20 == MAGIC('S','c','e','n')) || // 0x5363656E
      (v20 == MAGIC('M','A','l','t')) || // 0x4D416C74
      (v20 == MAGIC('P','u','p','p'))) { // 0x50757070 ) {
    v13++;
  } else {
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

  // Close files
  sub_42D6F0(3);
  sub_42D6F0(0);

  return v13;
}
```

### Buffer helpers

```C
//----- (00445B20) --------------------------------------------------------
// Sets a buffer / file pointer?
int __cdecl sub_445B20(int a1) {
  dword_E98200[dword_50C614] = a1;
  return nullsub_3();
}
```

```
//----- (00445B40) --------------------------------------------------------
// Used like malloc, but seems to tell the current file / buffer offset?
int sub_445B40() {
  return dword_E98200[dword_50C614];
}
```

```C
//----- (00445B50) --------------------------------------------------------
// Something like EOF?
BOOL __cdecl sub_445B50(unsigned int a1) {
  return a1 < sub_445B40();
}
```

### Texture helper

```C
//----- (00447490) --------------------------------------------------------
// a1 = ???
// a2 = texture index
// a3 = pointer to `struct {void* Texture, void* something};` (?) which receives output
// a4 = also an output, no idea, receives the equivalent of a3[1]?
void __usercall sub_447490(int a1@<ebp>, int a2, char **a3, int *a4) {
  uint32_t v8[3]; // [esp+Ch] [ebp-Ch]

  // Check texture index boundaries
  if ( a2 < 0 || a2 >= dword_E9823C ) {
    *a3 = 0;
    *a4 = 0;
    return;
  }

  // Load texture from cache
  uint32_t* v4 = dword_E93860[a2];
  if (v4) {
    *a3 = v4[0];
    *a4 = v4[1];
    return;
  }

  // Read texture offset table
  sub_42D640(3, 8 * a2 + 4, v8, 3 * 4);
  for(int32_t v6 = 0; v6 < 3; v6++) {
    v8[v6] = swap32(v8[v6]);
  }

  //FIXME: ???
  sub_447370(v8, a3, a4);

  //FIXME: ???
  sub_446C20(a3, a4);

  // Add model to cache
  dword_E93860[a2] = a3;

  // Keep track of some special textures?
  if ( a2 == 1257 ) {
    dword_50C620 = a3[0];
  } else if ( a2 == 1258 ) {
    dword_50C624 = a3[0];
  } else if ( a2 == 936 ) {
    dword_50C618 = a3[0];
  } else if ( a2 == 352 ) {
    dword_50C61C = a3[0];
  } else if ( a2 == 118 ) {
    sub_431DF0(a4, a1, a3[0]);
  }

  return;
}
```

# Parse model?!

```C
//----- (004485D0) --------------------------------------------------------
void __cdecl sub_4485D0(unsigned int *a1) {
  int v1; // esi
  signed int *v3; // eax
  unsigned int *v5; // esi
  unsigned int v6; // ecx
  int v7; // eax
  signed int v8; // eax
  signed int v9; // ecx
  unsigned int v10; // eax
  _DWORD *v11; // eax
  int v12; // esi
  int i; // edi
  unsigned int result; // eax
  int v15; // esi

  v1 = &a1[1];
  a1[0] = swap32(a1[0]);

  uint32_t v2 = a1[0];

  dword_E6B168 = 0;
  dword_E981E8 = 0;

  v3 = (signed int *)a1[1];
  if ( a1[1] != -1 ) {
    do {
      if ( v3 ) {
        sub_4476B0(v3);
      }
      v3 = *(signed int **)(v1 + 4);
      v1 += 4;
    }
    while ( v3 != (signed int *)-1 );
  }

  v5 = &a1[2];

  uint32_t tmp = swap32(*v5);
  if (tmp == MAGIC('D','a','t','a')) {
    v5[0] = tmp;
    v5[1] = swap32(v5[1]);
    for(int32_t v9 = 0; v9 < v5[1]; v9++) {
      v5[2 + v9] = swap32(v5[2 + v9]);
    }
  }

  uint32_t tmp = swap32(*v5);
  if (tmp == MAGIC('A','n','i','m') ) {
    v5[0] = tmp;
    v11 = (_DWORD *)v5[1]; //FIXME: No swap here?!
    v12 = (int)(v5 + 1);
    for ( i = v12; v11; v12 += 4 ) {
      sub_448180(v11);
      v11 = *(_DWORD **)(i + 4);
      i += 4;
    }
    v5 = (unsigned int *)(v12 + 4);
  }

  uint32_t tmp = swap32(*v5);
  if (tmp == MAGIC('A','l','t','N')) {
    v5[0] = tmp;
    v15 = &v5[1]
    if (v2 == MAGIC('M','A','l','t')) {
      while(*(int32_t*)v15) {
        sub_4476B0(*(int32_t*)v15);
        v15 += 4
      }
    }
  }

  return;
}
```

## Parse "Anim"

```C

//----- (00448180) --------------------------------------------------------
_DWORD *__cdecl sub_448180(_DWORD *a1)
{
  _DWORD *result; // eax
  signed int v2; // edi
  unsigned int v3; // ecx
  int v4; // edx
  unsigned int v5; // esi
  unsigned int v6; // ecx
  int v7; // edx
  unsigned int v8; // esi
  unsigned int v9; // ecx
  int v10; // edx
  unsigned int v11; // esi
  unsigned int v12; // ecx
  int v13; // edx
  unsigned int v14; // esi
  unsigned int v15; // ecx
  int v16; // edx
  unsigned int v17; // esi
  unsigned int v18; // ecx
  unsigned int v19; // ecx
  int v20; // esi
  int v21; // ebx
  int v22; // edx
  unsigned int v23; // ebx
  unsigned int v24; // edx
  int v25; // esi
  int v26; // ebx
  unsigned int v27; // ebp
  unsigned int v28; // edx
  int v29; // ebx
  unsigned int v30; // ebp
  unsigned int v31; // edx
  int v32; // ebx
  unsigned int v33; // ebp
  unsigned int v34; // edx
  int v35; // ebx
  unsigned int v36; // ebp
  unsigned int v37; // edx
  int v38; // ebx
  unsigned int v39; // ebp
  unsigned int v40; // edx
  int v41; // edx
  unsigned int *v42; // esi
  int i; // edx
  unsigned int *v44; // esi

  result = a1;
  v2 = 0;
  a1[55] = ((a1[55] & 0xFF0000u | (a1[55] >> 16)) >> 8) | (((a1[55] << 16) | a1[55] & 0xFF00) << 8);
  result[56] = ((result[56] & 0xFF0000u | (result[56] >> 16)) >> 8) | (((result[56] << 16) | result[56] & 0xFF00) << 8);
  v3 = a1[58];
  result[57] = ((result[57] & 0xFF0000u | (result[57] >> 16)) >> 8) | (((result[57] << 16) | result[57] & 0xFF00) << 8);
  v4 = (v3 << 16) | (unsigned __int16)(v3 & 0xFF00);
  v5 = v3 & 0xFF0000 | (v3 >> 16);
  v6 = a1[59];
  a1[58] = (v5 >> 8) | (v4 << 8);
  v7 = (v6 << 16) | (unsigned __int16)(v6 & 0xFF00);
  v8 = v6 & 0xFF0000 | (v6 >> 16);
  v9 = a1[60];
  a1[59] = (v8 >> 8) | (v7 << 8);
  v10 = (v9 << 16) | (unsigned __int16)(v9 & 0xFF00);
  v11 = v9 & 0xFF0000 | (v9 >> 16);
  v12 = a1[61];
  a1[60] = (v11 >> 8) | (v10 << 8);
  v13 = (v12 << 16) | (unsigned __int16)(v12 & 0xFF00);
  v14 = v12 & 0xFF0000 | (v12 >> 16);
  v15 = a1[62];
  a1[61] = (v14 >> 8) | (v13 << 8);
  v16 = (v15 << 16) | (unsigned __int16)(v15 & 0xFF00);
  v17 = v15 & 0xFF0000 | (v15 >> 16);
  v18 = a1[63];
  a1[62] = (v17 >> 8) | (v16 << 8);
  a1[63] = ((v18 & 0xFF0000 | (v18 >> 16)) >> 8) | (((v18 << 16) | v18 & 0xFF00) << 8);
  v19 = ((result[64] & 0xFF0000u | (result[64] >> 16)) >> 8) | (((result[64] << 16) | result[64] & 0xFF00) << 8);
  v20 = (result[65] << 16) | result[65] & 0xFF00;
  v21 = a1[65] >> 16;
  v22 = a1[65] & 0xFF0000;
  a1[64] = v19;
  v23 = v22 | v21;
  v24 = a1[66];
  v25 = (v23 >> 8) | (v20 << 8);
  LOWORD(v23) = a1[66];
  a1[65] = v25;
  v26 = (v24 << 16) | (unsigned __int16)(v23 & 0xFF00);
  v27 = (v24 >> 16) | v24 & 0xFF0000;
  v28 = a1[67];
  a1[66] = (v27 >> 8) | (v26 << 8);
  v29 = (v28 << 16) | (unsigned __int16)(v28 & 0xFF00);
  v30 = (v28 >> 16) | v28 & 0xFF0000;
  v31 = a1[68];
  a1[67] = (v30 >> 8) | (v29 << 8);
  v32 = (v31 << 16) | (unsigned __int16)(v31 & 0xFF00);
  v33 = (v31 >> 16) | v31 & 0xFF0000;
  v34 = a1[69];
  a1[68] = (v33 >> 8) | (v32 << 8);
  v35 = (v34 << 16) | (unsigned __int16)(v34 & 0xFF00);
  v36 = (v34 >> 16) | v34 & 0xFF0000;
  v37 = a1[70];
  a1[69] = (v36 >> 8) | (v35 << 8);
  v38 = (v37 << 16) | (unsigned __int16)(v37 & 0xFF00);
  v39 = (v37 >> 16) | v37 & 0xFF0000;
  v40 = a1[74];
  a1[70] = (v39 >> 8) | (v38 << 8);
  a1[74] = (((v40 >> 16) | v40 & 0xFF0000) >> 8) | (((v40 << 16) | v40 & 0xFF00) << 8);
  switch ( v19 & 0xF )
  {
    case 1u:
    case 0xBu:
    case 0xCu:
      v2 = 1;
      break;
    case 4u:
      v2 = 2;
      break;
    case 6u:
    case 8u:
      v2 = 4;
      break;
    case 7u:
    case 9u:
    case 0xAu:
      v2 = 3;
      break;
    default:
      break;
  }
  if ( a1[71] )
  {
    v41 = 0;
    if ( v25 > 0 )
    {
      do
      {
        v42 = (unsigned int *)(a1[71] + 4 * v41++);
        *v42 = ((*v42 & 0xFF0000 | (*v42 >> 16)) >> 8) | (((*v42 << 16) | *v42 & 0xFF00) << 8);
      }
      while ( v41 < a1[65] );
    }
  }
  if ( a1[72] )
  {
    if ( v2 > 0 )
    {
      for ( i = 0; i < a1[65] * v2; *v44 = ((*v44 & 0xFF0000 | (*v44 >> 16)) >> 8) | (((*v44 << 16) | *v44 & 0xFF00) << 8) )
        v44 = (unsigned int *)(a1[72] + 4 * i++);
    }
  }
  return result;
}
```