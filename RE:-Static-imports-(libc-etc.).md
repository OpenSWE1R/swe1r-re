## Guesses by IDA

Generated using the pretty bad `cat SWEP1RCR_newer_patch.c | grep "using guesse" | grep -v "dword_" | grep -v "flt_" | grep -v "word_" | grep -v "byte_" | grep -v "dbl_" | grep -v "off_" | grep -v "sub_" | grep -v "var_" | sort -h | uniq`

```C
//----- (0049FFE0) --------------------------------------------------------
// 417010: using guessed type _DWORD __cdecl _get_fname(_DWORD);
//----- (0049FFE0) --------------------------------------------------------
// 4318C0: using guessed type int _RTC_NumErrors(void);
// 445150: using guessed type int _cfltcvt_init_2(void);
// 44B530: using guessed type int _cfltcvt_init_5(void);
// 44B5E0: using guessed type int _cfltcvt_init_6(void);
// 4A1670: using guessed type _DWORD __cdecl _lock(_DWORD);
// 4A16F0: using guessed type _DWORD __cdecl _unlock(_DWORD);
// 4A1710: using guessed type _DWORD __cdecl _lock_file(_DWORD);
// 4A1780: using guessed type _DWORD __cdecl _unlock_file(_DWORD);
// 4A5600: using guessed type _DWORD __cdecl getSystemCP(_DWORD);
// 4A5650: using guessed type _DWORD __cdecl CPtoLCID(_DWORD);
// 4A56B0: using guessed type int setSBCS(void);
// 4A56F0: using guessed type CHAR DestStr[256];
// 4A56F0: using guessed type CHAR SrcStr[256];
// 4A70A0: using guessed type _DWORD __cdecl _ld12cvt(_DWORD, _DWORD, _DWORD);
// 4A8490: using guessed type _DWORD __cdecl __strgtold12(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 4A9430: using guessed type _DWORD __cdecl cvtdate(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 4AB170: using guessed type _DWORD __cdecl strncnt(_DWORD, _DWORD);
// 4AC054: using guessed type int __stdcall IFReleaseProject(_DWORD);
// 4AC058: using guessed type int __stdcall IFReleaseEffects(_DWORD, _DWORD);
// 4AC05C: using guessed type int __stdcall IFCreateEffects(_DWORD, _DWORD, _DWORD);
// 4AC060: using guessed type int __stdcall IFLoadProjectFile(_DWORD, _DWORD);
// 4AC1BC: using guessed type int __cdecl SmushSetVolume(_DWORD);
// 4AC1C0: using guessed type int __cdecl SmushPlay(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 4AC1C4: using guessed type int SmushShutdown(void);
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