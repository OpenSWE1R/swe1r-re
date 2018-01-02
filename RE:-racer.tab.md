```C
//----- (00421120) --------------------------------------------------------
signed int __cdecl sub_421120(int a1) {
  int v1; // ebx
  FILE *v2; // esi
  int v4; // ebp
  int i; // eax
  LPCSTR v6; // eax
  const CHAR *v7; // edx
  size_t v8; // edi
  LPCSTR v9; // eax
  CHAR *v10; // edi
  unsigned int v11; // ecx
  CHAR *v12; // esi
  char *v13; // eax

  v1 = 0;
  dword_4EB3CC = 0;
  v2 = (FILE *)(*(int (__cdecl **)(int, char *))(dword_ECC420 + 48))(a1, aRb);
  if ( !v2 )
    return 1;
  (*(void (__cdecl **)(FILE *, int *, signed int))(dword_ECC420 + 56))(v2, &a1, 4);
  (*(void (__cdecl **)(FILE *, _DWORD, signed int))(dword_ECC420 + 76))(v2, 0, 2);
  v4 = ftell(v2);
  (*(void (__cdecl **)(FILE *, _DWORD, _DWORD))(dword_ECC420 + 76))(v2, 0, 0);
  lpSrcStr = (LPCSTR)(*(int (__cdecl **)(int))(dword_ECC420 + 32))(v4);
  (*(void (__cdecl **)(FILE *, LPCSTR, int))(dword_ECC420 + 56))(v2, lpSrcStr, v4);
  (*(void (__cdecl **)(FILE *))(dword_ECC420 + 52))(v2);
  if ( a1 == 1162756946 )
  {
    v4 -= 4;
    for ( i = 0; i < v4; ++i )
      lpSrcStr[i] = lpSrcStr[i + 4] ^ 0xDD;
  }
  v6 = lpSrcStr;
  v7 = &lpSrcStr[v4];
  do
  {
    if ( v6 < v7 )
    {
      do
      {
        if ( *v6 == 13 )
          break;
        if ( *v6 == 10 )
          break;
        ++v6;
      }
      while ( v6 < v7 );
      for ( ; v6 < v7; ++v6 )
      {
        if ( *v6 != 13 && *v6 != 10 )
          break;
      }
    }
    v8 = dword_4EB3CC++ + 1;
  }
  while ( v6 < v7 - 1 );
  dword_4EB3C4 = (void *)(*(int (__cdecl **)(size_t))(dword_ECC420 + 32))(4 * v8);
  v9 = lpSrcStr;
  v10 = (CHAR *)lpSrcStr;
  do
  {
    v11 = (unsigned int)&v9[v4];
    v12 = v10;
    if ( v10 < &v9[v4] )
    {
      do
      {
        if ( *v12 == 13 )
          break;
        if ( *v12 == 10 )
          break;
        ++v12;
      }
      while ( (unsigned int)v12 < v11 );
    }
    if ( (unsigned int)v12 < v11 )
    {
      do
      {
        if ( *v12 != 13 && *v12 != 10 )
          break;
        *v12++ = 0;
      }
      while ( v12 < &lpSrcStr[v4] );
    }
    sub_4214C0(v10, v10);
    v13 = strchr(v10, 9);
    if ( v13 )
      *v13 = 0;
    sub_4AB5D0(v10);
    *(_DWORD *)((char *)dword_4EB3C4 + v1) = v10;
    v9 = lpSrcStr;
    v1 += 4;
    v10 = v12;
  }
  while ( v12 < &lpSrcStr[v4 - 1] );
  qsort(dword_4EB3C4, dword_4EB3CC, 4u, sub_4212F0);
  return 1;
}
```