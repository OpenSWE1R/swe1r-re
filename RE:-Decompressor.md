# Decompressor?

This is used from the model loader for "Comp" chunks

```C
//----- (0042D520) --------------------------------------------------------
_BYTE *__cdecl sub_42D520(char *a1, _BYTE *a2) {
  char *v2; // edx
  _BYTE *result; // eax
  int v4; // ebp
  int v5; // esi
  char v6; // cl
  char v7; // bl
  char v8; // cl
  int v9; // ebx
  int v10; // ecx
  int v11; // ecx
  int v12; // ebx
  int v13; // ebx
  int v14; // edi
  int v15; // esi
  char v16; // dl
  bool v17; // sf
  unsigned __int8 v18; // of
  signed __int16 v19; // [esp+10h] [ebp-Ch]
  int v20; // [esp+14h] [ebp-8h]
  __int16 v21; // [esp+18h] [ebp-4h]
  char *v22; // [esp+20h] [ebp+4h]
  int v23; // [esp+24h] [ebp+8h]

  v2 = a1;
  result = a2;
  v4 = (int)(a1 - 4096);
  v5 = 1;
  v19 = 0;
  do
  {
    v6 = *v2++;
    v7 = 0;
    v20 = v6;
    v23 = 0;
    while ( (1 << v7) & v20 )
    {
      v8 = *v2++;
      *result++ = v8;
      *(_BYTE *)(v5 + v4) = v8;
      v5 = ((_WORD)v5 + 1) & 0xFFF;
LABEL_11:
      v7 = v23 + 1;
      v18 = __OFSUB__(v23 + 1, 8);
      v17 = (signed __int16)(v23++ - 7) < 0;
      if ( !(v17 ^ v18) )
        goto LABEL_14;
    }
    v9 = *v2;
    v10 = v2[1];
    v2 += 2;
    v11 = ((v9 & 0xF) << 8) + v10;
    v22 = v2;
    v12 = v9 >> 4;
    v21 = v11;
    if ( v11 )
    {
      v13 = v12 + 1;
      v14 = 0;
      if ( v13 >= 0 )
      {
        while ( 1 )
        {
          ++result;
          v15 = v5 + 1;
          v16 = *(_BYTE *)((((_WORD)v14 + (_WORD)v11) & 0xFFF) + v4);
          *(result - 1) = v16;
          *(_BYTE *)(v15 + v4 - 1) = v16;
          v5 = v15 & 0xFFF;
          if ( ++v14 > v13 )
            break;
          LOWORD(v11) = v21;
        }
        v2 = v22;
      }
      goto LABEL_11;
    }
    v19 = 1;
LABEL_14:
    ;
  }
  while ( !v19 );
  return result;
}
```