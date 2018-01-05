# Load model

```C
//----- (00448780) --------------------------------------------------------
// a1 = index of model to load
int *__cdecl sub_448780(int32_t a1) {
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

  // Load modelblock
  v1 = 0;
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
  v2 = ((v21 >> 16) | v21 & 0xFF0000) >> 8;
  v3 = v2 | (((v21 << 16) | v21 & 0xFF00) << 8);
  v21 = v2 | (((v21 << 16) | v21 & 0xFF00) << 8);

  // Check if model index is in valid range
  if ((a1 < 0) || (a1 >= v3)) {
    sub_42D6F0(3);
    sub_42D6F0(0);
    return 0;
  }

  // Read model entry from offset table
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
    sub_42D6F0(3);
    sub_42D6F0(0);
    return 0;
  }

  sub_42D640(0, v23, dword_E6B180, v24 - v23);
  if ( v7 / 4 > 0 )
  {
    v9 = dword_E6B180;
    v10 = v7 / 4;
    do {
      v11 = *v9;
      ++v9;
      --v10;
      *(v9 - 1) = (((v11 >> 16) | v11 & 0xFF0000) >> 8) | (((v11 << 16) | v11 & 0xFF00) << 8);
    } while ( v10 );
  }
  v12 = sub_445B40();
  v13 = (int *)((v12 + 7) & 0xFFFFFFF8);
  v22 = v12;
  sub_42D640(0, v24, v13, 0xCu);
  if ( (((*v13 & 0xFF0000 | ((unsigned int)*v13 >> 16)) >> 8) | (((*v13 << 16) | *v13 & 0xFF00) << 8)) == 1131375984 ) {
    v14 = v8 - 12;
    v26 = v8 - 12;
    v8 = ((((unsigned int)v13[2] >> 16) | v13[2] & 0xFF0000) >> 8) | (((v13[2] << 16) | v13[2] & 0xFF00) << 8);
    if ( v8 + 8 > sub_445BF0() ) {
      dword_50C610 = 1;
      sub_42D6F0(3);
      sub_42D6F0(0);
      return 0;
    }
    v16 = (char *)((dword_E981E4 - v14) & 0xFFFFFFF8);
    if ( v16 < (char *)v13 + v8 ) {
      sub_42D6F0(3);
      sub_42D6F0(0);
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
    if ( v8 + 8 > sub_445BF0() ) {
      sub_42D6F0(3);
      sub_42D6F0(0);
      dword_50C610 = 1;
      return 0;
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

  // Close files
  sub_42D6F0(3);
  sub_42D6F0(0);

  return v13;
}
```