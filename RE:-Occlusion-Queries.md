```
(gdb) print/x *(uint32_t*)Memory(0x4BEE48)
$5 = 0x3b808081
(gdb) print/x *(uint32_t*)Memory(0x4BEE48+4)
$6 = 0x37800080
(gdb) print/x *(uint32_t*)Memory(0x4BEE48+8)
$7 = 0x33800001
(gdb) print/x *(uint32_t*)Memory(0x4BEE48+12)
$8 = 0x2f800000
```


**THIS IS FROM THE DEMO VERSION!**

```C
//----- (0042D440) --------------------------------------------------------
int sub_42D440() {
  signed int v4; // ecx
  int v5; // esi
  _BYTE *v6; // eax
  signed int v10; // ebx
  int v11; // ecx
  double v12; // st6
  int *v16; // esi
  int v17; // ebx
  int v18; // ecx
  double v19; // st6
  int v20; // esi
  int v21; // eax
  int v22; // ebp
  int v23; // ebx
  int *v24; // esi
  int v25; // ecx
  double v26; // st6
  int v27; // esi
  int v28; // eax
  int v29; // ebp
  int v31; // [esp+10h] [ebp-30h]
  unsigned int v32; // [esp+14h] [ebp-2Ch]
  int v33; // [esp+18h] [ebp-28h]
  int v35; // [esp+20h] [ebp-20h]
  int v36; // [esp+24h] [ebp-1Ch]
  int v37; // [esp+28h] [ebp-18h]
  int v38; // [esp+2Ch] [ebp-14h]
  int v39; // [esp+30h] [ebp-10h]
  unsigned int v40; // [esp+34h] [ebp-Ch]
  char v41; // [esp+38h] [ebp-8h]
  float v42; // [esp+3Ch] [ebp-4h]

  // Lock the Z-Buffer
  sub_433CD0((unsigned int *)&v35, &v33, &v32, &v42, &v41);

  int32_t v0 = v33; // pitch?
  uint32_t v1 = v32; // buffer base?
  int32_t v2 = v35; // pixel size in bytes
  v40 = v32 + dword_ED38C8 * v33; // buffer end?
  
  for(unsigned int v3 = 0; v3 < 8; v3++) {
    if ( *(int *)((char *)dword_4BEE60 + v3) >= 0 ) {
      v4 = *(int *)((char *)dword_EA5760 + v3);
      v5 = *(int *)((char *)dword_EA5768 + v3);
      if ( v4 >= -500 ) {
        v31 = 0;

        v36 = 12 - v4;
        v38 = 12 - v5;

        v37 = dword_ED39A4 - v4 - 8;
        v39 = dword_ED38C8 - v5 - 8;

        // Get pixel (v4 - 4, v5 - 4)
        v6 = (_BYTE *)(v1 + v0 * (v5 - 4) + v2 * (v4 - 4));

        // This seems to scan a 7x7 pixel block and counts pixels which were not in depth buffer [= farplane]
        for(int v7 = 0; v7 < 8; v7++) {
          for(int v8 = 0; v8 < 8; v8++) {
            if ( v8 < v36 || v8 >= v37 ||
                 v7 < v38 || v7 >= v39 ||
                 (unsigned int)v6 >= v1 && (unsigned int)v6 < v40
              && (v2 == 1 && *(uint8_t*)v6 != 0xFF || v2 == 2 && *(uint16_t*)v6 != 0xFFFF) ) {
              v31++;
            }
            v6 += v2;
          }

          v6 += v0 - 8 * v2;
        }

        *(int *)((char *)dword_EA56A0 + v3) = v31;
      } else {
        *(int *)((char *)dword_EA56A0 + v3) = 50;
      }
    }
  }

  // Get factor to bring depth values into [0.0, 1.0] range
  float v9;
  switch ( v2 ) {
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
    v11 = dword_EA5A00[v10];
    dword_EA5AC0[v10] = -1000.0f;
    if ( v11 >= 0 ) {
      v12 = 0.0;

      // Get depth pointer for pixel (v11, dword_EA5A60[v10])
      int v13 = v1 + v0 * dword_EA5A60[v10] + v11 * v2 + v2;
      int v14 = 8 * v2;

      // Read depth bytes
      for(int v15 = 0; v15 < v2; v15++) {
        v14 -= 8;
        v40 = *(uint8_t*)(--v13);
        v40 <<= v14;
        v12 += (int32_t)v40;
      }

      // Normalize depth
      dword_EA5AC0[v10] = v12 * v9;
    }
  }


  v16 = dword_EA5060;
  v17 = 0;
  v34 = dword_EA5060;
  do
  {
    if ( byte_EA59C0[v17] )
    {
      v18 = dword_EA4FC0[v17];
      *v16 = -1000.0;
      if ( v18 >= 0 )
      {
        v19 = 0.0;



        if ( v2 > 0 )
        {
          v20 = v2 + v0 * dword_EA4F20[v17] + v32 + v18 * v2;
          v21 = 8 * v2;
          v22 = v2;
          do
          {
            v21 -= 8;
            v40 = *(unsigned __int8 *)(v20-- - 1);
            --v22;
            v40 <<= v21;
            v19 = v19 + (double)(signed int)v40;
          }
          while ( v22 );
          v0 = v33;
          v16 = v34;
        }



        *(float *)v16 = v19 * v9;
      }
    }
    ++v16;
    ++v17;
    v34 = v16;
  }
  while ( (signed int)v16 < (signed int)dword_EA5100 );


  v23 = 0;
  if ( dword_517348 > 0 )
  {
    v24 = (int *)&unk_EA5BC0;
    v34 = (int *)&unk_EA5BC0;
    do
    {
      v25 = dword_EA5B80[v23];
      *v24 = -1000.0;
      if ( v25 >= 0 )
      {
        v26 = 0.0;
        if ( v2 > 0 )
        {
          v27 = v2 + v0 * dword_EA5C00[v23] + v32 + v25 * v2;
          v28 = 8 * v2;
          v29 = v2;
          do
          {
            v28 -= 8;
            v40 = *(unsigned __int8 *)(v27-- - 1);
            --v29;
            v40 <<= v28;
            v26 = v26 + (double)(signed int)v40;
          }
          while ( v29 );
          v0 = v33;
          v24 = v34;
        }
        *(float *)v24 = v26 * v9;
      }
      ++v23;
      ++v24;
      v34 = v24;
    }
    while ( v23 < dword_517348 );
  }


  return sub_433D60();
}
```