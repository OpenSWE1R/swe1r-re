## Allocator

They probably didn't write this themselves, but yet I can't find it online.. mhhhh

```C
typedef struct {
  union {
    struct {
      uint16_t size_short; // -8
      uint16_t pad;
    }
    uint32_t size; // -8
  };
  uint32_t unk1; // -4
  uint8_t data[]; // 0 Pointer which is actually returned
} Allocation;

//----- (0048D7E0) --------------------------------------------------------
// Allocate()
// allocator which grabs small allocations from malloc, and seems to use buckets or a heap for larger allocations
unsigned __int16 *__cdecl sub_48D7E0(unsigned int a1);

//----- (0048DB10) --------------------------------------------------------
// allocator which will be used when the alloction is small enough
void* __cdecl sub_48DB10(uint32_t a1) {
  Allocation* result = malloc(8 + a1); // 8 = sizeof(Allocation)
  if (result == 0) {
    return 0;
  }
  result->size = a1 + 8;
  result->unk1 = 0;
  return result->data;
}

//----- (0048D9A0) --------------------------------------------------------
// Free()
// counterpart to 0048D7E0
void __cdecl sub_48D9A0(int a1);

//----- (0048DA80) --------------------------------------------------------
// Realloc()
// a1 = old pointer or 0
// a2 = new size
unsigned __int16 *__cdecl sub_48DA80(_DWORD *a1, unsigned int a2) {
  unsigned __int16 *result; // eax
  unsigned int v3; // esi
  unsigned __int16 *v4; // ebp
  int v5; // eax
  unsigned int v6; // eax

  // If no allocation existed, create a new one.. done!
  if ( a1 == 0) {
    return sub_48D7E0(a2);
  }

  // If the new size is zero, just free the block
  if ( a2 == 0) {
    sub_48D9A0((int)a1);
    return 0;
  }

  // Create a new allocation where we can move to
  v4 = sub_48D7E0(a2);
  if ( v4 == 0) {
    return 0;
  }

  // Lookup old allocation size
  Allocation* a = (uintptr_t)a1 - 8; // 8 = sizeof(Allocation)
  if (a->unk1) ) {
    v5 = a->size_short & 0x7FFF; // FIXME: WTH?! *((unsigned __int16 *)a1 - 4);
  } else {
    v5 = a->size;
  }
  v6 = v5 - 8;
  
  // Copy old data (sized so it fits new buffer, but doesn't read beyond old buffer)
  v3 = min(a2, v6);
  qmemcpy(v4, a1, v3);

  // Free the old allocation
  sub_48D9A0(a1);

  // Return the new allocation
  return v4;
}
```

## Guesses by me

```C
//----- (004214C0) --------------------------------------------------------
//FIXME: This one they probably wrote themselves?!
// a1 = input string
// a2 = output string
// Unescapes string, returns length of output string
int __cdecl sub_4214C0(_BYTE *a1, char *a2);

//----- (004AB5D0) --------------------------------------------------------
// Probably '_strupr', however, might not use the C locale?! (maybe POSIX version, `strupr`?)
LPCSTR __cdecl sub_4AB5D0(LPCSTR lpSrcStr);

//----- (0049EDD0) --------------------------------------------------------
// `_strlwr`, same caveats as with `_strupr` above.
LPCSTR __cdecl sub_49EDD0(LPCSTR lpSrcStr)
```

## Guesses by IDA

Generated using the pretty bad `cat SWEP1RCR_newer_patch.c | grep "using guesse" | grep -v "dword_" | grep -v "flt_" | grep -v "word_" | grep -v "byte_" | grep -v "dbl_" | grep -v "off_" | grep -v "sub_" | grep -v "var_" | sort -h | uniq`

```C
//----- (00417010) --------------------------------------------------------
// 417010: using guessed type _DWORD __cdecl _get_fname(_DWORD);
//----- (004318C0) --------------------------------------------------------
// 4318C0: using guessed type int _RTC_NumErrors(void);
//----- (00445150) --------------------------------------------------------
// 445150: using guessed type int _cfltcvt_init_2(void);
//----- (0044B530) --------------------------------------------------------
// 44B530: using guessed type int _cfltcvt_init_5(void);
//----- (0044B5E0) --------------------------------------------------------
// 44B5E0: using guessed type int _cfltcvt_init_6(void);
//----- (004A1670) --------------------------------------------------------
// 4A1670: using guessed type _DWORD __cdecl _lock(_DWORD);
//----- (004A16F0) --------------------------------------------------------
// 4A16F0: using guessed type _DWORD __cdecl _unlock(_DWORD);
//----- (004A1710) --------------------------------------------------------
// 4A1710: using guessed type _DWORD __cdecl _lock_file(_DWORD);
//----- (004A1780) --------------------------------------------------------
// 4A1780: using guessed type _DWORD __cdecl _unlock_file(_DWORD);
//----- (004A5600) --------------------------------------------------------
// 4A5600: using guessed type _DWORD __cdecl getSystemCP(_DWORD);
//----- (004A5650) --------------------------------------------------------
// 4A5650: using guessed type _DWORD __cdecl CPtoLCID(_DWORD);
//----- (004A56B0) --------------------------------------------------------
// 4A56B0: using guessed type int setSBCS(void);
//----- (004A70A0) --------------------------------------------------------
// 4A70A0: using guessed type _DWORD __cdecl _ld12cvt(_DWORD, _DWORD, _DWORD);
//----- (004A8490) --------------------------------------------------------
// 4A8490: using guessed type _DWORD __cdecl __strgtold12(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
//----- (004A9430) --------------------------------------------------------
// 4A9430: using guessed type _DWORD __cdecl cvtdate(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
//----- (004AB170) --------------------------------------------------------
// 4AB170: using guessed type _DWORD __cdecl strncnt(_DWORD, _DWORD);
```

**Imports:**

```C
//----- (004AC054) --------------------------------------------------------
// 4AC054: using guessed type int __stdcall IFReleaseProject(_DWORD);
//----- (004AC058) --------------------------------------------------------
// 4AC058: using guessed type int __stdcall IFReleaseEffects(_DWORD, _DWORD);
//----- (004AC05C) --------------------------------------------------------
// 4AC05C: using guessed type int __stdcall IFCreateEffects(_DWORD, _DWORD, _DWORD);
//----- (004AC060) --------------------------------------------------------
// 4AC060: using guessed type int __stdcall IFLoadProjectFile(_DWORD, _DWORD);
//----- (004AC1BC) --------------------------------------------------------
// 4AC1BC: using guessed type int __cdecl SmushSetVolume(_DWORD);
//----- (004AC1C0) --------------------------------------------------------
// 4AC1C0: using guessed type int __cdecl SmushPlay(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
//----- (004AC1C4) --------------------------------------------------------
// 4AC1C4: using guessed type int SmushShutdown(void);
//----- (004AC1C8) --------------------------------------------------------
// 4AC1C8: using guessed type int __cdecl SmushStartup(_DWORD, _DWORD);
```


## fread

```C
//----- (0049FFE0) --------------------------------------------------------
size_t __cdecl sub_49FFE0(void *a1, size_t a2, size_t a3, FILE *a4) {
  size_t v4; // edi

  _lock_file(a4);
  v4 = fread(a1, a2, a3, a4);  // actually _fread_nolock() probably
  _unlock_file(a4);
  return v4;
}
```

## fwrite

```C
//----- (004A0160) --------------------------------------------------------
size_t __cdecl sub_4A0160(void *a1, size_t a2, size_t a3, FILE *a4) {
  size_t v4; // edi

  _lock_file(a4);
  v4 = fwrite(a1, a2, a3, a4); // actually _fwrite_nolock() probably
  _unlock_file(a4);
  return v4;
}
```