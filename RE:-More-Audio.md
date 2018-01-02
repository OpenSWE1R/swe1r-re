# Something to do with streaming

```C
//----- (00422AC0) --------------------------------------------------------
signed int __cdecl sub_422AC0(_DWORD *a1)
{
  int v1; // edi
  int v2; // eax
  int v3; // ecx
  int v4; // eax
  signed int v5; // ebx
  char *v6; // eax
  char *v7; // ebp
  char v9; // [esp+10h] [ebp-280h]
  char v10; // [esp+90h] [ebp-200h]

  v1 = 0;
  v2 = a1[9];
  if ( v2 & 1 )
    return 0;
  v3 = a1[10];
  if ( v3 + dword_4EB44C > (unsigned int)dword_4B6D10 && !(v2 & 8) )
    sub_422F60(v3 + 102400);
  if ( a1[9] & 8 )
  {
    v4 = dword_4EB414;
  }
  else
  {
    v4 = sub_484AA0(a1[13], a1[11], a1[12], a1[10], dword_4B6D30);
    if ( !v4 )
    {
LABEL_25:
      if ( v1 )
        (*(void (__cdecl **)(int))(dword_ECC420 + 52))(v1);
      if ( a1[18] )
        sub_4850A0(a1[18]);
      a1[18] = 0;
      return 0;
    }
    dword_4EB44C += a1[10];
  }
  a1[18] = v4;
  v5 = 0;
  v6 = aDataWavs22kDat;
  if ( !dword_4B6D14 )
    v6 = aDataWavs11kDat;
  sprintf(&v10, aSSSSS, v6, &unk_E9F300, aDataWavsMusic, &Class, aDataWavsVoice);
  v7 = &v10;
  while ( 1 )
  {
    v7 = sub_48C2D0(v7, &v9, 128, asc_4B3B5C);
    if ( v9 )
    {
      sprintf(&v9, aSCS, &v9, 92, a1);
      v1 = (*(int (__cdecl **)(char *, char *))(dword_ECC420 + 48))(&v9, aRb);
      if ( v1 )
        break;
    }
    if ( !v7 )
      goto LABEL_17;
  }
  v5 = 1;
LABEL_17:
  if ( !v5 )
    goto LABEL_25;
  if ( !(a1[9] & 8) )
  {
    (*(void (__cdecl **)(int, _DWORD, _DWORD))(dword_ECC420 + 76))(v1, a1[15], 0);
    if ( sub_422F00(v1, (int)a1) )
    {
      a1[9] |= 1u;
      (*(void (__cdecl **)(int))(dword_ECC420 + 52))(v1);
      return 1;
    }
    goto LABEL_25;
  }
  if ( dword_4EB418 )
  {
    if ( *(_BYTE *)(dword_4EB418 + 36) & 1 )
      sub_422D10((_DWORD *)dword_4EB418);
  }
  dword_4EB404 = v1;
  dword_4EB418 = (int)a1;
  dword_4EB40C = a1[10];
  (*(void (__cdecl **)(int, _DWORD, _DWORD))(dword_ECC420 + 76))(v1, a1[15], 0);
  dword_4EB40C -= sub_4233A0((int)a1, 0, (void *)dword_4EB410);
  a1[9] |= 1u;
  SetEvent(hEvent);
  return 1;
}
```