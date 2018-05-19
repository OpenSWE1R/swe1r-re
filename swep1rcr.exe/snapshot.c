/* Code related to the snapshot / screenshot feature */

// Research based on patched US version


//----- (0048D4A0) --------------------------------------------------------
// Take a screenshot
// a1 = Path
// a2 = Unknown //FIXME
signed int __cdecl sub_48D4A0(int a1, _DWORD *a2)
{
  _DWORD *v2; // esi
  int v4; // ebp
  int v5; // ebx
  unsigned int v6; // edx
  int v7; // ebp
  unsigned int v8; // edi
  _BYTE *v9; // ebx
  int v10; // edi
  int v11; // ecx
  int v12; // eax
  __int64 v13; // [esp+10h] [ebp-70h]
  int v14; // [esp+18h] [ebp-68h]
  int v15; // [esp+20h] [ebp-60h]
  int v16; // [esp+24h] [ebp-5Ch]
  int v17; // [esp+28h] [ebp-58h]
  __int16 v18; // [esp+2Ch] [ebp-54h]
  __int16 v19; // [esp+2Eh] [ebp-52h]
  int v20; // [esp+30h] [ebp-50h]
  unsigned int v21; // [esp+34h] [ebp-4Ch]
  int v22; // [esp+38h] [ebp-48h]
  int v23; // [esp+3Ch] [ebp-44h]
  int v24; // [esp+48h] [ebp-38h]
  int v25; // [esp+4Ch] [ebp-34h]
  int v26; // [esp+50h] [ebp-30h]
  int v27; // [esp+54h] [ebp-2Ch]
  int v28; // [esp+58h] [ebp-28h]
  int v29; // [esp+5Ch] [ebp-24h]
  int v30; // [esp+60h] [ebp-20h]
  int v31; // [esp+64h] [ebp-1Ch]
  int v32; // [esp+88h] [ebp+8h]

  v2 = a2;
  if ( !a2[8] )
    return 1;
  v4 = a2[4];
  v5 = a2[3];
  v6 = (unsigned int)(v5 * v4 * a2[9]) >> 3;
  HIDWORD(v13) = 0;
  *(_DWORD *)((char *)&v13 + 2) = v6 + 54;
  v14 = 0;
  memset(&v15, 0, 0x28u);
  v20 = 0;
  v21 = v6;
  LOWORD(v13) = 19778; // 'MB' (= 'B','M')
  *(int *)((char *)&v14 + 2) = 54;
  v15 = 40;
  v16 = v5;
  v17 = v4;
  v18 = 1;
  v19 = 24;
  v22 = 2834;
  v23 = 2834;
  v7 = (*(int (__cdecl **)(int, char *))(dword_ECC420 + 48))(a1, aWb);
  if ( !v7 )
  {
    sub_484780(*(_DWORD *)(dword_ECC420 + 16), (int)aDDevelQa5PcGno_2, 506, aUnableToOpenFi, a1, 0, 0, 0);
    return 1;
  }
  if ( (*(int (__cdecl **)(int, __int64 *, signed int))(dword_ECC420 + 64))(v7, &v13, 14) != 14 )
  {
    sub_484780(*(_DWORD *)(dword_ECC420 + 16), (int)aDDevelQa5PcGno_2, 515, aErrorAttemptin, 14, a1, 0, 0);
    (*(void (__cdecl **)(int))(dword_ECC420 + 52))(v7);
    return 1;
  }
  if ( (*(int (__cdecl **)(int, int *, signed int))(dword_ECC420 + 64))(v7, &v15, 40) == 40 )
  {
    v8 = 3 * a2[3];
    v32 = 3 * a2[3];
    v9 = (_BYTE *)(*(int (__cdecl **)(int))(dword_ECC420 + 32))(3 * v2[3]);
    if ( !v9 )
    {
      (*(void (__cdecl **)(int))(dword_ECC420 + 52))(v7);
      return 1;
    }
    memset(v9, 0, v8);
    v24 = 1;
    v25 = 24;
    v26 = 8;
    v27 = 8;
    v28 = 8;
    v29 = 0;
    v30 = 8;
    v31 = 16;
    sub_488370(v2);
    v10 = v2[4] - 1;
    if ( v10 < 0 )
    {
LABEL_15:
      (*(void (__cdecl **)(_BYTE *))(dword_ECC420 + 36))(v9);
      sub_4883C0(v2);
      (*(void (__cdecl **)(int))(dword_ECC420 + 52))(v7);
      return 0;
    }
    v11 = v2[3];
    while ( 1 )
    {
      sub_48D1C0(v9, &v24, (unsigned __int8 *)(v2[22] + v2[6] * v10), v2 + 8, v11, 0, 0);
      v12 = (*(int (__cdecl **)(int, _BYTE *, int))(dword_ECC420 + 64))(v7, v9, v32);
      v11 = v2[3];
      if ( v12 != 3 * v11 )
        break;
      if ( --v10 < 0 )
        goto LABEL_15;
    }
    sub_484780(*(_DWORD *)(dword_ECC420 + 16), (int)aDDevelQa5PcGno_2, 560, aErrorAttemptin, v32, a1, 0, 0);
    (*(void (__cdecl **)(_BYTE *))(dword_ECC420 + 36))(v9);
  }
  else
  {
    sub_484780(*(_DWORD *)(dword_ECC420 + 16), (int)aDDevelQa5PcGno_2, 525, aErrorAttemptin, 40, a1, 0, 0);
  }
  (*(void (__cdecl **)(int))(dword_ECC420 + 52))(v7);
  return 1;
}

//----- (00489D20) --------------------------------------------------------
// Take a screenshot
// a1 = Path to screenshot
signed int __cdecl sub_489D20(int a1) {
  return sub_48D4A0(a1, &dword_EC8DA0);
}

//----- (00410480) --------------------------------------------------------
// a1 = Filename prefix (typically "snap_")
signed int __cdecl sub_410480(char* a1) {
  FILE *v2; // eax
  char v5; // [esp+8h] [ebp-50h]

  // Search for a free screenshot index
  do {

    // Get index for this screenshot and construct filename
    int v1 = dword_4D79E4++;
    sprintf(&v5, aS03dBmp, a1, v1);

    // Try to open the file (for read access)
    v2 = fopen(&v5, aRb);

    // If we were unable to open it, assume that it doesn't exist.
    // This means we have found a free index, so we can leave the loop
    if (v2 == NULL) {
      break;
    }

    // If we opened the file successfully, close it
    fclose(v2);

  } while ( v2 );

  // Take the actual screenshot now
  return sub_489D20((int)&v5);
}
