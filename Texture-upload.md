```C
//----- (0048A5E0) --------------------------------------------------------
int __cdecl sub_48A5E0(_DWORD *a1, _DWORD *a2, unsigned int a3, int a4)
{
  int result; // eax
  _DWORD **v5; // ebx
  unsigned int *v6; // ebp
  unsigned int v7; // edx
  int v8; // eax
  int v9; // eax
  unsigned int v10; // ebp
  unsigned int v11; // esi
  signed int v12; // eax
  unsigned int v13; // eax
  unsigned int v14; // esi
  int v15; // [esp+8Ch] [ebp-1C4h]
  int v16; // [esp+90h] [ebp-1C0h]
  int v17; // [esp+94h] [ebp-1BCh]
  int v18; // [esp+98h] [ebp-1B8h]
  int v19; // [esp+9Ch] [ebp-1B4h]
  signed int (__cdecl *v20)(_DWORD *, unsigned int, int); // [esp+A0h] [ebp-1B0h]
  int v21; // [esp+A4h] [ebp-1ACh]
  int v22; // [esp+A8h] [ebp-1A8h]
  int v23; // [esp+ACh] [ebp-1A4h]
  int v24; // [esp+B0h] [ebp-1A0h]
  unsigned int v25; // [esp+B4h] [ebp-19Ch]
  unsigned int *v26; // [esp+B8h] [ebp-198h]
  char v27; // [esp+BCh] [ebp-194h]
  int v28; // [esp+DCh] [ebp-174h]
  int v29; // [esp+E0h] [ebp-170h]
  int v30; // [esp+E4h] [ebp-16Ch]
  unsigned int v31; // [esp+E8h] [ebp-168h]
  unsigned int v32; // [esp+F4h] [ebp-15Ch]
  char v33; // [esp+124h] [ebp-12Ch]
  int (*v34)(); // [esp+144h] [ebp-10Ch]
  int v35; // [esp+158h] [ebp-F8h]
  unsigned int v36; // [esp+160h] [ebp-F0h]
  int v37; // [esp+164h] [ebp-ECh]
  int v38; // [esp+168h] [ebp-E8h]
  int v39; // [esp+17Ch] [ebp-D4h]
  char v40; // [esp+1D4h] [ebp-7Ch]
  int v41; // [esp+1DCh] [ebp-74h]
  int v42; // [esp+1E0h] [ebp-70h]

  memset(a1, 0, 0x94u);
  result = dword_52E61C;
  v15 = 0;
  v16 = 0;
  if ( !dword_52E61C )
    return result;
  v5 = (_DWORD **)a2;
  v6 = (unsigned int *)*a2;
  v26 = v6;
  sub_48A9E0(v6[3], v6[4], (unsigned int *)&v19, (unsigned int *)&v18);
  v25 = v19 * v18 * v6[9] >> 3;
  if ( dword_52E614 )
  {
    v7 = a3;
  }
  else
  {
    v7 = 1;
    a3 = 1;
  }
  if ( a4 == 1 )
  {
    v8 = dword_52D568;
  }
  else if ( a4 == 2 )
  {
    v8 = dword_52D560;
  }
  else
  {
    v8 = dword_52D564;
  }
  qmemcpy(&v27, (char *)&unk_52D5B0 + 96 * v8, 0x20u);
  memset(&v28, 0, 0x7Cu);
  v28 = 124;
  v29 = 4103;
  v34 = (int (*)())6144;
  v31 = v6[3];
  v9 = v6[4];
  v10 = 0;
  v30 = v9;
  v15 = 0;
  qmemcpy(&v33, &v27, 0x20u);
  if ( v7 > 1 )
  {
    v29 = 135175;
    v34 = sub_401808;
    v32 = v7;
  }
  qmemcpy(&v40, &v28, 0x7Cu);
  if ( dword_52E638->CreateSurface(&v28, &v15, 0) || v15->QueryInterface(&unk_4AF328, &v17) )
  {
    goto LABEL_43;
  }
  v11 = a3;
  if ( a3 )
  {
    do
    {
      memset(&v35, 0, 0x7Cu);
      v35 = 124;
      if (v15->Lock(0, &v35, 1, 0))
        goto LABEL_43;
      v12 = (*v5)[8];
      if ( v12 && v12 > 0 && v12 <= 2 )
      {
        sub_488370(*v5);
        v13 = 0;
        // Check if height is != 0
        if ( v36 )
        {
          // Copy line `v13`
          do {
            qmemcpy((void *)(v39 + v13 * v38), (const void *)((*v5)[22] + v13 * (*v5)[6]), 2 * v37);
            ++v13;
          } while ( v13 < v36 );
          v11 = a3;
        }
        sub_4883C0(*v5);
      }
      if (v15->Unlock(0))
        goto LABEL_43;
      if ( v10 < v11 - 1 )
      {
        v21 = 0;
        v22 = 0;
        v23 = 0;
        v20 = sub_401000;
        if (v15->GetAttachedSurface(&v20, &v15))
        {
          goto LABEL_43;
        }
      }
      ++v10;
      ++v5;
    }
    while ( v10 < v11 );
  }
  if ( v19 == v26[3] && v18 == v26[4] )
    goto LABEL_39;
  v42 = v19;
  v41 = v18;
  if ( !dword_52E638->CreateSurface(&v40, &v16, 0) && !(v16->QueryInterface((&unk_4AF328, &v24) )
  {
    v14 = 0;
    if ( a3 )
    {
      while ( !v16->Blt(0, v15, 0, 0x1000000, 0) )
      {
        if ( v14 < a3 - 1 )
        {
          v20 = sub_401000;
          v21 = 0;
          v22 = 0;
          v23 = 0;
          if (v16->GetAttachedSurface(&v20, &v16) )
          {
            break;
          }
        }
        if ( ++v14 >= a3 )
          goto LABEL_36;
      }
      goto LABEL_43;
    }
LABEL_36:
    if ( v16 )
      v16->Release();
      v17->Release();
    qmemcpy(&v28, &v40, 0x7Cu);
    v17 = v24;
LABEL_39:
    if ( v15 )
      v15->Release();
    result = (int)a1;
    a1[31] = v17;
    qmemcpy(a1, &v28, 0x7Cu);
    a1[33] = v25;
    return result;
  }
LABEL_43:
  result = v15;
  if ( v15 )
    result = v15->Release();
  return result;
}
```