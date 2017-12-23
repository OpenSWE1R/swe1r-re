```C
//----- (00490550) --------------------------------------------------------
int __cdecl sub_490550(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, float a9)
{
  int result; // eax
  int v10; // esi
  int v11; // edi
  int v12; // edx
  float *v13; // ecx
  int v14; // esi
  signed int v15; // eax
  int v16; // esi
  int v17; // eax
  float *v18; // ebx
  float *v19; // esi
  int v20; // eax
  double v21; // st7
  int v22; // eax
  float *v23; // ecx
  signed int v24; // edx
  double v25; // st7
  double v26; // st7
  double v27; // st6
  float *v28; // eax
  signed int v29; // edx
  double v30; // st7
  bool v31; // zf
  float v32; // [esp+4h] [ebp-20h]
  float v33; // [esp+8h] [ebp-1Ch]
  float v34; // [esp+Ch] [ebp-18h]
  float v35; // [esp+10h] [ebp-14h]
  int v36; // [esp+14h] [ebp-10h]
  int v37; // [esp+18h] [ebp-Ch]
  int v38; // [esp+1Ch] [ebp-8h]
  float *v39; // [esp+20h] [ebp-4h]
  int v40; // [esp+38h] [ebp+14h]
  float v41; // [esp+38h] [ebp+14h]
  float v42; // [esp+38h] [ebp+14h]
  int v43; // [esp+3Ch] [ebp+18h]
  float *v44; // [esp+48h] [ebp+24h]

  result = a8;
  v10 = a8 - 1;
  if ( a8 - 1 >= 0 )
  {
    v11 = a7 + 16 * v10;
    v12 = a5 - a4;
    v39 = (float *)(a5 + 12 * v10);
    v13 = (float *)(a4 + 12 * v10 + 8);
    v14 = a8;
    v44 = v13;
    v37 = a5 - a4;
    v36 = v14;
    do
    {
      v15 = 92;
      v16 = v11;
      do
      {
        v15 += 4;
        v16 += 4;
        *(_DWORD *)(v16 - 4) = *(_DWORD *)(dword_DF7F2C + v15 - 4);
      }
      while ( v15 < 104 );
      *(_DWORD *)(v11 + 12) = 1065353216;
      v17 = a3 - 1;
      if ( a3 - 1 >= 0 )
      {
        v43 = a1 + 4 * v17;
        v18 = (float *)(a2 + 12 * v17 + 8);
        v38 = a3;
        do
        {
          v19 = *(float **)v43;
          v20 = *(_DWORD *)(*(_DWORD *)v43 + 4);
          if ( v20 )
          {
            if ( v20 == 1 )
            {
              v32 = *(v18 - 2) - *v39;
              v33 = *(v18 - 1) - *(float *)((char *)v13 + v12 - 4);
              v34 = *v18 - *(float *)((char *)v13 + v12);
              v41 = v32 * v32 + v33 * v33 + v34 * v34;
              v35 = sqrt(v41);
              v42 = v35;
              if ( v35 < (double)v19[10] )
              {
                sub_492440(&v32);
                v26 = *(v44 - 2) * v32 + *(v44 - 1) * v33 + *v44 * v34;
                if ( v26 > 0.0 )
                {
                  v27 = v42 * a9;
                  *(float *)v11 = (v19[6] - v27) * v26 + *(float *)v11;
                  *(float *)(v11 + 4) = (v19[7] - v27) * v26 + *(float *)(v11 + 4);
                  *(float *)(v11 + 8) = (v19[8] - v27) * v26 + *(float *)(v11 + 8);
                }
              }
            }
          }
          else
          {
            v21 = *(v13 - 2) * *(v18 - 2) + *(v13 - 1) * *(v18 - 1) + *v13 * *v18;
            *(float *)&v40 = v21;
            if ( v21 > 0.0 )
            {
              v22 = v11;
              v23 = v19 + 6;
              v24 = 3;
              do
              {
                v25 = *v23 * *(float *)&v40;
                ++v23;
                v22 += 4;
                --v24;
                *(float *)(v22 - 4) = v25 + *(float *)(v22 - 4);
              }
              while ( v24 );
            }
          }
          v28 = (float *)v11;
          v29 = 4;
          do
          {
            v30 = *(float *)((char *)v28 + a6 - a7) * *v28;
            ++v28;
            --v29;
            *(v28 - 1) = v30;
          }
          while ( v29 );
          v13 = v44;
          v18 -= 3;
          v31 = v38 == 1;
          v43 -= 4;
          v12 = v37;
          --v38;
        }
        while ( !v31 );
      }
      v13 -= 3;
      v11 -= 16;
      v39 -= 3;
      result = v36 - 1;
      v31 = v36 == 1;
      v44 = v13;
      --v36;
    }
    while ( !v31 );
  }
  return result;
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