# Thread mainloop

```C
//----- (00423330) --------------------------------------------------------
void __stdcall __noreturn StartAddress(LPVOID lpThreadParameter) {
  while(1) {
    WaitForSingleObject(hHandle, 0xFFFFFFFF);
    sub_4234C0();
  }
}
```

# Thread loop function

```C
#define ASSERT(condition, message, path, line) \
  if ( !(condition) ) { \
    dword_ECC420->unk6((message), (path), (line)); \
  }
```

```C
//----- (004233A0) --------------------------------------------------------
signed int __cdecl sub_4233A0(int a1, int32_t a2, int32_t a3) {
  unsigned int v4; // esi
  int v5; // ebp
  unsigned int v6; // ebx
  int v7; // eax

  if ( !a1 ) {
    return 0;
  }

  if ( !dword_4EB40C ) {
    return 0;
  }

  v4 = (unsigned int)a3;
  v5 = dword_4EB414;
  if ( (*(int (__stdcall **)(int, int, void *, void **, int *, _DWORD, _DWORD, _DWORD))(*(_DWORD *)dword_4EB414 + 44))(
         dword_4EB414,
         a2,
         a3,
         &a3,
         &a2,
         0,
         0,
         0) < 0 )
    return 0;
  v6 = dword_4EB40C;

  if ( dword_4EB40C >= v4 ) {
    v6 = v4;
  }

  memset(a3, 0, v4);
  (*(void (__cdecl **)(int, void *, unsigned int))(dword_ECC420 + 56))(dword_4EB404, a3, v6);
  if ( v6 < v4 && dword_4EB408 ) {
    (*(void (__cdecl **)(int, _DWORD, _DWORD))(dword_ECC420 + 76))(dword_4EB404, *(_DWORD *)(a1 + 60), 0);
    dword_4EB40C = *(_DWORD *)(a1 + 40);
    (*(void (__cdecl **)(int, unsigned int, unsigned int))(dword_ECC420 + 56))(
      dword_4EB404,
      (unsigned int)a3 + v6,
      v4 - v6);
  }

  v7 = (*(int (__stdcall **)(int, void *, int, _DWORD, _DWORD))(*(_DWORD *)v5 + 48))(v5, a3, a2, 0, 0);
  if ( v7 < 0 ) {
    v7 = (*(int (__stdcall **)(int, void *, int, _DWORD, _DWORD))(*(_DWORD *)v5 + 48))(v5, a3, a2, 0, 0);
  }

  return v7 < 0 ? 0 : v6;
}
```

```C
//----- (004234C0) --------------------------------------------------------
signed void sub_4234C0() {
  signed int result; // eax
  int v1; // esi
  unsigned int v2; // [esp+8h] [ebp-4h]

  if ( !dword_4EB418 ) {
    return;
  }

  if ( !dword_4EB40C ) {
    if ( !dword_4EB408 ) {
      return;
    }

    // Seek to current playback location (?)
    dword_ECC420->unk19(dword_4EB404, *(_DWORD *)(dword_4EB418 + 60), 0);
    dword_4EB40C = *(_DWORD *)(dword_4EB418 + 40);
  }

  ASSERT(dword_4EB414, aPbuffer, aDDevelQa5PcGno_5, 1774)

  // Check how many bytes are available?
  (*(void (__stdcall **)(int, unsigned int *))(*(_DWORD *)dword_4EB414 + 76))(v1, &v2);

  // Write bytes to stream?
  int32_t r = sub_4233A0(dword_4EB418, v2 < 88200 ? 88200 : 0, 88200);
  dword_4EB40C -= r;

  return;
}
```