```C
//----- (00421120) --------------------------------------------------------
signed int __cdecl sub_421120(const char* a1) {
  int v1; // ebx
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

  // Open file
  FILE* v2 = dword_ECC420->unk12(a1, aRb);
  if ( !v2 ) {
    return 1;
  }

  // Read 4 magic bytes
  uint32_t magic;
  dword_ECC420->unk14(v2, &magic, 4);

  // Query file size
  dword_ECC420->unk19(v2, 0, 2);
  v4 = ftell(v2);
  dword_ECC420->unk19(v2, 0, 0);

  // Allocate a buffer and read file to buffer
  lpSrcStr = dword_ECC420->unk8(v4);
  dword_ECC420->unk14(v2, lpSrcStr, v4);

  // Close file again
  dword_ECC420->unk13(v2);
  
  if ( magic == 0x454E4352 ) { // 'ENCR' or 'RCNE'
    v4 -= 4;

    // Descramble the file and skip header
    for ( i = 0; i < v4; i++ ) {
      lpSrcStr[i] = lpSrcStr[i + 4] ^ 0xDD;
    }
  }

  // Scan over the whole file
  v6 = lpSrcStr;
  v7 = &lpSrcStr[v4];
  do {
    if ( v6 < v7 ) {

      do {
        if ( *v6 == 13 ) { break; }
        if ( *v6 == 10 ) { break; }
        v6++;
      } while ( v6 < v7 );

      for ( ; v6 < v7; ++v6 ) {
        if ( *v6 != 13 && *v6 != 10 ) {
          break;
        }
      }

    }
    v8 = ++dword_4EB3CC;
  } while ( v6 < v7 - 1 );

  dword_4EB3C4 = dword_ECC420->unk8(4 * v8);

  v9 = lpSrcStr;
  v10 = (CHAR *)lpSrcStr;
  do {
    v11 = (unsigned int)&v9[v4];
    v12 = v10;

    if ( v10 < &v9[v4] ) {
      do {
        if ( *v12 == 13 ) {
          break;
        }
        if ( *v12 == 10 ) {
          break;
        }
        ++v12;
      } while ( (unsigned int)v12 < v11 );
    }

    if ( (unsigned int)v12 < v11 ) {
      do {
        if ( *v12 != 13 && *v12 != 10 ) {
          break;
        }
        *v12++ = 0;
      } while ( v12 < &lpSrcStr[v4] );
    }

    sub_4214C0(v10, v10);

    v13 = strchr(v10, 9);
    if ( v13 ) {
      *v13 = 0;
    }

    sub_4AB5D0(v10);
    *(_DWORD *)((char *)dword_4EB3C4 + v1) = v10;

    v9 = lpSrcStr;

    v1 += 4;
    v10 = v12;
  } while ( v12 < &lpSrcStr[v4 - 1] );

  qsort(dword_4EB3C4, dword_4EB3CC, 4u, sub_4212F0);
  return 1;
}
```