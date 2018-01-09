# elfControl_Initialize

```C
//----- (00404B10) --------------------------------------------------------
signed int sub_404B10()
{
  signed int v1; // esi
  int v2; // eax
  signed int v3; // esi

  if ( sub_485360() )
    return 1;
  if ( sub_485570() )
    return 1;
  sub_407DE0();
  v1 = 0;
  dword_EC8824 = 0;
  dword_EC879C = 0;
  dword_EC887C = 0;
  dword_EC87A0 = 0;
  do
  {
    if ( sub_4855F0(v1 + 6 * dword_4D6B3C) )
    {
      dword_EC887C |= 1 << v1;
      ++dword_EC87A0;
    }
    ++v1;
  }
  while ( v1 < 6 );
  if ( dword_EC87A0 )
  {
    v2 = dword_ECA0FC[157 * dword_4D6B3C];
    dword_EC879C = dword_ECA0F8[157 * dword_4D6B3C];
    dword_EC8824 = v2;
  }
  else
  {
    dword_4B294C = 0;
    dword_4B2944 = 0;
  }
  dword_EC8770 = 0;
  dword_EC8808 = 0;
  dword_EC878C = 0;
  v3 = 0;
  do
  {
    if ( sub_4855F0(v3 + 48) )
    {
      dword_EC8808 |= 1 << v3;
      ++dword_EC878C;
    }
    ++v3;
  }
  while ( v3 < 3 );
  if ( dword_EC878C )
  {
    dword_EC8770 = dword_ECB498;
  }
  else
  {
    dword_4B2950 = 0;
    dword_4D6B38 = 0;
  }
  InitializeCriticalSection(&CriticalSection);
  dword_EC8810 = 0;
  LOBYTE(dword_4D5E60) = 0;
  dword_EC8814 = 0;
  byte_4D6B54 = 1;
  dword_EC8818 = 0;
  dword_4D6300 = 0;
  LOWORD(dword_EC881C) = 0;
  dword_4D6824 = 0;
  BYTE2(dword_EC881C) = 0;
  dword_4D6304 = 1;
  dword_4D5FB8 = 1;
  dword_4D6308 = 0;
  sub_407800(-1);
  sub_40A120(0);
  sub_409D70(0);
  sub_409EE0(0x11u, -1, -1, -1);
  if ( sub_40AE40((int)aCurrent) < 0 )
  {
    sub_40AB60();
    sub_40AB80((int)aCurrent);
  }
  if ( sub_406470(-1, &Class, 1) < 0 )
  {
    sub_405EA0(0);
    sub_405EA0(1);
    sub_405EA0(2);
  }
  if ( dword_4D55D4 )
  {
    sub_406470(0, aWheel, 1);
    dword_4B297C = 0;
    dword_EC876C = 0.0;
  }
  if ( sub_406470(-1, aCurrent, 0) <= -1 )
    sub_406080((int)aCurrent);
  sub_407630(0);
  sub_407630(1);
  return 0;
}
```

# elfControl_ReplaceMapping

```C
//----- (004078A0) --------------------------------------------------------
/*
elfControl_ReplaceMapping(cid, fncStr, whichOne, bAnalogCapture, sign, lastBinding)
elfControl_ReplaceMapping(cid, TXT_ROLL_RIGHT, whichOne, 1, -sign, lastBinding)
elfControl_ReplaceMapping(cid, fncStr, whichOne, bAnalogCapture, 0, controllerBinding)
*/
signed int __cdecl sub_4078A0(char *a1, const char *a2, int a3, int a4, int a5, int a6) {
  int v6 = sub_407500(a1, a2, a4, a3, 0);
  return sub_4078E0(a1, a2, a6, a4, a5, v6);
}
```

# elfControl_RemoveMapping

```C
//----- (00407500) --------------------------------------------------------
// elfControl_RemoveMapping(cid, TXT_ROLL_RIGHT, 1, whichOne, TRUE)
signed int __cdecl sub_407500(char *a1, const char *a2, int a3, int a4, int a5) {
  char *v5; // ebp
  int v6; // esi
  int v7; // edi
  char v9; // cl
  char *v10; // eax
  char v11; // bl
  int v12; // ecx
  char *v13; // eax
  char *v14; // esi
  int v15; // [esp+10h] [ebp-10h]
  char v16; // [esp+14h] [ebp-Ch]
  int v17; // [esp+18h] [ebp-8h]
  int v18; // [esp+1Ch] [ebp-4h]

  v5 = a1;
  v6 = 0;
  v7 = -1;
  v15 = 0;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  if ( a1 )
  {
    if ( a1 == (char *)1 )
    {
      a1 = byte_4D6518;
    }
    else if ( a1 == (char *)2 )
    {
      a1 = byte_4D6828;
    }
  }
  else
  {
    a1 = byte_4D5FC0;
  }
  if ( !sub_407CD0((int)&v16, a2, 1) )
    return -1;
  if ( a3 )
    v9 = v16 | 4;
  else
    v9 = v16 | 8;
  v10 = a1;
  v16 = v9;
  if ( *a1 == -1 )
  {
LABEL_19:
    if ( v7 < 0 )
      return -1;
  }
  else
  {
    while ( v7 < 0 )
    {
      if ( *((_DWORD *)v10 + 2) == v18 && ((unsigned __int8)*v10 & (unsigned __int8)v9) == v9 && ++v15 == a4 )
        v7 = v6;
      v11 = v10[12];
      v10 += 12;
      ++v6;
      if ( v11 == -1 )
        goto LABEL_19;
    }
  }
  if ( a5 )
  {
    v12 = v7;
    if ( v7 <= dword_4D5E20[(_DWORD)v5] - 1 )
    {
      v13 = &a1[12 * v7];
      do
      {
        v14 = v13;
        ++v12;
        v13 += 12;
        *(_DWORD *)v14 = *(_DWORD *)v13;
        *((_DWORD *)v14 + 1) = *((_DWORD *)v13 + 1);
        *((_DWORD *)v14 + 2) = *((_DWORD *)v13 + 2);
      }
      while ( v12 <= dword_4D5E20[(_DWORD)v5] - 1 );
    }
    --dword_4D5E20[(_DWORD)v5];
  }
  return v7;
}
```