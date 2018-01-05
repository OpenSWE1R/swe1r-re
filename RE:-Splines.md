# Spline loader

```C
//----- (00446FC0) --------------------------------------------------------
int __cdecl sub_446FC0(int a1, int *a2) {
  unsigned int v2; // edx
  int result; // eax
  int *v4; // ecx
  signed int v5; // edx
  unsigned int v6; // eax
  int v7; // esi
  void *v8; // eax
  int v9; // edi
  int v10; // ebx
  int *v11; // ebp
  __int16 v12; // dx
  _WORD *v13; // edx
  __int16 v14; // cx
  __int16 *v15; // esi
  signed int v16; // edi
  __int16 v17; // ax
  __int16 v18; // cx
  __int16 *v19; // esi
  signed int v20; // edi
  __int16 v21; // ax
  __int16 v22; // cx
  unsigned int *v23; // ecx
  signed int v24; // esi
  unsigned int v25; // eax
  unsigned int *v26; // ecx
  signed int v27; // esi
  unsigned int v28; // eax
  unsigned int *v29; // ecx
  signed int v30; // esi
  unsigned int v31; // eax
  unsigned int *v32; // ecx
  signed int v33; // esi
  unsigned int v34; // eax
  __int16 v35; // cx
  __int16 *v36; // esi
  signed int v37; // edi
  __int16 v38; // ax
  __int16 v39; // cx
  unsigned int v40; // [esp+10h] [ebp-10h]
  int v41; // [esp+14h] [ebp-Ch]
  int v42; // [esp+18h] [ebp-8h]
  int v43; // [esp+1Ch] [ebp-4h]
  int v44; // [esp+24h] [ebp+4h]
  int v45; // [esp+28h] [ebp+8h]

  sub_42D680(2);
  sub_42D640(2, 0, &v40, 4u);
  v2 = ((v40 >> 16) | v40 & 0xFF0000) >> 8;
  result = v2 | (((v40 << 16) | v40 & 0xFF00) << 8);
  v40 = v2 | (((v40 << 16) | v40 & 0xFF00) << 8);
  if ( a1 < 0 || a1 >= result )
  {
    *a2 = 0;
  }
  else
  {
    sub_42D640(2, 4 * a1 + 4, &v42, 8u);
    v4 = &v42;
    v5 = 2;
    do
    {
      v6 = *v4;
      ++v4;
      --v5;
      *(v4 - 1) = (((v6 >> 16) | v6 & 0xFF0000) >> 8) | (((v6 << 16) | v6 & 0xFF00) << 8);
    }
    while ( v5 );
    v7 = v42;
    v8 = (void *)sub_445B40();
    v9 = v43 - v42;
    v10 = (int)v8;
    v44 = (int)v8;
    v41 = v43 - v42;
    sub_42D640(2, v7, v8, v43 - v42);
    v11 = a2;
    *a2 = sub_445B40();
    v45 = 0;
    *(_DWORD *)(*v11 + 12) = sub_445B40() + 16;
    LOBYTE(v12) = *(_WORD *)*v11 >> 8;
    HIBYTE(v12) = *(_WORD *)*v11;
    *(_WORD *)*v11 = v12;
    *(_DWORD *)(*v11 + 4) = ((*(_DWORD *)(*v11 + 4) & 0xFF0000u | (*(_DWORD *)(*v11 + 4) >> 16)) >> 8) | (((*(_DWORD *)(*v11 + 4) << 16) | *(_DWORD *)(*v11 + 4) & 0xFF00) << 8);
    *(_DWORD *)(*v11 + 8) = ((*(_DWORD *)(*v11 + 8) & 0xFF0000u | (*(_DWORD *)(*v11 + 8) >> 16)) >> 8) | (((*(_DWORD *)(*v11 + 8) << 16) | *(_DWORD *)(*v11 + 8) & 0xFF00) << 8);
    v13 = *(_WORD **)(*v11 + 12);
    if ( *(_DWORD *)(*v11 + 4) > 0 )
    {
      do
      {
        HIBYTE(v14) = *v13;
        v15 = v13 + 2;
        LOBYTE(v14) = *v13 >> 8;
        v16 = 2;
        *v13 = v14;
        LOBYTE(v14) = v13[1] >> 8;
        HIBYTE(v14) = v13[1];
        v13[1] = v14;
        do
        {
          v17 = *v15;
          HIBYTE(v18) = *v15;
          ++v15;
          LOBYTE(v18) = HIBYTE(v17);
          --v16;
          *(v15 - 1) = v18;
        }
        while ( v16 );
        v19 = v13 + 4;
        v20 = 4;
        do
        {
          v21 = *v19;
          LOBYTE(v22) = (unsigned __int16)*v19 >> 8;
          ++v19;
          HIBYTE(v22) = v21;
          --v20;
          *(v19 - 1) = v22;
        }
        while ( v20 );
        v23 = (unsigned int *)(v13 + 8);
        v24 = 3;
        do
        {
          v25 = *v23;
          ++v23;
          --v24;
          *(v23 - 1) = (((v25 >> 16) | v25 & 0xFF0000) >> 8) | (((v25 << 16) | v25 & 0xFF00) << 8);
        }
        while ( v24 );
        v26 = (unsigned int *)(v13 + 14);
        v27 = 3;
        do
        {
          v28 = *v26;
          ++v26;
          --v27;
          *(v26 - 1) = ((v28 & 0xFF0000 | (v28 >> 16)) >> 8) | (((v28 << 16) | v28 & 0xFF00) << 8);
        }
        while ( v27 );
        v29 = (unsigned int *)(v13 + 20);
        v30 = 3;
        do
        {
          v31 = *v29;
          ++v29;
          --v30;
          *(v29 - 1) = (((v31 >> 16) | v31 & 0xFF0000) >> 8) | (((v31 << 16) | v31 & 0xFF00) << 8);
        }
        while ( v30 );
        v32 = (unsigned int *)(v13 + 26);
        v33 = 3;
        do
        {
          v34 = *v32;
          ++v32;
          --v33;
          *(v32 - 1) = (((v34 >> 16) | v34 & 0xFF0000) >> 8) | (((v34 << 16) | v34 & 0xFF00) << 8);
        }
        while ( v33 );
        HIBYTE(v35) = v13[32];
        v36 = v13 + 33;
        LOBYTE(v35) = v13[32] >> 8;
        v37 = 8;
        v13[32] = v35;
        do
        {
          v38 = *v36;
          HIBYTE(v39) = *v36;
          ++v36;
          LOBYTE(v39) = HIBYTE(v38);
          --v37;
          *(v36 - 1) = v39;
        }
        while ( v37 );
        v13 += 42;
        ++v45;
      }
      while ( v45 < *(_DWORD *)(*v11 + 4) );
      v10 = v44;
      v9 = v41;
    }
    sub_445B20(v9 + v10);
    result = sub_42D6F0(2);
  }
  return result;
}
```