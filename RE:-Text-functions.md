There are more functions nearby which look like text rendering too

```
//----- (00450530) --------------------------------------------------------
int __cdecl sub_450530(__int16 a1, __int16 a2, char a3, char a4, char a5, char a6, int a7)
{
  return sub_4503E0(a1, a2, a3, a4, a5, a6, a7, -1, 0);
}

//----- (00450560) --------------------------------------------------------
int __cdecl sub_450560(__int16 a1, __int16 a2, int a3)
{
  return sub_4503E0(a1, a2, -1, -1, -1, -1, a3, -1, 0);
}

//----- (00450590) --------------------------------------------------------
// a1 = ?
// a2 = x
// a3 = y
// a4 = text
int __cdecl sub_450590(int a1, __int16 a2, __int16 a3, int a4)
{
  return sub_4503E0(a2, a3, -1, -1, -1, -1, a4, a1, 0);
}

//----- (004505C0) --------------------------------------------------------
int __cdecl sub_4505C0(__int16 a1, __int16 a2, char a3, char a4, char a5, char a6, int a7)
{
  return sub_4503E0(a1, a2, a3, a4, a5, a6, a7, -1, 1);
}
```

# Create text entry

```C
//----- (004503E0) --------------------------------------------------------
int __cdecl sub_4503E0(__int16 a1, __int16 a2, char a3, char a4, char a5, char a6, int a7, int a8, int a9)
{
  int result; // eax
  int v10; // eax
  int v11; // eax

  if ( a9 )
  {
    result = dword_50C758;
    if ( dword_50C758 < 32 )
    {
      if ( a8 < 0 )
        sprintf(&byte_E303A0[128 * dword_50C758], aS_0, a7);
      else
        sprintf(&byte_E303A0[128 * dword_50C758], aFDS, a8, a7);
      v11 = dword_50C758;
      word_E34660[2 * dword_50C758] = a1;
      word_E34662[2 * v11] = a2;
      byte_E343A0[4 * v11] = a3;
      byte_E343A1[4 * v11] = a4;
      byte_E343A2[4 * v11] = a5;
      byte_E343A3[4 * v11] = a6;
      result = v11 + 1;
      dword_50C758 = result;
    }
  }
  else
  {
    result = dword_50C750;
    if ( dword_50C750 < 128 )
    {
      if ( a8 < 0 )
        sprintf(&byte_E2C380[128 * dword_50C750], aS_0, a7);
      else
        sprintf(&byte_E2C380[128 * dword_50C750], aFDS, a8, a7);
      v10 = dword_50C750;
      word_E34860[2 * dword_50C750] = a1;
      word_E34862[2 * v10] = a2;
      byte_E2B480[4 * v10] = a3;
      byte_E2B481[4 * v10] = a4;
      byte_E2B482[4 * v10] = a5;
      byte_E2B483[4 * v10] = a6;
      result = v10 + 1;
      dword_50C750 = result;
    }
  }
  return result;
}
```

# Text rendering

This must be the actual text rendering. It also flushes all text which had been added

```C
//----- (00450100) --------------------------------------------------------
int sub_450100()
{
  int result; // eax
  int v1; // esi
  char *v2; // edi
  _DWORD *v3; // ebp
  __int16 *v4; // ebx
  int *v5; // [esp+4h] [ebp-4h]

  result = dword_50C750;
  v1 = 0;
  if ( dword_50C750 > 0 )
  {
    v2 = byte_E2C380;
    v5 = (int *)&unk_E2B680;
    v3 = &unk_E2BE80;
    v4 = word_E34860;
    do
    {
      sub_42D950(byte_E2B480[4 * v1], byte_E2B481[4 * v1], byte_E2B482[4 * v1], byte_E2B483[4 * v1]);
      sub_42D910(*v4, word_E34862[2 * v1]);
      if ( *v3 )
      {
        dword_50C0B0 = 1;
        dword_E99750 = *v5;
        dword_E99754 = v5[1];
        dword_E99758 = v5[2];
        dword_E9975C = v5[3];
      }
      sub_42EC50(v2);
      result = dword_50C750;
      ++v1;
      v4 += 2;
      ++v3;
      v2 += 128;
      dword_50C0B0 = 0;
      v5 += 4;
    }
    while ( v1 < dword_50C750 );
  }
  dword_50C750 = 0;
  return result;
}
```