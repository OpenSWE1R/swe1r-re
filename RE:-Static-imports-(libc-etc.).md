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