This function probably resolves collisions

```C
//----- (00490550) --------------------------------------------------------
// a1 =
// a2 = n x 3 component vectors
// a3 = n
// a4 = m x 3 component vectors
// a5 = # x 3 component vectors
// a6 = ?
// a7 = # x 4 component vectors
// a8 = #
// a9 = some vector scale factor
// Probably returns void, if not: needs work
void __cdecl sub_490550(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, float a9) {
  float *v13; // ecx
  signed int v15; // eax
  int v16; // esi
  int v20; // eax
  double v21; // st7
  signed int v24; // edx
  double v25; // st7
  double v26; // st7
  double v27; // st6
  float *v28; // eax
  signed int v29; // edx
  float v32; // [esp+4h] [ebp-20h]
  float v33; // [esp+8h] [ebp-1Ch]
  float v34; // [esp+Ch] [ebp-18h]
  float v35; // [esp+10h] [ebp-14h]
  int v36; // [esp+14h] [ebp-10h]
  int v38; // [esp+1Ch] [ebp-8h]
  float v41; // [esp+38h] [ebp+14h]
  float v42; // [esp+38h] [ebp+14h]

  int v10 = a8 - 1;

  float* v11 = a7 + 16 * v10;
  v13 = (float *)(a4 + 12 * v10 + 0);

  int offset = 0;

  for(int i = 0; i < a8; i++) {
    v16 = v11;

    v15 = 92;
    do {
      v15 += 4;
      v16 += 4;
      *(_DWORD *)(v16 - 4) = *(_DWORD *)(dword_DF7F2C + v15 - 4);
    } while ( v15 < 104 );

    v11[3] = 1.0f;

    int v17 = a3 - 1;

    typdef struct {
      uint32_t unk0;
      uint32_t unk1;
      uint32_t unk2;
      uint32_t unk3;
      uint32_t unk4;
      float x; // 6
      float y; // 7
      float z; // 8
      uint32_t unk9;
      float unkf10;
    } Unknown;

    Unknown** v43 = a1 + 4 * v17;
    float* v18 = (float *)(a2 + 12 * v17);

    for(int j = 0; j < a3; j++) {
      Unknown* v19 = *v43;
      v20 = v19->unk1;
      if ( v20 == 1 ) {
        v32 = v18[0] - *(float *)(a5 + 12 * v10 + 0 + offset);
        v33 = v18[1] - *(float *)(a5 + 12 * v10 + 4 + offset);
        v34 = v18[2] - *(float *)(a5 + 12 * v10 + 8 + offset);
        v41 = v32 * v32 + v33 * v33 + v34 * v34;
        v35 = sqrt(v41);
        v42 = v35;
        if ( v35 < v19->unkf10 ) {
          sub_492440(&v32);
          v26 = v13[0] * v32 + v13[1] * v33 + v13[2] * v34;
          if ( v26 > 0.0 ) {
            v27 = v42 * a9;
            v11[0] = (v19->x - v27) * v26 + v11[0];
            v11[1] = (v19->y - v27) * v26 + v11[1];
            v11[2] = (v19->z - v27) * v26 + v11[2];
          }
        }
      } else if (v20 != 0) {
        v21 = v13[0] * v18[0] + v13[1] * v18[1] + v13[2] * v18[2];
        if ( v21 > 0.0 ) {
          float* v22 = v11;
          float* v23 = &v19->x;
          for(int k = 0; k < 3; k++) {
            *v22 = *v23 * v21 + *v22;
            v22++;
            v23++;
          }

        }
      }

      v28 = v11;
      for(int v29 = 0; v29 < 4; v29++) {
        *v28 = *(float *)((char *)v28 + a6 - a7) * *v28;
        ++v28;
      }

      v18 -= 3;
      v43--;
    }
    v13 -= 3;
    v11 -= 4;

    offset -= 12;

  }

}
```

```C
//----- (0049C9F0) --------------------------------------------------------
signed int __cdecl sub_49C9F0(int a1, int *a2, _DWORD *a3)
{
  int v3; // ecx
  int v4; // ebx
  int v5; // ebp
  int *v6; // edx
  int v7; // eax
  int v8; // eax
  int v9; // ecx
  int v10; // esi
  float *v11; // edx
  int v12; // ebx
  float *v13; // ecx
  float *v14; // esi
  float *v15; // ebp
  int v16; // edi
  double v17; // st7
  int v18; // eax
  _DWORD *v19; // edx
  _DWORD *v20; // edx
  int v21; // eax
  signed int result; // eax
  signed int v23; // [esp+10h] [ebp-14h]
  int v24; // [esp+14h] [ebp-10h]
  float *v25; // [esp+18h] [ebp-Ch]
  float *v26; // [esp+1Ch] [ebp-8h]
  float *v27; // [esp+20h] [ebp-4h]
  signed int v28; // [esp+2Ch] [ebp+8h]
  int v29; // [esp+30h] [ebp+Ch]

  v3 = *a2;
  dword_DFAA04 = 0;
  v4 = a2[3];
  dword_DFAA1C = v4;
  v5 = a2[4];
  dword_DFAA08 = v5;
  dword_DFAA20 = a2[5];
  v6 = (int *)a2[1];
  v24 = v3;
  dword_DFAA18 = (int)v6;
  v7 = a2[2];
  dword_DFAA24 = v7;
  dword_DFAA14 = a3[3];
  dword_DFAA0C = a3[4];
  dword_DFAA10 = a3[5];
  v28 = 0;
  v8 = *(_DWORD *)(v7 + 4 * v3 - 4);
  v9 = v6[v3 - 1];
  v25 = (float *)(v5 + 8 * v8);
  v10 = *v6;
  v11 = (float *)(v4 + 12 * v9);
  v12 = v4 + 12 * v10;
  v13 = (float *)(dword_DFAA20 + 16 * v9);
  v14 = (float *)(dword_DFAA20 + 16 * v10);
  v26 = (float *)v12;
  v15 = (float *)(v5 + 8 * *(_DWORD *)dword_DFAA24);
  v27 = v15;
  if ( v24 > 0 )
  {
    v16 = 0;
    v23 = 4;
    v29 = 0;
    do
    {
      if ( v11[1] >= (double)*(float *)(a1 + 4) || *(float *)(v12 + 4) >= (double)*(float *)(a1 + 4) )
      {
        if ( v11[1] != *(float *)(a1 + 4)
          && *(float *)(v12 + 4) != *(float *)(a1 + 4)
          && (v11[1] < (double)*(float *)(a1 + 4) || *(float *)(v12 + 4) < (double)*(float *)(a1 + 4)) )
        {
          v17 = (*(float *)(a1 + 4) - v11[1]) / (*(float *)(v12 + 4) - v11[1]);
          *(_DWORD *)(dword_DFAA14 + v29 + 4) = *(_DWORD *)(a1 + 4);
          v12 = (int)v26;
          *(float *)(dword_DFAA14 + v29 + 8) = (v26[2] - v11[2]) * v17 + v11[2];
          v15 = v27;
          *(float *)(dword_DFAA14 + v29) = (*v26 - *v11) * v17 + *v11;
          *(float *)(dword_DFAA0C + 8 * v28) = (*v27 - *v25) * v17 + *v25;
          *(float *)(dword_DFAA0C + 8 * v28 + 4) = (v27[1] - v25[1]) * v17 + v25[1];
          *(float *)(dword_DFAA10 + v16) = (*v14 - *v13) * v17 + *v13;
          *(float *)(dword_DFAA10 + v16 + 4) = (v14[1] - v13[1]) * v17 + v13[1];
          ++v28;
          v16 += 16;
          *(float *)(dword_DFAA10 + v16 - 8) = (v14[2] - v13[2]) * v17 + v13[2];
          v29 += 12;
          *(float *)(dword_DFAA10 + v16 - 4) = (v14[3] - v13[3]) * v17 + v13[3];
          v18 = dword_DFAA04;
          LOBYTE(v18) = dword_DFAA04 | 1;
          dword_DFAA04 = v18;
        }
        if ( *(float *)(v12 + 4) >= (double)*(float *)(a1 + 4) )
        {
          v19 = (_DWORD *)(v29 + dword_DFAA14);
          *v19 = *(_DWORD *)v12;
          v19[1] = *(_DWORD *)(v12 + 4);
          v19[2] = *(_DWORD *)(v12 + 8);
          *(float *)(dword_DFAA0C + 8 * v28) = *v15;
          *(float *)(dword_DFAA0C + 8 * v28 + 4) = v15[1];
          v20 = (_DWORD *)(v16 + dword_DFAA10);
          *v20 = *(_DWORD *)v14;
          v20[1] = *((_DWORD *)v14 + 1);
          v20[2] = *((_DWORD *)v14 + 2);
          v20[3] = *((_DWORD *)v14 + 3);
          v29 += 12;
          ++v28;
          v16 += 16;
        }
      }
      v25 = v15;
      v21 = *(_DWORD *)(dword_DFAA18 + v23);
      v11 = (float *)v12;
      v12 = dword_DFAA1C + 12 * v21;
      v26 = (float *)(dword_DFAA1C + 12 * v21);
      v15 = (float *)(dword_DFAA08 + 8 * *(_DWORD *)(dword_DFAA24 + v23));
      v13 = v14;
      v27 = (float *)(dword_DFAA08 + 8 * *(_DWORD *)(dword_DFAA24 + v23));
      v14 = (float *)(dword_DFAA20 + 16 * v21);
      v23 += 4;
      --v24;
    }
    while ( v24 );
  }
  result = v28;
  if ( v28 < 3 )
    dword_DFAA04 |= 0x40u;
  return result;
}
```